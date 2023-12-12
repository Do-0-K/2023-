#pragma once
int board_20201840062[19][19];
#define WHITE 1
#define BLACK -1
#include <Windows.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
int black_turn1 = 0;
int board[19][19];
char bd[19][19];
int aa1 = 0, bb1 = 0;
using namespace std;
bool check123(int color);
int weight_board[19][19]; //가중치 보드판
int dir[8][2] = { { 1,0 },{ 0,1 },{ 1,1 },{ 1,-1 },{ -1,0 },{ 0,-1 },{ -1,-1 },{ -1,1 } };
int n = 19;
int weight_check123[2][6][3][2];
int start_x, start_y;//ai입장에서 탐색 맨 처음 좌표 
int ansx, ansy; // 최종 좌표
int real_high[6];
bool tf;
typedef struct xy {
	int x, y;
}xy;
typedef struct info {
	int num = 0, enemy = 0, emptyspace = 0;
}info;
typedef struct info2 {
	int x, y, weight;
}info2;
bool cmp(info2 a, info2 b) {
	return a.weight > b.weight;
}
void init() {
	weight_check123[0][1][0][0] = 2;
	weight_check123[1][1][0][0] = 1;
	weight_check123[0][1][0][1] = 2;
	weight_check123[1][1][0][1] = 0;

	weight_check123[0][2][0][0] = 50;
	weight_check123[1][2][0][0] = 5;
	weight_check123[0][2][0][1] = 50;
	weight_check123[1][2][0][1] = 1;
	weight_check123[0][2][1][1] = 2;
	weight_check123[1][2][1][1] = 1;
	weight_check123[0][2][1][0] = 2;
	weight_check123[1][2][1][0] = 1;

	weight_check123[0][3][0][0] = 500;
	weight_check123[1][3][0][0] = 100;
	weight_check123[0][3][0][1] = 250;
	weight_check123[1][3][0][1] = 10;
	weight_check123[0][3][1][0] = 250;
	weight_check123[1][3][1][0] = 10;
	weight_check123[0][3][1][1] = 250;
	weight_check123[1][3][1][1] = 10;

	weight_check123[0][4][0][0] = 30000;
	weight_check123[0][4][1][0] = 20000;
	weight_check123[0][4][2][0] = 20000;
	weight_check123[1][4][0][0] = 10000;
	weight_check123[1][4][1][0] = 10000;
	weight_check123[1][4][2][0] = 10000;
}
void add_weight(int color[2]) {//착수 후 근처에 가중치 부여
	memset(weight_board, 0, sizeof(weight_board));
	for (int type = 0; type < 2; type++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = 0;
				info Count[5];//세로, 가로, 우하, 우상 돌 갯수
				if (board[i][j])continue;
				for (int d = 0; d < 4; d++) {
					int nx, ny;
					int count = 1;
					int blank_count = 0;//빈칸이 0~ 2 개까지만 존재하도록 만들꺼
					int blank_count1 = 0;
					int blank_count2 = 0;
					int remember = 0;
					int num = 0;
					int enemy_count = 0;
					int before;
					while (true) {
						nx = i + (count * dir[d][0]), ny = j + (count * dir[d][1]);
						before = board[nx - dir[d][0]][ny - dir[d][1]];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							if (remember || blank_count1 == 0) {
								enemy_count++;
							}
							if (before != 0) {
								remember = blank_count1;
							}
							break;
						}
						if (board[nx][ny] == color[(type + 1) % 2]) {
							if (remember || blank_count1 == 0) {
								enemy_count++;
							}
							if (before != 0) {
								remember = blank_count1;
							}
							break;
						}
						if (board[nx][ny] == color[type]) {
							remember = blank_count1;
							num++;
						}
						if (board[nx][ny] == 0) {
							blank_count1++;
						}
						if (blank_count1 >= 2) {
							break;
						}
						count++;
					}
					blank_count1 = remember;
					count = 1;
					remember = 0;
					//반대편라인
					while (true) {
						nx = i + (count * dir[d + 4][0]), ny = j + (count * dir[d + 4][1]);
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							if (remember || blank_count2 == 0) {
								enemy_count++;
							}
							if (before != 0) {
								remember = blank_count2;
							}
							break;
						}
						if (board[nx][ny] == color[(type + 1) % 2]) {
							if (remember || blank_count2 == 0) {
								enemy_count++;
							}
							if (before != 0) {
								remember = blank_count2;
							}
							break;
						}
						if (board[nx][ny] == color[type]) {
							remember = blank_count2;
							num++;
						}
						if (board[nx][ny] == 0) {
							blank_count2++;
						}
						if (blank_count2 >= 2) {
							break;
						}
						count++;
					}
					blank_count2 = remember;
					blank_count = blank_count1 + blank_count2;
					Count[d] = { num,enemy_count,blank_count };
				}
				//막힌 경우 가중치 감소
				for (int d = 0; d < 4; d++) {
					int num = Count[d].num, enemy = Count[d].enemy, emptyspace = Count[d].emptyspace;
					int temp_w = weight_check123[(type + 1) % 2][num][enemy][emptyspace];
					//빈 공간은 하나만 감당, num+emptyspace>=5,enemy 2개 가중치 부여하지 않는다. 
					if (emptyspace >= 2 || num + emptyspace >= 5) {
						continue;
					}
					if (num != 4 && enemy >= 2) {
						continue;
					}
					sum += temp_w;
				}
				weight_board[i][j] += sum;
				if (board[i][j])weight_board[i][j] = 0;
			}
		}
	}
}
void search(int cnt, int color) {
	int ncolor[2] = { 0, };
	if (color == 1) {
		ncolor[0] = 2, ncolor[1] = 1;
	}
	else {
		ncolor[0] = 1, ncolor[1] = 2;
	}
	int high = 0;
	add_weight(ncolor);
	deque <info2> save_pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int wow = weight_board[i][j];
			if (wow) {
				if (wow == 301 || wow == 302) {
					wow = 24;
				}
				else if (wow >= 118 && wow <= 200) {
					wow = 320;
				}
				save_pos.push_back({ i,j,wow });
				high = max(high, wow);
			}
		}
	}
	sort(save_pos.begin(), save_pos.end(), cmp);
	int MAX = save_pos[0].weight;
	int idx = 0;
	for (int i = 1; i < save_pos.size(); i++) {
		idx = i;
		int num = save_pos[i].weight;
		if (num != MAX) {
			break;
		}
	}
	save_pos.erase(save_pos.begin() + idx, save_pos.end());
	int temp_color;
	if (color == 1)temp_color = 2;
	else temp_color = 1;
	if (cnt % 2 == 1 && check123(temp_color)) {
		return;
	}
	if (tf) {
		return;
	}
	if (!tf && (cnt % 2 == 1 && ((MAX >= 326 && MAX < 406) || MAX >= 521))) {
		if (!((105 <= MAX && MAX <= 300) || (4000 <= MAX && MAX < 20000))) {

			tf = true;
			ansx = start_x, ansy = start_y;

			return;
		}
	}
	if (cnt == 1) {
		return;
	}
	if (color == 1) {
		for (int i = 0; i < save_pos.size(); i++) {
			int x = save_pos[i].x, y = save_pos[i].y;
			board[x][y] = color;
			search(cnt + 1, 2);
			board[x][y] = 0;
		}
	}
	else if (color == 2) {
		for (int i = 0; i < save_pos.size(); i++) {
			int x = save_pos[i].x, y = save_pos[i].y;
			board[x][y] = color;
			search(cnt + 1, 1);
			board[x][y] = 0;
		}
	}
}
void AI(int user, int ai) {
	tf = false;
	int color[2] = { user,ai };
	memset(real_high, 0, sizeof(real_high));
	add_weight(color);
	deque <info2> save_pos;
	save_pos.clear();
	int high = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int wow = weight_board[i][j];
			if (wow) {
				if (wow == 301 || wow == 302)wow = 24;
				else if (wow >= 118 && wow <= 200)wow = 320;
				save_pos.push_back({ i,j,wow });
				if (high < wow) {
					high = wow;
					ansx = i, ansy = j;
				}
			}
		}
	}
	sort(save_pos.begin(), save_pos.end(), cmp);
	int MAX = save_pos[0].weight;
	if (!((MAX >= 326 && MAX < 406) || MAX >= 521)) {
		//가중치가 0이 아닌 놈들을 대상으로 search 시작
		//search안에서 add_weight로 map 탐색하는대신 true false 해야함
		for (int i = 0; i < save_pos.size(); i++) {
			int x = save_pos[i].x, y = save_pos[i].y;
			start_x = x, start_y = y;
			board[x][y] = ai;
			search(0, user);
			board[x][y] = 0;
		}

	}
	board[ansx][ansy] = ai;
	aa1 = ansx;
	bb1 = ansy;
}
bool check123(int color) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == color) {
				for (int d = 0; d < 8; d++) {
					int cnt = 1;
					while (true) {
						int nx = i + (cnt * dir[d][0]), ny = j + (cnt * dir[d][1]);
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							break;
						}
						if (board[nx][ny] != color) {
							break;
						}
						cnt++;
					}
					if (cnt == 5) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
void WhiteAttack_20201840062(int* x, int* y) {
	if (black_turn1 == 0) {
		init();
		black_turn1++;
	}
	AI(1, 2);
	*x = aa1;
	*y = bb1;
	board_20201840062[*y][*x] = WHITE;
}
void WhiteDefence_20201840062(int x, int y) {
	board[x][y] = 1;
	board_20201840062[y][x] = BLACK;
}
void BlackAttack_20201840062(int* x, int* y) {
	if (black_turn1 == 0) {
		init();
		*x = 9; *y = 9;
		board[9][9] = 1;
		black_turn1++;
	}
	else {
		AI(2, 1);
		*x = aa1;
		*y = bb1;
	}
	board_20201840062[*y][*x] = BLACK;
}
void BlackDefence_20201840062(int x, int y) {
	board[x][y] = 2;
	board_20201840062[y][x] = WHITE;
}