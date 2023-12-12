#pragma once
int board_20201840063[19][19];
#define WHITE 1
#define BLACK -1
int black_turn = 0;
int white_turn = 0;
typedef struct omok {
	char stone = '+';//무슨 돌인지 확인
	int garo_line = 0; //연속된 돌 확인
	int sero_line = 0; //연속된 돌 확인
	int ldegak_line = 0;
	int rdegak_line = 0;
	int weight = 0;//가중치
	int garo3 = 0;
	int sero3 = 0;
	int rdegak3 = 0;
	int ldegak3 = 0;
	int gongbak = 0;
}omok;
omok stone[19][19];
struct dot {
	int x = 0;
	int y = 0;
	int x1 = 0;
	int y1 = 0;
	int cnt = 0;
	int direct = 0;
	int num = 0;
	char dol = NULL;
};
dot dt[300000];
int lr = 0;
int k = 0, k1 = 0;
int aa = 0, bb = 0; //돌의 좌표
int a = 0, s = 0;
int b = 0;
void garo() {
	int sp = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
 			if (check != stone[i][j].stone) {
				if (stone[i][j].stone == '+') {
					if (sp == 0) {
						sp++;
						k = j;
						if (j == 18) {
							if (check != '+') {
								check1 = check;
								count1 = count;
								ct = 1;
								x1 = i;
								y1 = j - 1;
								if (count1 > 1) {
									dt[lr].x = y1 - count1 + ct;
									dt[lr].y = x1;
									dt[lr].x1 = y1;
									dt[lr].y1 = x1;
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
							if (check != '+') {
								check1 = check;
								count1 = count;
								if (stone[i][j - 1].stone == '+') {
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
								if (check != '+') {
									check2 = check;
									count2 = count;
									if (stone[i][j - 1].stone == '+') {
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
						check = stone[i][j].stone;
						count = 1;
					}
				}
				else {
					sp = 0;
					if (count >= count1) {
						if (check != '+') {
							check1 = check;
							count1 = count;
							if (stone[i][j - 1].stone == '+') {
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
							if (check != '+') {
								check2 = check;
								count2 = count;
								if (stone[i][j - 1].stone == '+') {
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
					check = stone[i][j].stone;
					count = 1;
				}
			}
			else {
				if (check == '+') {
					sp = 0;
				}
				count++;
				if (j == 18) {
					if (check != '+') {
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
void sero() {
	int sp1 = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19; i++) {
			if (check != stone[i][j].stone) {
				if (stone[i][j].stone == '+') {
					if (sp1 == 0) {
						sp1++;
						k1 = i;
						if (i == 18) {
							if (check != '+') {
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
							if (check != '+') {
								check1 = check;
								count1 = count;
								if (stone[i - 1][j].stone == '+') {
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
								if (check != '+') {
									check2 = check;
									count2 = count;
									if (stone[i - 1][j].stone == '+') {
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
						check = stone[i][j].stone;
						count = 1;
					}
				}
				else {
					sp1 = 0;
					if (count >= count1) {
						if (check != '+') {
							check1 = check;
							count1 = count;
							if (stone[i - 1][j].stone == '+') {
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
							if (check != '+') {
								check2 = check;
								count2 = count;
								if (stone[i - 1][j].stone == '+') {
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
					check = stone[i][j].stone;
					count = 1;
				}
			}
			else {
				if (check == '+') {
					sp1 = 0;
				}
				count++;
				if (i == 18) {
					if (check != '+') {
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
	int check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int j = 17; j > 0; j--) {
		for (int i = j; i < 19; i++) {
			if (check != stone[i][g].stone) {
				if (stone[i][g].stone == '+') {
					if (sp == 0) {
						sp++;
						k = g;
						if (i == 18) {
							if (check != '+') {
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
							if (check != 0) {
								check1 = check;
								count1 = count;
								if (stone[i - 1][g - 1].stone == '+') {
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
								if (check != 0) {
									check2 = check;
									count2 = count;
									if (stone[i - 1][g - 1].stone == '+') {
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
						check = stone[i][g].stone;
						count = 1;
					}
				}
				else {
					sp = 0;
					if (count >= count1) {
						if (check != 0) {
							check1 = check;
							count1 = count;
							if (stone[i - 1][g - 1].stone == '+') {
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
							if (check != '+') {
								check2 = check;
								count2 = count;
								if (stone[i - 1][g - 1].stone == '+') {
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
					check = stone[i][g].stone;
					count = 1;
				}
			}
			else {
				if (check == '+') {
					sp = 0;
				}
				count++;
				if (i == 18) {
					if (check != '+') {
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
			if (check != stone[g][j].stone) {
				if (stone[g][j].stone == '+') {
					if (sp == 0) {
						sp++;
						k = g;
						n = j;
						if (j == 18) {
							if (check != '+') {
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
							if (check != '+') {
								check1 = check;
								count1 = count;
								if (stone[g - 1][j - 1].stone == '+') {
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
								if (check != '+') {
									check2 = check;
									count2 = count;
									if (stone[g - 1][j - 1].stone == '+') {
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
						check = stone[g][j].stone;
						count = 1;
					}
				}
				else {
					sp = 0;
					if (count >= count1) {
						if (check != '+') {
							check1 = check;
							count1 = count;
							if (stone[g - 1][j - 1].stone == '+') {
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
							if (check != '+') {
								check2 = check;
								count2 = count;
								if (stone[g - 1][j - 1].stone == '+') {
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
					check = stone[g][j].stone;
					count = 1;
				}
			}
			else {
				if (check == '+') {
					sp = 0;
				}
				count++;
				if (j == 18) {
					if (check != '+') {
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
	int check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	int ct = 0, ct1 = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i <= 18; i++) {
		for (int j = i; j >= 0; j--) {
			if (check != stone[g][j].stone) {
				if (stone[g][j].stone == '+') {
					if (sp1 == 0) {
						sp1++;
						k = g;
						if (0 == j) {
							if (check != '+') {
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
							if (check != '+') {
								check1 = check;
								count1 = count;
								if (stone[g - 1][j + 1].stone == '+') {
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
								if (check != '+') {
									check2 = check;
									count2 = count;
									if (stone[g - 1][j + 1].stone == '+') {
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
						check = stone[g][j].stone;
						count = 1;
					}
				}
				else {
					sp1 = 0;
					if (count >= count1) {
						if (check != '+') {
							check1 = check;
							count1 = count;
							if (stone[g - 1][j + 1].stone == '+') {
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
							if (check != '+') {
								check2 = check;
								count2 = count;
								if (stone[g - 1][j + 1].stone == '+') {
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
					check = stone[g][j].stone;
					count = 1;
				}
			}
			else {
				if (check == 0) {
					sp1 = 0;
				}
				count++;
				if (0 == j) {
					if (check != '+') {
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
			if (check != stone[i][g].stone) {
				if (stone[i][g].stone == '+') {
					if (sp1 == 0) {
						sp1++;
						k = g;
						n = i;
						if (i == 18) {
							if (check != '+') {
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
							if (check != '+') {
								check1 = check;
								count1 = count;
								if (stone[i - 1][g + 1].stone == '+') {
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
								if (check != '+') {
									check2 = check;
									count2 = count;
									if (stone[i - 1][g + 1].stone == '+') {
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
						check = stone[i][g].stone;
						count = 1;
					}
				}
				else {
					sp1 = 0;
					if (count > count1) {
						if (check != '+') {
							check1 = check;
							count1 = count;
							if (stone[i - 1][g + 1].stone == '+') {
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
							if (check != '+') {
								check2 = check;
								count2 = count;
								if (stone[i - 1][g + 1].stone == '+') {
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
					check = stone[i][g].stone;
					count = 1;
				}
			}
			else {
				if (check == '+') {
					sp1 = 0;
				}
				count++;
				if (i == 18) {
					if (check != '+') {
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
void gajungchi() {
	int n = 0;
	for (int i = 0;i < 19;i++) {
		for (int j = 0;j < 19;j++) {
			if (stone[i][j].stone != '+') {
				stone[i - 1][j - 1].weight = 10;
				stone[i - 1][j].weight = 10;
				stone[i - 1][j + 1].weight = 10;
				stone[i][j - 1].weight = 10;
				stone[i][j + 1].weight = 10;
				stone[i + 1][j - 1].weight = 10;
				stone[i + 1][j].weight = 10;
				stone[i + 1][j + 1].weight = 10;
			}
		}
	}
	for (int i = 0; i < lr; i++) {
		if (dt[i].cnt == 2) {
			if (dt[i].direct == 0) {
				if (dt[i].x > -1 && dt[i].y - 1 > -1) {
					if (stone[dt[i].y][dt[i].x - 1].weight < 50) {
						stone[dt[i].y][dt[i].x - 1].weight = 50;
					}
				}
				for (int j = dt[i].x; j < dt[i].x1; j++) {
					if (stone[dt[i].y][j].stone == 0) {
						if (stone[dt[i].y][j].weight < 50) {
							stone[dt[i].y][j].weight = 50;
						}
					}
				}
				if (dt[i].x1 > -1 && dt[i].y1 + 1 > -1) {
					if (stone[dt[i].y1][dt[i].x1 + 1].weight < 50) {
						stone[dt[i].y1][dt[i].x1 + 1].weight = 50;
					}
				}
			}
			if (dt[i].direct == 1) {
				if (dt[i].x - 1 > -1 && dt[i].y > -1) {
					if (stone[dt[i].y - 1][dt[i].x].weight < 50) {
						stone[dt[i].y - 1][dt[i].x].weight = 50;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x].stone == 0) {
						if (stone[j][dt[i].x].weight < 50) {
							stone[j][dt[i].x].weight = 50;
						}
					}
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1].weight < 50) {
						stone[dt[i].y1 + 1][dt[i].x1].weight = 50;
					}
				}
			}
			if (dt[i].direct == 2) {
				if (dt[i].x - 1 > -1 && dt[i].y - 1 > -1) {
					if (stone[dt[i].y - 1][dt[i].x - 1].weight < 50) {
						stone[dt[i].y - 1][dt[i].x - 1].weight = 50;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x + n].stone == 0) {
						if (stone[j][dt[i].x + n].weight < 50) {
							stone[j][dt[i].x + n].weight = 50;
						}
					}
					n++;
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 + 1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1 + 1].weight < 50) {
						stone[dt[i].y1 + 1][dt[i].x1 + 1].weight = 50;
					}
				}
				n = 0;
			}
			if (dt[i].direct == 3) {
				if (dt[i].x - 1 > -1 && dt[i].y + 1 > -1) {
					if (stone[dt[i].y - 1][dt[i].x + 1].weight < 50) {
						stone[dt[i].y - 1][dt[i].x + 1].weight = 50;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x - n].stone == 0) {
						if (stone[j][dt[i].x - n].weight < 50) {
							stone[j][dt[i].x - n].weight = 50;
						}
					}
					n++;
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 - 1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1 - 1].weight < 50) {
						stone[dt[i].y1 + 1][dt[i].x1 - 1].weight = 50;
					}
				}
				n = 0;
			}
		}
		if (dt[i].cnt == 3) {
			if (dt[i].direct == 0) {
				if (dt[i].x > -1 && dt[i].y - 1 > -1) {
					if (stone[dt[i].y][dt[i].x - 1].weight < 2500) {
						stone[dt[i].y][dt[i].x - 1].weight = 2500;
					}
				}
				for (int j = dt[i].x; j < dt[i].x1; j++) {
					if (stone[dt[i].y][j].stone == 0) {
						if (stone[dt[i].y][j].weight < 2500) {
							stone[dt[i].y][j].weight = 2500;
						}
					}
				}
				if (dt[i].x1 > -1 && dt[i].y1 + 1 > -1) {
					if (stone[dt[i].y1][dt[i].x1 + 1].weight < 2500) {
						stone[dt[i].y1][dt[i].x1 + 1].weight = 2500;
					}
				}
			}
			if (dt[i].direct == 1) {
				if (dt[i].x - 1 > -1 && dt[i].y > -1) {
					if (stone[dt[i].y - 1][dt[i].x].weight < 2500) {
						stone[dt[i].y - 1][dt[i].x].weight = 2500;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x].stone == 0) {
						if (stone[j][dt[i].x].weight < 2500) {
							stone[j][dt[i].x].weight = 2500;
						}
					}
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1].weight < 2500) {
						stone[dt[i].y1 + 1][dt[i].x1].weight = 2500;
					}
				}
			}
			if (dt[i].direct == 2) {
				if (dt[i].x - 1 > -1 && dt[i].y - 1 > -1) {
					if (stone[dt[i].y - 1][dt[i].x - 1].weight < 2500) {
						stone[dt[i].y - 1][dt[i].x - 1].weight = 2500;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x + n].stone == 0) {
						if (stone[j][dt[i].x + n].weight < 2500) {
							stone[j][dt[i].x + n].weight = 2500;
						}
					}
					n++;
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 + 1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1 + 1].weight < 2500) {
						stone[dt[i].y1 + 1][dt[i].x1 + 1].weight = 2500;
					}
				}
				n = 0;
			}
			if (dt[i].direct == 3) {
				if (dt[i].x - 1 > -1 && dt[i].y + 1 > -1) {
					if (stone[dt[i].y - 1][dt[i].x + 1].weight < 2500) {
						stone[dt[i].y - 1][dt[i].x + 1].weight = 2500;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x - n].stone == 0) {
						if (stone[j][dt[i].x - n].weight < 2500) {
							stone[j][dt[i].x - n].weight = 2500;
						}
					}
					n++;
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 - 1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1 - 1].weight < 2500) {
						stone[dt[i].y1 + 1][dt[i].x1 - 1].weight = 2500;
					}
				}
				n = 0;
			}
		}
		if (dt[i].cnt == 4) {
			if (dt[i].direct == 0) {
				if (dt[i].x > -1 && dt[i].y - 1 > -1) {
					if (stone[dt[i].y][dt[i].x - 1].weight < 125000) {
						stone[dt[i].y][dt[i].x - 1].weight = 125000;
					}
				}
				for (int j = dt[i].x; j < dt[i].x1; j++) {
					if (stone[dt[i].y][j].stone == 0) {
						if (stone[dt[i].y][j].weight < 125000) {
							stone[dt[i].y][j].weight = 125000;
						}
					}
				}
				if (dt[i].x1 > -1 && dt[i].y1 + 1 > -1) {
					if (stone[dt[i].y1][dt[i].x1 + 1].weight < 125000) {
						stone[dt[i].y1][dt[i].x1 + 1].weight = 125000;
					}
				}
			}
			if (dt[i].direct == 1) {
				if (dt[i].x - 1 > -1 && dt[i].y > -1) {
					if (stone[dt[i].y - 1][dt[i].x].weight < 125000) {
						stone[dt[i].y - 1][dt[i].x].weight = 125000;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x].stone == 0) {
						if (stone[j][dt[i].x].weight < 125000) {
							stone[j][dt[i].x].weight = 125000;
						}
					}
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1].weight < 125000) {
						stone[dt[i].y1 + 1][dt[i].x1].weight = 125000;
					}
				}
			}
			if (dt[i].direct == 2) {
				if (dt[i].x - 1 > -1 && dt[i].y - 1 > -1) {
					if (stone[dt[i].y - 1][dt[i].x - 1].weight < 125000) {
						stone[dt[i].y - 1][dt[i].x - 1].weight = 125000;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x + n].stone == 0) {
						if (stone[j][dt[i].x + n].weight < 125000) {
							stone[j][dt[i].x + n].weight = 125000;
						}
					}
					n++;
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 + 1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1 + 1].weight < 125000) {
						stone[dt[i].y1 + 1][dt[i].x1 + 1].weight = 125000;
					}
				}
				n = 0;
			}
			if (dt[i].direct == 3) {
				if (dt[i].x - 1 > -1 && dt[i].y + 1 > -1) {
					if (stone[dt[i].y - 1][dt[i].x + 1].weight < 125000) {
						stone[dt[i].y - 1][dt[i].x + 1].weight = 125000;
					}
				}
				for (int j = dt[i].y; j < dt[i].y1; j++) {
					if (stone[j][dt[i].x - n].stone == 0) {
						if (stone[j][dt[i].x - n].weight <125000) {
							stone[j][dt[i].x - n].weight = 125000;
						}
					}
					n++;
				}
				if (dt[i].x1 + 1 > -1 && dt[i].y1 - 1 > -1) {
					if (stone[dt[i].y1 + 1][dt[i].x1 - 1].weight < 125000) {
						stone[dt[i].y1 + 1][dt[i].x1 - 1].weight = 125000;
					}
				}
				n = 0;
			}
		}
	}
}
void AI() {
	int max = 0;
	aa = 0, bb = 0;
	garo(); //가로 체크
	sero(); //세로 체크
	Ldegak(); //좌대각 체크
	Rdegak(); //우대각 체크
	gajungchi();
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (stone[j][i].weight > max) {
				max = stone[j][i].weight;
			}
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (stone[j][i].stone == '+') {
				if (max == stone[j][i].weight) {
					bb = j;
					aa = i;
				}
			}
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			stone[j][i].weight = 0;
			stone[j][i].garo3 = 0;
			stone[j][i].sero3 = 0;
			stone[j][i].garo_line = 0;
			stone[j][i].sero_line = 0;
			stone[j][i].gongbak = 0;
		}
	}
	lr = 0;
}
void WhiteAttack_20201840063(int* x, int* y) {
	AI();
	*x = aa;
	*y = bb;
	if (white_turn == 0) {
		*x = s;
		*y = a;
		white_turn++;
	}
	stone[*y][*x].stone = 'W';
	board_20201840063[*y][*x] = 1;
}
void WhiteDefence_20201840063(int x, int y) {
	if (b == 0) {
		for (int i = 0;i < 19;i++) {
			for (int j = 0;j < 19;j++) {
				stone[i][j].stone = '+';
				stone[i][j].garo_line = 0;
				stone[i][j].ldegak_line = 0;
				stone[i][j].rdegak_line = 0;
				stone[i][j].sero_line = 0;
				stone[i][j].weight = 0;
				stone[i][j].gongbak = 0;
			}
		}
		b++;
	}
	a = y;
	s = x - 1;
	stone[y][x].stone = 'B';
	board_20201840063[y][x] = -1;
}
void BlackAttack_20201840063(int* x, int* y) {
	if (black_turn == 0) {
		if (b == 0) {
			for (int i = 0;i < 19;i++) {
				for (int j = 0;j < 19;j++) {
					stone[i][j].stone = '+';
					stone[i][j].garo_line = 0;
					stone[i][j].ldegak_line = 0;
					stone[i][j].rdegak_line = 0;
					stone[i][j].sero_line = 0;
					stone[i][j].weight = 0;
					stone[i][j].gongbak = 0;
				}
			}
			b++;
		}
		*x = 9; *y = 9;
		lr = 0;
		black_turn++;
	}
	else {
		AI();
		*x = aa;
		*y = bb;
	}
	stone[*y][*x].stone = 'B';
	board_20201840063[*y][*x] = -1;
}
void BlackDefence_20201840063(int x, int y) {
	stone[y][x].stone = 'W';
	board_20201840063[y][x] = 1;
}