#pragma once
int board_2020184028[19][19];

//흰돌		1
//검은돌	-1
#define BLACK -1
#define WHITE 1

typedef struct omok {
	int stone;//무슨 돌인지 확인
	int cons; //연속된 돌 확인
	int weight;//가중치
}omok;

omok stone[19][19];
int stonenum = 0;

void WhiteAttack_2020184028(int* x, int* y)
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요
	int check = 0;//한 줄씩 검색하게 하는 변수

	int Echeck = 0;//적 공백 체크
	int Estone = 1;//적돌 연속 체크해주는 변수
	int b = 0; //공백을 한번만 찾게 하는 변수
	int savex = 0; //공백일때의 좌표 저장변수
	int savey = 0; //공백일때의 좌표 저장변수
	//대각선 전용 변수
	int linenum = 1;//대각선 연속확인 변수
	int max = 0;//가중치의 최대값 변수


	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board_2020184028[i][j] != BLACK && board_2020184028[i][j] != WHITE) {
				stone[i][j].stone = 0;
			}
			else {
				stone[i][j].stone = board_2020184028[i][j];
			}
		}
	}
	if (stonenum == 0) {
		//돌을 두고 만약에 돌이 있다면 다른데 두고
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK) {
					stone[i - 1][j].weight += 10;
				}
			}
		}
	}
	else if (stonenum == 1) {
		//랜덤하게 두는 돌 근데 판에 돌이 없을경우에만 발동되게한다.
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				//백돌을 기준으로 주변 8자리의 가중치를 늘려준다.
				if (stone[i][j].stone == WHITE) {
					if (stone[i + 1][j].stone == 0) {//돌(남)빈칸일경우
						stone[i + 1][j].weight += 10;//가중치를 늘린다.
					}
					if (stone[i][j + 1].stone == 0) {//돌(동)빈칸일경우
						stone[i][j + 1].weight += 10;//가중치를 늘린다.
					}
					if (stone[i + 1][j + 1].stone == 0) {//돌(남동)빈칸일경우
						stone[i + 1][j + 1].weight += 10;//가중치를 늘린다.
					}

					if (i > 0) {
						if (stone[i - 1][j].stone == 0) {//돌(북)빈칸일경우
							stone[i - 1][j].weight += 10;//가중치를 늘린다.
						}
						if (stone[i - 1][j + 1].stone == 0) {//돌(북동)빈칸일경우
							stone[i - 1][j + 1].weight += 10;//가중치를 늘린다.
						}
					}
					if (j > 0) {
						if (stone[i][j - 1].stone == 0) {//돌(서)빈칸일경우
							stone[i][j - 1].weight += 10;//가중치를 늘린다.
						}
						if (stone[i + 1][j - 1].stone == 0) {//돌(남서)빈칸일경우
							stone[i + 1][j - 1].weight += 10;//가중치를 늘린다.
						}
					}
					if (i > 0 && j > 0) {
						if (stone[i - 1][j - 1].stone == 0) {//돌(북서)빈칸일경우
							stone[i - 1][j - 1].weight += 10;//가중치를 늘린다.
						}
					}
				}
			}
		}
		//적돌 가로 연속 체크(수비)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0) {//2칸연속일 경우
						stone[i][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == WHITE && stone[i][j - 1].stone == 0) {//2칸 연속인데 닫혀있는경우
						stone[i][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == WHITE && stone[i][j - 1].stone == 0) {//3칸 연속인데 닫혀있는경우
						stone[i][j - 1].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == 0) {//3칸연속일경우
						stone[i][j + 3].weight += 40;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == WHITE && stone[i][j - 1].stone == 0) {//4칸 연속인데 닫혀 있는경우
						stone[i][j - 1].weight += 60;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == 0) {//4칸연속일경우
						stone[i][j + 4].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		//적돌 세로 연속 체크(수비)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0) {//2칸연속일 경우
						stone[i + 2][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == WHITE && stone[i - 1][j].stone == 0) {//2칸 연속인데 닫혀있는경우
						stone[i - 1][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == WHITE && stone[i - 1][j].stone == 0) {//3칸 연속인데 닫혀있는경우
						stone[i - 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == 0) {//3칸연속일경우
						stone[i + 3][j].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == WHITE && stone[i - 1][j].stone == 0) {//4칸 연속인데 닫혀 있는경우
						stone[i - 1][j].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == 0) {//4칸연속일경우
						stone[i + 4][j].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//좌하향 대각선 막기
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == 0) {//좌하향 2칸 연속일경우
						stone[i + 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//좌하향 2칸 연속일때 닫힌경우
						stone[i - 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == 0) {//좌하향 3칸 연속일경우
						stone[i + 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//좌하향 3칸 연속일때 닫힌경우
						stone[i - 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == 0) {//좌하향 4칸 연속일경우
						stone[i + 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//좌하향 4칸 연속일때 닫힌경우
						stone[i - 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//좌상향 대각선 막기
		for (int i = 18; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == 0) {//좌상향 2칸연속일때
						stone[i - 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == WHITE && stone[i + 1][j - 1].stone == 0) { //좌상향 2칸연속일때 닫힌경우
						stone[i + 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == 0) { //좌상향 3칸연속일때
						stone[i - 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == WHITE && stone[i + 1][j - 1].stone == 0) { //좌상향 3칸연속일때 닫힌경우
						stone[i + 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == 0) { //좌상향 4칸연속일때
						stone[i - 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == WHITE && stone[i + 1][j - 1].stone == 0) { //좌상향 4칸연속일때 닫힌경우
						stone[i + 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//가로 공백 체크
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK) {//OXO이경우
						stone[i][j + 1].weight += 20;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == BLACK) {//OOXO경우
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK) {//OXOO경우
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == 0 && stone[i][j + 4].stone == BLACK) {//OOOXO경우
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == BLACK) {//OXOOO경우
						stone[i][j + 1].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == BLACK) {//OOXOO경우
						stone[i][j + 2].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//세로 공백 체크
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK) {//OXO이경우
						stone[i + 1][j].weight += 20;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == BLACK) {//OOXO경우
						stone[i + 2][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK) {//OXOO경우
						stone[i + 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == 0 && stone[i + 4][j].stone == BLACK) {//OOOXO경우
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == BLACK) {//OXOOO경우
						stone[i + 1][j].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == BLACK) {//OOXOO경우
						stone[i + 2][j].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(가로)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == 0) {//열린경우 WWWWX
						stone[i][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == BLACK && stone[i][j - 1].stone == 0) {//닫힌경우 XWWWWB
						stone[i][j - 1].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == WHITE) {// WXWWW
						stone[i][j + 1].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == WHITE) {// WWXWW
						stone[i][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == 0 && stone[i][j + 4].stone == WHITE) {// WWWXW
						stone[i][j + 3].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(세로)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == 0) {//열린경우 WWWWX
						stone[i + 4][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == BLACK && stone[i - 1][j].stone == 0) {//닫힌경우 XWWWWB
						stone[i - 1][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == WHITE) {// WXWWW
						stone[i + 1][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == WHITE) {// WWXWW
						stone[i][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == 0 && stone[i + 4][j].stone == WHITE) {// WWWXW
						stone[i + 3][j].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(대각선 좌하향)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == 0) {//열린경우 WWWWX
						stone[i + 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//닫힌경우 XWWWWB
						stone[i - 1][j - 1].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == 0 && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == WHITE) {//WXWWW
						stone[i + 1][j + 1].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == 0 && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == WHITE) {//WWXWW
						stone[i + 2][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == 0 && stone[i + 4][j + 4].stone == WHITE) {//WWWXW
						stone[i + 3][j + 3].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(대각선 좌상향)
		for (int i = 18; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == 0) {//열린경우 WWWWX
						stone[i - 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == BLACK && stone[i + 1][j - 1].stone == 0) {//닫힌경우 XWWWWB
						stone[i + 1][j - 1].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == 0 && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == WHITE) {//WXWWW
						stone[i - 1][j + 1].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == 0 && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == WHITE) {//WWXWW
						stone[i - 2][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == 0 && stone[i - 4][j + 4].stone == WHITE) {//WWWXW
						stone[i - 3][j + 3].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
	}
	stonenum = 1;
	//만약 돌이 있으면 가중치를 0으로 초기화
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (stone[i][j].stone != 0) {
				stone[i][j].weight = 0;
			}
		}
	}
	//가중치의 최대값 찾기
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (max < stone[i][j].weight) {
				max = stone[i][j].weight;
			}
		}
	}
	//가중치가 제일 높은거 출력
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (max == stone[i][j].weight) {
				if (stone[i][j].stone != BLACK && stone[i][j].stone != WHITE) {
					*x = j;
					*y = i;
				}
			}
		}
	}
	//가중치 초기화
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			stone[i][j].weight = 0;
		}
	}
	board_2020184028[*y][*x] = WHITE;
}
void WhiteDefence_2020184028(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2020184028[y][x] = BLACK;
}
void BlackAttack_2020184028(int* x, int* y)
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요
	int check = 0;//한 줄씩 검색하게 하는 변수

	int Echeck = 0;//적 공백 체크
	int Estone = 1;//적돌 연속 체크해주는 변수
	int b = 0; //공백을 한번만 찾게 하는 변수
	int savex = 0; //공백일때의 좌표 저장변수
	int savey = 0; //공백일때의 좌표 저장변수
	//대각선 전용 변수
	int linenum = 1;//대각선 연속확인 변수


	int max = 0;//가중치의 최대값 변수


	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board_2020184028[i][j] != BLACK && board_2020184028[i][j] != WHITE) {
				stone[i][j].stone = 0;
			}
			else {
				stone[i][j].stone = board_2020184028[i][j];
			}
		}
	}

	if (stonenum == 0) {
		//처음 흑돌은 고정위치에 둔다.
		stone[8][8].weight += 10;
	}
	else if (stonenum == 1) {
		//랜덤하게 두는 돌 근데 판에 돌이 없을경우에만 발동되게한다.
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				//흑돌을 기준으로 주변 8자리의 가중치를 늘려준다.
				if (stone[i][j].stone == BLACK) {
					if (stone[i + 1][j].stone == 0) {//돌(남)빈칸일경우
						stone[i + 1][j].weight += 10;//가중치를 늘린다.
					}
					if (stone[i][j + 1].stone == 0) {//돌(동)빈칸일경우
						stone[i][j + 1].weight += 10;//가중치를 늘린다.
					}
					if (stone[i + 1][j + 1].stone == 0) {//돌(남동)빈칸일경우
						stone[i + 1][j + 1].weight += 10;//가중치를 늘린다.
					}

					if (i > 0) {
						if (stone[i - 1][j].stone == 0) {//돌(북)빈칸일경우
							stone[i - 1][j].weight += 10;//가중치를 늘린다.
						}
						if (stone[i - 1][j + 1].stone == 0) {//돌(북동)빈칸일경우
							stone[i - 1][j + 1].weight += 10;//가중치를 늘린다.
						}
					}
					if (j > 0) {
						if (stone[i][j - 1].stone == 0) {//돌(서)빈칸일경우
							stone[i][j - 1].weight += 10;//가중치를 늘린다.
						}
						if (stone[i + 1][j - 1].stone == 0) {//돌(남서)빈칸일경우
							stone[i + 1][j - 1].weight += 10;//가중치를 늘린다.
						}
					}
					if (i > 0 && j > 0) {
						if (stone[i - 1][j - 1].stone == 0) {//돌(북서)빈칸일경우
							stone[i - 1][j - 1].weight += 10;//가중치를 늘린다.
						}
					}
				}
			}
		}
		//적돌 가로 연속 체크(수비)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0) {//2칸연속일 경우
						stone[i][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == BLACK && stone[i][j - 1].stone == 0) {//2칸 연속인데 닫혀있는경우
						stone[i][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == BLACK && stone[i][j - 1].stone == 0) {//3칸 연속인데 닫혀있는경우
						stone[i][j - 1].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == 0) {//3칸연속일경우
						stone[i][j + 3].weight += 40;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == BLACK && stone[i][j - 1].stone == 0) {//4칸 연속인데 닫혀 있는경우
						stone[i][j - 1].weight += 60;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == 0) {//4칸연속일경우
						stone[i][j + 4].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		//적돌 세로 연속 체크(수비)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0) {//2칸연속일 경우
						stone[i + 2][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == BLACK && stone[i - 1][j].stone == 0) {//2칸 연속인데 닫혀있는경우
						stone[i - 1][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == BLACK && stone[i - 1][j].stone == 0) {//3칸 연속인데 닫혀있는경우
						stone[i - 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == 0) {//3칸연속일경우
						stone[i + 3][j].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == BLACK && stone[i - 1][j].stone == 0) {//4칸 연속인데 닫혀 있는경우
						stone[i - 1][j].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == 0) {//4칸연속일경우
						stone[i + 4][j].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//좌하향 대각선 막기
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == 0) {//좌하향 2칸 연속일경우
						stone[i + 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//좌하향 2칸 연속일때 닫힌경우
						stone[i - 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == 0) {//좌하향 3칸 연속일경우
						stone[i + 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//좌하향 3칸 연속일때 닫힌경우
						stone[i - 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == 0) {//좌하향 4칸 연속일경우
						stone[i + 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//좌하향 4칸 연속일때 닫힌경우
						stone[i - 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//좌상향 대각선 막기
		for (int i = 19; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == 0) {//좌상향 2칸연속일때
						stone[i - 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == BLACK && stone[i + 1][j - 1].stone == 0) { //좌상향 2칸연속일때 닫힌경우
						stone[i + 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == 0) { //좌상향 3칸연속일때
						stone[i - 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == BLACK && stone[i + 1][j - 1].stone == 0) { //좌상향 3칸연속일때 닫힌경우
						stone[i + 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == 0) { //좌상향 4칸연속일때
						stone[i - 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == BLACK && stone[i + 1][j - 1].stone == 0) { //좌상향 4칸연속일때 닫힌경우
						stone[i + 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//가로 공백 체크
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE) {//OXO이경우
						stone[i][j + 1].weight += 20;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == WHITE) {//OOXO경우
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE) {//OXOO경우
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == 0 && stone[i][j + 4].stone == WHITE) {//OOOXO경우
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == WHITE) {//OXOOO경우
						stone[i][j + 1].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == WHITE) {//OOXOO경우
						stone[i][j + 2].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//세로 공백 체크
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE) {//OXO이경우
						stone[i + 1][j].weight += 20;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == WHITE) {//OOXO경우
						stone[i + 2][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE) {//OXOO경우
						stone[i + 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == 0 && stone[i + 4][j].stone == WHITE) {//OOOXO경우
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == WHITE) {//OXOOO경우
						stone[i + 1][j].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == WHITE) {//OOXOO경우
						stone[i + 2][j].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(가로)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == 0) {//열린경우 BBBBX
						stone[i][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == WHITE && stone[i][j - 1].stone == 0) {//닫힌경우 XBBBBW
						stone[i][j - 1].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == BLACK) {// BXBBB
						stone[i][j + 1].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == BLACK) {// BBXBB
						stone[i][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == 0 && stone[i][j + 4].stone == BLACK) {// BBBXB
						stone[i][j + 3].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(세로)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == 0) {//열린경우 BBBBX
						stone[i + 4][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == WHITE && stone[i - 1][j].stone == 0) {//닫힌경우 XBBBBW
						stone[i - 1][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == BLACK) {// BXBBB
						stone[i + 1][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == BLACK) {// BBXBB
						stone[i + 2][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == 0 && stone[i + 4][j].stone == BLACK) {// BBBXB
						stone[i + 3][j].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(대각선 좌하향)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == 0) {//열린경우 BBBBX
						stone[i + 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//닫힌경우 XBBBBW
						stone[i - 1][j - 1].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == 0 && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == BLACK) {//BXBBB
						stone[i + 1][j + 1].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == 0 && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == BLACK) {//BBXBB
						stone[i + 2][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == 0 && stone[i + 4][j + 4].stone == BLACK) {//BBBXB
						stone[i + 3][j + 3].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//이길수 있는경우의 가중치(대각선 좌상향)
		for (int i = 18; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == 0) {//열린경우 BBBBX
						stone[i - 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == WHITE && stone[i + 1][j - 1].stone == 0) {//닫힌경우 XBBBBW
						stone[i + 1][j - 1].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == 0 && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == BLACK) {//BXBBB
						stone[i - 1][j + 1].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == 0 && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == BLACK) {//BBXBB
						stone[i - 2][j + 2].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == 0 && stone[i - 4][j + 4].stone == BLACK) {//BBBXB
						stone[i - 3][j + 3].weight += 200;
						check = 1;
					}
				}
			}
			check = 0;
		}
	}
	stonenum = 1;
	//만약 돌이 있으면 가중치를 0으로 초기화
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (stone[i][j].stone != 0) {
				stone[i][j].weight = 0;
			}
		}
	}
	//가중치의 최대값 찾기
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (max < stone[i][j].weight) {
				max = stone[i][j].weight;
			}
		}
	}
	//가중치가 제일 높은거 출력
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (max == stone[i][j].weight) {
				if (stone[i][j].stone != BLACK && stone[i][j].stone != WHITE) {
					*x = j;
					*y = i;
				}
			}
		}
	}
	//가중치 초기화
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			stone[i][j].weight = 0;
		}
	}
	board_2020184028[*y][*x] = BLACK;
}
void BlackDefence_2020184028(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2020184028[y][x] = WHITE;
}