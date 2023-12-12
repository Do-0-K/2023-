#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING_
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
void Destroy() {
	int s = 0, f = 0;
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
		if (a[f][s] == ' ') {
			printf("유닛이 없습니다.\n");
			continue;
		}
		for (int m = 0; m < 50; m++) {
			if (M[m].x == s && M[m].y == f) {
				M[m].x = 0;
				M[m].y = 0;
				sprintf(M[m].ID, "   ");
				M[m].hp = 0;
				M[m].mp = 0;
			}
			if (T[m].x == s && T[m].y == f) {
				T[m].x = 0;
				T[m].y = 0;
				sprintf(T[m].ID, "   ");
				T[m].hp = 0;
				T[m].mp = 0;
			}
			if (D[m].x == s && D[m].y == f) {
				D[m].x = 0;
				D[m].y = 0;
				sprintf(D[m].ID, "   ");
				D[m].hp = 0;
				D[m].mp = 0;
			}
			if (V[m].x == s && V[m].y == f) {
				V[m].x = 0;
				V[m].y = 0;
				sprintf(V[m].ID, "   ");
				V[m].hp = 0;
				V[m].mp = 0;
			}
			if (Q[m].x == s && Q[m].y == f) {
				Q[m].x = 0;
				Q[m].y = 0;
				sprintf(Q[m].ID, "   ");
				Q[m].hp = 0;
				Q[m].mp = 0;
			}
			if (H[m].x == s && H[m].y == f) {
				H[m].x = 0;
				H[m].y = 0;
				sprintf(H[m].ID, "   ");
				H[m].hp = 0;
				H[m].mp = 0;
			}
		}
		a[f][s] = ' ';
		break;
	}
}
void FindTarget() {
	int s = 0, f = 0;
	int distance;
	int distance2 = 40;
	if (z == 0) {
		printf("==================\n");
		printf("아군은 저그입니다.\n");
		printf("==================\n");
	}
	else {
		printf("==================\n");
		printf("아군은 테란입니다.\n");
		printf("==================\n");
	}
	for (int i = 0; i < 50; i++) {
		M[i].dist = 0;
		T[i].dist = 0;
		D[i].dist = 0;
		V[i].dist = 0;
		H[i].dist = 0;
		Q[i].dist = 0;
	}
	while (1) {
		printf("좌표를 입력하세요 - ");
		scanf_s(" %d %d", &s, &f);
		if (s > 40 || s < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (f > 20 || f < 1) {
			printf("잘못된 위치입니다.\n");
			continue;
		}
		if (z == 0) {
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
			for (int i = 0; i < m_num; i++) {
				if (M[i].dist == distance2) {
					printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d, 유닛과의 거리 = %d\n", M[i].ID, M[i].hp, M[i].mp, M[i].x, M[i].y, distance2);
				}
			}
			for (int i = 0; i < t_num; i++) {
				if (T[i].dist == distance2) {
					printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d, 유닛과의 거리 = %d\n", T[i].ID, T[i].hp, T[i].mp, T[i].x, T[i].y, distance2);
				}
			}
			for (int i = 0; i < v_num; i++) {
				if (V[i].dist == distance2) {
					printf("ID = %s, HP = %d, MP = %d, X = %d, Y = %d, 유닛과의 거리 = %d\n", V[i].ID, V[i].hp, V[i].mp, V[i].x, V[i].y, distance2);
				}
			}
		}
		else {
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
			for (int h = 0; h < h_num; h++) {
				if (H[h].dist == distance2) {
					printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d,선택 유닛과의 거리 : %d\n", H[h].ID, H[h].hp, H[h].mp, H[h].x, H[h].y, distance2);
				}
			}
			for (int d = 0; d < d_num; d++) {
				if (D[d].dist == distance2) {
					printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d,선택 유닛과의 거리 : %d\n", D[d].ID, D[d].hp, D[d].mp, D[d].x, D[d].y, distance2);
				}
			}
			for (int q = 0; q < q_num; q++) {
				if (Q[q].dist == distance2) {
					printf(" ID : %s, HP : %d, MP : %d, X : %d Y : %d,선택 유닛과의 거리 : %d\n", Q[q].ID, Q[q].hp, Q[q].mp, Q[q].x, Q[q].y, distance2);
				}
			}
		}
		break;
	}
}
void SortByID() {
	printf("==================\n");
	for (int m = m_num - 1; m > -1; m--) {
		if (strcmp(M[m].ID, "   ") == 0) {
			continue;
		}
		printf("ID = %s\n", M[m].ID);
	}
	printf("==================\n");
	for (int m = d_num - 1; m > -1; m--) {
		if (strcmp(D[m].ID, "   ") == 0) {
			continue;
		}
		printf("ID = %s\n", D[m].ID);
	}
	printf("==================\n");
	for (int m = t_num - 1; m > -1; m--) {
		if (strcmp(T[m].ID, "   ") == 0) {
			continue;
		}
		printf("ID = %s\n", T[m].ID);
	}
	printf("==================\n");
	for (int m = q_num - 1; m > -1; m--) {
		if (strcmp(Q[m].ID, "   ") == 0) {
			continue;
		}
		printf("ID = %s\n", Q[m].ID);
	}
	printf("==================\n");
	for (int m = h_num - 1; m > -1; m--) {
		if (strcmp(H[m].ID, "   ") == 0) {
			continue;
		}
		printf("ID = %s\n", H[m].ID);
	}
	printf("==================\n");
	for (int m = v_num - 1; m > -1; m--) {
		if (strcmp(V[m].ID, "   ") == 0) {
			continue;
		}
		printf("ID = %s\n", V[m].ID);
	}
	printf("==================\n");
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
		printf("1.Display 2.Produce 3.Select 4.SelectAll 5.Destroy 6.FindTarget 7.SortByID 8.Exit\n");
		printf("명령어를 입력해주세요 - ");
		scanf("%d", &ment);
		switch (ment) {
		case 1:
			Display();
			break;
		case 2:
			Produce();
			break;
		case 3:
			Select();
			break;
		case 4:
			SelectAll();
			break;
		case 5:
			Destroy();
			break;
		case 6:
			FindTarget();
			break;
		case 7:
			SortByID();
			break;
		case 8:
			printf("프로그램을 종료합니다.\n");
			exit(1);
		}
	}
}