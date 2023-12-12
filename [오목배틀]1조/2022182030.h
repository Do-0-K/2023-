#pragma once
#include<cstdlib>
#include<ctime>

int board_2022182030[19][19];
int GoodStone_2022182030[19][19];

//흰돌		1
//검은돌	-1
#define BLACK -1
#define WHITE 1
typedef struct stoneXY_2022182030
{
	int x, y;
	int num;
};


#define P_line 300

typedef struct {
	int x, y;
}XY_2022182030;



// 가중치
// 1. 같은 라인(상대 자신 상관 없이) : 가로세로대각선 : 10점
// 2. 자신 근접 돌 ( 1칸차이 : 40점, 2칸차이: 30점, 3칸차이: 20점 4칸차이: 10점 )
// 2. 상대 근접 돌 ( 1칸차이 : 45점, 2칸차이: 35점, 3칸차이: 25점 4칸차이: 15점 )
// 4. 상대 위치, 자신 위치엔 -10000점 (못놓게
// 5. 보드 가장자리 ( -3점 : 동점인경우 안쪽에 놓게)

void ScanBoard_W_2022182030();
void ScanBoard_W_2022182030() {


	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			GoodStone_2022182030[i][j] = 0;
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			// 1. 라인당 점수 추천 ( 10점 )
			if (board_2022182030[i][j] == BLACK || board_2022182030[i][j] == WHITE) {


				//일단 같은라인(가로세로)ㄱ 10점씩
				for (int a = 0; a < 19; a++) {
					GoodStone_2022182030[i][a] += P_line;
					GoodStone_2022182030[a][j] += P_line;
				}
				//대각선 왼위->오아래 1번
				for (int a = 0; a < 19; a++) {
					if (i - a < 0 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i - a][j - a] += P_line;
				}
				//대각선 왼위->오아래 2번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i + a][j + a] += P_line;
				}
				// 대각선 오위->왼아래 1번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i + a][j - a] += P_line;
				}
				// 대각선 오위->왼아래 2번
				for (int a = 0; a < 19; a++) {
					if (i - a > 0 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i - a][j + a] += P_line;
				}

			}
			// 1. 라인 점수 끝

			// 1. 라인당 점수 추천 ( 10점 )
			if (board_2022182030[i][j] == WHITE) {


				//일단 같은라인(가로세로)ㄱ 10점씩
				for (int a = 0; a < 19; a++) {
					GoodStone_2022182030[i][a] += P_line;
					GoodStone_2022182030[a][j] += P_line;
				}
				//대각선 왼위->오아래 1번
				for (int a = 0; a < 19; a++) {
					if (i - a < 0 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i - a][j - a] += P_line;
				}
				//대각선 왼위->오아래 2번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i + a][j + a] += P_line;
				}
				// 대각선 오위->왼아래 1번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i + a][j - a] += P_line;
				}
				// 대각선 오위->왼아래 2번
				for (int a = 0; a < 19; a++) {
					if (i - a > 0 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i - a][j + a] += P_line;
				}

			}
			// 1. 라인 점수 끝
			// 
			// 2. 근접 돌 점수 추천
			if (board_2022182030[i][j] == BLACK) {

				//가장자리돌이 아닐때
				for (int a = 0; a < 5; a++) {
					if (i > a && i < 18 - a && j >a && j < 18 - a) {

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i <= a && j <= a) { // 만약 왼쪾위에 붙은 돌이라면...
						// 6, 8, 9번만 증가

						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i <= a && j >= 18 - a) {	// 만약 오른쪾 위쪽에 붙은 돌이라면...
						//4,7,8번만 증가
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i >= 18 - a && j <= a) {//만약 왼쪽 아래에 붙은 돌이라면...
						// 2,3,6번만 증가
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));
					}
					else if (i >= 18 - a && j >= 18 - a) { // 만약 오른쪾아래에붙은.,
						//1,2,4번만 증가

						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
					}
					else if (i <= a) { // 위쪽에 붙은거라면
						// 4,5,6,7,8,9 머ㅏㄴ 증가

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (j <= a) { // 왼쪽에 붙은거라면

						//2,3,5,6,89만 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i >= 18 - a) { // 아래쪾에 붙은거라면
						// 123456 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

					}
					else if (j >= 18 - a) { // 오른쪼에 붙은거라면
						// 12,45,78 만 ㅈ븡가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));

					}
				}
			}
			else if (board_2022182030[i][j] == WHITE) {

				//가장자리돌이 아닐때
				for (int a = 0; a < 5; a++) {
					if (i > a && i < 18 - a && j >a && j < 18 - a) {

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i <= a && j <= a) { // 만약 왼쪾위에 붙은 돌이라면...
						// 6, 8, 9번만 증가

						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i <= a && j >= 18 - a) {	// 만약 오른쪾 위쪽에 붙은 돌이라면...
						//4,7,8번만 증가
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i >= 18 - a && j <= a) {//만약 왼쪽 아래에 붙은 돌이라면...
						// 2,3,6번만 증가
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));
					}
					else if (i >= 18 - a && j >= 18 - a) { // 만약 오른쪾아래에붙은.,
						//1,2,4번만 증가

						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
					}
					else if (i <= a) { // 위쪽에 붙은거라면
						// 4,5,6,7,8,9 머ㅏㄴ 증가

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (j <= a) { // 왼쪽에 붙은거라면

						//2,3,5,6,89만 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i >= 18 - a) { // 아래쪾에 붙은거라면
						// 123456 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

					}
					else if (j >= 18 - a) { // 오른쪼에 붙은거라면
						// 12,45,78 만 ㅈ븡가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));

					}
				}
			}
			// 근접 돌 위치 점수 끝



			// 3. 지금 위치한 돌에 못놓게 -10000점
			if (board_2022182030[i][j] == BLACK || board_2022182030[i][j] == WHITE) {
				GoodStone_2022182030[i][j] = -100000;
			}
			//4.가장자리 위치에 있는 돌은 -3점
			if (i == 0 || i == 19) {
				GoodStone_2022182030[i][j] -= 3;
			}
			if (j == 0 || j == 19) {
				GoodStone_2022182030[i][j] -= 3;
			}

			//4.가운데 쪽에 있는 있는 돌은 +3점
			if (i > 5 && i < 13) {
				GoodStone_2022182030[i][j] += 3;
			}
			if (j > 5 && j < 13) {
				GoodStone_2022182030[i][j] += 3;
			}

		}

	}
	return;
}


void ScanBoard_B_2022182030();
void ScanBoard_B_2022182030() {


	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			GoodStone_2022182030[i][j] = 0;
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			// 1. 라인당 점수 추천 ( 10점 )
			if (board_2022182030[i][j] == BLACK || board_2022182030[i][j] == WHITE) {


				//일단 같은라인(가로세로)ㄱ 10점씩
				for (int a = 0; a < 19; a++) {
					GoodStone_2022182030[i][a] += P_line;
					GoodStone_2022182030[a][j] += P_line;
				}
				//대각선 왼위->오아래 1번
				for (int a = 0; a < 19; a++) {
					if (i - a < 0 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i - a][j - a] += P_line;
				}
				//대각선 왼위->오아래 2번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i + a][j + a] += P_line;
				}
				// 대각선 오위->왼아래 1번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i + a][j - a] += P_line;
				}
				// 대각선 오위->왼아래 2번
				for (int a = 0; a < 19; a++) {
					if (i - a > 0 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i - a][j + a] += P_line;
				}

			}
			// 1. 라인 점수 끝

			// 1. 라인당 점수 추천 ( 10점 )
			if (board_2022182030[i][j] == BLACK) {


				//일단 같은라인(가로세로)ㄱ 10점씩
				for (int a = 0; a < 19; a++) {
					GoodStone_2022182030[i][a] += P_line;
					GoodStone_2022182030[a][j] += P_line;
				}
				//대각선 왼위->오아래 1번
				for (int a = 0; a < 19; a++) {
					if (i - a < 0 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i - a][j - a] += P_line;
				}
				//대각선 왼위->오아래 2번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i + a][j + a] += P_line;
				}
				// 대각선 오위->왼아래 1번
				for (int a = 0; a < 19; a++) {
					if (i + a > 18 || j - a < 0) {
						break;
					}
					GoodStone_2022182030[i + a][j - a] += P_line;
				}
				// 대각선 오위->왼아래 2번
				for (int a = 0; a < 19; a++) {
					if (i - a > 0 || j + a > 18) {
						break;
					}
					GoodStone_2022182030[i - a][j + a] += P_line;
				}

			}
			// 1. 라인 점수 끝
			// 2. 근접 돌 점수 추천
			if (board_2022182030[i][j] == WHITE) {

				//가장자리돌이 아닐때
				for (int a = 0; a < 5; a++) {
					if (i > a && i < 18 - a && j >a && j < 18 - a) {

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i <= a && j <= a) { // 만약 왼쪾위에 붙은 돌이라면...
						// 6, 8, 9번만 증가

						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i <= a && j >= 18 - a) {	// 만약 오른쪾 위쪽에 붙은 돌이라면...
						//4,7,8번만 증가
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i >= 18 - a && j <= a) {//만약 왼쪽 아래에 붙은 돌이라면...
						// 2,3,6번만 증가
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));
					}
					else if (i >= 18 - a && j >= 18 - a) { // 만약 오른쪾아래에붙은.,
						//1,2,4번만 증가

						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
					}
					else if (i <= a) { // 위쪽에 붙은거라면
						// 4,5,6,7,8,9 머ㅏㄴ 증가

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (j <= a) { // 왼쪽에 붙은거라면

						//2,3,5,6,89만 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (15 + (10 * (4 - a)));

					}
					else if (i >= 18 - a) { // 아래쪾에 붙은거라면
						// 123456 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (15 + (10 * (4 - a)));

					}
					else if (j >= 18 - a) { // 오른쪼에 붙은거라면
						// 12,45,78 만 ㅈ븡가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (15 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (15 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (15 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (15 + (10 * (4 - a)));

					}
				}
			}
			else if (board_2022182030[i][j] == BLACK) {

				//가장자리돌이 아닐때
				for (int a = 0; a < 5; a++) {
					if (i > a && i < 18 - a && j >a && j < 18 - a) {

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i <= a && j <= a) { // 만약 왼쪾위에 붙은 돌이라면...
						// 6, 8, 9번만 증가

						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i <= a && j >= 18 - a) {	// 만약 오른쪾 위쪽에 붙은 돌이라면...
						//4,7,8번만 증가
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i >= 18 - a && j <= a) {//만약 왼쪽 아래에 붙은 돌이라면...
						// 2,3,6번만 증가
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));
					}
					else if (i >= 18 - a && j >= 18 - a) { // 만약 오른쪾아래에붙은.,
						//1,2,4번만 증가

						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
					}
					else if (i <= a) { // 위쪽에 붙은거라면
						// 4,5,6,7,8,9 머ㅏㄴ 증가

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (j <= a) { // 왼쪽에 붙은거라면

						//2,3,5,6,89만 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j + a] += (10 + (10 * (4 - a)));

					}
					else if (i >= 18 - a) { // 아래쪾에 붙은거라면
						// 123456 증가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j + a] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j + a] += (10 + (10 * (4 - a)));

					}
					else if (j >= 18 - a) { // 오른쪼에 붙은거라면
						// 12,45,78 만 ㅈ븡가

						// 1 2 3번 위치
						GoodStone_2022182030[i - a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i - a][j] += (10 + (10 * (4 - a)));

						// 4 5 6번 위치
						GoodStone_2022182030[i][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i][j] += (10 + (10 * (4 - a)));

						// 7 8 9번 위치
						GoodStone_2022182030[i + a][j - a] += (10 + (10 * (4 - a)));
						GoodStone_2022182030[i + a][j] += (10 + (10 * (4 - a)));

					}
				}
			}
			// 근접 돌 위치 점수 끝


			// 3. 지금 위치한 돌에 못놓게 -10000점
			if (board_2022182030[i][j] == BLACK || board_2022182030[i][j] == WHITE) {
				GoodStone_2022182030[i][j] = -100000;
			}
			//4.가장자리 위치에 있는 돌은 -3점
			if (i == 0 || i == 19) {
				GoodStone_2022182030[i][j] -= 3;
			}
			if (j == 0 || j == 19) {
				GoodStone_2022182030[i][j] -= 3;
			}

			//4.가운데 쪽에 있는 있는 돌은 +3점
			if (i > 5 && i < 13) {
				GoodStone_2022182030[i][j] += 3;
			}
			if (j > 5 && j < 13) {
				GoodStone_2022182030[i][j] += 3;
			}

		}

	}
	return;
}

void WhiteAttack_2022182030(int* x, int* y)
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요

	// 보드 스캔
	ScanBoard_W_2022182030();

	stoneXY_2022182030 verygoodstone;

	verygoodstone.x = -1, verygoodstone.y = -1, verygoodstone.num = -20000;

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (GoodStone_2022182030[i][j] > verygoodstone.num) {	// 더 큰거 위치 저장
				verygoodstone.x = j;
				verygoodstone.y = i;
				verygoodstone.num = GoodStone_2022182030[i][j];
			}
			else if (GoodStone_2022182030[i][j] == verygoodstone.num) {		// 같으면 랜덤으로

				srand((unsigned int)time(NULL));

				int n = rand() % 2;
				if (n) {
					verygoodstone.x = j;
					verygoodstone.y = i;
					verygoodstone.num = GoodStone_2022182030[i][j];
				}
			}

		}
	}


	// 예시로 항상 [5,5]에만 돌을 두게함
	*x = verygoodstone.x;
	*y = verygoodstone.y;

	board_2022182030[*y][*x] = WHITE;
}
void WhiteDefence_2022182030(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2022182030[y][x] = BLACK;
}
void BlackAttack_2022182030(int* x, int* y)
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요

	ScanBoard_B_2022182030();

	stoneXY_2022182030 verygoodstone;

	verygoodstone.x = -1, verygoodstone.y = -1, verygoodstone.num = -20000;

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (GoodStone_2022182030[i][j] > verygoodstone.num) {	// 더 큰거 위치 저장
				verygoodstone.x = j;
				verygoodstone.y = i;
				verygoodstone.num = GoodStone_2022182030[i][j];
			}
			else if (GoodStone_2022182030[i][j] == verygoodstone.num) {		// 같으면 랜덤으로

				srand((unsigned int)time(NULL));

				int n = rand() % 2;
				if (n) {
					verygoodstone.x = j;
					verygoodstone.y = i;
					verygoodstone.num = GoodStone_2022182030[i][j];
				}
			}

		}
	}


	// 예시로 항상 [5,5]에만 돌을 두게함
	*x = verygoodstone.x;
	*y = verygoodstone.y;

	board_2022182030[*y][*x] = BLACK;
}
void BlackDefence_2022182030(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2022182030[y][x] = WHITE;
}