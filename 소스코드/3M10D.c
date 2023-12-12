#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[22][42];
int m_num = 0;
int v_num = 0;
int d_num = 0;
int q_num = 0;
int h_num = 0;
int t_num = 0;
struct unit {
	int hp;
	int mp;
	char ID[5];
	int x;
	int y;
};
struct unit M[50];
struct unit T[50];
struct unit Q[50];
struct unit D[50];
struct unit V[50];
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
		printf("=====================================\n");
		printf("M-¸¶¸°, V-º£½½, D-µðÆÄÀÏ·¯, Q-Äý, H-È÷µå¶ó, T-ÅÊÅ©\n");
		printf("»ý¼ºÇÒ À¯´ÖÀ» ¼±ÅÃÇØÁÖ¼¼¿ä : ");
		scanf(" %c", &c);
		printf("=====================================\n");
		printf("»ý¼ºÇÒ À¯´ÖÀÇ ÁÂÇ¥¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
		scanf_s(" %d %d", &s, &f);
		if (a[f][s] != ' ') {
			printf("ÀÌ¹Ì À¯´ÖÀÌ ÀÖ½À´Ï´Ù. \n");
			continue;
		}
		a[f][s] = c;
		if (a[f][s] == 'M') {
			M[m_num].x = f;
			M[m_num].y = s;
			m_num++;
		}
		else if (a[f][s] == 'V') {
			V[v_num].x = f;
			V[v_num].y = s;
			v_num++;
		}
		else if (a[f][s] == 'D') {
			D[d_num].x = f;
			D[d_num].y = s;
			d_num++;
		}
		else if (a[f][s] == 'Q') {
			Q[q_num].x = f;
			Q[q_num].y = s;
			q_num++;
		}
		else if (a[f][s] == 'H') {
			H[h_num].x = f;
			H[h_num].y = s;
			h_num++;
		}
		else if (a[f][s] == 'T') {
			T[t_num].x = f;
			T[t_num].y = s;
			t_num++;
		}
		printf("=====================================\n");
		break;
	}
}
void Select() {
	int s = 0, f = 0;
	while (1) {
		printf("ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");
		scanf_s("%d %d", &s, &f);
		if (a[f][s] == ' ') {
			printf("ÀÌºÁ ±è¾¾ °Å±â ¾Ï°Íµµ ¾÷´ç²²~\n");
			continue;
		}
		for (int m = 0; m < 50; m++) {
			if (s == M[m].x && f == M[m].y) {
				printf("=====================================\n");
				printf("HP = %d\n", M[m].hp);
				printf("MP = %d\n", M[m].mp);
				printf("XÁÂÇ¥ = %d\n", M[m].x);
				printf("YÁÂÇ¥ = %d\n", M[m].y);
				printf("ID = %s\n", M[m].ID);
				printf("=====================================\n");
			}
		}
		for (int v = 0; v < 50; v++) {
			if (V[v].x == s && V[v].y == f) {
				printf("=====================================\n");
				printf("HP = %d\n", V[v].hp);
				printf("MP = %d\n", V[v].mp);
				printf("XÁÂÇ¥ = %d\n", V[v].x);
				printf("YÁÂÇ¥ = %d\n", V[v].y);
				printf("ID = %s\n", V[v].ID);
				printf("=====================================\n");
			}
		}
		for (int q = 0; q < 50; q++) {
			if (Q[q].x == s && Q[q].y == f) {
				printf("=====================================\n");
				printf("HP = %d\n", Q[q].hp);
				printf("MP = %d\n", Q[q].mp);
				printf("XÁÂÇ¥ = %d\n", Q[q].x);
				printf("YÁÂÇ¥ = %d\n", Q[q].y);
				printf("ID = %s\n", Q[q].ID);
				printf("=====================================\n");
			}
		}
		for (int d = 0; d < 50; d++) {
			if (D[d].x == s && D[d].y == f) {
				printf("=====================================\n");
				printf("HP = %d\n", D[d].hp);
				printf("MP = %d\n", D[d].mp);
				printf("XÁÂÇ¥ = %d\n", D[d].x);
				printf("YÁÂÇ¥ = %d\n", D[d].y);
				printf("ID = %s\n", D[d].ID);
				printf("=====================================\n");
			}
		}
		for (int h = 0; h < 50; h++) {
			if (H[h].x == s && H[h].y == f) {
				printf("=====================================\n");
				printf("HP = %d\n", H[h].hp);
				printf("MP = %d\n", H[h].mp);
				printf("XÁÂÇ¥ = %d\n", H[h].x);
				printf("YÁÂÇ¥ = %d\n", H[h].y);
				printf("ID = %s\n", H[h].ID);
				printf("=====================================\n");
			}
		}
		for (int t = 0; t < 50; t++) {
			if (T[t].x == s && T[t].y == f) {
				printf("=====================================\n");
				printf("HP = %d\n", T[t].hp);
				printf("MP = %d\n", T[t].mp);
				printf("XÁÂÇ¥ = %d\n", T[t].x);
				printf("YÁÂÇ¥ = %d\n", T[t].y);
				printf("ID = %s\n", T[t].ID);
				printf("=====================================\n");
			}
		}
		break;
	}
}
void SelectAll() {
	int x = 0, y = 0, z = 0, c = 0;
	int t = 0, r = 0;;//¾²·¹±â °ª
	printf("=====================================\n");
	printf("Ã¹¹øÂ° ÁÂÇ¥¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
	scanf_s("%d %d", &x, &y);
	printf("µÎ¹øÂ° ÁÂÇ¥¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
	scanf_s("%d %d", &z, &c);
	if (x > z) {
		t = x;
		x = z;
		z = t;
	}
	if (y > c) {
		r = y;
		y = c;
		c = r;
	}
	while (1) {
		for (int i = x; i < z + 1; i++) {
			for (int j = y; j < c + 1; j++) {
				for (int m = 0; m < 50; m++) {
					if (i == M[m].x && j == M[m].y) {
						printf("=====================================\n");
						printf("HP = %d\n", M[m].hp);
						printf("MP = %d\n", M[m].mp);
						printf("XÁÂÇ¥ = %d\n", M[m].x);
						printf("YÁÂÇ¥ = %d\n", M[m].y);
						printf("ID = %s\n", M[m].ID);
						printf("=====================================\n");
					}
				}
				for (int v = 0; v < 50; v++) {
					if (V[v].x == i && V[v].y == j) {
						printf("=====================================\n");
						printf("HP = %d\n", V[v].hp);
						printf("MP = %d\n", V[v].mp);
						printf("XÁÂÇ¥ = %d\n", V[v].x);
						printf("YÁÂÇ¥ = %d\n", V[v].y);
						printf("ID = %s\n", V[v].ID);
						printf("=====================================\n");
					}
				}
				for (int q = 0; q < 50; q++) {
					if (Q[q].x == i && Q[q].y == j) {
						printf("=====================================\n");
						printf("HP = %d\n", Q[q].hp);
						printf("MP = %d\n", Q[q].mp);
						printf("XÁÂÇ¥ = %d\n", Q[q].x);
						printf("YÁÂÇ¥ = %d\n", Q[q].y);
						printf("ID = %s\n", Q[q].ID);
						printf("=====================================\n");
					}
				}
				for (int d = 0; d < 50; d++) {
					if (D[d].x == i && D[d].y == j) {
						printf("=====================================\n");
						printf("HP = %d\n", D[d].hp);
						printf("MP = %d\n", D[d].mp);
						printf("XÁÂÇ¥ = %d\n", D[d].x);
						printf("YÁÂÇ¥ = %d\n", D[d].y);
						printf("ID = %s\n", D[d].ID);
						printf("=====================================\n");
					}
				}
				for (int h = 0; h < 50; h++) {
					if (H[h].x == i && H[h].y == j) {
						printf("=====================================\n");
						printf("HP = %d\n", H[h].hp);
						printf("MP = %d\n", H[h].mp);
						printf("XÁÂÇ¥ = %d\n", H[h].x);
						printf("YÁÂÇ¥ = %d\n", H[h].y);
						printf("ID = %s\n", H[h].ID);
						printf("=====================================\n");
					}
				}
				for (int t = 0; t < 50; t++) {
					if (T[t].x == i && T[t].y == j) {
						printf("=====================================\n");
						printf("HP = %d\n", T[t].hp);
						printf("MP = %d\n", T[t].mp);
						printf("XÁÂÇ¥ = %d\n", T[t].x);
						printf("YÁÂÇ¥ = %d\n", T[t].y);
						printf("ID = %s\n", T[t].ID);
						printf("=====================================\n");
					}
				}
			}
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
	a[1][1] = 'M';
	a[2][1] = 'M';
	a[3][1] = 'M';
	a[3][2] = 'V';
	a[3][3] = 'V';
	a[4][1] = 'T';
	a[4][2] = 'M';
	a[5][1] = 'T';
	a[5][2] = 'M';
	a[6][1] = 'M';
	a[15][40] = 'H';
	a[16][39] = 'H';
	a[16][40] = 'D';
	a[17][39] = 'H';
	a[17][40] = 'D';
	a[18][38] = 'H';
	a[18][39] = 'Q';
	a[18][40] = 'Q';
	a[19][40] = 'H';
	a[20][40] = 'H';
	for (int g = 0; g < 50; g++) {
		sprintf(M[g].ID, "M%04d", g);
		M[g].hp = 30;
		M[g].mp = 0;
		M[g].x = 0;
		M[g].y = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(T[g].ID, "T%04d", g);
		T[g].hp = 120;
		T[g].mp = 0;
		T[g].x = 0;
		T[g].y = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(Q[g].ID, "Q%04d", g);
		Q[g].hp = 70;
		Q[g].mp = 150;
		Q[g].x = 0;
		Q[g].y = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(V[g].ID, "V%04d", g);
		V[g].hp = 80;
		V[g].mp = 140;
		V[g].x = 0;
		V[g].y = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(D[g].ID, "D%04d", g);
		D[g].hp = 60;
		D[g].mp = 200;
		D[g].x = 0;
		D[g].y = 0;
	}
	for (int g = 0; g < 50; g++) {
		sprintf(H[g].ID, "H%04d", g);
		H[g].hp = 50;
		H[g].mp = 0;
		H[g].x = 0;
		H[g].y = 0;
	}
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (a[i][j] == 'M') {
				M[m_num].x = j;
				M[m_num].y = i;
				m_num++;
			}
			else if (a[i][j] == 'Q') {
				Q[q_num].x = j;
				Q[q_num].y = i;
				q_num++;
			}
			else if (a[i][j] == 'T') {
				T[t_num].x = j;
				T[t_num].y = i;
				t_num++;
			}
			else if (a[i][j] == 'D') {
				D[d_num].x = j;
				D[d_num].y = i;
				d_num++;
			}
			else if (a[i][j] == 'H') {
				H[h_num].x = j;
				H[h_num].y = i;
				h_num++;
			}
			else if (a[i][j] == 'V') {
				V[v_num].x = j;
				V[v_num].y = i;
				v_num++;
			}
		}
	}
	while (1) {
		printf("1.Display 2.Produce 3.Select 4.SelectAll\n");
		printf("¸í·É¾î¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			Display();
			continue;
		case 2:
			Produce();
			continue;
		case 3:
			Select();
			continue;
		case 4:
			SelectAll();
			continue;
		}
	}
}