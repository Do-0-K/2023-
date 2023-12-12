#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNING_
int i = 0;
int z = 0;
int k = 0;
int b = 1;
int t;
char a[22][42];
struct unit {
	char name;
	int x;
	int y;
	int hp;
	int mp;
	char ID[5] = "   ";
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
int minHP = 200;
void MakeUL() {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (a[i][j] == 'M') {
				sprintf(UNIT[p].ID, "M%04d", m_num);
				UNIT[p].name = 'M';
				UNIT[p].mp = 0;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				m_num++;
			}
			if (a[i][j] == 'D') {
				sprintf(UNIT[p].ID, "D%04d", d_num);
				UNIT[p].name = 'D';
				UNIT[p].mp = 200;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				d_num++;
			}
			if (a[i][j] == 'T') {
				sprintf(UNIT[p].ID, "T%04d", t_num);
				UNIT[p].name = 'T';
				UNIT[p].mp = 0;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				t_num++;
			}
			if (a[i][j] == 'Q') {
				sprintf(UNIT[p].ID, "Q%04d", q_num);
				UNIT[p].name = 'Q';
				UNIT[p].mp = 150;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				q_num++;
			}
			if (a[i][j] == 'V') {
				sprintf(UNIT[p].ID, "V%04d", v_num);
				UNIT[p].name = 'V';
				UNIT[p].mp = 140;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				v_num++;
			}
			if (a[i][j] == 'H') {
				sprintf(UNIT[p].ID, "H%04d", h_num);
				UNIT[p].name = 'H';
				UNIT[p].mp = 0;
				UNIT[p].x = j;
				UNIT[p].y = i;
				p++;
				h_num++;
			}
		}
	}
	UNIT[0].hp = 25;
	UNIT[1].hp = 20;
	UNIT[2].hp = 30;
	UNIT[3].hp = 80;
	UNIT[4].hp = 75;
	UNIT[5].hp = 120;
	UNIT[6].hp = 15;
	UNIT[7].hp = 50;
	UNIT[8].hp = 30;
	UNIT[9].hp = 27;
	UNIT[10].hp = 50;
	UNIT[11].hp = 45;
	UNIT[12].hp = 40;
	UNIT[13].hp = 20;
	UNIT[14].hp = 15;
	UNIT[15].hp = 30;
	UNIT[16].hp = 70;
	UNIT[17].hp = 35;
	UNIT[18].hp = 47;
	UNIT[19].hp = 37;
}
void ShowUL_R() {
	if (h > p - 1) {
		h = 0;
		return;
	}
	else {
		printf("%d - 유닛 = %c, ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", b + 1, UNIT[h].name, UNIT[h].ID, UNIT[h].hp, UNIT[h].mp, UNIT[h].x, UNIT[h].y);
		b++;
		h++;
		ShowUL_R();
	}
}
void Produce_UL_R(int s, int f, int w) {
	if (h > p - 1) {
		h = 0;
		return;
	}
	else {
		if (strcmp(UNIT[h].ID, "   ") == 0) {
			switch (w) {
			case 1: UNIT[h].name = 'M'; sprintf(UNIT[h].ID, "M%04d", m_num);m_num++; break;
			case 2: UNIT[h].name = 'D'; sprintf(UNIT[h].ID, "D%04d", d_num);d_num++; break;
			case 3: UNIT[h].name = 'T'; sprintf(UNIT[h].ID, "T%04d", t_num);t_num++; break;
			case 4: UNIT[h].name = 'Q'; sprintf(UNIT[h].ID, "Q%04d", q_num);q_num++; break;
			case 5: UNIT[h].name = 'V'; sprintf(UNIT[h].ID, "V%04d", v_num);v_num++; break;
			case 6: UNIT[h].name = 'H'; sprintf(UNIT[h].ID, "H%04d", h_num);h_num++; break;
			}
			printf("HP, MP를 입력하세요 : ");
			scanf_s("%d %d", &UNIT[h].hp, &UNIT[h].mp);
			UNIT[h].x = s;
			UNIT[h].y = f;
			UNIT[h].dist = 0;
			a[f][s] = UNIT[h].name;
		}
		h++;
		Produce_UL_R(s, f, w);
	}
}
void SelectALL_UL_R(int s, int f, int s1, int f1) {
	if (h > p - 1) {
		h = 0;
		if (k == 0) {
			printf("해당 좌표에 유닛이 없습니다.\n");
		}
		return;
	}
	else {
		if (s <= UNIT[h].x && UNIT[h].x <= s1) {
			if (f <= UNIT[h].y && UNIT[h].y <= f1) {
				printf("NAME = %c, ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[h].name, UNIT[h].ID, UNIT[h].hp, UNIT[h].mp, UNIT[h].x, UNIT[h].y);
				k++;
			}
		}
		h++;
		SelectALL_UL_R(s, f, s1, f1);
	}
}
void Destroy_UL_R(int s, int f) {
	if (h > p - 1) {
		h = 0;
		if (k == 0) {
			printf("해당 좌표에 유닛이 없습니다.\n");
		}
		return;
	}
	else {
		if (UNIT[h].x == s && UNIT[h].y == f) {
			UNIT[h].hp = 0;
			UNIT[h].dist = 0;
			UNIT[h].mp = 0;
			UNIT[h].x = 0;
			UNIT[h].y = 0;
			UNIT[h].name = NULL;
			sprintf(UNIT[h].ID, "   ");
			k++;
			a[f][s] = ' ';
		}
		h++;
		Destroy_UL_R(s, f);
	}
}
void FindWeakEnemy_R(int s, int f, int w) {
	if (h > p-1) {
		t = 0;
		h = 0;
		return;
	}
	else {
		if (t == 1) {
			if (s - w <= UNIT[h].x && UNIT[h].x < s + w + 1) {
				if (f - w <= UNIT[h].y && UNIT[h].y < f + w + 1) {
					if (UNIT[h].hp == minHP) {
						if (UNIT[h].name == 'H' || UNIT[h].name == 'Q' || UNIT[h].name == 'D') {
							printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[h].ID, UNIT[h].hp, UNIT[h].mp, UNIT[h].x, UNIT[h].y);
						}
					}
				}
			}
		}
		if (t == 2) {
			if (s - w <= UNIT[h].x && UNIT[h].x < s + w + 1) {
				if (f - w <= UNIT[h].y && UNIT[h].y < f + w + 1) {
					if (UNIT[h].hp == minHP) {
						if (UNIT[h].name == 'M' || UNIT[h].name == 'T' || UNIT[h].name == 'V') {
							printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", UNIT[h].ID, UNIT[h].hp, UNIT[h].mp, UNIT[h].x, UNIT[h].y);
						}
					}
				}
			}
		}
		h++;
		FindWeakEnemy_R(s, f, w);
	}
}
void DisplayMap_UL() {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			for (int k = 0; k < p; k++) {
				if (UNIT[k].x == j && UNIT[k].y == i) {
					a[i][j] = UNIT[k].name;
				}
			}
			printf("%2c", a[i][j]);
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
		int d = 0;
		int s = 0, f = 0, s1 = 0, f1 = 0, z = 0;
		int w = 0;
		b = 0;
		int count = 0;
		printf("1.ShowUL_R 2.Produce_UL_R 3.SelectALL_UL_R 4.Destroy_UL_R 5.FindWeakEnemy 6.DisplayMap_UL 7.Exit\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			ShowUL_R();
			break;
		case 2:
			for (int i = 0; i < p; i++) {
				if (strcmp(UNIT[i].ID, "   ") == 0) {
					count++;
				}
			}
			if (count == 0) {
				p++;
			}
			while (1) {
				printf("생성할 유닛의 좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s, &f);
				if (s > 40 || s < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (f > 20 || f < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				for (int i = 0;i < p;i++) {
					if (UNIT[i].x == s && UNIT[i].y == f) {
						d++;
					}
				}
				if (d != 0) {
					printf("이미 유닛이 있습니다.\n");
					continue;
				}
				printf("1. M, 2. D, 3. T, 4. Q, 5. V, 6. H\n");
				printf("생성할 유닛을 골라주세요 - ");
				scanf_s("%d", &w);
				break;
			}
			Produce_UL_R(s, f, w);
			break;
		case 3:
			while (1) {
				printf("첫번째 좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s, &f);
				printf("두번째 좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s1, &f1);
				if (s > 40 || s < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (f > 20 || f < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (s1 > 40 || s1 < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (f1 > 20 || f1 < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (s > s1) {
					z = s; s = s1; s1 = z;
				}
				if (f > f1) {
					z = f; f = f1; f1 = z;
				}
				break;
			}
			SelectALL_UL_R(s, f, s1, f1);
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
			Destroy_UL_R(s, f);
			break;
		case 5:
			while (1) {
				printf("좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s, &f);
				if (s > 40 || s < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				if (f > 20 || f < 1) {
					printf("잘못된 위치입니다.\n");
					continue;
				}
				for (int i = 0;i < p ;i++) {
					if (UNIT[i].x == s && UNIT[i].y == f) {
						d++;
					}
				}
				if (d == 0) {
					printf("좌표에 유닛이 없습니다.\n");
					continue;
				}
				printf("거리를 입력해주세요 - ");
				scanf_s("%d", &w);
				for (int i = 0; i < p; i++) {
					if (UNIT[i].x == s && UNIT[i].y == f) {
						if (UNIT[i].name == 'M'|| UNIT[i].name == 'V' || UNIT[i].name == 'T') {
							t = 1;
						}
						else {
							t = 2;
						}
					}
				}
				for (int f1 = f - w; f1 < f + w + 1; f1++) {
					for (int s1 = s - w; s1 < s + w + 1; s1++) {
						for (int i = 0; i < p; i++) {
							if (UNIT[i].x == s1 && UNIT[i].y == f1) {
								if (t == 1) {
									if (UNIT[i].name == 'H' || UNIT[i].name == 'Q' || UNIT[i].name == 'D') {
										if (UNIT[i].hp < minHP) {
											minHP = UNIT[i].hp;
										}
									}
								}
								else if (t == 2) {
									if (UNIT[i].name == 'M' || UNIT[i].name == 'V' || UNIT[i].name == 'T') {
										if (UNIT[i].hp < minHP) {
											minHP = UNIT[i].hp;
										}
									}
								}
							}
						}
					}
				}
				break;
			}
			FindWeakEnemy_R(s, f, w);
			break;
		case 6:
			DisplayMap_UL();
			break;
		case 7:
			printf("프로그램을 종료합니다.\n");
			exit(1);
		}
	}
}