#pragma once
#include<ctime>
int board_2020184003[19][19];
bool s_white = false;
//��		999
//������	-999
#define BLACK -999
#define WHITE 999

//���� ��밡 4���̴�? -5000
//���� 5����(����� ������ 4����) -7000
//��밡 3���̴�? -1500
//���� ������ 4�� - 50000
//���� 4���̴�? -30000
//���� 3���̴�? -50

void WhiteAttack_2020184003(int* x, int* y)
{
	srand(time(NULL));
	if (!s_white) {	//�����Ҷ� ��� ����
		do {
			*x = rand() % 3 + 8;
			*y = rand() % 3 + 8;
		} while (board_2020184003[*y][*x] == BLACK);
		s_white = true;
	}
	else {
		//��� 4�� ����ġ ����
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == BLACK) {
							continuity++;
							e_y = j;
							//Ȯ�� �ʿ�
							if (continuity > 4) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								for (int k = s_y; board_2020184003[i][k] == BLACK; ++k) {
									continuity = 0;
									j = k + 1;
								}
							}
							//Ȯ�� �ʿ�
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[i][j] == WHITE) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == BLACK) {
							continuity++;
							e_y = j;
							//
							if (continuity > 4) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								for (int k = s_y; board_2020184003[i][k] == BLACK; ++k) {
									continuity = 0;
									j = k + 1;
								}
							}
							//
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[j][i] == WHITE) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
		//�밢��
		{
			//������ 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == BLACK) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 4) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[k][j] == WHITE) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
			//������ 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
			//������  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k - 1) < 0) {
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
			//������ 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == BLACK) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[k][n] == WHITE) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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

		//��� 3�� ����ġ ����
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == BLACK) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[i][j] == WHITE) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 3�����϶�
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
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//�̹� 3�����϶�
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
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == BLACK) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[j][i] == WHITE) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
		//�밢��
		{
			//������ 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == BLACK) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[k][j] == WHITE) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
			//������ 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
			//������  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == BLACK) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
			//������ 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == BLACK) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[k][n] == WHITE) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
		//���� 4��
		{
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[i][j] == BLACK) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[j][i] == BLACK) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
			//�밢��
			{
				//������ 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == WHITE) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[k][j] == BLACK) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
				//������ 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
				//������  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k - 1) < 0) {
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
				//������ 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == WHITE) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[k][n] == BLACK) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
		//���� 3��
		{
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[i][j] == BLACK) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�
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
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�
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
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == WHITE) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[j][i] == BLACK) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�
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
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�
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
			//�밢��
			{
				//������ 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == WHITE) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[k][j] == BLACK) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�
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
				//������ 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�										
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�											
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
				//������  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == WHITE) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�										
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
										//Ȯ�� �ʿ�
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�										
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
				//������ 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == WHITE) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[k][n] == BLACK) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�										
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�												
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

		//�Ϲ� �� ����ġ ���
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
	// ��밡 ���� ���� ��ġ�� ���޹޾Ƽ� �����մϴ�
	board_2020184003[y][x] = BLACK;
}
void BlackAttack_2020184003(int* x, int* y)
{
	//�鵹�� 6�� ����, 5�̻� ���ƶ�
	if (board_2020184003[9][9] != BLACK) {	//�����Ҷ� ��� ����
		*x = *y = 9;
	}
	else {
		//��� 4�� ����ġ ����
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[i][j] == BLACK) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((j + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[j][i] == BLACK) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
		//�밢��
		{
			//������ 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == WHITE) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[k][j] == BLACK) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
			//������ 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
			//������  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k - 1) < 0) {
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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
			//������ 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == WHITE) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
							//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
							//		continuity = 0;
							//		j = k + 1;
							//	}
							//}
							if ((k + 1) > 18) {
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							if (board_2020184003[k][n] == BLACK) {	//���ٰ� �������� ��������
								if (continuity >= 4) {
									if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 4) {//�̹� 4�����϶�
									if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
									else {	//���� 4
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 4) {//�̹� 4�����϶�
											if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
											else {	//���� 4
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

		//��� 3�� ����ġ ����
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[i][j] == WHITE) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[i][j] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[i][j] == BLACK) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 3�����϶�
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
									if ((j + 1 <= 18) && board_2020184003[i][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//�̹� 3�����϶�
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
		//������
		{
			int continuity = 0;
			int s_y, e_y;	//������ ����
			for (int i = 0; i < 19; ++i) {
				continuity = 0;
				for (int j = 0; j < 19; ++j) {
					if (continuity == 0 && board_2020184003[j][i] == WHITE) {	//ó�� ���� ������ ��
						s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[j][i] == WHITE) {
							continuity++;
							e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[j][i] == BLACK) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									if ((j + 1 <= 18) && board_2020184003[j + 1][i] == WHITE) {//��ĭ ����ĭ�� ����϶�
										j++;
										continuity++;
										e_y = j;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
		//�밢��
		{
			//������ 17~ 0
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 17; i >= 0; --i) {
				continuity = 0; k = i;
				for (int j = 0; j <= n; ++j) {
					if (continuity == 0 && board_2020184003[k][j] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = j; e_y = j; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][j] == WHITE) {
							continuity++;
							e_x = k; e_y = j;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[k][j] == BLACK) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										j++;
										k++;
										continuity++;
										e_y = j;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
			//������ 1~ 18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 0;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										n++;
										k++;
										continuity++;
										e_y = n;
										e_x = k;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
			//������  1~ 19
			int continuity = 0;
			int s_x, e_x, s_y, e_y;
			int n = 1;
			int k;
			int l;
			for (int i = 1; i < 19; ++i) {
				continuity = 0; k = i; n = 0;
				for (k; k >= 0; --k) {
					if (continuity == 0 && board_2020184003[n][k] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = n; s_y = k; e_y = k; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[n][k] == WHITE) {
							continuity++;
							e_x = n; e_y = k;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[n][k] == BLACK) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										n++;
										k--;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
			//������ 1~18
			for (int i = 1; i < 18; ++i) {
				continuity = 0;
				k = i; n = 18;
				for (k; k < 19; ++k) {
					if (continuity == 0 && board_2020184003[k][n] == WHITE) {	//ó�� ���� ������ ��
						s_x = e_x = k; s_y = n; e_y = n; continuity++;
					}
					else if (continuity >= 1) {
						if (board_2020184003[k][n] == WHITE) {
							continuity++;
							e_x = k; e_y = n;
							//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
							if (board_2020184003[k][n] == BLACK) {	//���ٰ� �������� ��������
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
							else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
								if (continuity >= 3) {//�̹� 4�����϶�
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
									//Ȯ�� �ʿ�
									if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == WHITE) {//��ĭ ����ĭ�� ����϶�
										n--;
										k++;
										continuity++;
										e_y = k;
										e_x = n;
									}
									else {
										if (continuity >= 3) {//�̹� 4�����϶�
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
		//���� 4��
		{
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[i][j] == WHITE) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((j + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[j][i] == WHITE) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
			//�밢��
			{
				//������ 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == BLACK) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[k][j] == WHITE) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_x - s_x >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
				//������ 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (e_y - s_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
				//������  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k - 1) < 0) {
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (s_x - e_x >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
				//������ 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == BLACK) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
								//	for (int k = s_y; board_2020184003[i][k] == WHITE; ++k) {
								//		continuity = 0;
								//		j = k + 1;
								//	}
								//}
								if ((k + 1) > 18) {
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								if (board_2020184003[k][n] == WHITE) {	//���ٰ� �������� ��������
									if (continuity >= 4) {
										if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 4) {//�̹� 4�����϶�
										if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
										else {	//���� 4
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 4) {//�̹� 4�����϶�
												if (s_y - e_y >= 4) { //��ĭ ������ 4�̻�
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
												else {	//���� 4
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
		//���� 3��
		{
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[i][j] == BLACK) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[i][j] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[i][j] == WHITE) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[i][j] != BLACK && board_2020184003[i][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�
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
										if ((j + 1 <= 18) && board_2020184003[i][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�
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
			//������
			{
				int continuity = 0;
				int s_y, e_y;	//������ ����
				for (int i = 0; i < 19; ++i) {
					continuity = 0;
					for (int j = 0; j < 19; ++j) {
						if (continuity == 0 && board_2020184003[j][i] == BLACK) {	//ó�� ���� ������ ��
							s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[j][i] == BLACK) {
								continuity++;
								e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[j][i] == WHITE) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[j][i] != BLACK && board_2020184003[j][i] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�
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
										if ((j + 1 <= 18) && board_2020184003[j + 1][i] == BLACK) {//��ĭ ����ĭ�� ����϶�
											j++;
											continuity++;
											e_y = j;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�
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
			//�밢��
			{
				//������ 17~ 0
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 17; i >= 0; --i) {
					continuity = 0; k = i;
					for (int j = 0; j <= n; ++j) {
						if (continuity == 0 && board_2020184003[k][j] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = j; e_y = j; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][j] == BLACK) {
								continuity++;
								e_x = k; e_y = j;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[k][j] == WHITE) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[k][j] != BLACK && board_2020184003[k][j] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][j + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											j++;
											k++;
											continuity++;
											e_y = j;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�
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
				//������ 1~ 18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 0;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�										
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[n + 1][k + 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											n++;
											k++;
											continuity++;
											e_y = n;
											e_x = k;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�											
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
				//������  1~ 19
				int continuity = 0;
				int s_x, e_x, s_y, e_y;
				int n = 1;
				int k;
				int l;
				for (int i = 1; i < 19; ++i) {
					continuity = 0; k = i; n = 0;
					for (k; k >= 0; --k) {
						if (continuity == 0 && board_2020184003[n][k] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = n; s_y = k; e_y = k; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[n][k] == BLACK) {
								continuity++;
								e_x = n; e_y = k;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[n][k] == WHITE) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[n][k] != BLACK && board_2020184003[n][k] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�										
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
										//Ȯ�� �ʿ�
										if ((k - 1 >= 0) && board_2020184003[n + 1][k - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											n++;
											k--;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�										
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
				//������ 1~18
				for (int i = 1; i < 18; ++i) {
					continuity = 0;
					k = i; n = 18;
					for (k; k < 19; ++k) {
						if (continuity == 0 && board_2020184003[k][n] == BLACK) {	//ó�� ���� ������ ��
							s_x = e_x = k; s_y = n; e_y = n; continuity++;
						}
						else if (continuity >= 1) {
							if (board_2020184003[k][n] == BLACK) {
								continuity++;
								e_x = k; e_y = n;
								//if (continuity > 8) {//���� 4������ �Ѿ�� 6���̹Ƿ� ���� ���� ã�´�
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
								if (board_2020184003[k][n] == WHITE) {	//���ٰ� �������� ��������
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
								else if (board_2020184003[k][n] != BLACK && board_2020184003[k][n] != WHITE) {//��ĭ�� ������ ��
									if (continuity >= 3) {//�̹� 4�����϶�										
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
										//Ȯ�� �ʿ�
										if ((k + 1 <= 18) && board_2020184003[k + 1][n - 1] == BLACK) {//��ĭ ����ĭ�� ����϶�
											n--;
											k++;
											continuity++;
											e_y = k;
											e_x = n;
										}
										else {
											if (continuity >= 3) {//�̹� 4�����϶�												
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

		//�Ϲ� �� ����ġ ���
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
	// ��밡 ���� ���� ��ġ�� ���޹޾Ƽ� �����մϴ�
	board_2020184003[y][x] = WHITE;
}