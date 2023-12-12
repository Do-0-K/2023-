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
int k = 0, k1 = 0;
struct dot {
	int x = 0;
	int y = 0;
	int x1 = 0;
	int y1 = 0;
	int cnt = 0;
	int direct = 0;
	int num = 0;
	char dol;
};
struct dot dt[3000];
int lr = 0;
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
void dbgaro() {
	int sp = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (check != a[i][j]) {
				if (a[i][j] == '*') {
					if (sp == 0) {
						sp++;
						k = j;
						if (j == 18) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								ct = 1;
								x1 = i;
								y1 = j - 1;
								if (count1 > 1) {
									dt[lr].x = x1;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 0;
									dt[lr].num = i + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
						}
						continue;
					}
					else {
						if (count >= count1) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								if (a[i][j - 1] == '*') {
									ct = 1;
									x1 = i;
									y1 = j - 2;
									if (count1 > 1) {
										dt[lr].x = x1;
										dt[lr].y = y1 - count1 + ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 0;
										dt[lr].num = i + 1;
										dt[lr].dol = check1;
										lr++;
									}
								}
								else {
									ct = 0;
									x1 = i;
									y1 = j - 1;
									if (count1 > 1) {
										dt[lr].x = x1;
										dt[lr].y = y1 - count1 + ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 0;
										dt[lr].num = i + 1;
										dt[lr].dol = check1;
										lr++;
									}
								}
								j = k;
							}
						}
						else if (count == count1) {
							if (check != check1) {
								if (check != '*') {
									check2 = check;
									count2 = count;
									if (a[i][j - 1] == '*') {
										ct1 = 1;
										x2 = i;
										y2 = j - 2;
										if (count2 > 1) {
											dt[lr].x = x2;
											dt[lr].y = y2 - count2 + ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 0;
											dt[lr].num = i + 1;
											dt[lr].dol = check2;
											lr++;
										}
									}
									else {
										ct1 = 0;
										x2 = i;
										y2 = j - 1;
										if (count2 > 1) {
											dt[lr].x = x2;
											dt[lr].y = y2 - count2 + ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 0;
											dt[lr].num = i + 1;
											dt[lr].dol = check2;
											lr++;
										}
									}
									j = k;
								}
							}
						}
						check = a[i][j];
						count = 1;
					}
				}
				else {
					sp = 0;
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							if (a[i][j - 1] == '*') {
								ct = 1;
								x1 = i;
								y1 = j - 2;
								if (count1 > 1) {
									dt[lr].x = x1;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 0;
									dt[lr].num = i + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
							else {
								ct = 1;
								x1 = i;
								y1 = j - 1;
								if (count1 > 1) {
									dt[lr].x = x1;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 0;
									dt[lr].num = i + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
							j = k;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
								if (a[i][j - 1] == '*') {
									ct1 = 1;
									x2 = i;
									y2 = j - 2;
									if (count2 > 1) {
										dt[lr].x = x2;
										dt[lr].y = y2 - count2 + ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 0;
										dt[lr].num = i + 1;
										dt[lr].dol = check2;
										lr++;
									}
								}
								else {
									ct1 = 1;
									x2 = i;
									y2 = j - 1;
									if (count2 > 1) {
										dt[lr].x = x2;
										dt[lr].y = y2 - count2 + ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 0;
										dt[lr].num = i + 1;
										dt[lr].dol = check2;
										lr++;
									}
								}
								j = k;
							}
						}
					}
					check = a[i][j];
					count = 1;
				}
			}
			else {
				if (check == '*') {
					sp = 0;
				}
				count++;
				if (j == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						ct = 1;
						x1 = i;
						y1 = j;
						if (count1 > 1) {
							dt[lr].x = x1;
							dt[lr].y = y1 - count1 + ct;
							dt[lr].x1 = x1;
							dt[lr].y1 = y1;
							dt[lr].cnt = count1;
							dt[lr].direct = 0;
							dt[lr].num = i + 1;
							dt[lr].dol = check1;
							lr++;
						}
					}
				}
			}
		}
		k = 0; ct = 0; ct1 = 0;
		check = 0; count = 0; count1 = 0; check1 = 0; check2 = 0; count2 = 0;
	}
}
void dbsero() {
	int sp1 = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19; i++) {
			if (check != a[i][j]) {
				if (a[i][j] == '*') {
					if (sp1 == 0) {
						sp1++;
						k1 = i;
						if (i == 18) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								ct = 1;
								x1 = i - 1;
								y1 = j;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 1;
									dt[lr].num = j + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
						}
						continue;
					}
					else {
						if (count >= count1) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								if (a[i - 1][j] == '*') {
									ct = 1;
									x1 = i - 2;
									y1 = j;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 1;
										dt[lr].num = j + 1;
										dt[lr].dol = check1;
										lr++;
									}
								}
								else {
									ct = 0;
									x1 = i - 1;
									y1 = j;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 1;
										dt[lr].num = j + 1;
										dt[lr].dol = check1;
										lr++;
									}
								}
								i = k1;
							}
						}
						else if (count == count1) {
							if (check != check1) {
								if (check != '*') {
									check2 = check;
									count2 = count;
									if (a[i - 1][j] == '*') {
										ct1 = 1;
										x2 = i - 2;
										y2 = j;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 1;
											dt[lr].num = j + 1;
											dt[lr].dol = check2;
											lr++;
										}
									}
									else {
										ct1 = 0;
										x2 = i - 1;
										y2 = j;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 1;
											dt[lr].num = j + 1;
											dt[lr].dol = check2;
											lr++;
										}
									}
									i = k1;
								}
							}
						}
						check = a[i][j];
						count = 1;
					}
				}
				else {
					sp1 = 0;
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							if (a[i - 1][j] == '*') {
								ct = 1;
								x1 = i - 2;
								y1 = j;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 1;
									dt[lr].num = j + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
							else {
								ct = 1;
								x1 = i - 1;
								y1 = j;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 1;
									dt[lr].num = j + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
							i = k1;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
								if (a[i - 1][j] == '*') {
									ct1 = 1;
									x2 = i - 2;
									y2 = j;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 1;
										dt[lr].num = j + 1;
										dt[lr].dol = check2;
										lr++;
									}
								}
								else {
									ct1 = 1;
									x2 = i - 1;
									y2 = j;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 1;
										dt[lr].num = j + 1;
										dt[lr].dol = check2;
										lr++;
									}
								}
								i = k1;
							}
						}
					}
					check = a[i][j];
					count = 1;
				}
			}
			else {
				if (check == '*') {
					sp1 = 0;
				}
				count++;
				if (i == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						ct = 1;
						x1 = i;
						y1 = j;
						if (count1 > 1) {
							dt[lr].x = x1 - count1 + ct;
							dt[lr].y = y1;
							dt[lr].x1 = x1;
							dt[lr].y1 = y1;
							dt[lr].cnt = count1;
							dt[lr].direct = 1;
							dt[lr].num = j + 1;
							dt[lr].dol = check1;
							lr++;
						}
					}
				}
			}
		}
		k1 = 0; ct = 0; ct1 = 0;
		check = 0; count = 0; count1 = 0; check1 = 0; check2 = 0; count2 = 0;
	}
}
void Ldegak() {
	int g = 0;
	int sp = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int j = 17; j > 0; j--) {
		for (int i = j; i < 19; i++) {
			if (check != a[i][g]) {
				if (a[i][g] == '*') {
					if (sp == 0) {
						sp++;
						k = g;
						if (i == 18) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								ct = 1;
								x1 = i - 1;
								y1 = g - 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 2;
									dt[lr].num = 19 - j;
									dt[lr].dol = check1;
									lr++;
								}
							}
						}
						g++;
						continue;
					}
					else {
						if (count >= count1) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								if (a[i - 1][g - 1] == '*') {
									ct = 1;
									x1 = i - 2;
									y1 = g - 2;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 - count1 + ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 2;
										dt[lr].num = 19 - j;
										dt[lr].dol = check1;
										lr++;
									}
								}
								else {
									ct = 0;
									x1 = i - 1;
									y1 = g - 1;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 - count1 + ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 2;
										dt[lr].num = 19 - j;
										dt[lr].dol = check1;
										lr++;
									}
								}
								g = k;
							}
						}
						else if (count == count1) {
							if (check != check1) {
								if (check != '*') {
									check2 = check;
									count2 = count;
									if (a[i - 1][g - 1] == '*') {
										ct1 = 1;
										x2 = i - 2;
										y2 = g - 2;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 - count2 + ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 2;
											dt[lr].num = 19 - j;
											dt[lr].dol = check2;
											lr++;
										}
									}
									else {
										ct1 = 0;
										x2 = i - 1;
										y2 = g - 1;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 - count2 + ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 2;
											dt[lr].num = 19 - j;
											dt[lr].dol = check2;
											lr++;
										}
									}
									g = k;
								}
							}
						}
						check = a[i][g];
						count = 1;
					}
				}
				else {
					sp = 0;
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							if (a[i - 1][g - 1] == '*') {
								ct = 1;
								x1 = i - 2;
								y1 = g - 2;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 2;
									dt[lr].num = 19 - j;
									dt[lr].dol = check1;
									lr++;
								}
							}
							else {
								ct = 1;
								x1 = i - 1;
								y1 = g - 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 2;
									dt[lr].num = 19 - j;
									dt[lr].dol = check1;
									lr++;
								}
							}
							g = k;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
								if (a[i - 1][g - 1] == '*') {
									ct1 = 1;
									x2 = i - 2;
									y2 = g - 2;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 - count2 + ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 2;
										dt[lr].num = 19 - j;
										dt[lr].dol = check2;
										lr++;
									}
								}
								else {
									ct1 = 1;
									x2 = i - 1;
									y2 = g - 1;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 - count2 + ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 2;
										dt[lr].num = 19 - j;
										dt[lr].dol = check2;
										lr++;
									}
								}
								g = k;
							}
						}
					}
					check = a[i][g];
					count = 1;
				}
			}
			else {
				if (check == '*') {
					sp = 0;
				}
				count++;
				if (i == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						x1 = i;
						y1 = g;
						ct = 1;
						if (count1 > 1) {
							dt[lr].x = x1 - count1 + ct;
							dt[lr].y = y1 - count1 + ct;
							dt[lr].x1 = x1;
							dt[lr].y1 = y1;
							dt[lr].cnt = count1;
							dt[lr].direct = 2;
							dt[lr].num = 19 - j;
							dt[lr].dol = check1;
							lr++;
						}
					}
				}
			}
			g++;
		}
		ct = 0; ct1 = 0;
		check = 0; count = 0; count1 = 0; check1 = 0; g = 0; k = 0; check2 = 0; count2 = 0;
	}
	int n = 0;
	for (int i = 0; i < 18; i++) {
		for (int j = i; j < 19; j++) {
			if (check != a[g][j]) {
				if (a[g][j] == '*') {
					if (sp == 0) {
						sp++;
						k = g;
						n = j;
						if (j == 18) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								x1 = g - 1;
								y1 = j - 1;
								ct = 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 2;
									dt[lr].num = i + 19;
									dt[lr].dol = check1;
									lr++;
								}
							}
						}
						g++;
						continue;
					}
					else {
						if (count >= count1) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								if (a[g - 1][j - 1] == '*') {
									ct = 1;
									x1 = g - 2;
									y1 = j - 2;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 - count1 + ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 2;
										dt[lr].num = i + 19;
										dt[lr].dol = check1;
										lr++;
									}
								}
								else {
									ct = 0;
									x1 = g - 1;
									y1 = j - 1;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 - count1 + ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 2;
										dt[lr].num = i + 19;
										dt[lr].dol = check1;
										lr++;
									}
								}
								g = k;
								j = n;
							}
						}
						else if (count == count1) {
							if (check != check1) {
								if (check != '*') {
									check2 = check;
									count2 = count;
									if (a[g - 1][j - 1] == '*') {
										ct1 = 1;
										x2 = g - 2;
										y2 = j - 2;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 - count2 + ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 2;
											dt[lr].num = i + 19;
											dt[lr].dol = check2;
											lr++;
										}
									}
									else {
										ct1 = 0;
										x2 = g - 1;
										y2 = j - 1;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 - count2 + ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 2;
											dt[lr].num = i + 19;
											dt[lr].dol = check2;
											lr++;
										}
									}
									g = k;
									j = n;
								}
							}
						}
						check = a[g][j];
						count = 1;
					}
				}
				else {
					sp = 0;
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							if (a[g - 1][j - 1] == '*') {
								ct = 1;
								x1 = g - 2;
								y1 = j - 2;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 2;
									dt[lr].num = i + 19;
									dt[lr].dol = check1;
									lr++;
								}
							}
							else {
								ct = 1;
								x1 = g - 1;
								y1 = j - 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 - count1 + ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 2;
									dt[lr].num = i + 19;
									dt[lr].dol = check1;
									lr++;
								}
							}
							j = n;
							g = k;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
								if (a[g - 1][j - 1] == '*') {
									ct1 = 1;
									x2 = g - 2;
									y2 = j - 2;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 - count2 + ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 2;
										dt[lr].num = i + 19;
										dt[lr].dol = check2;
										lr++;
									}
								}
								else {
									ct1 = 1;
									x2 = g - 1;
									y2 = j - 1;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 - count2 + ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 2;
										dt[lr].num = i + 19;
										dt[lr].dol = check2;
										lr++;
									}
								}
								j = n;
								g = k;
							}
						}
					}
					check = a[g][j];
					count = 1;
				}
			}
			else {
				if (check == '*') {
					sp = 0;
				}
				count++;
				if (j == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						x1 = g;
						y1 = j;
						ct = 1;
						if (count1 > 1) {
							dt[lr].x = x1 - count1 + ct;
							dt[lr].y = y1 - count1 + ct;
							dt[lr].x1 = x1;
							dt[lr].y1 = y1;
							dt[lr].cnt = count1;
							dt[lr].direct = 2;
							dt[lr].num = i + 19;
							dt[lr].dol = check1;
							lr++;
						}
					}
				}
			}
			g++;
		}
		ct = 0; ct1 = 0;
		check = 0; count = 0; count1 = 0; check1 = 0; g = 0; k = 0; check2 = 0; count2 = 0;
	}
}
void Rdegak() {
	int sp1 = 0;
	int g = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i <= 18; i++) {
		for (int j = i; j >= 0; j--) {
			if (check != a[g][j]) {
				if (a[g][j] == '*') {
					if (sp1 == 0) {
						sp1++;
						k = g;
						if (0 == j) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								ct = 1;
								x1 = g - 1;
								y1 = j + 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 + count1 - ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 3;
									dt[lr].num = i + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
						}
						g++;
						continue;
					}
					else {
						if (count >= count1) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								if (a[g - 1][j + 1] == '*') {
									ct = 1;
									x1 = g - 2;
									y1 = j + 2;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 + count1 - ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 3;
										dt[lr].num = i + 1;
										dt[lr].dol = check1;
										lr++;
									}
								}
								else {
									ct = 0;
									x1 = g - 1;
									y1 = j + 1;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 + count1 - ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 3;
										dt[lr].num = i + 1;
										dt[lr].dol = check1;
										lr++;
									}
								}
								g = k;
							}
						}
						else if (count == count1) {
							if (check != check1) {
								if (check != '*') {
									check2 = check;
									count2 = count;
									if (a[g - 1][j + 1] == '*') {
										ct1 = 1;
										x2 = g - 2;
										y2 = j + 2;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 + count2 - ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 3;
											dt[lr].num = i + 1;
											dt[lr].dol = check2;
											lr++;
										}
									}
									else {
										ct1 = 0;
										x2 = g - 1;
										y2 = j + 1;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 + count2 - ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 3;
											dt[lr].num = i + 1;
											dt[lr].dol = check2;
											lr++;
										}
									}
									g = k;
								}
							}
						}
						check = a[g][j];
						count = 1;
					}
				}
				else {
					sp1 = 0;
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							if (a[g - 1][j + 1] == '*') {
								ct = 1;
								x1 = g - 2;
								y1 = j + 2;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 + count1 - ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 3;
									dt[lr].num = i + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
							else {
								ct = 0;
								x1 = g - 1;
								y1 = j + 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 + count1 - ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 3;
									dt[lr].num = i + 1;
									dt[lr].dol = check1;
									lr++;
								}
							}
							g = k;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
								if (a[g - 1][j + 1] == '*') {
									ct1 = 1;
									x2 = g - 2;
									y2 = j + 2;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 + count2 - ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 3;
										dt[lr].num = i + 1;
										dt[lr].dol = check2;
										lr++;
									}
								}
								else {
									ct1 = 0;
									x2 = g - 1;
									y2 = j + 1;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 + count2 - ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 3;
										dt[lr].num = i + 1;
										dt[lr].dol = check2;
										lr++;
									}
								}
								g = k;
							}
						}
					}
					check = a[g][j];
					count = 1;
				}
			}
			else {
				if (check == '*') {
					sp1 = 0;
				}
				count++;
				if (0 == j) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						x1 = g - 1;
						y1 = j + 1;
						ct = 1;
						if (count1 > 1) {
							dt[lr].x = x1 - count1 + ct;
							dt[lr].y = y1 + count1 - ct;
							dt[lr].x1 = x1;
							dt[lr].y1 = y1;
							dt[lr].cnt = count1;
							dt[lr].direct = 3;
							dt[lr].num = i + 1;
							dt[lr].dol = check1;
							lr++;
						}
					}
				}
			}
			g++;
		}
		ct = 0; ct1 = 0;
		check = 0; count = 0; count1 = 0; check1 = 0; g = 0; k = 0; check2 = 0; count2 = 0;
	}
	g = 18;
	int n = 0;
	for (int j = 18; j > 0; j--) {
		for (int i = 17 - (18 - j); i < 19; i++) {
			if (check != a[i][g]) {
				if (a[i][g] == '*') {
					if (sp1 == 0) {
						sp1++;
						k = g;
						n = i;
						if (i == 18) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								x1 = i - 1;
								y1 = g + 1;
								ct = 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 + count1 - ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 3;
									dt[lr].num = 18 + j;
									dt[lr].dol = check1;
									lr++;
								}
							}
						}
						g--;
						continue;
					}
					else {
						if (count > count1) {
							if (check != '*') {
								check1 = check;
								count1 = count;
								if (a[i - 1][g + 1] == '*') {
									ct = 1;
									x1 = i - 2;
									y1 = g + 2;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 + count1 - ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 3;
										dt[lr].num = 18 + j;
										dt[lr].dol = check1;
										lr++;
									}
								}
								else {
									ct = 0;
									x1 = i - 1;
									y1 = g + 1;
									if (count1 > 1) {
										dt[lr].x = x1 - count1 + ct;
										dt[lr].y = y1 + count1 - ct;
										dt[lr].x1 = x1;
										dt[lr].y1 = y1;
										dt[lr].cnt = count1;
										dt[lr].direct = 3;
										dt[lr].num = 18 + j;
										dt[lr].dol = check1;
										lr++;
									}
								}
								g = k;
								i = n;
							}
						}
						else if (count == count1) {
							if (check != check1) {
								if (check != '*') {
									check2 = check;
									count2 = count;
									if (a[i - 1][g + 1] == '*') {
										ct1 = 1;
										x2 = i - 2;
										y2 = g + 2;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 + count2 - ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 3;
											dt[lr].num = 18 + j;
											dt[lr].dol = check2;
											lr++;
										}
									}
									else {
										ct1 = 0;
										x2 = i - 1;
										y2 = g + 1;
										if (count2 > 1) {
											dt[lr].x = x2 - count2 + ct1;
											dt[lr].y = y2 + count2 - ct1;
											dt[lr].x1 = x2;
											dt[lr].y1 = y2;
											dt[lr].cnt = count2;
											dt[lr].direct = 3;
											dt[lr].num = 18 + j;
											dt[lr].dol = check2;
											lr++;
										}
									}
									g = k;
									i = n;
								}
							}
						}
						check = a[i][g];
						count = 1;
					}
				}
				else {
					sp1 = 0;
					if (count > count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							if (a[i - 1][g + 1] == '*') {
								ct = 1;
								x1 = i - 2;
								y1 = g + 2;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 + count1 - ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 3;
									dt[lr].num = 18 + j;
									dt[lr].dol = check1;
									lr++;
								}
							}
							else {
								ct = 0;
								x1 = i - 1;
								y1 = g + 1;
								if (count1 > 1) {
									dt[lr].x = x1 - count1 + ct;
									dt[lr].y = y1 + count1 - ct;
									dt[lr].x1 = x1;
									dt[lr].y1 = y1;
									dt[lr].cnt = count1;
									dt[lr].direct = 3;
									dt[lr].num = 18 + j;
									dt[lr].dol = check1;
									lr++;
								}
							}
							g = k;
							i = n;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							if (check != '*') {
								check2 = check;
								count2 = count;
								if (a[i - 1][g + 1] == '*') {
									ct1 = 1;
									x2 = i - 2;
									y2 = g + 2;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 + count2 - ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 3;
										dt[lr].num = 18 + j;
										dt[lr].dol = check2;
										lr++;
									}
								}
								else {
									ct1 = 0;
									x2 = i - 1;
									y2 = g + 1;
									if (count2 > 1) {
										dt[lr].x = x2 - count2 + ct1;
										dt[lr].y = y2 + count2 - ct1;
										dt[lr].x1 = x2;
										dt[lr].y1 = y2;
										dt[lr].cnt = count2;
										dt[lr].direct = 3;
										dt[lr].num = 18 + j;
										dt[lr].dol = check2;
										lr++;
									}
								}
								g = k;
								i = n;
							}
						}
					}
					check = a[i][g];
					count = 1;
				}
			}
			else {
				if (check == '*') {
					sp1 = 0;
				}
				count++;
				if (i == 18) {
					if (check != '*') {
						check1 = check;
						count1 = count;
						ct = 1;
						x1 = i - 1;
						y1 = g + 1;
						if (count1 > 1) {
							dt[lr].x = x1 - count1 + ct;
							dt[lr].y = y1 + count1 - ct;
							dt[lr].x1 = x1;
							dt[lr].y1 = y1;
							dt[lr].cnt = count1;
							dt[lr].direct = 3;
							dt[lr].num = 18 + j;
							dt[lr].dol = check1;
							lr++;
						}
					}
				}
			}
			g--;
		}
		ct = 0, ct1 = 0; n = 0;
		check = 0; count = 0; count1 = 0; check1 = 0; g = 18; k = 0; check2 = 0; count2 = 0;
	}
}
void many(int max) {
	printf("========제일 많은 돌=========\n");
	for (int i = 0; i < lr; i++) {
		if (max == dt[i].cnt) {
			if (dt[i].direct == 0) {
				printf("%d번째 가로줄 - ", dt[i].num);
				printf("(%d, %d) , ", dt[i].x, dt[i].y);
				printf("(%d, %d)\n", dt[i].x1, dt[i].y1);
				continue;
			}
			if (dt[i].direct == 1) {
				printf("%d번째 세로줄 - ", dt[i].num);
				printf("(%d, %d) , ", dt[i].x, dt[i].y);
				printf("(%d, %d)\n", dt[i].x1, dt[i].y1);
				continue;
			}
			if (dt[i].direct == 2) {
				printf("%d번째 좌->우 대각선 - ", dt[i].num);
				printf("(%d, %d) , ", dt[i].x, dt[i].y);
				printf("(%d, %d)\n", dt[i].x1, dt[i].y1);
				continue;
			}
			if (dt[i].direct == 3) {
				printf("%d번째 우->좌 대각선 - ", dt[i].num);
				printf("(%d, %d) , ", dt[i].x, dt[i].y);
				printf("(%d, %d)\n", dt[i].x1, dt[i].y1);
				continue;
			}
		}
	}
	printf("==============================\n");
}
void hunsu(int p) {
	int n = 0;
	for (int i = 0; i < lr; i++) {
		if (p % 2 == 0) {
			if (dt[i].dol == 'X') {
				if (dt[i].cnt > 2 && dt[i].cnt < 5) {
					if (dt[i].direct == 0) {
						printf("%d번째 가로줄 - ", dt[i].num);
						if (dt[i].x > -1 && dt[i].y - 1 > -1) {
							printf("(%d, %d) , ", dt[i].x, dt[i].y - 1);
						}
						for (int j = dt[i].y; j < dt[i].y1; j++) {
							if (a[dt[i].x][j] == '*') {
								printf("(%d, %d) , ", dt[i].x, j);
							}
						}
						if (dt[i].x1 > -1 && dt[i].y1 + 1 > -1) {
							printf("(%d, %d)\n", dt[i].x1, dt[i].y1 + 1);
						}
					}
					if (dt[i].direct == 1) {
						printf("%d번째 세로줄 - ", dt[i].num);
						if (dt[i].x - 1 > -1 && dt[i].y > -1) {
							printf("(%d, %d) , ", dt[i].x - 1, dt[i].y);
						}
						for (int j = dt[i].x; j < dt[i].x1; j++) {
							if (a[j][dt[i].y] == '*') {
								printf("(%d, %d) , ", j, dt[i].y);
							}
						}
						if (dt[i].x1 + 1 > -1 && dt[i].y1 > -1) {
							printf("(%d, %d)\n", dt[i].x1 + 1, dt[i].y1);
						}
					}
					if (dt[i].direct == 2) {
						printf("%d번째 좌->우 대각선 - ", dt[i].num);
						if (dt[i].x - 1 > -1 && dt[i].y - 1 > -1) {
							printf("(%d, %d) , ", dt[i].x - 1, dt[i].y - 1);
						}
						for (int j = dt[i].x; j < dt[i].x1; j++) {
							if (a[j][dt[i].y + n] == '*') {
								printf("(%d, %d) , ", j, dt[i].y + n);
							}
							n++;
						}
						if (dt[i].x1 + 1 > -1 && dt[i].y1 + 1 > -1) {
							printf("(%d, %d)\n", dt[i].x1 + 1, dt[i].y1 + 1);
						}
						n = 0;
					}
					if (dt[i].direct == 3) {
						printf("%d번째 우->좌 대각선 - ", dt[i].num);
						if (dt[i].x - 1 > -1 && dt[i].y + 1 > -1) {
							printf("(%d, %d) , ", dt[i].x - 1, dt[i].y + 1);
						}
						for (int j = dt[i].x; j < dt[i].x1; j++) {
							if (a[j][dt[i].y - n] == '*') {
								printf("(%d, %d) , ", j, dt[i].y - n);
							}
							n++;
						}
						if (dt[i].x1 + 1 > -1 && dt[i].y1 - 1 > -1) {
							printf("(%d, %d)\n", dt[i].x1 + 1, dt[i].y1 - 1);
						}
						n = 0;
					}
				}
			}
		}
		else {
			if (dt[i].dol == 'O') {
				if (dt[i].cnt > 2 && dt[i].cnt < 5) {
					if (dt[i].direct == 0) {
						printf("%d번째 가로줄 - ", dt[i].num);
						if (dt[i].x > -1 && dt[i].y - 1 > -1) {
							printf("(%d, %d) , ", dt[i].x, dt[i].y - 1);
						}
						for (int j = dt[i].y; j < dt[i].y1; j++) {
							if (a[dt[i].x][j] == '*') {
								printf("(%d, %d) , ", dt[i].x, j);
							}
						}
						if (dt[i].x1 > -1 && dt[i].y1 + 1 > -1) {
							printf("(%d, %d)\n", dt[i].x1, dt[i].y1 + 1);
						}
					}
					if (dt[i].direct == 1) {
						printf("%d번째 세로줄 - ", dt[i].num);
						if (dt[i].x - 1 > -1 && dt[i].y > -1) {
							printf("(%d, %d) , ", dt[i].x - 1, dt[i].y);
						}
						for (int j = dt[i].x; j < dt[i].x1; j++) {
							if (a[j][dt[i].y] == '*') {
								printf("(%d, %d) , ", j, dt[i].y);
							}
						}
						if (dt[i].x1 + 1 > -1 && dt[i].y1 > -1) {
							printf("(%d, %d)\n", dt[i].x1 + 1, dt[i].y1);
						}
					}
					if (dt[i].direct == 2) {
						printf("%d번째 좌->우 대각선 - ", dt[i].num);
						if (dt[i].x - 1 > -1 && dt[i].y - 1 > -1) {
							printf("(%d, %d) , ", dt[i].x - 1, dt[i].y - 1);
						}
						for (int j = dt[i].x; j < dt[i].x1; j++) {
							if (a[j][dt[i].y + n] == '*') {
								printf("(%d, %d) , ", j, dt[i].y + n);
							}
							n++;
						}
						if (dt[i].x1 + 1 > -1 && dt[i].y1 + 1 > -1) {
							printf("(%d, %d)\n", dt[i].x1 + 1, dt[i].y1 + 1);
						}
						n = 0;
					}
					if (dt[i].direct == 3) {
						printf("%d번째 우->좌 대각선 - ", dt[i].num);
						if (dt[i].x - 1 > -1 && dt[i].y + 1 > -1) {
							printf("(%d, %d) , ", dt[i].x - 1, dt[i].y + 1);
						}
						for (int j = dt[i].x; j < dt[i].x1; j++) {
							if (a[j][dt[i].y - n] == '*') {
								printf("(%d, %d) , ", j, dt[i].y - n);
							}
							n++;
						}
						if (dt[i].x1 + 1 > -1 && dt[i].y1 - 1 > -1) {
							printf("(%d, %d)\n", dt[i].x1 + 1, dt[i].y1 - 1);
						}
						n = 0;
					}
				}
			}
		}
	}
}
int main() {
	int ment;
	int p = 0;
	init_stack();
	while (1) {
		ment = 0;
		int s = 0, f = 0, w = 0;
		int max = 1;
		map();
		printf("1.돌 놓기 2.연속 체크 3.훈수(하기전 연속 체크를 해주세요)\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			while (1) {
				printf("돌의 위치를 정해주세요 - ");
				scanf_s("%d %d", &f, &s);
				if (s > 18 || s < 0) {
					printf("잘못된 좌표입니다.\n");
					continue;
				}
				if (f > 18 || f < 0) {
					printf("잘못된 좌표입니다.\n");
					continue;
				}
				if (a[f][s] != '*') {
					printf("이미 돌이 놓여져있습니다.\n");
					continue;
				}
				break;
			}
			push(s, f, p);
			p++;
			break;
		case 2:
			lr = 0;
			dbgaro();
			dbsero();
			Ldegak();
			Rdegak();
			for (int i = 0; i < lr; i++) {
				if (dt[i].cnt >= max) {
					max = dt[i].cnt;
				}
			}
			many(max);
			break;
		case 3:
			hunsu(p);
			break;
		}
	}
}