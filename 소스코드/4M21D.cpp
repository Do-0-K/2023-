#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNING_
int i = 0;
int z = 0;
int k = 0;
int t = 0;
char a[22][42];
struct unit {
	char name;
	int x;
	int y;
	int hp;
	int mp;
	char ID[5] = "   ";
};
struct unit UNIT[100];
typedef struct node {
	unit data;
	struct node* next;
	node* head;
	node* tail;
}node;
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
void UL_SL(node** head, node** tail) {
	for (int i = 0; i < 21; i++) {
		if ((*head) == NULL) {
			(*head) = (*tail) = (node*)malloc(sizeof(node));
		}
		else {
			(*tail)->next = (node*)malloc(sizeof(node));
			(*tail)->next->next = (*head);
			(*tail) = (*tail)->next;
		}
	}
}
void MakeUL_SL(node** head) {
	for (int i = 0; i < 21; i++) {
		(*head)->next->data = UNIT[i];
		(*head) = (*head)->next;
	}
}
void ShowUL_R(node* head) {
	node* cur = head;
	node* cu = head;
	do {
		printf("NAME = %c\n", cur->next->data.name);
		printf("ID = %s\n", cur->next->data.ID);
		printf("HP = %d\n", cur->next->data.hp);
		printf("MP = %d\n", cur->next->data.mp);
		printf("X = %d\n", cur->next->data.x);
		printf("Y = %d\n", cur->next->data.y);
		cur = cur->next;
	} while (cur->next != cu);
}
void Produce_UL_R(node** head, node** tail, int x, int y) {
	(*tail)->next = (node*)malloc(sizeof(node));
	printf("새로운 유닛의 HP,MP를 입력하세요 - ");
	scanf_s("%d %d", &(*tail)->next->data.hp, &(*tail)->next->data.mp);
	printf("새로운 유닛의 종류를 입력하세요 - ");
	scanf(" %c", &(*tail)->next->data.name);
	printf("새로운 유닛의 ID를 입력하세요 - ");
	scanf(" %s", &(*tail)->next->data.ID);
	(*tail)->next->data.x = x;
	(*tail)->next->data.y = y;
	(*tail)->next->next = (*head);
}
void Select_UL_R(node* head, int x, int y) {
	node* cur = head;
	node* cu = head;
	do {
		if (cur->data.x == x) {
			if (cur->data.y == y) {
				printf("NAME = %c\n", cur->data.name);
				printf("ID = %s\n", cur->data.ID);
				printf("HP = %d\n", cur->data.hp);
				printf("MP = %d\n", cur->data.mp);
				printf("X = %d\n", cur->data.x);
				printf("Y = %d\n", cur->data.y);
			}
		}
		cur = cur->next;
	} while (cur != cu);
}
void Destroy_UL_R(node** head, node** tail, int x, int y) {
	node* cur = (*head);
	node* cu = (*head);
	if (cur->data.x == x && cur->data.y == y) {
		(*tail)->next = cur->next;
		free(cur);
		(*head) = (*tail)->next;
		cur = (*head);
	}
	while (cur->next != (*head)) {
		if (cur->next->data.x == x) {
			if (cur->next->data.y == y) {
				node* del = cur->next;
				if (cur->next == (*tail)) {
					cur->next = cur->next->next;
					(*tail) = cur;
				}
				else {
					cur->next = cur->next->next;
				}
				free(del);
			}
		}
		cur = cur->next;
	}
}
void FindWeakEnemy_R(node* head, node* tail, int x, int y, int w) {
	node* cur = head;
	node* cu = head;
	do {
		if (x - w <= cur->data.x && cur->data.x <= x + w) {
			if (y - w <= cur->data.y && cur->data.y <= y + w) {
				if (t == 1) {
					if (cur->data.name == 'H' || cur->data.name == 'Q' || cur->data.name == 'D') {
						if (cur->data.hp < minHP) {
							minHP = cur->data.hp;
						}
					}
				}
				if (t == 2) {
					if (cur->data.name == 'M' || cur->data.name == 'V' || cur->data.name == 'T') {
						if (cur->data.hp < minHP) {
							minHP = cur->data.hp;
						}
					}
				}
			}
		}
		cur = cur->next;
	} while (cur->next != cu);
	do {
		if (x - w <= cur->data.x && cur->data.x <= x + w) {
			if (y - w <= cur->data.y && cur->data.y <= y + w) {
				if (t == 1) {
					if (cur->data.name == 'H' || cur->data.name == 'Q' || cur->data.name == 'D') {
						if (cur->data.hp == minHP) {
							printf("NAME = %c\n", cur->data.name);
							printf("ID = %s\n", cur->data.ID);
							printf("HP = %d\n", cur->data.hp);
							printf("MP = %d\n", cur->data.mp);
							printf("X = %d\n", cur->data.x);
							printf("Y = %d\n", cur->data.y);
						}
					}
				}
				if (t == 2) {
					if (cur->data.name == 'M' || cur->data.name == 'V' || cur->data.name == 'T') {
						if (cur->data.hp == minHP) {
							printf("NAME = %c\n", cur->data.name);
							printf("ID = %s\n", cur->data.ID);
							printf("HP = %d\n", cur->data.hp);
							printf("MP = %d\n", cur->data.mp);
							printf("X = %d\n", cur->data.x);
							printf("Y = %d\n", cur->data.y);
						}
					}
				}
			}
		}
		cur = cur->next;
	} while (cur->next != cu);
	z = 0;
}
void SortByIDUL_SL(node** head, node** tail) {
	node* cur = (*head);
	node* cu = (*head)->next;
	node* ct = cu->next;
	while (ct != (*head)) {
		if (strcmp(cu->data.ID, ct->data.ID) > 0) {
			cur->next = ct;
			cu->next = ct->next;
			ct->next = cu;

			cur = (*head);
			cu = (*head)->next;
			ct = cu->next;
		}
		else {
			cu = cu->next;
			cur = cur->next; 
			ct = ct->next;
		}
	}
	for (node* cut = (*head); cut->next != (*head); cut = cut->next) {
		if (cut->next->next == (*head)) {
			(*tail) = cut->next;
			(*tail)->next = (*head);
		}
	}
	node* cut = (*head);
	node* cv = (*head);
	do {
		printf("ID = %s\n", cut->next->data.ID);
		cut = cut->next;
	} while (cut->next != cv);
}
int main() {
	node* head = NULL;
	node* tail = NULL;
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
	UL_SL(&head, &tail);
	MakeUL_SL(&head);
	while (1) {
		ment = 0;
		int s = 0, f = 0, w = 0;
		z = 0;
		printf("1.ShowUL_R 2.Produce_UL_R 3.Select_UL_R 4.Destroy_UL_R 5.FindWeakEnemy 6.SortByIDUL_SL 7.Exit\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			ShowUL_R(head);
			break;
		case 2:
			while (1) {
				z = 0;
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
				node* cur = head;
				node* cu = head;
				do {
					if (cur->data.x == s && cur->data.y == f) {
						z++;
					}
					cur = cur->next;
				} while (cur != cu);
				if (z != 0) {
					printf("해당 좌표에 유닛이 있습니다.\n");
					continue;
				}
				break;
			}
			Produce_UL_R(&head, &tail, s, f);
			break;
		case 3:
			while (1) {
				z = 0;
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
				node* cur = head;
				node* cu = head;
				do {
					if (cur->data.x == s && cur->data.y == f) {
						z++;
					}
					cur = cur->next;
				} while (cur->next != cu);
				if (z == 0) {
					printf("해당 좌표에 유닛이 없습니다.\n");
					continue;
				}
				break;
			}
			Select_UL_R(head, s, f);
			break;
		case 4:
			while (1) {
				z = 0;
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
				node* cur = head;
				node* cu = head;
				do {
					if (cur->data.x == s && cur->data.y == f) {
						z++;
					}
					cur = cur->next;
				} while (cur != cu);
				if (z == 0) {
					printf("해당 좌표에 유닛이 없습니다.\n");
					continue;
				}
				break;
			}
			Destroy_UL_R(&head, &tail, s, f);
			break;
		case 5:
			while (1) {
				z = 0;
				printf("좌표를 입력해주세요 - ");
				scanf_s("%d %d", &s, &f);
				if (s < 1 || s>40) {
					printf("잘못된 좌표입니다.\n");
					continue;
				}
				if (f < 1 || f>20) {
					printf("잘못된 좌표입니다.\n");
					continue;
				}
				node* cur = head;
				node* cu = head;
				do {
					if (cur->data.x == s && cur->data.y == f) {
						if (cur->data.name == 'M' || cur->data.name == 'V' || cur->data.name == 'T') {
							t = 1;
						}
						else {
							t = 2;
						}
						z++;
					}
					cur = cur->next;
				} while (cur != cu);
				if (z == 0) {
					printf("해당 좌표에 유닛이 없습니다.\n");
					continue;
				}
				printf("거리를 입력해주세요 - ");
				scanf_s("%d", &w);
				break;
			}
			FindWeakEnemy_R(head, tail, s, f, w);
			break;
		case 6:
			SortByIDUL_SL(&head, &tail);
			break;
		case 7:
			printf("프로그램을 종료합니다.\n");
			exit(1);
		}
	}
}
