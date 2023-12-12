#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNING_
int i = 0;
int z = 0;
char a[22][42];
struct unit {
	char name;
	int x;
	int y;
	int hp;
	int mp;
	char ID[5];
	int dist;
};
struct unit UNIT[1000];
int m_num = 1;
int h_num = 1;
int t_num = 1;
int v_num = 1;
int d_num = 1;
int q_num = 1;
int p = 0;
int h = 0;
void MakeUL() {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (a[i][j] == 'M') {
				sprintf(UNIT[p].ID, "M%04d", m_num);
				UNIT[p].name = 'M';
				UNIT[p].hp = 30;
				UNIT[p].mp = 0;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				m_num++;
			}
			if (a[i][j] == 'D') {
				sprintf(UNIT[p].ID, "D%04d", d_num);
				UNIT[p].name = 'D';
				UNIT[p].hp = 60;
				UNIT[p].mp = 200;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				d_num++;
			}
			if (a[i][j] == 'T') {
				sprintf(UNIT[p].ID, "T%04d", t_num);
				UNIT[p].name = 'T';
				UNIT[p].hp = 120;
				UNIT[p].mp = 0;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				t_num++;
			}
			if (a[i][j] == 'Q') {
				sprintf(UNIT[p].ID, "Q%04d", q_num);
				UNIT[p].name = 'Q';
				UNIT[p].hp = 70;
				UNIT[p].mp = 150;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				q_num++;
			}
			if (a[i][j] == 'V') {
				sprintf(UNIT[p].ID, "V%04d", v_num);
				UNIT[p].name = 'V';
				UNIT[p].hp = 80;
				UNIT[p].mp = 140;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				v_num++;
			}
			if (a[i][j] == 'H') {
				sprintf(UNIT[p].ID, "H%04d", h_num);
				UNIT[p].name = 'H';
				UNIT[p].hp = 50;
				UNIT[p].mp = 0;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				h_num++;
			}
		}
	}
}
void ShowUL() {
	for (int i = 0; i < p; i++) {
		printf("NAME = %c, ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[i].name, UNIT[i].ID, UNIT[i].hp, UNIT[i].mp, UNIT[i].x, UNIT[i].y);
	}
}
void ShowUL_R() {
	if (h > p - 1) {
		h = 0;
		return;
	}
	else {
		printf("NAME = %c, ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[h].name, UNIT[h].ID, UNIT[h].hp, UNIT[h].mp, UNIT[h].x, UNIT[h].y);
		h++;
		ShowUL_R();
	}
}
void Select_UL() {
	int s, f;
	while (1) {
		printf("유닛의 좌표를 입력해주세요 - ");
		scanf_s("%d %d", &s, &f);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		for (int i = 0; i < p; i++) {
			if (UNIT[i].x == s && UNIT[i].y == f) {
				printf("NAME = %c, ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[i].name, UNIT[i].ID, UNIT[i].hp, UNIT[i].mp, UNIT[i].x, UNIT[i].y);
			}
		}
		break;
	}
}
void Select_UL_R(int s, int f) {
	if (h > p - 1) {
		h = 0;
		return;
	}
	else {
		if (UNIT[h].x == s && UNIT[h].y == f) {
			printf("NAME = %c, ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[h].name, UNIT[h].ID, UNIT[h].hp, UNIT[h].mp, UNIT[h].x, UNIT[h].y);
		}
		h++;
		Select_UL_R(s, f);
	}
}
void Destroy_UL() {
	int s, f;
	int z = 0;
	int k = 0;
	while (1) {
		printf("유닛의 좌표를 입력해주세요 - ");
		scanf_s("%d %d", &s, &f);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		for (int i = 0; i < p; i++) {
			if (UNIT[i].x == s && UNIT[i].y == f) {
				k++;
			}
		}
		if (k == 0) {
			printf("좌표에 유닛이 없습니다.\n");
			return;
		}
		else {
			for (int i = 0; i < p; i++) {
				if (UNIT[i].x == s && UNIT[i].y == f) {
					z = i;
				}
			}
			for (int i = z; i < p - 1; i++) {
				UNIT[i] = UNIT[i + 1];
			}
			p--;
		}
		break;
	}
}
void Destroy_UL_R(int s, int f) {
	int k = 0;
	if (h > p - 1) {
		h = 0;
		return;
	}
	else {
		if (UNIT[h].x == s && UNIT[h].y == f) {
			for (int i = h; i < p; i++) {
				UNIT[i] = UNIT[i + 1];
			}
			p--;
		}
		h++;
		Destroy_UL_R(s, f);
	}
}
void DisplayMap_UL() {
	char map[22][42];
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			map[i][j] = '*';
		}
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 41; j++) {
			map[i][j] = ' ';
		}
	}
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			for (int k = 0; k < p; k++) {
				if (UNIT[k].x == j && UNIT[k].y == i) {
					map[i][j] = UNIT[k].name;
				}
			}
			printf("%2c", map[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int ment;
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			a[i][j] = '*';
		}
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 41; j++) {
			a[i][j] = ' ';
		}
	}
	a[1][1] = 'M'; a[2][1] = 'M'; a[3][1] = 'M'; a[3][2] = 'V'; a[3][3] = 'V'; a[4][1] = 'T'; a[4][2] = 'M';
	a[5][1] = 'T'; a[5][2] = 'M'; a[6][1] = 'M';
	a[20][40] = 'H'; a[19][40] = 'H'; a[18][40] = 'Q'; a[18][39] = 'Q'; a[18][38] = 'H'; a[17][40] = 'D'; a[17][39] = 'H'; a[16][40] = 'D';
	a[16][39] = 'H'; a[15][40] = 'H';
	MakeUL();
	while (1) {
		ment = 0;
		int s = 0, f = 0;
		printf("1.ShowUL 2.ShowUL_R 3.Select_UL 4.Select_UL_R 5.Destroy_UL 6.Destroy_UL_R 7.DisplayMap_UL 8.Exit\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			ShowUL();
			break;
		case 2:
			ShowUL_R();
			break;
		case 3:
			Select_UL();
			break;
		case 4:
			while (1) {
				printf("유닛의 좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s, &f);
				if (s > 40 || s < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (f > 20 || f < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				break;
			}
			Select_UL_R(s, f);
			break;
		case 5:
			Destroy_UL();
			break;
		case 6:
			while (1) {
				printf("유닛의 좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s, &f);
				if (s > 40 || s < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (f > 20 || f < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				break;
			}
			Destroy_UL_R(s, f);
			break;
		case 7:
			DisplayMap_UL();
			break;
		case 8:
			printf("프로그램을 종료합니다.\n");
			exit(1);
		}
	}
}