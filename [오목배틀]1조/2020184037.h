#pragma once
int board_2020184037[19][19];
//��		1
//������	-1
#define BLACK -1
#define WHITE 1
void way(int bp[][19], int y, int x);
typedef struct _Check {
	int stone;
	int way[4];		//���ӵ� ���� ������ ���° ������(1~4)
	int maxstone;	//�ִ� ��� ���� �ִ���
	int plusCheck;	//���ӵ� �� ���� ��ĭ üũ(��ȸ��)
	int plus[4];		//���ӵ� �� ���� ��ĭ üũ
	int weight;		//����ġ
	int check;
	int plusX[4];
	int plusY[4];
	int def[4];//wayn�� �������� ���� 0�̸� �ȸ��� 1�̸� �ϳ� ���� 2�� �ٸ���
}Check;
Check pan_2020184037[19][19];
static int way1Check;
static int way2Check;
static int way3Check;
static int way4Check;
static int UnchangeX;// ������ �ʴ� x ��(��üũ ����Լ��� ���� x,y���� �ٲ�Ƿ� ����ϴ� ����)
static int UnchangeY;// ������ �ʴ� y ��
void WhiteAttack_2020184037(int* x, int* y) //���� �� �϶� ���� ���� �˰��� 
{
	// ���� �����Ͻ� �� ���� ������ �־��ּ���
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j�� x i�� y
			pan_2020184037[i][j].stone = board_2020184037[i][j];
			way1Check = 0;
			way2Check = 0;
			way3Check = 0;
			way4Check = 0;
			UnchangeX = j;
			UnchangeY = i;
			way(board_2020184037, i, j);

		}
	}
	//����ġ ���̱�(�鵹 ����)
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j�� x i�� y
			if (pan_2020184037[i][j].stone == -1) {//�鵹�� ����
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//���� 1
					{
						if (pan_2020184037[i - 1][j - 1].weight < 20)
							pan_2020184037[i - 1][j - 1].weight = 20;

						if (pan_2020184037[i - 1][j].weight < 20)
							pan_2020184037[i - 1][j].weight = 20;

						if (pan_2020184037[i - 1][j + 1].weight < 20)
							pan_2020184037[i - 1][j + 1].weight = 20;

						if (pan_2020184037[i][j - 1].weight < 20)
							pan_2020184037[i][j + 1].weight = 20;

						if (pan_2020184037[i + 1][j + 1].weight < 20)
							pan_2020184037[i + 1][j + 1].weight = 20;

						if (pan_2020184037[i + 1][j].weight < 20)
							pan_2020184037[i + 1][j].weight = 20;

						if (pan_2020184037[i + 1][j - 1].weight < 20)
							pan_2020184037[i + 1][j - 1].weight = 20;

						if (pan_2020184037[i][j - 1].weight < 20)
							pan_2020184037[i][j - 1].weight = 20;

					}

					break;
				case 2:
					if (pan_2020184037[i][j].way[0])//way1
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].weight < 40)
									pan_2020184037[i - 3][j + 3].weight = 40;
								if (pan_2020184037[i + 1][j - 1].weight < 40)
									pan_2020184037[i + 1][j - 1].weight = 40;
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].weight < 40)
									pan_2020184037[i - 2][j + 2].weight = 40;
								if (pan_2020184037[i + 1][j - 1].weight < 40)
									pan_2020184037[i + 1][j - 1].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)//��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else//�ٸ����� ��������
								{
									if (pan_2020184037[i - 3][j + 3].weight < 30)
										pan_2020184037[i - 3][j + 3].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].stone == 1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i - 2][j + 2].weight < 30)
										pan_2020184037[i - 2][j + 2].weight = 30;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])//way2
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].weight < 40)
									pan_2020184037[i][j + 3].weight = 40;
								if (pan_2020184037[i][j - 1].weight < 40)
									pan_2020184037[i][j - 1].weight = 40;
							}
							else
							{
								if (pan_2020184037[i][j + 2].weight < 40)
									pan_2020184037[i][j + 2].weight = 40;
								if (pan_2020184037[i][j - 1].weight < 40)
									pan_2020184037[i][j - 1].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == 1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 30)
										pan_2020184037[i][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 30)
										pan_2020184037[i][j + 3].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 2].stone == 1)
								{
									if (pan_2020184037[i][j - 1].weight < 30)
										pan_2020184037[i][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i][j + 2].weight < 30)
										pan_2020184037[i][j + 2].weight = 30;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])//way3
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].weight < 40)
									pan_2020184037[i + 3][j + 3].weight = 40;
								if (pan_2020184037[i - 1][j - 1].weight < 40)
									pan_2020184037[i - 1][j - 1].weight = 40;
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].weight < 40)
									pan_2020184037[i + 2][j + 2].weight = 40;
								if (pan_2020184037[i - 1][j - 1].weight < 40)
									pan_2020184037[i - 1][j - 1].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)//��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 30)
										pan_2020184037[i - 1][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 30)
										pan_2020184037[i + 3][j + 3].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].stone == 1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 30)
										pan_2020184037[i - 1][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 2][j + 2].weight < 30)
										pan_2020184037[i + 2][j + 2].weight = 30;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])//way4
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].weight < 40)
									pan_2020184037[i + 3][j].weight = 40;
								if (pan_2020184037[i - 1][j].weight < 40)
									pan_2020184037[i - 1][j].weight = 40;
							}
							else
							{
								if (pan_2020184037[i + 2][j].weight < 40)
									pan_2020184037[i + 2][j].weight = 40;
								if (pan_2020184037[i - 1][j].weight < 40)
									pan_2020184037[i - 1][j].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == 1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 30)
										pan_2020184037[i - 1][j].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 30)
										pan_2020184037[i + 3][j].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j].stone == 1)
								{
									if (pan_2020184037[i - 1][j].weight < 30)
										pan_2020184037[i - 1][j].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 2][j].weight < 30)
										pan_2020184037[i + 2][j].weight = 30;
								}
							}
						}
					}



					break;
				case 3:
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].weight < 400)
									pan_2020184037[i - 4][j + 4].weight = 400;
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].weight < 400)
									pan_2020184037[i - 3][j + 3].weight = 400;
							}
							if (pan_2020184037[i + 1][j - 1].weight < 400)
								pan_2020184037[i + 1][j - 1].weight = 400;
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 60)
										pan_2020184037[i + 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 60)
										pan_2020184037[i - 4][j + 4].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 60)
										pan_2020184037[i + 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i - 3][j + 3].weight < 60)
										pan_2020184037[i - 3][j + 3].weight = 60;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].weight < 400)
									pan_2020184037[i][j + 4].weight = 400;
							}
							else
							{
								if (pan_2020184037[i][j + 3].weight < 400)
									pan_2020184037[i][j + 3].weight = 400;
							}
							if (pan_2020184037[i][j - 1].weight < 400)
								pan_2020184037[i][j - 1].weight = 400;
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == 1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 60)
										pan_2020184037[i][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 60)
										pan_2020184037[i][j + 4].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 3].stone == 1)
								{
									if (pan_2020184037[i][j - 1].weight < 60)
										pan_2020184037[i][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 60)
										pan_2020184037[i][j + 3].weight = 60;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].weight < 400)
									pan_2020184037[i + 4][j + 4].weight = 400;
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].weight < 400)
									pan_2020184037[i + 3][j + 3].weight = 400;
							}
							if (pan_2020184037[i - 1][j - 1].weight < 400)
								pan_2020184037[i - 1][j - 1].weight = 400;
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)//��������
								{
									if (pan_2020184037[i - 1][j - 1].weight < 60)
										pan_2020184037[i - 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 60)
										pan_2020184037[i + 4][j + 4].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 60)
										pan_2020184037[i - 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 60)
										pan_2020184037[i + 3][j + 3].weight = 60;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].weight < 400)
									pan_2020184037[i + 4][j].weight = 400;
							}
							else
							{
								if (pan_2020184037[i + 3][j].weight < 400)
									pan_2020184037[i + 3][j].weight = 400;
							}
							if (pan_2020184037[i - 1][j].weight < 400)
								pan_2020184037[i - 1][j].weight = 400;
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == 1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 60)
										pan_2020184037[i - 1][j].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 60)
										pan_2020184037[i + 4][j].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j].stone == 1)
								{
									if (pan_2020184037[i - 1][j].weight < 60)
										pan_2020184037[i - 1][j].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 60)
										pan_2020184037[i + 3][j].weight = 60;
								}
							}
						}
					}
					break;
				case 4:
					//��ĭ ���� ���� �簡 ������ �̹� ������������ ���� ��� ��ĭ�ִ� �����縸 ������
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 600)
										pan_2020184037[i + 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i - 5][j + 5].weight < 600)
										pan_2020184037[i - 5][j + 5].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 600)
										pan_2020184037[i + 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 600)
										pan_2020184037[i - 4][j + 4].weight = 600;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])//�� ������ ������
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i][j - 1].weight < 600)
										pan_2020184037[i][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i][j + 5].weight < 600)
										pan_2020184037[i][j + 5].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 4].stone == 1)
								{
									if (pan_2020184037[i][j - 1].weight < 600)
										pan_2020184037[i][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 600)
										pan_2020184037[i][j + 4].weight = 600;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 600)
										pan_2020184037[i - 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 5][j + 5].weight < 600)
										pan_2020184037[i + 5][j + 5].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 600)
										pan_2020184037[i - 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 600)
										pan_2020184037[i + 4][j + 4].weight = 600;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i - 1][j].weight < 600)
										pan_2020184037[i - 1][j].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 5][j].weight < 600)
										pan_2020184037[i + 5][j].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i + 4][j].stone == 1)
								{
									if (pan_2020184037[i - 1][j].weight < 600)
										pan_2020184037[i - 1][j].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 600)
										pan_2020184037[i + 4][j].weight = 600;
								}

							}
						}
					}

					break;

				default:
					break;
				}
			}
			else if (pan_2020184037[i][j].stone == 1)//�鵹�϶� ����
			{
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//���� 1
					{
						if (pan_2020184037[i - 1][j - 1].weight < 30)
							pan_2020184037[i - 1][j - 1].weight = 30;

						if (pan_2020184037[i - 1][j].weight < 30)
							pan_2020184037[i - 1][j].weight = 30;

						if (pan_2020184037[i - 1][j + 1].weight < 30)
							pan_2020184037[i - 1][j + 1].weight = 30;

						if (pan_2020184037[i][j - 1].weight < 30)
							pan_2020184037[i][j + 1].weight = 30;

						if (pan_2020184037[i + 1][j + 1].weight < 30)
							pan_2020184037[i + 1][j + 1].weight = 30;

						if (pan_2020184037[i + 1][j].weight < 30)
							pan_2020184037[i + 1][j].weight = 30;

						if (pan_2020184037[i + 1][j - 1].weight < 30)
							pan_2020184037[i + 1][j - 1].weight = 30;

						if (pan_2020184037[i][j - 1].weight < 30)
							pan_2020184037[i][j - 1].weight = 30;

					}

					break;
				case 2:
					if (pan_2020184037[i][j].way[0])//way1
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].weight < 50)
									pan_2020184037[i - 3][j + 3].weight = 50;
								if (pan_2020184037[i + 1][j - 1].weight < 50)
									pan_2020184037[i + 1][j - 1].weight = 50;
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].weight < 50)
									pan_2020184037[i - 2][j + 2].weight = 50;
								if (pan_2020184037[i + 1][j - 1].weight < 50)
									pan_2020184037[i + 1][j - 1].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)//��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else//�ٸ����� ��������
								{
									if (pan_2020184037[i - 3][j + 3].weight < 40)
										pan_2020184037[i - 3][j + 3].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].stone == -1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i - 2][j + 2].weight < 40)
										pan_2020184037[i - 2][j + 2].weight = 40;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])//way2
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].weight < 50)
									pan_2020184037[i][j + 3].weight = 50;
								if (pan_2020184037[i][j - 1].weight < 50)
									pan_2020184037[i][j - 1].weight = 50;
							}
							else
							{
								if (pan_2020184037[i][j + 2].weight < 50)
									pan_2020184037[i][j + 2].weight = 50;
								if (pan_2020184037[i][j - 1].weight < 50)
									pan_2020184037[i][j - 1].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == -1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 40)
										pan_2020184037[i][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 40)
										pan_2020184037[i][j + 3].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 2].stone == -1)
								{
									if (pan_2020184037[i][j - 1].weight < 40)
										pan_2020184037[i][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i][j + 2].weight < 40)
										pan_2020184037[i][j + 2].weight = 40;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])//way3
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].weight < 50)
									pan_2020184037[i + 3][j + 3].weight = 50;
								if (pan_2020184037[i - 1][j - 1].weight < 50)
									pan_2020184037[i - 1][j - 1].weight = 50;
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].weight < 50)
									pan_2020184037[i + 2][j + 2].weight = 50;
								if (pan_2020184037[i - 1][j - 1].weight < 50)
									pan_2020184037[i - 1][j - 1].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)//��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 40)
										pan_2020184037[i - 1][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 40)
										pan_2020184037[i + 3][j + 3].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].stone == -1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 40)
										pan_2020184037[i - 1][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 2][j + 2].weight < 40)
										pan_2020184037[i + 2][j + 2].weight = 40;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])//way4
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].weight < 50)
									pan_2020184037[i + 3][j].weight = 50;
								if (pan_2020184037[i - 1][j].weight < 50)
									pan_2020184037[i - 1][j].weight = 50;
							}
							else
							{
								if (pan_2020184037[i + 2][j].weight < 50)
									pan_2020184037[i + 2][j].weight = 50;
								if (pan_2020184037[i - 1][j].weight < 50)
									pan_2020184037[i - 1][j].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == -1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 40)
										pan_2020184037[i - 1][j].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 40)
										pan_2020184037[i + 3][j].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j].stone == -1)
								{
									if (pan_2020184037[i - 1][j].weight < 40)
										pan_2020184037[i - 1][j].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 2][j].weight < 40)
										pan_2020184037[i + 2][j].weight = 40;
								}
							}
						}
					}



					break;
				case 3:
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].weight < 410)
									pan_2020184037[i - 4][j + 4].weight = 410;
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].weight < 410)
									pan_2020184037[i - 3][j + 3].weight = 410;
							}
							if (pan_2020184037[i + 1][j - 1].weight < 410)
								pan_2020184037[i + 1][j - 1].weight = 410;
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 70)
										pan_2020184037[i + 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 70)
										pan_2020184037[i - 4][j + 4].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 70)
										pan_2020184037[i + 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i - 3][j + 3].weight < 70)
										pan_2020184037[i - 3][j + 3].weight = 70;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].weight < 410)
									pan_2020184037[i][j + 4].weight = 410;
							}
							else
							{
								if (pan_2020184037[i][j + 3].weight < 410)
									pan_2020184037[i][j + 3].weight = 410;
							}
							if (pan_2020184037[i][j - 1].weight < 410)
								pan_2020184037[i][j - 1].weight = 410;
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == -1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 70)
										pan_2020184037[i][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 70)
										pan_2020184037[i][j + 4].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 3].stone == -1)
								{
									if (pan_2020184037[i][j - 1].weight < 70)
										pan_2020184037[i][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 70)
										pan_2020184037[i][j + 3].weight = 70;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].weight < 410)
									pan_2020184037[i + 4][j + 4].weight = 410;
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].weight < 410)
									pan_2020184037[i + 3][j + 3].weight = 410;
							}
							if (pan_2020184037[i - 1][j - 1].weight < 410)
								pan_2020184037[i - 1][j - 1].weight = 410;
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)//��������
								{
									if (pan_2020184037[i - 1][j - 1].weight < 70)
										pan_2020184037[i - 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 70)
										pan_2020184037[i + 4][j + 4].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 70)
										pan_2020184037[i - 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 70)
										pan_2020184037[i + 3][j + 3].weight = 70;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].weight < 410)
									pan_2020184037[i + 4][j].weight = 410;
							}
							else
							{
								if (pan_2020184037[i + 3][j].weight < 410)
									pan_2020184037[i + 3][j].weight = 410;
							}
							if (pan_2020184037[i - 1][j].weight < 410)
								pan_2020184037[i - 1][j].weight = 410;
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == -1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 70)
										pan_2020184037[i - 1][j].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 70)
										pan_2020184037[i + 4][j].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j].stone == -1)
								{
									if (pan_2020184037[i - 1][j].weight < 70)
										pan_2020184037[i - 1][j].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 70)
										pan_2020184037[i + 3][j].weight = 70;
								}
							}
						}
					}
					break;
				case 4:
					//��ĭ ���� ���� �簡 ������ �̹� �̰����������� ���� ��� ��ĭ�ִ� �����縸 ������
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i - 4][j + 4].weight < 610)
									pan_2020184037[i - 4][j + 4].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])//��ĭ ������
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
							else//��ĭ ������
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 610)
										pan_2020184037[i + 1][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 610)
										pan_2020184037[i - 4][j + 4].weight = 610;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i][j + 4].weight < 610)
									pan_2020184037[i][j + 4].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i][j + 4].stone == -1)
								{
									if (pan_2020184037[i][j - 1].weight < 610)
										pan_2020184037[i][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 610)
										pan_2020184037[i][j + 4].weight = 610;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i + 4][j + 4].weight < 610)
									pan_2020184037[i + 4][j + 4].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 610)
										pan_2020184037[i - 1][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 610)
										pan_2020184037[i + 4][j + 4].weight = 610;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i + 4][j].weight < 610)
									pan_2020184037[i + 4][j].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 610;
							}
							else
							{
								if (pan_2020184037[i + 4][j].stone == -1)
								{
									if (pan_2020184037[i - 1][j].weight < 610)
										pan_2020184037[i - 1][j].weight = 610;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 610)
										pan_2020184037[i + 4][j].weight = 610;
								}

							}
						}
					}

					break;

				default:
					break;
				}
			}

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (pan_2020184037[i][j].stone != 0)//���� �ִ� ĭ�� ����ġ 0 (���� �θ� �ȵ�)
				pan_2020184037[i][j].weight = 0;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (max < pan_2020184037[i][j].weight)
				max = pan_2020184037[i][j].weight;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (max == pan_2020184037[i][j].weight)
			{
				*x = j;
				*y = i;
			}
		}
	}

	board_2020184037[*y][*x] = WHITE;
}
void WhiteDefence_2020184037(int x, int y)//���� �� ���϶� ���� ���� ���� ��ġ
{
	// ��밡 ���� ���� ��ġ�� ���޹޾Ƽ� �����մϴ�
	board_2020184037[y][x] = BLACK;
}
void BlackAttack_2020184037(int* x, int* y)//���� ������ �϶� ���� ���� �˰���
{
	// ���� �����Ͻ� �� ���� ������ �־��ּ���
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j�� x i�� y
			pan_2020184037[i][j].stone = board_2020184037[i][j];
			way1Check = 0;
			way2Check = 0;
			way3Check = 0;
			way4Check = 0;
			UnchangeX = j;
			UnchangeY = i;
			way(board_2020184037, i, j);

		}
	}
	//����ġ ���̱�(�鵹 ����)
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j�� x i�� y
			if (pan_2020184037[i][j].stone == 1) {
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//���� 1
					{
						if (pan_2020184037[i - 1][j - 1].weight < 20)
							pan_2020184037[i - 1][j - 1].weight = 20;

						if (pan_2020184037[i - 1][j].weight < 20)
							pan_2020184037[i - 1][j].weight = 20;

						if (pan_2020184037[i - 1][j + 1].weight < 20)
							pan_2020184037[i - 1][j + 1].weight = 20;

						if (pan_2020184037[i][j - 1].weight < 20)
							pan_2020184037[i][j + 1].weight = 20;

						if (pan_2020184037[i + 1][j + 1].weight < 20)
							pan_2020184037[i + 1][j + 1].weight = 20;

						if (pan_2020184037[i + 1][j].weight < 20)
							pan_2020184037[i + 1][j].weight = 20;

						if (pan_2020184037[i + 1][j - 1].weight < 20)
							pan_2020184037[i + 1][j - 1].weight = 20;

						if (pan_2020184037[i][j - 1].weight < 20)
							pan_2020184037[i][j - 1].weight = 20;

					}

					break;
				case 2:
					if (pan_2020184037[i][j].way[0])//way1
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].weight < 40)
									pan_2020184037[i - 3][j + 3].weight = 40;
								if (pan_2020184037[i + 1][j - 1].weight < 40)
									pan_2020184037[i + 1][j - 1].weight = 40;
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].weight < 40)
									pan_2020184037[i - 2][j + 2].weight = 40;
								if (pan_2020184037[i + 1][j - 1].weight < 40)
									pan_2020184037[i + 1][j - 1].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)//��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else//�ٸ����� ��������
								{
									if (pan_2020184037[i - 3][j + 3].weight < 30)
										pan_2020184037[i - 3][j + 3].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].stone == -1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i - 2][j + 2].weight < 30)
										pan_2020184037[i - 2][j + 2].weight = 30;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])//way2
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].weight < 40)
									pan_2020184037[i][j + 3].weight = 40;
								if (pan_2020184037[i][j - 1].weight < 40)
									pan_2020184037[i][j - 1].weight = 40;
							}
							else
							{
								if (pan_2020184037[i][j + 2].weight < 40)
									pan_2020184037[i][j + 2].weight = 40;
								if (pan_2020184037[i][j - 1].weight < 40)
									pan_2020184037[i][j - 1].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == -1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 30)
										pan_2020184037[i][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 30)
										pan_2020184037[i][j + 3].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 2].stone == -1)
								{
									if (pan_2020184037[i][j - 1].weight < 30)
										pan_2020184037[i][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i][j + 2].weight < 30)
										pan_2020184037[i][j + 2].weight = 30;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])//way3
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].weight < 40)
									pan_2020184037[i + 3][j + 3].weight = 40;
								if (pan_2020184037[i - 1][j - 1].weight < 40)
									pan_2020184037[i - 1][j - 1].weight = 40;
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].weight < 40)
									pan_2020184037[i + 2][j + 2].weight = 40;
								if (pan_2020184037[i - 1][j - 1].weight < 40)
									pan_2020184037[i - 1][j - 1].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)//��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 30)
										pan_2020184037[i - 1][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 30)
										pan_2020184037[i + 3][j + 3].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].stone == -1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 30)
										pan_2020184037[i - 1][j - 1].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 2][j + 2].weight < 30)
										pan_2020184037[i + 2][j + 2].weight = 30;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])//way4
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].weight < 40)
									pan_2020184037[i + 3][j].weight = 40;
								if (pan_2020184037[i - 1][j].weight < 40)
									pan_2020184037[i - 1][j].weight = 40;
							}
							else
							{
								if (pan_2020184037[i + 2][j].weight < 40)
									pan_2020184037[i + 2][j].weight = 40;
								if (pan_2020184037[i - 1][j].weight < 40)
									pan_2020184037[i - 1][j].weight = 40;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == -1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 30)
										pan_2020184037[i - 1][j].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 30)
										pan_2020184037[i + 3][j].weight = 30;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j].stone == -1)
								{
									if (pan_2020184037[i - 1][j].weight < 30)
										pan_2020184037[i - 1][j].weight = 30;
								}
								else
								{
									if (pan_2020184037[i + 2][j].weight < 30)
										pan_2020184037[i + 2][j].weight = 30;
								}
							}
						}
					}



					break;
				case 3:
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].weight < 400)
									pan_2020184037[i - 4][j + 4].weight = 400;
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].weight < 400)
									pan_2020184037[i - 3][j + 3].weight = 400;
							}
							if (pan_2020184037[i + 1][j - 1].weight < 400)
								pan_2020184037[i + 1][j - 1].weight = 400;
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 60)
										pan_2020184037[i + 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 60)
										pan_2020184037[i - 4][j + 4].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 60)
										pan_2020184037[i + 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i - 3][j + 3].weight < 60)
										pan_2020184037[i - 3][j + 3].weight = 60;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].weight < 400)
									pan_2020184037[i][j + 4].weight = 400;
							}
							else
							{
								if (pan_2020184037[i][j + 3].weight < 400)
									pan_2020184037[i][j + 3].weight = 400;
							}
							if (pan_2020184037[i][j - 1].weight < 400)
								pan_2020184037[i][j - 1].weight = 400;
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == -1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 60)
										pan_2020184037[i][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 60)
										pan_2020184037[i][j + 4].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 3].stone == -1)
								{
									if (pan_2020184037[i][j - 1].weight < 60)
										pan_2020184037[i][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 60)
										pan_2020184037[i][j + 3].weight = 60;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].weight < 400)
									pan_2020184037[i + 4][j + 4].weight = 400;
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].weight < 400)
									pan_2020184037[i + 3][j + 3].weight = 400;
							}
							if (pan_2020184037[i - 1][j - 1].weight < 400)
								pan_2020184037[i - 1][j - 1].weight = 400;
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)//��������
								{
									if (pan_2020184037[i - 1][j - 1].weight < 60)
										pan_2020184037[i - 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 60)
										pan_2020184037[i + 4][j + 4].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 60)
										pan_2020184037[i - 1][j - 1].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 60)
										pan_2020184037[i + 3][j + 3].weight = 60;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].weight < 400)
									pan_2020184037[i + 4][j].weight = 400;
							}
							else
							{
								if (pan_2020184037[i + 3][j].weight < 400)
									pan_2020184037[i + 3][j].weight = 400;
							}
							if (pan_2020184037[i - 1][j].weight < 400)
								pan_2020184037[i - 1][j].weight = 400;
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == -1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 60)
										pan_2020184037[i - 1][j].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 60)
										pan_2020184037[i + 4][j].weight = 60;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j].stone == -1)
								{
									if (pan_2020184037[i - 1][j].weight < 60)
										pan_2020184037[i - 1][j].weight = 60;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 60)
										pan_2020184037[i + 3][j].weight = 60;
								}
							}
						}
					}
					break;
				case 4:
					//��ĭ ���� ���� �簡 ������ �̹� ������������ ���� ��� ��ĭ�ִ� �����縸 ������
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == -1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 600)
										pan_2020184037[i + 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i - 5][j + 5].weight < 600)
										pan_2020184037[i - 5][j + 5].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 600)
										pan_2020184037[i + 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 600)
										pan_2020184037[i - 4][j + 4].weight = 600;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == -1)//�� ���� ��������	
								{
									if (pan_2020184037[i][j - 1].weight < 600)
										pan_2020184037[i][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i][j + 5].weight < 600)
										pan_2020184037[i][j + 5].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 4].stone == -1)
								{
									if (pan_2020184037[i][j - 1].weight < 600)
										pan_2020184037[i][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 600)
										pan_2020184037[i][j + 4].weight = 600;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == -1)//�� ���� ��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 600)
										pan_2020184037[i - 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 5][j + 5].weight < 600)
										pan_2020184037[i + 5][j + 5].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 600)
										pan_2020184037[i - 1][j - 1].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 600)
										pan_2020184037[i + 4][j + 4].weight = 600;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == -1)//�� ���� ��������	
								{
									if (pan_2020184037[i - 1][j].weight < 600)
										pan_2020184037[i - 1][j].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 5][j].weight < 600)
										pan_2020184037[i + 5][j].weight = 600;
								}
							}
							else
							{
								if (pan_2020184037[i + 4][j].stone == -1)
								{
									if (pan_2020184037[i - 1][j].weight < 600)
										pan_2020184037[i - 1][j].weight = 600;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 600)
										pan_2020184037[i + 4][j].weight = 600;
								}

							}
						}
					}

					break;

				default:
					break;
				}
			}
			else if (pan_2020184037[i][j].stone == -1)
			{
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//���� 1
					{
						if (pan_2020184037[i - 1][j - 1].weight < 30)
							pan_2020184037[i - 1][j - 1].weight = 30;

						if (pan_2020184037[i - 1][j].weight < 30)
							pan_2020184037[i - 1][j].weight = 30;

						if (pan_2020184037[i - 1][j + 1].weight < 30)
							pan_2020184037[i - 1][j + 1].weight = 30;

						if (pan_2020184037[i][j - 1].weight < 30)
							pan_2020184037[i][j + 1].weight = 30;

						if (pan_2020184037[i + 1][j + 1].weight < 30)
							pan_2020184037[i + 1][j + 1].weight = 30;

						if (pan_2020184037[i + 1][j].weight < 30)
							pan_2020184037[i + 1][j].weight = 30;

						if (pan_2020184037[i + 1][j - 1].weight < 30)
							pan_2020184037[i + 1][j - 1].weight = 30;

						if (pan_2020184037[i][j - 1].weight < 30)
							pan_2020184037[i][j - 1].weight = 30;

					}

					break;
				case 2:
					if (pan_2020184037[i][j].way[0])//way1
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].weight < 50)
									pan_2020184037[i - 3][j + 3].weight = 50;
								if (pan_2020184037[i + 1][j - 1].weight < 50)
									pan_2020184037[i + 1][j - 1].weight = 50;
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].weight < 50)
									pan_2020184037[i - 2][j + 2].weight = 50;
								if (pan_2020184037[i + 1][j - 1].weight < 50)
									pan_2020184037[i + 1][j - 1].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)//��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else//�ٸ����� ��������
								{
									if (pan_2020184037[i - 3][j + 3].weight < 40)
										pan_2020184037[i - 3][j + 3].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i - 2][j + 2].stone == 1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i - 2][j + 2].weight < 40)
										pan_2020184037[i - 2][j + 2].weight = 40;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])//way2
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].weight < 50)
									pan_2020184037[i][j + 3].weight = 50;
								if (pan_2020184037[i][j - 1].weight < 50)
									pan_2020184037[i][j - 1].weight = 50;
							}
							else
							{
								if (pan_2020184037[i][j + 2].weight < 50)
									pan_2020184037[i][j + 2].weight = 50;
								if (pan_2020184037[i][j - 1].weight < 50)
									pan_2020184037[i][j - 1].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == 1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 40)
										pan_2020184037[i][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 40)
										pan_2020184037[i][j + 3].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 2].stone == 1)
								{
									if (pan_2020184037[i][j - 1].weight < 40)
										pan_2020184037[i][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i][j + 2].weight < 40)
										pan_2020184037[i][j + 2].weight = 40;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])//way3
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].weight < 50)
									pan_2020184037[i + 3][j + 3].weight = 50;
								if (pan_2020184037[i - 1][j - 1].weight < 50)
									pan_2020184037[i - 1][j - 1].weight = 50;
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].weight < 50)
									pan_2020184037[i + 2][j + 2].weight = 50;
								if (pan_2020184037[i - 1][j - 1].weight < 50)
									pan_2020184037[i - 1][j - 1].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)//��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 40)
										pan_2020184037[i - 1][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 40)
										pan_2020184037[i + 3][j + 3].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j + 2].stone == 1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 40)
										pan_2020184037[i - 1][j - 1].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 2][j + 2].weight < 40)
										pan_2020184037[i + 2][j + 2].weight = 40;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])//way4
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].weight < 50)
									pan_2020184037[i + 3][j].weight = 50;
								if (pan_2020184037[i - 1][j].weight < 50)
									pan_2020184037[i - 1][j].weight = 50;
							}
							else
							{
								if (pan_2020184037[i + 2][j].weight < 50)
									pan_2020184037[i + 2][j].weight = 50;
								if (pan_2020184037[i - 1][j].weight < 50)
									pan_2020184037[i - 1][j].weight = 50;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == 1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 40)
										pan_2020184037[i - 1][j].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 40)
										pan_2020184037[i + 3][j].weight = 40;
								}
							}
							else
							{
								if (pan_2020184037[i + 2][j].stone == 1)
								{
									if (pan_2020184037[i - 1][j].weight < 40)
										pan_2020184037[i - 1][j].weight = 40;
								}
								else
								{
									if (pan_2020184037[i + 2][j].weight < 40)
										pan_2020184037[i + 2][j].weight = 40;
								}
							}
						}
					}



					break;
				case 3:
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].weight < 410)
									pan_2020184037[i - 4][j + 4].weight = 410;
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].weight < 410)
									pan_2020184037[i - 3][j + 3].weight = 410;
							}
							if (pan_2020184037[i + 1][j - 1].weight < 410)
								pan_2020184037[i + 1][j - 1].weight = 410;
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 70)
										pan_2020184037[i + 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 70)
										pan_2020184037[i - 4][j + 4].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 70)
										pan_2020184037[i + 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i - 3][j + 3].weight < 70)
										pan_2020184037[i - 3][j + 3].weight = 70;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].weight < 410)
									pan_2020184037[i][j + 4].weight = 410;
							}
							else
							{
								if (pan_2020184037[i][j + 3].weight < 410)
									pan_2020184037[i][j + 3].weight = 410;
							}
							if (pan_2020184037[i][j - 1].weight < 410)
								pan_2020184037[i][j - 1].weight = 410;
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == 1)//��������	
								{
									if (pan_2020184037[i][j - 1].weight < 70)
										pan_2020184037[i][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 70)
										pan_2020184037[i][j + 4].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 3].stone == 1)
								{
									if (pan_2020184037[i][j - 1].weight < 70)
										pan_2020184037[i][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i][j + 3].weight < 70)
										pan_2020184037[i][j + 3].weight = 70;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].weight < 410)
									pan_2020184037[i + 4][j + 4].weight = 410;
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].weight < 410)
									pan_2020184037[i + 3][j + 3].weight = 410;
							}
							if (pan_2020184037[i - 1][j - 1].weight < 410)
								pan_2020184037[i - 1][j - 1].weight = 410;
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)//��������
								{
									if (pan_2020184037[i - 1][j - 1].weight < 70)
										pan_2020184037[i - 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 70)
										pan_2020184037[i + 4][j + 4].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 70)
										pan_2020184037[i - 1][j - 1].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 3][j + 3].weight < 70)
										pan_2020184037[i + 3][j + 3].weight = 70;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].weight < 410)
									pan_2020184037[i + 4][j].weight = 410;
							}
							else
							{
								if (pan_2020184037[i + 3][j].weight < 410)
									pan_2020184037[i + 3][j].weight = 410;
							}
							if (pan_2020184037[i - 1][j].weight < 410)
								pan_2020184037[i - 1][j].weight = 410;
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == 1)//��������	
								{
									if (pan_2020184037[i - 1][j].weight < 70)
										pan_2020184037[i - 1][j].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 70)
										pan_2020184037[i + 4][j].weight = 70;
								}
							}
							else
							{
								if (pan_2020184037[i + 3][j].stone == 1)
								{
									if (pan_2020184037[i - 1][j].weight < 70)
										pan_2020184037[i - 1][j].weight = 70;
								}
								else
								{
									if (pan_2020184037[i + 3][j].weight < 70)
										pan_2020184037[i + 3][j].weight = 70;
								}
							}
						}
					}
					break;
				case 4:
					//��ĭ ���� ���� �簡 ������ �̹� ������������ ���� ��� ��ĭ�ִ� �����縸 ������
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 610)
										pan_2020184037[i + 1][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i - 5][j + 5].weight < 610)
										pan_2020184037[i - 5][j + 5].weight = 610;
								}
							}
							else
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)
								{
									if (pan_2020184037[i + 1][j - 1].weight < 610)
										pan_2020184037[i + 1][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i - 4][j + 4].weight < 610)
										pan_2020184037[i - 4][j + 4].weight = 610;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[1])
					{
						if (pan_2020184037[i][j].def[1] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i][j - 1].weight < 610)
										pan_2020184037[i][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i][j + 5].weight < 610)
										pan_2020184037[i][j + 5].weight = 610;
								}
							}
							else
							{
								if (pan_2020184037[i][j + 4].stone == 1)
								{
									if (pan_2020184037[i][j - 1].weight < 610)
										pan_2020184037[i][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i][j + 4].weight < 610)
										pan_2020184037[i][j + 4].weight = 610;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[2])
					{
						if (pan_2020184037[i][j].def[2] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i - 1][j - 1].weight < 610)
										pan_2020184037[i - 1][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i + 5][j + 5].weight < 610)
										pan_2020184037[i + 5][j + 5].weight = 610;
								}
							}
							else
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)
								{
									if (pan_2020184037[i - 1][j - 1].weight < 610)
										pan_2020184037[i - 1][j - 1].weight = 610;
								}
								else
								{
									if (pan_2020184037[i + 4][j + 4].weight < 610)
										pan_2020184037[i + 4][j + 4].weight = 610;
								}

							}
						}
					}
					if (pan_2020184037[i][j].way[3])
					{
						if (pan_2020184037[i][j].def[3] == 0) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //���� ��
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == 1)//�� ���� ��������	
								{
									if (pan_2020184037[i - 1][j].weight < 610)
										pan_2020184037[i - 1][j].weight = 610;
								}
								else
								{
									if (pan_2020184037[i + 5][j].weight < 610)
										pan_2020184037[i + 5][j].weight = 610;
								}
							}
							else
							{
								if (pan_2020184037[i + 4][j].stone == 1)
								{
									if (pan_2020184037[i - 1][j].weight < 610)
										pan_2020184037[i - 1][j].weight = 610;
								}
								else
								{
									if (pan_2020184037[i + 4][j].weight < 610)
										pan_2020184037[i + 4][j].weight = 610;
								}

							}
						}
					}

					break;

				default:
					break;
				}
			}

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (pan_2020184037[i][j].stone != 0)//���� �ִ� ĭ�� ����ġ 0 (���� �θ� �ȵ�)
				pan_2020184037[i][j].weight = 0;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (max < pan_2020184037[i][j].weight)
				max = pan_2020184037[i][j].weight;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (max == pan_2020184037[i][j].weight)
			{
				*x = j;
				*y = i;
			}
		}
	}
	if (max == 0)
	{
		*x = 10;
		*y = 10;
	}

	board_2020184037[*y][*x] = BLACK;
}
void BlackDefence_2020184037(int x, int y)//���� �������϶� ���� ���� ��ġ
{
	// ��밡 ���� ���� ��ġ�� ���޹޾Ƽ� �����մϴ�
	board_2020184037[y][x] = WHITE;
}
void way(int bp[][19], int y, int x)
{
	if (way1Check == 0)
	{
		if (bp[y][x] != 0)//���� ������(1�Ǵ� -1�϶�)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y - 1][x + 1] == bp[y][x])//way1���� �������� ������
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y - 1, x + 1);
			}
			else if (bp[y - 1][x + 1] == 0)//�������� ��ĭ�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//��ĭ�� �ι� ������ �˻縦 ����
				{
					if (bp[y - 2][x + 2] == bp[y][x])// o+o���¸� +�� �ǳʶ�
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[0] = y - 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[0] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[0]++;
						way(bp, y - 2, x + 2);
					}
				}
			}
			else//�������� ��뵹�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].def[0] = 1;
			}
			pan_2020184037[UnchangeY][UnchangeX].maxstone = pan_2020184037[UnchangeY][UnchangeX].check;
		}
		pan_2020184037[UnchangeY][UnchangeX].check = 0;
		pan_2020184037[UnchangeY][UnchangeX].plusCheck = 0;
		pan_2020184037[UnchangeY][UnchangeX].way[0] = 1;
		way1Check = 1;
	}
	if (way2Check == 0)
	{
		if (bp[y][x] != 0)//���� ������(1�Ǵ� -1�϶�)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y][x + 1] == bp[y][x])//way2���� �������� ������
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y, x + 1);
			}
			else if (bp[y][x + 1] == 0)//�������� ��ĭ�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//��ĭ�� �ι� ������ �˻縦 ����
				{
					if (bp[y][x + 2] == bp[y][x])// o+o���¸� +�� �ǳʶ�
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[1] = y;
						pan_2020184037[UnchangeY][UnchangeX].plusX[1] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[1]++;
						way(bp, y, x + 2);
					}
				}
			}
			else//�������� ��뵹�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].def[1] = 1;
			}
			if (pan_2020184037[UnchangeY][UnchangeX].check > pan_2020184037[UnchangeY][UnchangeX].maxstone)
			{
				pan_2020184037[UnchangeY][UnchangeX].maxstone = pan_2020184037[UnchangeY][UnchangeX].check;
				pan_2020184037[UnchangeY][UnchangeX].way[0] = 0;
				pan_2020184037[UnchangeY][UnchangeX].way[1] = 1;
			}
			else if (pan_2020184037[UnchangeY][UnchangeX].check == pan_2020184037[UnchangeY][UnchangeX].maxstone)
			{
				pan_2020184037[UnchangeY][UnchangeX].way[1] = 1;
			}

		}
		way2Check = 1;
		pan_2020184037[UnchangeY][UnchangeX].check = 0;
		pan_2020184037[UnchangeY][UnchangeX].plusCheck = 0;
	}
	if (way3Check == 0)
	{
		if (bp[y][x] != 0)//���� ������(1�Ǵ� -1�϶�)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y + 1][x + 1] == bp[y][x])//way3���� �������� ������
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y + 1, x + 1);
			}
			else if (bp[y + 1][x + 1] == 0)//�������� ��ĭ�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//��ĭ�� �ι� ������ �˻縦 ����
				{
					if (bp[y + 2][x + 2] == bp[y][x])// o+o���¸� +�� �ǳʶ�
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[2] = y + 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[2] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[2]++;
						way(bp, y + 2, x + 2);
					}
				}
			}
			else//�������� ��뵹�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].def[2] = 1;
			}
			if (pan_2020184037[UnchangeY][UnchangeX].check > pan_2020184037[UnchangeY][UnchangeX].maxstone)
			{
				pan_2020184037[UnchangeY][UnchangeX].maxstone = pan_2020184037[UnchangeY][UnchangeX].check;
				pan_2020184037[UnchangeY][UnchangeX].way[0] = 0;
				pan_2020184037[UnchangeY][UnchangeX].way[1] = 0;
				pan_2020184037[UnchangeY][UnchangeX].way[2] = 1;
			}
			else if (pan_2020184037[UnchangeY][UnchangeX].check == pan_2020184037[UnchangeY][UnchangeX].maxstone)
			{
				pan_2020184037[UnchangeY][UnchangeX].way[2] = 1;
			}

		}
		way3Check = 1;
		pan_2020184037[UnchangeY][UnchangeX].check = 0;
		pan_2020184037[UnchangeY][UnchangeX].plusCheck = 0;
	}
	if (way4Check == 0)
	{
		if (bp[y][x] != 0)//���� ������
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y + 1][x] == bp[y][x])//way4���� �������� ������
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y + 1, x);
			}
			else if (bp[y + 1][x] == 0)//�������� ��ĭ�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//��ĭ�� �ι� ������ �˻縦 ����
				{
					if (bp[y + 2][x] == bp[y][x])// o+o���¸� +�� �ǳʶ�
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[3] = y + 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[3] = x;
						pan_2020184037[UnchangeY][UnchangeX].plus[3]++;
						way(bp, y + 2, x);
					}
				}
			}
			else//�������� ��뵹�϶�
			{
				pan_2020184037[UnchangeY][UnchangeX].def[3] = 1;
			}
			if (pan_2020184037[UnchangeY][UnchangeX].check > pan_2020184037[UnchangeY][UnchangeX].maxstone)
			{
				pan_2020184037[UnchangeY][UnchangeX].maxstone = pan_2020184037[UnchangeY][UnchangeX].check;
				pan_2020184037[UnchangeY][UnchangeX].way[0] = 0;
				pan_2020184037[UnchangeY][UnchangeX].way[1] = 0;
				pan_2020184037[UnchangeY][UnchangeX].way[2] = 0;
				pan_2020184037[UnchangeY][UnchangeX].way[3] = 1;
			}
			else if (pan_2020184037[UnchangeY][UnchangeX].check == pan_2020184037[UnchangeY][UnchangeX].maxstone)
			{
				pan_2020184037[UnchangeY][UnchangeX].way[3] = 1;
			}

		}
		way4Check = 1;
		pan_2020184037[UnchangeY][UnchangeX].check = 0;
		pan_2020184037[UnchangeY][UnchangeX].plusCheck = 0;
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[0]) //���帹�� ���� way1���� ������
	{
		if (bp[UnchangeY + 1][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//�� �� ���� ���̸� ������
		{
			pan_2020184037[UnchangeY][UnchangeX].def[0] ++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[1])
	{
		if (bp[UnchangeY][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//�� �� ���� ���̸� ������
		{
			pan_2020184037[UnchangeY][UnchangeX].def[1]++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[2])
	{
		if (bp[UnchangeY - 1][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//�� �� ���� ���̸� ������
		{
			pan_2020184037[UnchangeY][UnchangeX].def[2]++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[3])
	{
		if (bp[UnchangeY - 1][UnchangeX] == -bp[UnchangeY][UnchangeX])//�� �� ���� ���̸� ������
		{
			pan_2020184037[UnchangeY][UnchangeX].def[3]++;
		}
	}
}