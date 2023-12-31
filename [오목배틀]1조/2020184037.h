#pragma once
int board_2020184037[19][19];
//避宜		1
//伊精宜	-1
#define BLACK -1
#define WHITE 1
void way(int bp[][19], int y, int x);
typedef struct _Check {
	int stone;
	int way[4];		//尻紗吉 宜戚 赤聖凶 護腰属 掩昔走(1~4)
	int maxstone;	//置企 護鯵税 宜戚 赤澗走
	int plusCheck;	//尻紗吉 宜 紫戚 朔牒 端滴(析噺遂)
	int plus[4];		//尻紗吉 宜 紫戚 朔牒 端滴
	int weight;		//亜掻帖
	int check;
	int plusX[4];
	int plusY[4];
	int def[4];//wayn戚 厳縛澗走 食採 0戚檎 照厳毘 1戚檎 馬蟹 厳毘 2檎 陥厳毘
}Check;
Check pan_2020184037[19][19];
static int way1Check;
static int way2Check;
static int way3Check;
static int way4Check;
static int UnchangeX;// 痕馬走 省澗 x 葵(掩端滴 仙瑛敗呪研 承凶 x,y葵戚 郊餓糠稽 紫遂馬澗 痕呪)
static int UnchangeY;// 痕馬走 省澗 y 葵
void WhiteAttack_2020184037(int* x, int* y) //鎧亜 避宜 析凶 宜聖 兜澗 硝壱軒葬 
{
	// 送羨 姥薄馬重 宜 兜奄 稽送聖 隔嬢爽室推
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j亜 x i亜 y
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
	//亜掻帖 呼戚奄(拷宜 呪搾)
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j亜 x i亜 y
			if (pan_2020184037[i][j].stone == -1) {//拷宜税 呪搾
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//伸鍵 1
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)//厳縛生檎	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else//陥献員戚 厳縛生檎
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)//厳縛生檎
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == 1)//厳縛生檎	
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
					//朔牒 蒸澗 伸鍵 紫亜 赤生檎 戚耕 然製せせさぁ 丸微 紫櫛 朔牒赤澗 伸鍵紫幻 坐醤敗
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[1])//朔 因娃戚 赤生檎
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == 1)//廃 楕戚 厳縛生檎	
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
			else if (pan_2020184037[i][j].stone == 1)//拷宜析凶 因維
			{
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//伸鍵 1
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)//厳縛生檎	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else//陥献員戚 厳縛生檎
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)//厳縛生檎
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == -1)//厳縛生檎	
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
					//朔牒 蒸澗 伸鍵 紫亜 赤生檎 戚耕 戚医製せせさぁ 丸微 紫櫛 朔牒赤澗 伸鍵紫幻 坐醤敗
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 紫
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[0])//朔牒 赤聖凶
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
							else//朔牒 蒸聖凶
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 紫
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 紫
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 紫
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 紫
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 紫
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 紫
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
			if (pan_2020184037[i][j].stone != 0)//宜戚 赤澗 牒精 亜掻帖 0 (箭企 砧檎 照喫)
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
void WhiteDefence_2020184037(int x, int y)//鎧亜 避 宜析凶 伊精 宜戚 兜精 是帖
{
	// 雌企亜 兜精 宜税 是帖研 穿含閤焼辞 煽舌杯艦陥
	board_2020184037[y][x] = BLACK;
}
void BlackAttack_2020184037(int* x, int* y)//鎧亜 伊精宜 析凶 宜聖 兜澗 硝壱軒葬
{
	// 送羨 姥薄馬重 宜 兜奄 稽送聖 隔嬢爽室推
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j亜 x i亜 y
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
	//亜掻帖 呼戚奄(拷宜 呪搾)
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{//j亜 x i亜 y
			if (pan_2020184037[i][j].stone == 1) {
				switch (pan_2020184037[i][j].maxstone)
				{
				case 1:

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//伸鍵 1
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == -1)//厳縛生檎	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 30)
										pan_2020184037[i + 1][j - 1].weight = 30;
								}
								else//陥献員戚 厳縛生檎
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == -1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == -1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == -1)//厳縛生檎
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == -1)//厳縛生檎	
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
					//朔牒 蒸澗 伸鍵 紫亜 赤生檎 戚耕 然製せせさぁ 丸微 紫櫛 朔牒赤澗 伸鍵紫幻 坐醤敗
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == -1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == -1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == -1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 600)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 600;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == -1)//廃 楕戚 厳縛生檎	
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

					if (!(pan_2020184037[i][j].def[0] && pan_2020184037[i][j].def[1] && pan_2020184037[i][j].def[2] && pan_2020184037[i][j].def[3]))//伸鍵 1
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 3][j + 3].stone == 1)//厳縛生檎	
								{
									if (pan_2020184037[i + 1][j - 1].weight < 40)
										pan_2020184037[i + 1][j - 1].weight = 40;
								}
								else//陥献員戚 厳縛生檎
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 3].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 3][j + 3].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 戚
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 戚
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 3][j].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 4][j + 4].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 4].stone == 1)//厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 4][j + 4].stone == 1)//厳縛生檎
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 誌
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
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 誌
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 4][j].stone == 1)//厳縛生檎	
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
					//朔牒 蒸澗 伸鍵 紫亜 赤生檎 戚耕 然製せせさぁ 丸微 紫櫛 朔牒赤澗 伸鍵紫幻 坐醤敗
					if (pan_2020184037[i][j].way[0])
					{
						if (pan_2020184037[i][j].def[0] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[0]][pan_2020184037[i][j].plusX[0]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[0] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[0])
							{
								if (pan_2020184037[i - 5][j + 5].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[1] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[1]][pan_2020184037[i][j].plusX[1]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[1] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[1])
							{
								if (pan_2020184037[i][j + 5].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[2] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[2]][pan_2020184037[i][j].plusX[2]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[2] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[2])
							{
								if (pan_2020184037[i + 5][j + 5].stone == 1)//廃 楕戚 厳縛生檎	
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
						if (pan_2020184037[i][j].def[3] == 0) //伸鍵 紫
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight < 610)
									pan_2020184037[pan_2020184037[i][j].plusY[3]][pan_2020184037[i][j].plusX[3]].weight = 610;
							}
						}
						else if (pan_2020184037[i][j].def[3] == 1) //丸微 紫
						{
							if (pan_2020184037[i][j].plus[3])
							{
								if (pan_2020184037[i + 5][j].stone == 1)//廃 楕戚 厳縛生檎	
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
			if (pan_2020184037[i][j].stone != 0)//宜戚 赤澗 牒精 亜掻帖 0 (箭企 砧檎 照喫)
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
void BlackDefence_2020184037(int x, int y)//鎧亜 伊精宜析凶 避宜戚 兜精 是帖
{
	// 雌企亜 兜精 宜税 是帖研 穿含閤焼辞 煽舌杯艦陥
	board_2020184037[y][x] = WHITE;
}
void way(int bp[][19], int y, int x)
{
	if (way1Check == 0)
	{
		if (bp[y][x] != 0)//宜戚 赤聖凶(1暁澗 -1析凶)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y - 1][x + 1] == bp[y][x])//way1拭辞 陥製宜亀 旭聖凶
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y - 1, x + 1);
			}
			else if (bp[y - 1][x + 1] == 0)//陥製宜戚 朔牒析凶
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//朔牒戚 砧腰 蟹神檎 伊紫研 魁蛙
				{
					if (bp[y - 2][x + 2] == bp[y][x])// o+o莫殿檎 +研 闇格芹
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[0] = y - 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[0] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[0]++;
						way(bp, y - 2, x + 2);
					}
				}
			}
			else//陥製宜戚 雌企宜析凶
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
		if (bp[y][x] != 0)//宜戚 赤聖凶(1暁澗 -1析凶)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y][x + 1] == bp[y][x])//way2拭辞 陥製宜亀 旭聖凶
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y, x + 1);
			}
			else if (bp[y][x + 1] == 0)//陥製宜戚 朔牒析凶
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//朔牒戚 砧腰 蟹神檎 伊紫研 魁蛙
				{
					if (bp[y][x + 2] == bp[y][x])// o+o莫殿檎 +研 闇格芹
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[1] = y;
						pan_2020184037[UnchangeY][UnchangeX].plusX[1] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[1]++;
						way(bp, y, x + 2);
					}
				}
			}
			else//陥製宜戚 雌企宜析凶
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
		if (bp[y][x] != 0)//宜戚 赤聖凶(1暁澗 -1析凶)
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y + 1][x + 1] == bp[y][x])//way3拭辞 陥製宜亀 旭聖凶
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y + 1, x + 1);
			}
			else if (bp[y + 1][x + 1] == 0)//陥製宜戚 朔牒析凶
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//朔牒戚 砧腰 蟹神檎 伊紫研 魁蛙
				{
					if (bp[y + 2][x + 2] == bp[y][x])// o+o莫殿檎 +研 闇格芹
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[2] = y + 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[2] = x + 1;
						pan_2020184037[UnchangeY][UnchangeX].plus[2]++;
						way(bp, y + 2, x + 2);
					}
				}
			}
			else//陥製宜戚 雌企宜析凶
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
		if (bp[y][x] != 0)//宜戚 赤聖凶
		{
			pan_2020184037[UnchangeY][UnchangeX].check++;
			if (bp[y + 1][x] == bp[y][x])//way4拭辞 陥製宜亀 旭聖凶
			{
				//pan_2020184037[UnchangeY][UnchangeX].check++;
				way(bp, y + 1, x);
			}
			else if (bp[y + 1][x] == 0)//陥製宜戚 朔牒析凶
			{
				pan_2020184037[UnchangeY][UnchangeX].plusCheck++;
				if (pan_2020184037[UnchangeY][UnchangeX].plusCheck < 2)//朔牒戚 砧腰 蟹神檎 伊紫研 魁蛙
				{
					if (bp[y + 2][x] == bp[y][x])// o+o莫殿檎 +研 闇格芹
					{
						//pan_2020184037[UnchangeY][UnchangeX].check++;
						pan_2020184037[UnchangeY][UnchangeX].plusY[3] = y + 1;
						pan_2020184037[UnchangeY][UnchangeX].plusX[3] = x;
						pan_2020184037[UnchangeY][UnchangeX].plus[3]++;
						way(bp, y + 2, x);
					}
				}
			}
			else//陥製宜戚 雌企宜析凶
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
	if (pan_2020184037[UnchangeY][UnchangeX].way[0]) //亜舌弦精 宜戚 way1是拭 赤聖凶
	{
		if (bp[UnchangeY + 1][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//益 穿 宜戚 避宜戚檎 厳縛陥
		{
			pan_2020184037[UnchangeY][UnchangeX].def[0] ++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[1])
	{
		if (bp[UnchangeY][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//益 穿 宜戚 避宜戚檎 厳縛陥
		{
			pan_2020184037[UnchangeY][UnchangeX].def[1]++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[2])
	{
		if (bp[UnchangeY - 1][UnchangeX - 1] == -bp[UnchangeY][UnchangeX])//益 穿 宜戚 避宜戚檎 厳縛陥
		{
			pan_2020184037[UnchangeY][UnchangeX].def[2]++;
		}
	}
	if (pan_2020184037[UnchangeY][UnchangeX].way[3])
	{
		if (bp[UnchangeY - 1][UnchangeX] == -bp[UnchangeY][UnchangeX])//益 穿 宜戚 避宜戚檎 厳縛陥
		{
			pan_2020184037[UnchangeY][UnchangeX].def[3]++;
		}
	}
}