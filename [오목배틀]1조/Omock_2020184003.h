#pragma once
#include<ctime>
int board_2020184003[19][19];
bool s_white = false;
//흰돌		999
//검은돌	-999
#define BLACK -999
#define WHITE 999

//만약 상대가 4줄이다? -5000
//만약 5연속(가운데가 떨어진 4개돌) -7000
//상대가 3줄이다? -1500
//내가 떨어진 4줄 - 50000
//내가 4줄이다? -30000
//내가 3줄이다? -50

void WhiteAttack_2020184003(int* x, int* y)
{
	srand(time(NULL));
	if (!s_white) {	//시작할때 가운데 착수
		do {
			*x = rand() % 3 + 8;
			*y = rand() % 3 + 8;
		} while (board_2020184003[*y][*x] == BLACK);
		s_white = true;
	}
	else {
		//상대 4줄 가중치 설정
		//가로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == BLACK) {
							continuity++;
							e_y = j;
							//확인 필요
							if (continuity > 4) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								for (int k = s_y; board_2020184003[i][k] == BLACK; ++k) {
									continuity = 0;
									j = k + 1;
								}
							}
							//확인 필요
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[i][j] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_y - s_y >= 4) { //한칸 떨어진 4이상
												for (int k = s_y; k <= e_y; ++k) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 7000;
													}
												}
												for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {	//붙은 4
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
															board_2020184003[i][k] -= 5000;
														}
													}
												}
												for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
										else {
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//세로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == BLACK) {
							continuity++;
							e_y = j;
							//
							if (continuity > 4) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								for (int k = s_y; board_2020184003[i][k] == BLACK; ++k) {
									continuity = 0;
									j = k + 1;
								}
							}
							//
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[j][i] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_y - s_y >= 4) { //한칸 떨어진 4이상
												for (int k = s_y; k <= e_y; ++k) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 7000;
													}
												}
												for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {	//붙은 4
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
															board_2020184003[k][i] -= 5000;
														}
													}
												}
												for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
										else {
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//대각선
		{
			//좌하향 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == BLACK) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 4) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][j] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_x - s_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_x - s_x >= 4) { //한칸 떨어진 4이상
												l = s_y;
												for (int q = s_x; q <= e_x; ++q) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 7000;
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
											else {	//붙은 4
												l = s_y - 1;
												for (int q = s_x - 1; q <= e_x + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 5000;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					k++;
				}
				n++;
			}
			//좌하향 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										l = s_x;
										for (int q = s_y; q <= e_y; ++q) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 7000;
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										l = s_x;
										for (int q = s_y; q <= e_y; ++q) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 7000;
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										l = s_x;
										for (int q = s_y; q <= e_y; ++q) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 7000;
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//빈칸 다음칸이 흰색일때
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_y - s_y >= 4) { //한칸 떨어진 4이상
												l = s_x;
												for (int q = s_y; q <= e_y; ++q) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 7000;
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
											else {	//붙은 4
												l = s_x - 1;
												for (int q = s_y - 1; q <= e_y + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 5000;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
		}
		{
			//우히향  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k - 1) < 0) {
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (s_x - e_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									//확인 필요
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//빈칸 다음칸이 흰색일때
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (s_x - e_x >= 4) { //한칸 떨어진 4이상
												l = s_y;
												for (int q = s_x; q <= e_x; ++q) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 7000;
													}
													l--;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
											else {	//붙은 4
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 5000;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
			//우하향 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == BLACK) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][n] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (s_y - e_y >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//빈칸 다음칸이 흰색일때
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (s_y - e_y >= 4) { //한칸 떨어진 4이상
												l = s_y;
												for (int q = s_x; q <= e_x; ++q) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 7000;
													}
													l--;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
											else {	//붙은 4
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 5000;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
								}
							}
						}
					}
					n--;
				}
			}
		}

		//상대 3줄 가중치 설정
		//가로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == BLACK) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[i][j] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 3연속일때
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//이미 3연속일때
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 1500;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//세로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == BLACK) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[j][i] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 1500;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//대각선
		{
			//좌하향 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == BLACK) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 3) {
									l = s_y - 1;
									for (int q = s_x - 1; q <= e_x + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][j] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_y - 1;
									for (int q = s_x - 1; q <= e_x + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_y - 1;
									for (int q = s_x - 1; q <= e_x + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 1500;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					k++;
				}
				n++;
			}
			//좌하향 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y - 1; q <= e_y + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y - 1; q <= e_y + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_x - 1;
									for (int q = s_y - 1; q <= e_y + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//빈칸 다음칸이 흰색일때
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 1500;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
		}
		{
			//우히향  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k - 1) < 0) {
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
								else {
									//확인 필요
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//빈칸 다음칸이 흰색일때
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 1500;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
			//우하향 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == BLACK) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][n] == WHITE) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//빈칸 다음칸이 흰색일때
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 1500;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
								}
							}
						}
					}
					n--;
				}
			}
		}
		//내가 4줄
		{
			//가로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[i][j] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_y - s_y >= 4) { //한칸 떨어진 4이상
													for (int k = s_y; k <= e_y; ++k) {
														if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
															board_2020184003[i][k] -= 50000;
														}
													}
													for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
												else {	//붙은 4
													for (int k = s_y - 1; k <= e_y + 1; ++k) {
														if (k >= 0 && k <= 18) {
															if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
																board_2020184003[i][k] -= 30000;
															}
														}
													}
													for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
											}
											else {
												for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//세로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[j][i] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_y - s_y >= 4) { //한칸 떨어진 4이상
													for (int k = s_y; k <= e_y; ++k) {
														if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
															board_2020184003[k][i] -= 50000;
														}
													}
													for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
												else {	//붙은 4
													for (int k = s_y - 1; k <= e_y + 1; ++k) {
														if (k >= 0 && k <= 18) {
															if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
																board_2020184003[k][i] -= 30000;
															}
														}
													}
													for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
											}
											else {
												for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//대각선
			{
				//좌하향 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == WHITE) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][j] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_x - s_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_x - s_x >= 4) { //한칸 떨어진 4이상
													l = s_y;
													for (int q = s_x; q <= e_x; ++q) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50000;
														}
														l++;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														j = l + 1;
														l++;
													}
												}
												else {	//붙은 4
													l = s_y - 1;
													for (int q = s_x - 1; q <= e_x + 1; ++q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
																board_2020184003[q][l] -= 30000;
															}
														}
														l++;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
														continuity = 0;
														k = q + 1;
														j = l + 1;
														l++;
													}
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						k++;
					}
					n++;
				}
				//좌하향 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											l = s_x;
											for (int q = s_y; q <= e_y; ++q) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50000;
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											l = s_x;
											for (int q = s_y; q <= e_y; ++q) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50000;
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											l = s_x;
											for (int q = s_y; q <= e_y; ++q) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50000;
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//빈칸 다음칸이 흰색일때
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_y - s_y >= 4) { //한칸 떨어진 4이상
													l = s_x;
													for (int q = s_y; q <= e_y; ++q) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50000;
														}
														l++;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l + 1;
														l++;
													}
												}
												else {	//붙은 4
													l = s_x - 1;
													for (int q = s_y - 1; q <= e_y + 1; ++q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
																board_2020184003[l][q] -= 30000;
															}
														}
														l++;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l + 1;
														l++;
													}
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
			}
			{
				//우히향  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k - 1) < 0) {
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (s_x - e_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										//확인 필요
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//빈칸 다음칸이 흰색일때
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (s_x - e_x >= 4) { //한칸 떨어진 4이상
													l = s_y;
													for (int q = s_x; q <= e_x; ++q) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50000;
														}
														l--;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
														continuity = 0;
														k = q - 1;
														n = l + 1;
														l++;
													}
												}
												else {	//붙은 4
													l = s_x - 1;
													for (int q = s_y + 1; q >= e_y - 1; --q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
																board_2020184003[l][q] -= 30000;
															}
														}
														l++;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
														continuity = 0;
														k = q - 1;
														n = l + 1;
														l++;
													}
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
				//우하향 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == WHITE) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][n] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (s_y - e_y >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//빈칸 다음칸이 흰색일때
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (s_y - e_y >= 4) { //한칸 떨어진 4이상
													l = s_y;
													for (int q = s_x; q <= e_x; ++q) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50000;
														}
														l--;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l - 1;
														l--;
													}
												}
												else {	//붙은 4
													l = s_x - 1;
													for (int q = s_y + 1; q >= e_y - 1; --q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
																board_2020184003[l][q] -= 30000;
															}
														}
														l++;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l - 1;
														l--;
													}
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
										}
									}
								}
							}
						}
						n--;
					}
				}
			}
		}
		//내가 3줄
		{
			//가로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[i][j] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
															board_2020184003[i][k] -= 50;
														}
													}
												}
												for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {
												for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//세로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[j][i] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
															board_2020184003[k][i] -= 50;
														}
													}
												}
												for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {
												for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//대각선
			{
				//좌하향 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == WHITE) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 3) {
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][j] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때
												l = s_y - 1;
												for (int q = s_x - 1; q <= e_x + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						k++;
					}
					n++;
				}
				//좌하향 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때										
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//빈칸 다음칸이 흰색일때
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때											
												l = s_x - 1;
												for (int q = s_y - 1; q <= e_y + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
			}
			{
				//우히향  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k - 1) < 0) {
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때										
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {
										//확인 필요
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//빈칸 다음칸이 흰색일때
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때										
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
				//우하향 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == WHITE) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][n] == BLACK) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때										
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//빈칸 다음칸이 흰색일때
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때												
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
										}
									}
								}
							}
						}
						n--;
					}
				}
			}
		}

		//일반 돌 가중치 계산
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (board_2020184003[j][i] == WHITE) {
					for (int n = i - 1; n <= i + 1; ++n) {
						if (n >= 0 && n <= 18) {
							for (int k = j - 1; k <= j + 1; ++k) {
								if (k >= 0 && k <= 18) {
									if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {
										board_2020184003[k][n]--;
									}
								}
							}
						}
					}
				}
				else if (board_2020184003[j][i] == BLACK) {
					for (int n = i - 1; n <= i + 1; ++n) {
						if (n >= 0 && n <= 18) {
							for (int k = j - 1; k <= j + 1; ++k) {
								if (k >= 0 && k <= 18) {
									if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {
										board_2020184003[k][n]++;
									}
								}
							}
						}
					}
				}
			}
		}
		int min = 0;
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE && min >= board_2020184003[j][i]) {
					min = board_2020184003[j][i];
				}
			}
		}
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (min == board_2020184003[j][i]) {
					*x = i; *y = j;
					break;
				}
			}
		}
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {
					board_2020184003[j][i] = 0;
				}
			}
		}
	}
	board_2020184003[*y][*x] = WHITE;
}
void WhiteDefence_2020184003(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2020184003[y][x] = BLACK;
}
void BlackAttack_2020184003(int* x, int* y)
{
	//백돌은 6목 가능, 5이상도 막아라
	if (board_2020184003[9][9] != BLACK) {	//시작할때 가운데 착수
		*x = *y = 9;
	}
	else {
		//상대 4줄 가중치 설정
		//가로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[i][j] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_y - s_y >= 4) { //한칸 떨어진 4이상
												for (int k = s_y; k <= e_y; ++k) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 7000;
													}
												}
												for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {	//붙은 4
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
															board_2020184003[i][k] -= 5000;
														}
													}
												}
												for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
										else {
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//세로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[j][i] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										for (int k = s_y; k <= e_y; ++k) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 7000;
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {	//붙은 4
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 5000;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_y - s_y >= 4) { //한칸 떨어진 4이상
												for (int k = s_y; k <= e_y; ++k) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 7000;
													}
												}
												for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {	//붙은 4
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
															board_2020184003[k][i] -= 5000;
														}
													}
												}
												for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
										else {
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//대각선
		{
			//좌하향 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == WHITE) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][j] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_x - s_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_x - s_x >= 4) { //한칸 떨어진 4이상
												l = s_y;
												for (int q = s_x; q <= e_x; ++q) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 7000;
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
											else {	//붙은 4
												l = s_y - 1;
												for (int q = s_x - 1; q <= e_x + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 5000;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					k++;
				}
				n++;
			}
			//좌하향 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										l = s_x;
										for (int q = s_y; q <= e_y; ++q) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 7000;
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										l = s_x;
										for (int q = s_y; q <= e_y; ++q) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 7000;
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (e_y - s_y >= 4) { //한칸 떨어진 4이상
										l = s_x;
										for (int q = s_y; q <= e_y; ++q) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 7000;
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//빈칸 다음칸이 흰색일때
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (e_y - s_y >= 4) { //한칸 떨어진 4이상
												l = s_x;
												for (int q = s_y; q <= e_y; ++q) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 7000;
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
											else {	//붙은 4
												l = s_x - 1;
												for (int q = s_y - 1; q <= e_y + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 5000;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
		}
		{
			//우히향  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k - 1) < 0) {
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (s_x - e_x >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else {
									//확인 필요
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//빈칸 다음칸이 흰색일때
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (s_x - e_x >= 4) { //한칸 떨어진 4이상
												l = s_y;
												for (int q = s_x; q <= e_x; ++q) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 7000;
													}
													l--;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
											else {	//붙은 4
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 5000;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
			//우하향 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == WHITE) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][n] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 4) {//이미 4연속일때
									if (s_y - e_y >= 4) { //한칸 떨어진 4이상
										l = s_y;
										for (int q = s_x; q <= e_x; ++q) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 7000;
											}
											l--;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {	//붙은 4
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 5000;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//빈칸 다음칸이 흰색일때
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//이미 4연속일때
											if (s_y - e_y >= 4) { //한칸 떨어진 4이상
												l = s_y;
												for (int q = s_x; q <= e_x; ++q) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 7000;
													}
													l--;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
											else {	//붙은 4
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 5000;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
								}
							}
						}
					}
					n--;
				}
			}
		}

		//상대 3줄 가중치 설정
		//가로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[i][j] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 3연속일때
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
												board_2020184003[i][k] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//이미 3연속일때
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 1500;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {
											for (int k = s_y; board_2020184003[i][k] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//세로줄
		{
			int continuity = 0;
			int s_y, e_y;	//시작점 끝점
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//처음 돌을 만났을 때
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
						}
						else {
							if (board_2020184003[j][i] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
							}
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									for (int k = s_y - 1; k <= e_y + 1; ++k) {
										if (k >= 0 && k <= 18) {
											if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
												board_2020184003[k][i] -= 1500;
											}
										}
									}
									for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
										continuity = 0;
										j = k + 1;
									}
								}
								else {
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//빈칸 다음칸이 흰색일때
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 1500;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {
											for (int k = s_y; board_2020184003[k][i] == WHITE && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//대각선
		{
			//좌하향 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == WHITE) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 3) {
									l = s_y - 1;
									for (int q = s_x - 1; q <= e_x + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][j] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_y - 1;
									for (int q = s_x - 1; q <= e_x + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_y - 1;
									for (int q = s_x - 1; q <= e_x + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
												board_2020184003[q][l] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
										continuity = 0;
										k = q + 1;
										j = l + 1;
										l++;
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//빈칸 다음칸이 흰색일때
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 1500;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					k++;
				}
				n++;
			}
			//좌하향 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y - 1; q <= e_y + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y - 1; q <= e_y + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_x - 1;
									for (int q = s_y - 1; q <= e_y + 1; ++q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l + 1;
										l++;
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//빈칸 다음칸이 흰색일때
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 1500;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
		}
		{
			//우히향  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k - 1) < 0) {
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
						}
						else {
							if (board_2020184003[n][k] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
								else {
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
							}
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_x;
									for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
										continuity = 0;
										k = q - 1;
										n = l + 1;
										l++;
									}
								}
								else {
									//확인 필요
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//빈칸 다음칸이 흰색일때
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 1500;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == WHITE && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
								}
							}
						}
					}
					n++;
				}
			}
			//우하향 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//처음 돌을 만났을 때
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == WHITE) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
						}
						else {
							if (board_2020184003[k][n] == BLACK) {	//가다가 검은돌을 만났을때
								if (continuity >= 3) {
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
								else {
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
							}
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
								if (continuity >= 3) {//이미 4연속일때
									l = s_x - 1;
									for (int q = s_y + 1; q >= e_y - 1; --q) {
										if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
											if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
												board_2020184003[l][q] -= 1500;
											}
										}
										l++;
									}
									l = s_y;
									for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
										continuity = 0;
										k = q + 1;
										n = l - 1;
										l--;
									}
								}
								else {
									//확인 필요
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//빈칸 다음칸이 흰색일때
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//이미 4연속일때
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 1500;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == WHITE && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
								}
							}
						}
					}
					n--;
				}
			}
		}
		//내가 4줄
		{
			//가로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[i][j] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
														board_2020184003[i][k] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_y - s_y >= 4) { //한칸 떨어진 4이상
													for (int k = s_y; k <= e_y; ++k) {
														if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
															board_2020184003[i][k] -= 50000;
														}
													}
													for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
												else {	//붙은 4
													for (int k = s_y - 1; k <= e_y + 1; ++k) {
														if (k >= 0 && k <= 18) {
															if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
																board_2020184003[i][k] -= 30000;
															}
														}
													}
													for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
											}
											else {
												for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//세로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[j][i] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											for (int k = s_y; k <= e_y; ++k) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50000;
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
										else {	//붙은 4
											for (int k = s_y - 1; k <= e_y + 1; ++k) {
												if (k >= 0 && k <= 18) {
													if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
														board_2020184003[k][i] -= 30000;
													}
												}
											}
											for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
												continuity = 0;
												j = k + 1;
											}
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_y - s_y >= 4) { //한칸 떨어진 4이상
													for (int k = s_y; k <= e_y; ++k) {
														if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
															board_2020184003[k][i] -= 50000;
														}
													}
													for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
												else {	//붙은 4
													for (int k = s_y - 1; k <= e_y + 1; ++k) {
														if (k >= 0 && k <= 18) {
															if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
																board_2020184003[k][i] -= 30000;
															}
														}
													}
													for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
														continuity = 0;
														j = k + 1;
													}
												}
											}
											else {
												for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//대각선
			{
				//좌하향 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == BLACK) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][j] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_x - s_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_y - 1;
											for (int q = s_x - 1; q <= e_x + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
														board_2020184003[q][l] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
												continuity = 0;
												k = q + 1;
												j = l + 1;
												l++;
											}
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_x - s_x >= 4) { //한칸 떨어진 4이상
													l = s_y;
													for (int q = s_x; q <= e_x; ++q) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50000;
														}
														l++;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														j = l + 1;
														l++;
													}
												}
												else {	//붙은 4
													l = s_y - 1;
													for (int q = s_x - 1; q <= e_x + 1; ++q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
																board_2020184003[q][l] -= 30000;
															}
														}
														l++;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
														continuity = 0;
														k = q + 1;
														j = l + 1;
														l++;
													}
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						k++;
					}
					n++;
				}
				//좌하향 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											l = s_x;
											for (int q = s_y; q <= e_y; ++q) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50000;
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											l = s_x;
											for (int q = s_y; q <= e_y; ++q) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50000;
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (e_y - s_y >= 4) { //한칸 떨어진 4이상
											l = s_x;
											for (int q = s_y; q <= e_y; ++q) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50000;
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y - 1; q <= e_y + 1; ++q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//빈칸 다음칸이 흰색일때
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (e_y - s_y >= 4) { //한칸 떨어진 4이상
													l = s_x;
													for (int q = s_y; q <= e_y; ++q) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50000;
														}
														l++;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l + 1;
														l++;
													}
												}
												else {	//붙은 4
													l = s_x - 1;
													for (int q = s_y - 1; q <= e_y + 1; ++q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
																board_2020184003[l][q] -= 30000;
															}
														}
														l++;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l + 1;
														l++;
													}
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
			}
			{
				//우히향  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k - 1) < 0) {
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (s_x - e_x >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_x;
											for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
												continuity = 0;
												k = q - 1;
												n = l + 1;
												l++;
											}
										}
									}
									else {
										//확인 필요
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//빈칸 다음칸이 흰색일때
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (s_x - e_x >= 4) { //한칸 떨어진 4이상
													l = s_y;
													for (int q = s_x; q <= e_x; ++q) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50000;
														}
														l--;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
														continuity = 0;
														k = q - 1;
														n = l + 1;
														l++;
													}
												}
												else {	//붙은 4
													l = s_x - 1;
													for (int q = s_y + 1; q >= e_y - 1; --q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
																board_2020184003[l][q] -= 30000;
															}
														}
														l++;
													}
													l = s_x;
													for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
														continuity = 0;
														k = q - 1;
														n = l + 1;
														l++;
													}
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
				//우하향 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == BLACK) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][n] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 4) {//이미 4연속일때
										if (s_y - e_y >= 4) { //한칸 떨어진 4이상
											l = s_y;
											for (int q = s_x; q <= e_x; ++q) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50000;
												}
												l--;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
										else {	//붙은 4
											l = s_x - 1;
											for (int q = s_y + 1; q >= e_y - 1; --q) {
												if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
													if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
														board_2020184003[l][q] -= 30000;
													}
												}
												l++;
											}
											l = s_y;
											for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
												continuity = 0;
												k = q + 1;
												n = l - 1;
												l--;
											}
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//빈칸 다음칸이 흰색일때
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//이미 4연속일때
												if (s_y - e_y >= 4) { //한칸 떨어진 4이상
													l = s_y;
													for (int q = s_x; q <= e_x; ++q) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50000;
														}
														l--;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l - 1;
														l--;
													}
												}
												else {	//붙은 4
													l = s_x - 1;
													for (int q = s_y + 1; q >= e_y - 1; --q) {
														if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
															if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
																board_2020184003[l][q] -= 30000;
															}
														}
														l++;
													}
													l = s_y;
													for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
														continuity = 0;
														k = q + 1;
														n = l - 1;
														l--;
													}
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
										}
									}
								}
							}
						}
						n--;
					}
				}
			}
		}
		//내가 3줄
		{
			//가로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[i][j] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
													board_2020184003[i][k] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[i][k] != BLACK && board_2020184003[i][k] != WHITE) {
															board_2020184003[i][k] -= 50;
														}
													}
												}
												for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {
												for (int k = s_y; board_2020184003[i][k] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//세로줄
			{
				int continuity = 0;
				int s_y, e_y;	//시작점 끝점
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//처음 돌을 만났을 때
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
							}
							else {
								if (board_2020184003[j][i] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
								}
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때
										for (int k = s_y - 1; k <= e_y + 1; ++k) {
											if (k >= 0 && k <= 18) {
												if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
													board_2020184003[k][i] -= 50;
												}
											}
										}
										for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
											continuity = 0;
											j = k + 1;
										}
									}
									else {
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//빈칸 다음칸이 흰색일때
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때
												for (int k = s_y - 1; k <= e_y + 1; ++k) {
													if (k >= 0 && k <= 18) {
														if (board_2020184003[k][i] != BLACK && board_2020184003[k][i] != WHITE) {
															board_2020184003[k][i] -= 50;
														}
													}
												}
												for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
											else {
												for (int k = s_y; board_2020184003[k][i] == BLACK && k <= 18; ++k) {
													continuity = 0;
													j = k + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//대각선
			{
				//좌하향 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == BLACK) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 3) {
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][j] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때
										l = s_y - 1;
										for (int q = s_x - 1; q <= e_x + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
													board_2020184003[q][l] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
											continuity = 0;
											k = q + 1;
											j = l + 1;
											l++;
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//빈칸 다음칸이 흰색일때
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때
												l = s_y - 1;
												for (int q = s_x - 1; q <= e_x + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[q][l] != BLACK && board_2020184003[q][l] != WHITE) {
															board_2020184003[q][l] -= 50;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && k <= 18; ++k) {
													continuity = 0;
													k = q + 1;
													j = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						k++;
					}
					n++;
				}
				//좌하향 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때										
										l = s_x - 1;
										for (int q = s_y - 1; q <= e_y + 1; ++q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l + 1;
											l++;
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//빈칸 다음칸이 흰색일때
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때											
												l = s_x - 1;
												for (int q = s_y - 1; q <= e_y + 1; ++q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
			}
			{
				//우히향  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k - 1) < 0) {
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
							}
							else {
								if (board_2020184003[n][k] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
								}
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때										
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_x;
										for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
											continuity = 0;
											k = q - 1;
											n = l + 1;
											l++;
										}
									}
									else {
										//확인 필요
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//빈칸 다음칸이 흰색일때
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때										
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50;
														}
													}
													l++;
												}
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
											else {
												l = s_x;
												for (int q = s_y; board_2020184003[l][q] == BLACK && q >= 0; --q) {
													continuity = 0;
													k = q - 1;
													n = l + 1;
													l++;
												}
											}
										}
									}
								}
							}
						}
						n++;
					}
				}
				//우하향 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//처음 돌을 만났을 때
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == BLACK) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//만약 4연속이 넘어가면 6돌이므로 다음 흰돌을 찾는다
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
							}
							else {
								if (board_2020184003[k][n] == WHITE) {	//가다가 검은돌을 만났을때
									if (continuity >= 3) {
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
								}
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//빈칸을 만났을 때
									if (continuity >= 3) {//이미 4연속일때										
										l = s_x - 1;
										for (int q = s_y + 1; q >= e_y - 1; --q) {
											if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
												if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
													board_2020184003[l][q] -= 50;
												}
											}
											l++;
										}
										l = s_y;
										for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
											continuity = 0;
											k = q + 1;
											n = l - 1;
											l--;
										}
									}
									else {
										//확인 필요
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//빈칸 다음칸이 흰색일때
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//이미 4연속일때												
												l = s_x - 1;
												for (int q = s_y + 1; q >= e_y - 1; --q) {
													if (q >= 0 && q <= 18 && l >= 0 && l <= 18) {
														if (board_2020184003[l][q] != BLACK && board_2020184003[l][q] != WHITE) {
															board_2020184003[l][q] -= 50;
														}
													}
													l++;
												}
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
											else {
												l = s_y;
												for (int q = s_x; board_2020184003[q][l] == BLACK && q <= 18; ++q) {
													continuity = 0;
													k = q + 1;
													n = l - 1;
													l--;
												}
											}
										}
									}
								}
							}
						}
						n--;
					}
				}
			}
		}

		//일반 돌 가중치 계산
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (board_2020184003[j][i] == BLACK) {
					for (int n = i - 1; n <= i + 1; ++n) {
						if (n >= 0 && n <= 18) {
							for (int k = j - 1; k <= j + 1; ++k) {
								if (k >= 0 && k <= 18) {
									if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {
										board_2020184003[k][n]--;
									}
								}
							}
						}
					}
				}
				else if (board_2020184003[j][i] == WHITE) {
					for (int n = i - 1; n <= i + 1; ++n) {
						if (n >= 0 && n <= 18) {
							for (int k = j - 1; k <= j + 1; ++k) {
								if (k >= 0 && k <= 18) {
									if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {
										board_2020184003[k][n]++;
									}
								}
							}
						}
					}
				}
			}
		}
		int min = 0;
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE && min >= board_2020184003[j][i]) {
					min = board_2020184003[j][i];
				}
			}
		}
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (min == board_2020184003[j][i]) {
					*x = i; *y = j;
					break;
				}
			}
		}
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {
					board_2020184003[j][i] = 0;
				}
			}
		}
	}
	board_2020184003[*y][*x] = BLACK;
}
void BlackDefence_2020184003(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2020184003[y][x] = WHITE;
}