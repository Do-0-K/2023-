#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNING_
char a[19][19];
typedef struct node {
	int x, y;
	char dol;
	struct node* next;
}node;
typedef struct nod {
	int x, y;
	char dol;
	struct nod* next;
}nod;
node* head, * tail;
nod* head1, * tail1;
nod* data1;
node* data;
FILE* fu;
int p = 0;
int first = 0;
int p1 = 0;
void init_stack() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));

	head->next = tail;
	tail->next = tail;

	head1 = (nod*)malloc(sizeof(nod));
	tail1 = (nod*)malloc(sizeof(nod));

	head1->next = tail1;
	tail1->next = tail1;
}
void push(int x, int y, int p) {
	data = (node*)malloc(sizeof(node));
	data->x = x;
	data->y = y;
	if (p % 2 == 0) {
		data->dol = 'O';
	}
	else {
		data->dol = 'X';
	}
	data->next = head->next;
	head->next = data;
	if (first==1) {
		first = 0;
		for (int i = 0;i < p1;i++) {
			data1 = head1->next;
			head1->next = head1->next->next;
			free(data1);
		}
		p1 = 0;
	}
}
int pop() {
	int s;
	int f;
	char dol;
	if (first == 0) {
		first++;
	}
	data = head->next;
	if (data == tail) {
		printf("아무런 스택이 없다.\n");
		return -1;
	}
	head->next = head->next->next;
	s = data->x;
	f = data->y;
	dol = data->dol;
	data1 = (nod*)malloc(sizeof(nod));
	data1->x = s;
	data1->y = f;
	data1->dol = dol;
	data1->next = head1->next;
	head1->next = data1;
	free(data);
	p1++;
	return s, f, dol;
}
int repush() {
	int s, f;
	char dol;
	data1 = head1->next;
	if (data1 == tail1) {
		printf("아무런 스택이 없다.\n");
		return -1;
	}
	head1->next = head1->next->next;
	s = data1->x;
	f = data1->y;
	dol = data1->dol;
	data = (node*)malloc(sizeof(node));
	data->x = s;
	data->y = f;
	data->dol = dol;
	data->next = head->next;
	head->next = data;
	free(data1);
	return s, f, dol;
}
void map() {
	node* sp;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			a[i][j] = '*';
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			for (sp = head->next; sp != tail; sp = sp->next) {
				if (sp->x == j && sp->y == i) {
					a[i][j] = sp->dol;
				}
			}
			printf("%2c", a[i][j]);
		}
		printf("\n");
	}
}
void garo() {
	int w = 0, b = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (a[i][j] == 'O') {
				w++;
			}
			if (a[i][j] == 'X') {
				b++;
			}
		}
		if (w > 0 || b > 0) {
			printf("%d번째 가로 줄 - O의 개수 : %d       X의 개수 : %d\n", i + 1, w, b);
		}
		w = 0; b = 0;
	}
}
void sero() {
	int w = 0, b = 0;
	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19; i++) {
			if (a[i][j] == 'O') {
				w++;
			}
			if (a[i][j] == 'X') {
				b++;
			}
		}
		if (w > 0 || b > 0) {
			printf("%d번째 세로 줄 - O의 개수 : %d       X의 개수 : %d\n", j + 1, w, b);
		}
		w = 0; b = 0;
	}
}
void dbgaro() {
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (check != a[i][j]) {
				if (count > count1) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						x1 = i;
						y1 = j - 1;
					}
				}
				else if (count == count1) {
					if (check != check1) {
						if (check != '*') {
							check2 = check;
							count2 = count;
							x2 = i;
							y2 = j - 1;
						}
					}
				}
				check = a[i][j];
				count = 1;
			}
			else {
				count++;
				if (j == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						x1 = i;
						y1 = j - 1;
					}
				}
			}
		}
		if (count1 > 1) {
			if (count1 > count2) {
				printf("%d번째 가로 줄에서 연속되는 돌 - %c : %d\t", i + 1, check1, count1);
				printf("연속되는 돌의 좌표 = \t");
				for (int l = count1 - 1; l > -1; l--) {
					printf("(%d, %d). ", x1, y1 - l);
				}
				printf("\n");
			}
			if (count1 == count2) {
				printf("%d번째 가로 줄에서 연속되는 돌 - %c : %d - %c : %d\t", i + 1, check1, count1, check2, count2);
				printf("연속되는 돌의 좌표 = \t");
				for (int l = count1 - 1; l > -1; l--) {
					printf("(%d, %d). ", x1, y1 - l);
				}
				printf("\t");
				for (int l = count2 - 1; l > -1; l--) {
					printf("(%d, %d). ", x2, y2 - l);
				}
				printf("\n");
			}
			if (count2 > count1) {
				printf("%d번째 가로 줄에서 연속되는 돌 - %c : %d\t", i + 1, check2, count2);
				printf("연속되는 돌의 좌표 = \t");
				for (int l = count2 - 1; l > -1; l--) {
					printf("(%d, %d). ", x2, y2 - l);
				}
				printf("\n");
			}
		}
		check = 0; count = 0; count1 = 0; check1 = 0; check2 = 0; count2 = 0;
	}
}
void dbsero() {
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19; i++) {
			if (check != a[i][j]) {
				if (count > count1) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
				else if (count == count1) {
					if (check != check1) {
						if (check != '*') {
							check2 = check;
							count2 = count;
						}
					}
				}
				check = a[i][j];
				count = 1;
			}
			else {
				count++;
				if (i == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
			}
		}
		if (count1 > 1) {
			if (count1 > count2) {
				printf("%d번째 세로 줄에서 연속되는 돌 - %c : %d\n", j + 1, check1, count1);
			}
			if (count1 == count2) {
				printf("%d번째 세로 줄에서 연속되는 돌 - %c : %d - %c : %d\n", j + 1, check1, count1, check2, count2);
			}
			if (count2 > count1) {
				printf("%d번째 세로 줄에서 연속되는 돌 - %c : %d\n", j + 1, check2, count2);
			}
		}
		check = 0; count = 0; count1 = 0; check1 = 0; check2 = 0; count2 = 0;
	}
}
void Ldegak() {
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	int k = 0;
	for (int j = 17; j > 0; j--) {
		for (int i = j; i < 19; i++) {
			if (check != a[i][k]) {
				if (check != '*') {
					if (count > count1) {
						check1 = check;
						count1 = count;
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
							}
						}
					}
				}
				check = a[i][k];
				count = 1;
			}
			else {
				count++;
				if (i == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
			}
			k++;
		}
		if (count1 > 1) {
			if (count1 > count2) {
				printf("(좌하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", 20 - j, check1, count1);
			}
			if (count1 == count2) {
				printf("(좌하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d - %c : %d\n", 20 - j, check1, count1, check2, count2);
			}
			if (count2 > count1) {
				printf("(좌하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", 20 - j, check2, count2);
			}
		}
		check = 0; count = 0; count1 = 0; check1 = 0; k = 0; check2 = 0; count2 = 0;
	}
	for (int i = 0; i < 18; i++) {
		for (int j = i; j < 19; j++) {
			if (check != a[k][j]) {
				if (count > count1) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
				else if (count == count1) {
					if (check != check1) {
						if (check != '*') {
							check2 = check;
							count2 = count;
						}
					}
				}
				check = a[k][j];
				count = 1;
			}
			else {
				count++;
				if (j == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
			}
			k++;
		}
		if (count1 > 1 || count2 > 1) {
			if (count1 > count2) {
				printf("(좌하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", i + 20, check1, count1);
			}
			if (count1 == count2) {
				printf("(좌하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d - %c : %d\n", i + 20, check1, count1, check2, count2);
			}
			if (count2 > count1) {
				printf("(좌하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", i + 20, check2, count2);
			}
		}
		check = 0; count = 0; count1 = 0; check1 = 0; k = 0; check2 = 0; count2 = 0;
	}
}
void Rdegak() {
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	int k = 0;
	for (int i = 1; i <= 18; i++) {
		for (int j = i; j >= 0; j--) {
			if (check != a[k][j]) {
				if (count > count1) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
				else if (count == count1) {
					if (check != check1) {
						if (check != '*') {
							check2 = check;
							count2 = count;
						}
					}
				}
				check = a[k][j];
				count = 1;
			}
			else {
				count++;
				if (j == 0) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
			}
			k++;
		}
		if (count1 > 1) {
			if (count1 > count2) {
				printf("(우하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", i + 1, check1, count1);
			}
			if (count1 == count2) {
				printf("(우하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d - %c : %d\n", i + 1, check1, count1, check2, count2);
			}
			if (count2 > count1) {
				printf("(우하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", i + 1, check2, count2);
			}
		}
		check = 0; count = 0; count1 = 0; check1 = 0; k = 0; check2 = 0; count2 = 0;
	}
	k = 18;
	for (int j = 18; j >0; j--) {
		for (int i = 17 - (18 - j); i < 19; i++) {
			if (check != a[i][k]) {
				if (count > count1) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
				else if (count == count1) {
					if (check != check1) {
						if (check != '*') {
							check2 = check;
							count2 = count;
						}
					}
				}
				check = a[i][k];
				count = 1;
			}
			else {
				count++;
				if (i == j) {
					if (check != '*') {
						check1 = check;
						count1 = count;
					}
				}
			}
			k--;
		}
		if (count1 > 1) {
			if (count1 > count2) {
				printf("(우하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", 19 + j, check1, count1);
			}
			if (count1 == count2) {
				printf("(우하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d - %c : %d\n", 19 + j, check1, count1, check2, count2);
			}
			if (count2 > count1) {
				printf("(우하향)%d번째 대각선 줄에서 연속되는 돌 - %c : %d\n", 19 + j, check2, count2);
			}
		}
		check = 0; count = 0; count1 = 0; check1 = 0; k = 19; check2 = 0; count2 = 0;
	}
}
void savefile(int p) {
	fu = fopen("omok.txt", "w");
	fprintf_s(fu, "%d\n", p);
	for (node* sp = head->next; sp != tail; sp = sp->next) {
		fprintf(fu, "%d %d %c\n", sp->x, sp->y, sp->dol);
	}
	for (nod* st = head1->next; st != tail1; st = st->next) {
		fprintf(fu, "%d %d %c\n", st->x, st->y, st->dol);
	}
}
void loadfile(int t) {
	int s = 0;
	fu = fopen("omok.txt", "r");
	fscanf_s(fu, "%d\n", &t);
	printf("%d\n", t);
	p = t;
	for (int i = 0;i <= p;i++) {
		data1 = (nod*)malloc(sizeof(nod));
		fscanf_s(fu, "%d ", &data1->x);
		fscanf_s(fu, "%d ", &data1->y);
		if (s % 2 == 0) {
			fscanf_s(fu, "%c\n", &data1->dol);
		}
		else {
			fscanf_s(fu, "%c\n", &data1->dol);
		}
		data1->next = head1->next;
		head1->next = data1;
	}
	int r;
	int f;
	char dol;
	for (int i = 0;i <= p;i++) {
		data1 = head1->next;
		head1->next = head1->next->next;
		r = data1->x;
		f = data1->y;
		dol = data1->dol;
		data = (node*)malloc(sizeof(node));
		data->x = r;
		data->y = f;
		data->dol = dol;
		data->next = head->next;
		head->next = data;
		free(data1);
	}
	fclose(fu);
}
int main() {
	int ment;
	init_stack();
	while (1) {
		ment = 0;
		int s = 0, f = 0, w = 0;
		map();
		printf("1.돌 놓기 2.무르기 3.무르기 취소 4.가로,세로 개수 5.가로 연속\n6.세로 연속 7.좌하향 대각선 8.우하향 대각선 9.저장 및 종료 0.읽어오기\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			while (1) {
				printf("돌의 위치를 정해주세요 - ");
				scanf_s("%d %d", &s, &f);
				if (s > 19 || s < 0) {
					printf("잘못된 좌표입니다.\n");
					continue;
				}
				if (f > 19 || f < 0) {
					printf("잘못된 좌표입니다.\n");
					continue;
				}
				if (a[s][f] != '*') {
					printf("이미 돌이 놓여있습니다.\n");
					continue;
				}
				break;
			}
			push(s, f, p);
			p++;
			break;
		case 2:
			pop();
			p--;
			break;
		case 3:
			repush();
			p++;
			break;
		case 4:
			garo();
			printf("============================================\n");
			sero();
			break;
		case 5:
			dbgaro();
			break;
		case 6:
			dbsero();
			break;
		case 7:
			Ldegak();
			break;
		case 8:
			Rdegak();
			break;
		case 9:
			savefile(p);
			printf("프로그램을 종료합니다.\n");
			fclose(fu);
			exit(1);
			break;
		case 0:
			loadfile(p);
			break;
		}
	}
}