#pragma once
int board_2020184037[19][19];
//흰돌		1
//검은돌	-1
#define BLACK -1
#define WHITE 1
void way(int bp[][19], int y, int x);
typedef struct _Check {
	int stone;
	int way[4];		//연속된 돌이 있을때 몇번째 길인지(1~4)
	int maxstone;	//최대 몇개의 돌이 있는지
	int plusCheck;	//연속된 돌 사이 빈칸 체크(일회용)
	int plus[4];		//연속된 돌 사이 빈칸 체크
	int weight;		//가중치
	int check;
	int plusX[4];
	int plusY[4];
	int def[4];//wayn이 막혔는지 여부 0이면 안막힘 1이면 하나 막힘 2면 다막힘
}Check;
Check pan_2020184037[19][19];
static int way1Check;
static int way2Check;
static int way3Check;
static int way4Check;
static int UnchangeX;// 변하지 않는 x 값(길체크 재귀함수를 쓸때 x,y값이 바뀌므로 사용하는 변수)
static int UnchangeY;// 변하지 않는 y 값
void WhiteAttack_2020184037(int* x, int* y) //내가 흰돌 일때 돌을 놓는 알고리즘 
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j가 x i가 y
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
	//가중치 맥이기(백돌 수비)
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j가 x i가 y
			if (pan_2020184037[i][j].stone == -1) {//백돌의 수비
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//열린 1
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)//막혔으면	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else//다른곳이 막혔으면
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)//막혔으면
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == 1)//막혔으면	
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
					//빈칸 없는 열린 사가 있으면 이미 졌음ㅋㅋㅅㄱ 닫힌 사랑 빈칸있는 열린사만 봐야함
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[1])//빈 공간이 있으면
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == 1)//한 쪽이 막혔으면	
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
			else if (pan_2020184037[i][j].stone == 1)//백돌일때 공격
			{
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//열린 1
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)//막혔으면	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else//다른곳이 막혔으면
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)//막혔으면
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == -1)//막혔으면	
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
					//빈칸 없는 열린 사가 있으면 이미 이겼음ㅋㅋㅅㄱ 닫힌 사랑 빈칸있는 열린사만 봐야함
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //열린 사
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[0])//빈칸 있을때
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
							else//빈칸 없을때
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 사
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 사
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 사
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 사
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 사
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 사
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
			if (pan_2020184037[i][j].stone != 0)//돌이 있는 칸은 가중치 0 (절대 두면 안됨)
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
void WhiteDefence_2020184037(int x, int y)//내가 흰 돌일때 검은 돌이 놓은 위치
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2020184037[y][x] = BLACK;
}
void BlackAttack_2020184037(int* x, int* y)//내가 검은돌 일때 돌을 놓는 알고리즘
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j가 x i가 y
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
	//가중치 맥이기(백돌 수비)
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j가 x i가 y
			if (pan_2020184037[i][j].stone == 1) {
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//열린 1
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)//막혔으면	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else//다른곳이 막혔으면
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == -1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)//막혔으면
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == -1)//막혔으면	
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
					//빈칸 없는 열린 사가 있으면 이미 졌음ㅋㅋㅅㄱ 닫힌 사랑 빈칸있는 열린사만 봐야함
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == -1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == -1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == -1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == -1)//한 쪽이 막혔으면	
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

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//열린 1
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)//막혔으면	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else//다른곳이 막혔으면
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 이
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 이
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[0] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == 1)//막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)//막혔으면
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 삼
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
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 삼
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == 1)//막혔으면	
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
					//빈칸 없는 열린 사가 있으면 이미 졌음ㅋㅋㅅㄱ 닫힌 사랑 빈칸있는 열린사만 봐야함
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[1] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[2] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == 1)//한 쪽이 막혔으면	
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
						if (pan_2020184037[i][j].def[3] == 0) //열린 사
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //닫힌 사
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == 1)//한 쪽이 막혔으면	
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
			if (pan_2020184037[i][j].stone != 0)//돌이 있는 칸은 가중치 0 (절대 두면 안됨)
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
void BlackDefence_2020184037(int x, int y)//내가 검은돌일때 흰돌이 놓은 위치
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2020184037[y][x] = WHITE;
}
void way(int bp[][19], int y, int x)
{
	if (way1Check == 0)
	{
		if (bp[y][x] != 0)//돌이 있을때(1또는 -1일때)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y - 1][x + 1] == bp[y][x])//way1에서 다음돌도 같을때
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y - 1, x + 1);
			}
			else if (bp[y - 1][x + 1] == 0)//다음돌이 빈칸일때
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//빈칸이 두번 나오면 검사를 끝냄
				{
					if (bp[y - 2][x + 2] == bp[y][x])// o+o형태면 +를 건너뜀
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[0] = y - 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[0] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[0]++;
						way(bp, y - 2, x + 2);
					}
				}
			}
			else//다음돌이 상대돌일때
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
		if (bp[y][x] != 0)//돌이 있을때(1또는 -1일때)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y][x + 1] == bp[y][x])//way2에서 다음돌도 같을때
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y, x + 1);
			}
			else if (bp[y][x + 1] == 0)//다음돌이 빈칸일때
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//빈칸이 두번 나오면 검사를 끝냄
				{
					if (bp[y][x + 2] == bp[y][x])// o+o형태면 +를 건너뜀
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[1] = y;
						pan_2020184037[UnchangeY][UnchangeX].plusX[1] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[1]++;
						way(bp, y, x + 2);
					}
				}
			}
			else//다음돌이 상대돌일때
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
		if (bp[y][x] != 0)//돌이 있을때(1또는 -1일때)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y + 1][x + 1] == bp[y][x])//way3에서 다음돌도 같을때
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y + 1, x + 1);
			}
			else if (bp[y + 1][x + 1] == 0)//다음돌이 빈칸일때
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//빈칸이 두번 나오면 검사를 끝냄
				{
					if (bp[y + 2][x + 2] == bp[y][x])// o+o형태면 +를 건너뜀
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[2] = y + 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[2] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[2]++;
						way(bp, y + 2, x + 2);
					}
				}
			}
			else//다음돌이 상대돌일때
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
		if (bp[y][x] != 0)//돌이 있을때
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y + 1][x] == bp[y][x])//way4에서 다음돌도 같을때
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y + 1, x);
			}
			else if (bp[y + 1][x] == 0)//다음돌이 빈칸일때
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//빈칸이 두번 나오면 검사를 끝냄
				{
					if (bp[y + 2][x] == bp[y][x])// o+o형태면 +를 건너뜀
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[3] = y + 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[3] = x;
						pan_2020184037[UnchangeY][UnchangeX].plus[3]++;
						way(bp, y + 2, x);
					}
				}
			}
			else//다음돌이 상대돌일때
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
	if (pan_2020184037[UnchangeY][UnchangeX].way[0]) //가장많은 돌이 way1위에 있을때
	{
		if (bp[UnchangeY + 1][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//그 전 돌이 흰돌이면 막혔다
		{
			pan_2020184037[UnchangeY][UnchangeX].def[0] ++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[1])
	{
		if (bp[UnchangeY][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//그 전 돌이 흰돌이면 막혔다
		{
			pan_2020184037[UnchangeY][UnchangeX].def[1]++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[2])
	{
		if (bp[UnchangeY - 1][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//그 전 돌이 흰돌이면 막혔다
		{
			pan_2020184037[UnchangeY][UnchangeX].def[2]++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[3])
	{
		if (bp[UnchangeY - 1][UnchangeX] == -bp[UnchangeY][UnchangeX])//그 전 돌이 흰돌이면 막혔다
		{
			pan_2020184037[UnchangeY][UnchangeX].def[3]++;
		}
	}
}