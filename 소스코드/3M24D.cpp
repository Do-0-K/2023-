#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNING_
struct order {
	int x;
	int y;
	int x1;
	int y1;
	char ment = NULL;
	char unit = NULL;
};
struct order order[30];
int i = 0;
int z = 0;
char a[22][42];
int m_num = 0;
int q_num = 0;
int d_num = 0;
int v_num = 0;
int h_num = 0;
int t_num = 0;
struct unit {
	int x;
	int y;
	int hp;
	int mp;
	char ID[5];
	int dist;
};
struct unit M[50];
struct unit Q[50];
struct unit D[50];
struct unit V[50];
struct unit T[50];
struct unit H[50];
void Display() {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			printf("%2c", a[i][j]);
		}
		printf("\n");
	}
}
void Produce() {
	char c;
	int s = 0, f = 0;
	while (1) {
		printf("M-마린, H-히드라, T-탱크, Q-퀸, V-베슬, D-디파일러\n");
		printf("생성할 유닛을 선택해주세요 - ");
		scanf(" %c", &c);
		printf("새로운 유닛의 좌표를 입력해주세요 - ");
		scanf_s(" %d %d", &s, &f);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (a[f][s] != ' ') {
			printf("이미 유닛이 있습니다.\n");
			continue;
		}
		a[f][s] = c;
		switch (c) {
		case 'M':
			M[m_num].x = s;
			M[m_num].y = f;
			m_num++;
			break;
		case 'T':
			T[t_num].x = s;
			T[t_num].y = f;
			t_num++;
			break;
		case 'Q':
			Q[q_num].x = s;
			Q[q_num].y = f;
			q_num++;
			break;
		case 'D':
			D[d_num].x = s;
			D[d_num].y = f;
			d_num++;
			break;
		case 'V':
			V[v_num].x = s;
			V[v_num].y = f;
			v_num++;
			break;
		case 'H':
			H[h_num].x = s;
			H[h_num].y = f;
			h_num++;
			break;
		}
		break;
	}
}
void Select() {
	int s = 0, f = 0;
	while (1) {
		printf("유닛의 좌표를 입력해주세요 - ");
		scanf_s(" %d %d", &s, &f);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (a[f][s] == ' ') {
			printf("유닛이 없습니다.\n");
			continue;
		}
		for (int m = 0; m < 50; m++) {
			if (M[m].x == s && M[m].y == f) {
				printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", M[m].ID, M[m].hp, M[m].mp, M[m].x, M[m].y);
			}
			if (T[m].x == s && T[m].y == f) {
				printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", T[m].ID, T[m].hp, T[m].mp, T[m].x, T[m].y);
			}
			if (D[m].x == s && D[m].y == f) {
				printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", D[m].ID, D[m].hp, D[m].mp, D[m].x, D[m].y);
			}
			if (V[m].x == s && V[m].y == f) {
				printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", V[m].ID, V[m].hp, V[m].mp, V[m].x, V[m].y);
			}
			if (Q[m].x == s && Q[m].y == f) {
				printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", Q[m].ID, Q[m].hp, Q[m].mp, Q[m].x, Q[m].y);
			}
			if (H[m].x == s && H[m].y == f) {
				printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", H[m].ID, H[m].hp, H[m].mp, H[m].x, H[m].y);
			}
		}
		break;
	}
}
void SelectAll() {
	int s = 0, f = 0, s1 = 0, f1 = 0;
	int d = 0;
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
			d = s;
			s = s1;
			s1 = d;
		}
		if (f > f1) {
			d = f;
			f = f1;
			f1 = d;
		}
		for (int i = f; i < f1 + 1; i++) {
			for (int j = s; j < s1 + 1; j++) {
				for (int m = 0; m < 50; m++) {
					if (M[m].x == j && M[m].y == i) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", M[m].ID, M[m].hp, M[m].mp, M[m].x, M[m].y);
					}
					if (T[m].x == j && T[m].y == i) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", T[m].ID, T[m].hp, T[m].mp, T[m].x, T[m].y);
					}
					if (D[m].x == j && D[m].y == i) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", D[m].ID, D[m].hp, D[m].mp, D[m].x, D[m].y);
					}
					if (V[m].x == j && V[m].y == i) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", V[m].ID, V[m].hp, V[m].mp, V[m].x, V[m].y);
					}
					if (Q[m].x == j && Q[m].y == i) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", Q[m].ID, Q[m].hp, Q[m].mp, Q[m].x, Q[m].y);
					}
					if (H[m].x == j && H[m].y == i) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", H[m].ID, H[m].hp, H[m].mp, H[m].x, H[m].y);
					}
				}
			}
		}
		break;
	}
}
void Order() {
	printf("p - 생성(행동력 1), m - 이동(행동력 1), s or S - 선택(행동력 0), a - 공격(행동력 1)\n");
	printf("명령을 입력하세요 - ");
	scanf(" %c", &order[i].ment);
	switch (order[i].ment) {
	case 'p':
		printf("생성할 유닛을 선택하세요 : ");
		scanf(" %c", &order[i].unit);
		printf("새로운 유닛의 좌표를 입력하세요 : ");
		scanf_s("%d %d", &order[i].x, &order[i].y);
		break;
	case 'm':
		printf("이동할 유닛의 좌표를 입력하세요 : ");
		scanf_s(" %d %d", &order[i].x, &order[i].y);
		printf("이동할 좌표를 입력하세요 : ");
		scanf_s(" %d %d", &order[i].x1, &order[i].y1);
		break;
	case 's':
		printf("선택할 유닛의 좌표를 입력하세요 : ");
		scanf_s("%d %d", &order[i].x, &order[i].y);
		break;
	case 'S':
		printf("첫번째 좌표를 입력하세요 : ");
		scanf_s("%d %d", &order[i].x, &order[i].y);
		printf("두번째 좌표를 입력하세요 : ");
		scanf_s("%d %d", &order[i].x1, &order[i].y1);
		break;
	case 'a':
		printf("좌표를 입력하세요 : ");
		scanf_s("%d %d", &order[i].x, &order[i].y);
		break;
	}
	i++;
	printf("\n");
}
void ShowOrderList() {
	for (int i = 0; i < sizeof(order); i++) {
		if (order[i].ment == 'p') {
			printf("%d - ", i + 1);
			printf("%c %c %d %d", order[i].ment, order[i].unit, order[i].x, order[i].y);
			printf("\n");
			continue;
		}
		if (order[i].ment == 's') {
			printf("%d - ", i + 1);
			printf("%c %d %d", order[i].ment, order[i].x, order[i].y); printf("\n");
			continue;
		}
		if (order[i].ment == 'S') {
			printf("%d - ", i + 1);
			printf("%c %d %d %d %d", order[i].ment, order[i].x, order[i].y, order[i].x1, order[i].y1); printf("\n");
			continue;
		}
		if (order[i].ment == 'm') {
			printf("%d - ", i + 1);
			printf("%c %d %d", order[i].ment, order[i].x, order[i].y); printf("\n");
			continue;
		}
		if (order[i].ment == 'a') {
			printf("%d - ", i + 1);
			printf("%c %d %d", order[i].ment, order[i].x, order[i].y); printf("\n");
			continue;
		}
	}
	printf("\n");
}
void DestroyAll() {
	int s = 0, f = 0, s1 = 0, f1 = 0;
	int d = 0;
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
			d = s;
			s = s1;
			s1 = d;
		}
		if (f > f1) {
			d = f;
			f = f1;
			f1 = d;
		}
		for (int i = f; i < f1 + 1; i++) {
			for (int j = s; j < s1 + 1; j++) {
				for (int m = 0; m < 50; m++) {
					if (M[m].x == j && M[m].y == i) {
						M[m].x = 0;
						M[m].y = 0;
						sprintf(M[m].ID, "   ");
						M[m].hp = 0;
						M[m].mp = 0;
						M[m].dist = 0;
					}
					if (T[m].x == j && T[m].y == i) {
						T[m].x = 0;
						T[m].y = 0;
						sprintf(T[m].ID, "   ");
						T[m].hp = 0;
						T[m].mp = 0;
						T[m].dist = 0;
					}
					if (D[m].x == j && D[m].y == i) {
						D[m].x = 0;
						D[m].y = 0;
						sprintf(D[m].ID, "   ");
						D[m].hp = 0;
						D[m].mp = 0;
						D[m].dist = 0;
					}
					if (V[m].x == j && V[m].y == i) {
						V[m].x = 0;
						V[m].y = 0;
						sprintf(V[m].ID, "   ");
						V[m].hp = 0;
						V[m].mp = 0;
						V[m].dist = 0;
					}
					if (Q[m].x == j && Q[m].y == i) {
						Q[m].x = 0;
						Q[m].y = 0;
						sprintf(Q[m].ID, "   ");
						Q[m].hp = 0;
						Q[m].mp = 0;
						Q[m].dist = 0;
					}
					if (H[m].x == j && H[m].y == i) {
						H[m].x = 0;
						H[m].y = 0;
						sprintf(H[m].ID, "   ");
						H[m].hp = 0;
						H[m].mp = 0;
						H[m].dist = 0;
					}
					a[i][j] = ' ';
				}
			}
		}
		break;
	}
}
void GetDistance() {
	int s = 0, f = 0;
	int s1 = 0, f1 = 0;
	double distance = 0;
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
		distance = (abs(s - s1)) > (abs(f - f1)) ? (abs(s - s1)) : (abs(f - f1));
		printf("(%d , %d)에서 (%d , %d)까지 거리 = %.1f\n", s, f, s1, f1, distance);
		break;
	}
}
void FindWeakEnemy() {
	int s = 0, f = 0;
	int d = 0, g = 0;
	int minHP = 200;
	int distance;
	int dist;
	if (z == 0) {
		printf("==================\n");
		printf("아군은 저그(H,Q,D)입니다.\n");
		printf("==================\n");
	}
	else {
		printf("==================\n");
		printf("아군은 테란(M,T,V)입니다.\n");
		printf("==================\n");
	}
	while (1) {
		printf("좌표를 입력하세요 - ");
		scanf_s("%d %d", &s, &f);
		printf("거리를 입력하세요 - ");
		scanf_s("%d", &d);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		for (int i = f - d; i < f + d + 1; i++) {
			for (int j = s - d; j < s + d + 1; j++) {
				if (a[i][j] != ' ' && a[i][j] != '*') {
					g++;
				}
			}
		}
		if (g == 0) {
			printf("범위안에 유닛이 없습니다.\n");
			return;
		}
		if (z == 0) {
			for (int f1 = f - d; f1 < f + d + 1; f1++) {
				for (int s1 = s - d; s1 < s + d + 1; s1++) {
					for (int m = 0; m < m_num; m++) {
						if (M[m].x == s1 && M[m].y == f1) {
							minHP = M[m].hp;
						}
					}
					for (int t = 0; t < t_num; t++) {
						if (T[t].x == s1 && T[t].y == f1) {
							minHP = T[t].hp;
						}
					}
					for (int v = 0; v < v_num; v++) {
						if (V[v].x == s1 && V[v].y == f1) {
							minHP = V[v].hp;
						}
					}
				}
			}
			for (int f1 = f - d; f1 < f + d + 1; f1++) {
				for (int s1 = s - d; s1 < s + d + 1; s1++) {
					for (int i = 0; i < m_num; i++) {
						if (M[i].x == s1 && M[i].y == f1) {
							if (M[i].hp == minHP) {
								printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", M[i].ID, M[i].hp, M[i].mp, M[i].x, M[i].y);
							}
						}
					}
					for (int i = 0; i < t_num; i++) {
						if (T[i].x == s1 && T[i].y == f1) {
							if (T[i].hp == minHP) {
								printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", T[i].ID, T[i].hp, T[i].mp, T[i].x, T[i].y);
							}
						}
					}
					for (int i = 0; i < v_num; i++) {
						if (V[i].x == s1 && V[i].y == f1) {
							if (V[i].hp == minHP) {
								printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d\n", V[i].ID, V[i].hp, V[i].mp, V[i].x, V[i].y);
							}
						}
					}
				}
			}
		}
		else {
			for (int f1 = f - d; f1 < f + d + 1; f1++) {
				for (int s1 = s - d; s1 < s + d + 1; s1++) {
					for (int h = 0; h < h_num; h++) {
						if (H[h].x == s1 && H[h].y == f1) {
							minHP = H[h].hp;
						}
					}
					for (int d = 0; d < d_num; d++) {
						if (D[d].x == s1 && D[d].y == f1) {
							minHP = D[d].hp;
						}
					}
					for (int q = 0; q < q_num; q++) {
						if (Q[q].x == s1 && Q[q].y == f1) {
							minHP = Q[q].hp;
						}
					}
				}
			}
			for (int f1 = f - d; f1 < f + d + 1; f1++) {
				for (int s1 = s - d; s1 < s + d + 1; s1++) {
					for (int h = 0; h < h_num; h++) {
						if (H[h].x == s1 && H[h].y == f1) {
							if (H[h].hp == minHP) {
								printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d\n", H[h].ID, H[h].hp, H[h].mp, H[h].x, H[h].y);
							}
						}
					}
					for (int d = 0; d < d_num; d++) {
						if (D[d].x == s1 && D[d].y == f1) {
							if (D[d].hp == minHP) {
								printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d\n", D[d].ID, D[d].hp, D[d].mp, D[d].x, D[d].y);
							}
						}
					}
					for (int q = 0; q < q_num; q++) {
						if (Q[q].x == s1 && Q[q].y == f1) {
							if (Q[q].hp == minHP) {
								printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d\n", Q[q].ID, Q[q].hp, Q[q].mp, Q[q].x, Q[q].y);
							}
						}
					}
				}
			}
		}
		z++;
		if (z > 1) {
			z = 0;
		}
		break;
	}
}
void SortByDistance() {
	int s = 0, f = 0;
	int distance;
	int distance2 = 40;
	for (int i = 0; i < 50; i++) {
		M[i].dist = -1;
		T[i].dist = -1;
		D[i].dist = -1;
		V[i].dist = -1;
		H[i].dist = -1;
		Q[i].dist = -1;
	}
	while (1) {
		int g = 0;
		printf("좌표를 입력하세요 - ");
		scanf_s("%d %d", &s, &f);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		for (int i = 0; i < m_num; i++) {
			distance = (abs(s - M[i].x)) > (abs(f - M[i].y)) ? (abs(s - M[i].x)) : (abs(f - M[i].y));
			M[i].dist = distance;
			if (distance2 >= distance) {
				distance2 = distance;
				M[i].dist = distance2;
			}
		}
		for (int i = 0; i < t_num; i++) {
			distance = (abs(s - T[i].x)) > (abs(f - T[i].y)) ? (abs(s - T[i].x)) : (abs(f - T[i].y));
			T[i].dist = distance;
			if (distance2 >= distance) {
				distance2 = distance;
				T[i].dist = distance2;
			}
		}
		for (int i = 0; i < v_num; i++) {
			distance = (abs(s - V[i].x)) > (abs(f - V[i].y)) ? (abs(s - V[i].x)) : (abs(f - V[i].y));
			V[i].dist = distance;
			if (distance2 >= distance) {
				distance2 = distance;
				V[i].dist = distance2;
			}
		}
		for (int h = 0; h < h_num; h++) {
			distance = (abs(s - H[h].x)) > (abs(f - H[h].y)) ? (abs(s - H[h].x)) : (abs(f - H[h].y));
			H[h].dist = distance;
			if (distance2 >= distance) {
				distance2 = distance;
				H[h].dist = distance2;
			}
		}
		for (int d = 0; d < d_num; d++) {
			distance = (abs(s - D[d].x)) > (abs(f - D[d].y)) ? (abs(s - D[d].x)) : (abs(f - D[d].y));
			D[d].dist = distance;
			if (distance2 >= distance) {
				distance2 = distance;
				D[d].dist = distance2;
			}
		}
		for (int q = 0; q < q_num; q++) {
			distance = (abs(s - Q[q].x)) > (abs(f - Q[q].y)) ? (abs(s - Q[q].x)) : (abs(f - Q[q].y));
			Q[q].dist = distance;
			if (distance2 >= distance) {
				distance2 = distance;
				Q[q].dist = distance2;
			}
		}
		while (g != 40) {
			for (int i = 0; i < m_num; i++) {
				if (strcmp(M[i].ID, "   ") == 0) {
					continue;
				}
				else {
					if (M[i].dist == distance2 + g) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d, 선택 좌표와 유닛과의 거리 = %d\n", M[i].ID, M[i].hp, M[i].mp, M[i].x, M[i].y, distance2 + g);
					}
				}
			}
			for (int i = 0; i < t_num; i++) {
				if (strcmp(T[i].ID, "   ") == 0) {
					continue;
				}
				else {
					if (T[i].dist == distance2 + g) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d, 선택 좌표와 유닛과의 거리 = %d\n", T[i].ID, T[i].hp, T[i].mp, T[i].x, T[i].y, distance2 + g);
					}
				}
			}
			for (int i = 0; i < v_num; i++) {
				if (strcmp(V[i].ID, "   ") == 0) {
					continue;
				}
				else {
					if (V[i].dist == distance2 + g) {
						printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d, 선택 좌표와 유닛과의 거리 = %d\n", V[i].ID, V[i].hp, V[i].mp, V[i].x, V[i].y, distance2 + g);
					}
				}
			}
			for (int i = 0; i < h_num; i++) {
				if (strcmp(H[i].ID, "   ") == 0) {
					continue;
				}
				else {
					if (H[i].dist == distance2 + g) {
						printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d, 선택 좌표와 유닛과의 거리 : %d\n", H[i].ID, H[i].hp, H[i].mp, H[i].x, H[i].y, distance2 + g);
					}
				}
			}
			for (int i = 0; i < d_num; i++) {
				if (strcmp(D[i].ID, "   ") == 0) {
					continue;
				}
				else {
					if (D[i].dist == distance2 + g) {
						printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d, 선택 좌표와 유닛과의 거리 : %d\n", D[i].ID, D[i].hp, D[i].mp, D[i].x, D[i].y, distance2 + g);
					}
				}
			}
			for (int i = 0; i < q_num; i++) {
				if (strcmp(Q[i].ID, "   ") == 0) {
					continue;
				}
				else {
					if (Q[i].dist == distance2 + g) {
						printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d, 선택 좌표와 유닛과의 거리 : %d\n", Q[i].ID, Q[i].hp, Q[i].mp, Q[i].x, Q[i].y, distance2 + g);
					}
				}
			}
			g++;
		}
		break;
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
	for (int g = 0; g < 50; g++) {
		sprintf(M[g].ID, "M%04d", g);
		M[g].hp = 30;
		M[g].mp = 0;
		M[g].x = 0;
		M[g].y = 0;
		M[g].dist = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(Q[g].ID, "Q%04d", g);
		Q[g].hp = 70;
		Q[g].mp = 150;
		Q[g].x = 0;
		Q[g].y = 0;
		Q[g].dist = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(V[g].ID, "V%04d", g);
		V[g].hp = 80;
		V[g].mp = 140;
		V[g].x = 0;
		V[g].y = 0;
		V[g].dist = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(D[g].ID, "D%04d", g);
		D[g].hp = 60;
		D[g].mp = 200;
		D[g].x = 0;
		D[g].y = 0;
		D[g].dist = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(T[g].ID, "T%04d", g);
		T[g].hp = 120;
		T[g].mp = 0;
		T[g].x = 0;
		T[g].y = 0;
		T[g].dist = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(H[g].ID, "H%04d", g);
		H[g].hp = 50;
		H[g].mp = 0;
		H[g].x = 0;
		H[g].y = 0;
		H[g].dist = 0;
	}
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (a[i][j] == 'M') {
				M[m_num].x = j;
				M[m_num].y = i;
				m_num++;
			}
			if (a[i][j] == 'D') {
				D[d_num].x = j;
				D[d_num].y = i;
				d_num++;
			}
			if (a[i][j] == 'T') {
				T[t_num].x = j;
				T[t_num].y = i;
				t_num++;
			}
			if (a[i][j] == 'Q') {
				Q[q_num].x = j;
				Q[q_num].y = i;
				q_num++;
			}
			if (a[i][j] == 'V') {
				V[v_num].x = j;
				V[v_num].y = i;
				v_num++;
			}
			if (a[i][j] == 'H') {
				H[h_num].x = j;
				H[h_num].y = i;
				h_num++;
			}
		}
	}
	while (1) {
		ment = 0;
		printf("1.Display 2.Order 3.ShowOrderList 4.DestroyAll 5.GetDistance 6.FindWeakEnemy 7.SortByDistance 8.Exit\n");
		printf("명령어를 입력해주세요 - ");
		scanf("%d", &ment);
		switch (ment) {
		case 1:
			Display();
			break;
		case 2:
			Order();
			break;
		case 3:
			ShowOrderList();
			break;
		case 4:
			DestroyAll();
			break;
		case 5:
			GetDistance();
			break;
		case 6:
			FindWeakEnemy();
			break;
		case 7:
			SortByDistance();
			break;
		case 8:
			printf("프로그램을 종료합니다.\n");
			exit(1);
		}
	}
}