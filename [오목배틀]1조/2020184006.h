#pragma once
int board_2020184006[19][19];
#define WHITE 1
#define BLACK -1
int black_turn_2020184006 = 0;
int white_turn_2020184006 = 0;
typedef struct OmokS {
	int Stone_2020184006 = 0;
	int garo_line = 0;
	int sero_line = 0;
	int ldegak_line = 0;
	int rdegak_line = 0;
	int ga_line = 0;
	int weight = 0;
	int garo3 = 0;
	int sero3 = 0;
	int rdegak3 = 0;
	int ldegak3 = 0;
	int gongbak = 0;
}OmokS;
OmokS Stone_2020184006[19][19];
int aa_2020184006 = 0, bb_2020184006 = 0;
int a_2020184006 = 0, s_2020184006 = 0;
int d_2020184006 = 0;
void WhiteAttack_2020184006(int* x, int* y) {
	int max = 0;
	aa_2020184006 = 0, bb_2020184006 = 0;
	int g = 0;
	for (int j = 0; j <= 18; j++) {
		for (int i = j; i >= 0; i--) {
			if (Stone_2020184006[g][i].Stone_2020184006 != 0) {
				if (i > 0) {
					if (Stone_2020184006[g][i].Stone_2020184006 != Stone_2020184006[g + 1][i - 1].Stone_2020184006) {
						Stone_2020184006[g][i].rdegak_line = 1;
						Stone_2020184006[g][i].gongbak = 0;
					}
				}
				if (i > 1) {
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006) && (Stone_2020184006[g + 2][i - 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 2;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006) && (Stone_2020184006[g + 1][i - 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
				}
				if (i > 2) {
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006) && (Stone_2020184006[g + 3][i - 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 3;
						Stone_2020184006[g][i].rdegak3 = 1;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006) && (Stone_2020184006[g + 1][i - 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 3;
						Stone_2020184006[g][i].rdegak3 = 1;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006) && (Stone_2020184006[g + 2][i - 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 3;
						Stone_2020184006[g][i].rdegak3 = 1;
						Stone_2020184006[g][i].gongbak = 1;
					}
				}
				if (i > 3) {
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006) && (Stone_2020184006[g + 4][i - 4].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 4;
						Stone_2020184006[g][i].rdegak3 = 2;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006 == Stone_2020184006[g + 4][i - 4].Stone_2020184006) && (Stone_2020184006[g + 1][i - 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 4;
						Stone_2020184006[g][i].rdegak3 = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006 == Stone_2020184006[g + 4][i - 4].Stone_2020184006) && (Stone_2020184006[g + 2][i - 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 4;
						Stone_2020184006[g][i].rdegak3 = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 4][i - 4].Stone_2020184006) && (Stone_2020184006[g + 3][i - 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].rdegak_line = 4;
						Stone_2020184006[g][i].rdegak3 = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
				}
			}
			g++;
		}
		g = 0;
	}
	g = 18;
	for (int i = 18; i > 0; i--) {
		for (int j = 17 - (18 - i); j < 19; j++) {
			if (Stone_2020184006[j][g].Stone_2020184006 != 0) {
				if (j < 18) {
					if (Stone_2020184006[j][g].Stone_2020184006 != Stone_2020184006[j + 1][g - 1].Stone_2020184006) {
						Stone_2020184006[j][g].rdegak_line = 1;
						Stone_2020184006[j][g].gongbak = 0;
					}
				}
				if (j < 17) {
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006) && (Stone_2020184006[j + 2][g - 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 2;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006) && (Stone_2020184006[j + 1][g - 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
				}
				if (j < 16) {
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006) && (Stone_2020184006[j + 3][g - 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 3;
						Stone_2020184006[j][g].ldegak3 = 1;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006) && (Stone_2020184006[j + 1][g - 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 3;
						Stone_2020184006[j][g].ldegak3 = 1;
						Stone_2020184006[j][g].gongbak = 1;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006) && (Stone_2020184006[j + 2][g - 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 3;
						Stone_2020184006[j][g].ldegak3 = 1;
						Stone_2020184006[j][g].gongbak = 1;
					}
				}
				if (j < 15) {
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006) && (Stone_2020184006[j + 4][g - 4].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006 == Stone_2020184006[j + 4][g - 4].Stone_2020184006) && (Stone_2020184006[j + 1][g - 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006 == Stone_2020184006[j + 4][g - 4].Stone_2020184006) && (Stone_2020184006[j + 2][g - 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 4][g - 4].Stone_2020184006) && (Stone_2020184006[j + 3][g - 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].rdegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
				}
			}
			g--;
		}
		g = 18;
	}
	g = 0;
	for (int i = 17; i > 0; i--) {
		for (int j = i; j < 19; j++) {
			if (Stone_2020184006[j][g].Stone_2020184006 != 0) {
				if (Stone_2020184006[j][g].Stone_2020184006 != Stone_2020184006[j + 1][g + 1].Stone_2020184006) {
					Stone_2020184006[j][g].ldegak_line = 1;
					Stone_2020184006[j][g].gongbak = 0;
				}
				if (j < 17) {
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006) && (Stone_2020184006[j + 2][g + 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 2;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006) && (Stone_2020184006[j + 1][g + 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
				}
				if (j < 16) {
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006) && (Stone_2020184006[j + 3][g + 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 3;
						Stone_2020184006[j][g].ldegak3 = 1;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006) && (Stone_2020184006[j + 1][g + 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 3;
						Stone_2020184006[j][g].ldegak3 = 1;
						Stone_2020184006[j][g].gongbak = 1;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006) && (Stone_2020184006[j + 2][g + 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 3;
						Stone_2020184006[j][g].ldegak3 = 1;
						Stone_2020184006[j][g].gongbak = 1;
					}
				}
				if (j < 15) {
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006) && (Stone_2020184006[j + 4][g + 4].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006 == Stone_2020184006[j + 4][g + 4].Stone_2020184006) && (Stone_2020184006[j + 1][g + 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006 == Stone_2020184006[j + 4][g + 4].Stone_2020184006) && (Stone_2020184006[j + 2][g + 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
					if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 4][g + 4].Stone_2020184006) && (Stone_2020184006[j + 3][g + 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
						Stone_2020184006[j][g].ldegak_line = 4;
						Stone_2020184006[j][g].ldegak3 = 2;
						Stone_2020184006[j][g].gongbak = 1;
					}
				}
			}
			g++;
		}
		g = 0;
	}
	for (int j = 0; j < 18; j++) {
		for (int i = j; i < 19; i++) {
			if (Stone_2020184006[g][i].Stone_2020184006 != 0) {
				if (Stone_2020184006[g][i].Stone_2020184006 != Stone_2020184006[g + 1][i + 1].Stone_2020184006) {
					Stone_2020184006[g][i].ldegak_line = 1;
					Stone_2020184006[g][i].gongbak = 0;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006) && (Stone_2020184006[g + 2][i + 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 2;
					Stone_2020184006[g][i].gongbak = 0;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006) && (Stone_2020184006[g + 1][i + 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 2;
					Stone_2020184006[g][i].gongbak = 1;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006) && (Stone_2020184006[g + 3][i + 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 3;
					Stone_2020184006[g][i].ldegak3 = 1;
					Stone_2020184006[g][i].gongbak = 0;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006) && (Stone_2020184006[g + 1][i + 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 3;
					Stone_2020184006[g][i].ldegak3 = 1;
					Stone_2020184006[g][i].gongbak = 1;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006) && (Stone_2020184006[g + 2][i + 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 3;
					Stone_2020184006[g][i].ldegak3 = 1;
					Stone_2020184006[g][i].gongbak = 1;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006) && (Stone_2020184006[g + 4][i + 4].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 4;
					Stone_2020184006[g][i].ldegak3 = 2;
					Stone_2020184006[g][i].gongbak = 0;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006 == Stone_2020184006[g + 4][i + 4].Stone_2020184006) && (Stone_2020184006[g + 1][i + 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 4;
					Stone_2020184006[g][i].ldegak3 = 2;
					Stone_2020184006[g][i].gongbak = 1;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006 == Stone_2020184006[g + 4][i + 4].Stone_2020184006) && (Stone_2020184006[g + 2][i + 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 4;
					Stone_2020184006[g][i].ldegak3 = 2;
					Stone_2020184006[g][i].gongbak = 1;
				}
				if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 4][i + 4].Stone_2020184006) && (Stone_2020184006[g + 3][i + 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
					Stone_2020184006[g][i].ldegak_line = 4;
					Stone_2020184006[g][i].ldegak3 = 2;
					Stone_2020184006[g][i].gongbak = 1;
				}
			}
			g++;
		}
		g = 0;
	}
	for (int i = 0;i < 19;i++) {
		for (int j = 0;j < 19;j++) {
			if (Stone_2020184006[j][i].Stone_2020184006 != 0) {
				if (Stone_2020184006[j][i].Stone_2020184006 != Stone_2020184006[j][i + 1].Stone_2020184006) {
					Stone_2020184006[j][i].garo_line = 1;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006) && (Stone_2020184006[j][i + 2].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 2;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006) && (Stone_2020184006[j][i + 1].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 2;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006) && (Stone_2020184006[j][i + 3].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 3;
					Stone_2020184006[j][i].garo3 = 1;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006) && (Stone_2020184006[j][i + 1].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 3;
					Stone_2020184006[j][i].garo3 = 1;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006) && (Stone_2020184006[j][i + 2].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 3;
					Stone_2020184006[j][i].garo3 = 1;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006) && (Stone_2020184006[j][i + 4].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 4;
					Stone_2020184006[j][i].garo3 = 2;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006 == Stone_2020184006[j][i + 4].Stone_2020184006) && (Stone_2020184006[j][i + 1].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 4;
					Stone_2020184006[j][i].garo3 = 2;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006 == Stone_2020184006[j][i + 4].Stone_2020184006) && (Stone_2020184006[j][i + 2].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 4;
					Stone_2020184006[j][i].garo3 = 2;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 4].Stone_2020184006) && (Stone_2020184006[j][i + 3].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
					Stone_2020184006[j][i].garo_line = 4;
					Stone_2020184006[j][i].garo3 = 2;
					Stone_2020184006[j][i].gongbak = 1;
				}
			}
		}
	}
	for (int j = 0;j < 19;j++) {
		for (int i = 0;i < 19;i++) {
			if (Stone_2020184006[j][i].Stone_2020184006 != 0) {
				if (Stone_2020184006[j][i].Stone_2020184006 != Stone_2020184006[j + 1][i].Stone_2020184006) {
					Stone_2020184006[j][i].sero_line = 1;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006) && (Stone_2020184006[j + 2][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 2;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006) && (Stone_2020184006[j + 1][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 2;
					Stone_2020184006[j][i].gongbak = 1;

				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006) && (Stone_2020184006[j + 3][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 3;
					Stone_2020184006[j][i].sero3 = 1;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006) && (Stone_2020184006[j + 1][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 3;
					Stone_2020184006[j][i].sero3 = 1;
					Stone_2020184006[j][i].gongbak = 1;

				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006) && (Stone_2020184006[j + 2][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 3;
					Stone_2020184006[j][i].sero3 = 1;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006) && (Stone_2020184006[j + 4][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 4;
					Stone_2020184006[j][i].sero3 = 2;
					Stone_2020184006[j][i].gongbak = 0;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006 == Stone_2020184006[j + 4][i].Stone_2020184006) && (Stone_2020184006[j + 1][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 4;
					Stone_2020184006[j][i].sero3 = 2;
					Stone_2020184006[j][i].gongbak = 1;

				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006 == Stone_2020184006[j + 4][i].Stone_2020184006) && (Stone_2020184006[j + 2][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 4;
					Stone_2020184006[j][i].sero3 = 2;
					Stone_2020184006[j][i].gongbak = 1;
				}
				if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 4][i].Stone_2020184006) && (Stone_2020184006[j + 3][i].Stone_2020184006 == 0)) {
					Stone_2020184006[j][i].sero_line = 4;
					Stone_2020184006[j][i].sero3 = 2;
					Stone_2020184006[j][i].gongbak = 1;
				}
			}
		}
	}
	for (int i = 0;i < 19;i++) {
		for (int j = 0;j < 19;j++) {
			if (Stone_2020184006[j][i].Stone_2020184006 != 0) {
				switch (Stone_2020184006[j][i].sero_line) {
				case 1:
					if (i > 0 && j > 0) {
						Stone_2020184006[j - 1][i - 1].weight += 1;
						Stone_2020184006[j - 1][i].weight += 1;
						Stone_2020184006[j - 1][i + 1].weight += 1;
						Stone_2020184006[j][i - 1].weight += 1;
						Stone_2020184006[j][i + 1].weight += 1;
						Stone_2020184006[j + 1][i - 1].weight += 1;
						Stone_2020184006[j + 1][i].weight += 1;
						Stone_2020184006[j + 1][i + 1].weight += 1;
					}
					else {
						Stone_2020184006[j - 1][i].weight += 1;
						Stone_2020184006[j - 1][i + 1].weight += 1;
						Stone_2020184006[j][i + 1].weight += 1;
						Stone_2020184006[j + 1][i].weight += 1;
						Stone_2020184006[j + 1][i + 1].weight += 1;
					}
					break;
				case 2:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //XWWX
							Stone_2020184006[j - 1][i].weight += 30000;
							Stone_2020184006[j + 2][i].weight += 30000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 != 0) { //XWWB
							Stone_2020184006[j - 1][i].weight += 500;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //BWWX
							Stone_2020184006[j + 2][i].weight += 500;
						}
					}
					else {
						if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWX
							Stone_2020184006[j - 1][i].weight += 30000;
							Stone_2020184006[j + 1][i].weight += 300000;
							Stone_2020184006[j + 3][i].weight += 30000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWB
							Stone_2020184006[j - 1][i].weight += 500;
							Stone_2020184006[j + 1][i].weight += 500;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //BWXWX
							Stone_2020184006[j + 1][i].weight += 500;
							Stone_2020184006[j + 3][i].weight += 500;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //BWXWB
							Stone_2020184006[j + 1][i].weight += 500;
						}
					}
					break;
				case 3:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //XWWWX
							Stone_2020184006[j - 1][i].weight += 8470000;
							Stone_2020184006[j + 3][i].weight += 8470000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 != 0) { //XWWWB
							Stone_2020184006[j - 1][i].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //BWWWX
							Stone_2020184006[j + 3][i].weight += 145000;
						}
					}
					else {
						if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) {//X0X00X
							Stone_2020184006[j - 1][i].weight += 847000;
							Stone_2020184006[j + 4][i].weight += 847000;
							Stone_2020184006[j + 1][i].weight += 8470000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) {//BWXWWX
							Stone_2020184006[j + 4][i].weight += 1450;
							Stone_2020184006[j + 1][i].weight += 1450;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) {//XWXWWB
							Stone_2020184006[j - 1][i].weight += 145000;
							Stone_2020184006[j + 1][i].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) {//XWWXWX
							Stone_2020184006[j - 1][i].weight += 847000;
							Stone_2020184006[j + 4][i].weight += 847000;
							Stone_2020184006[j + 2][i].weight += 8470000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) {//BWWXWX
							Stone_2020184006[j + 4][i].weight += 145000;
							Stone_2020184006[j + 2][i].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) {//XWWXWB
							Stone_2020184006[j - 1][i].weight += 145000;
							Stone_2020184006[j + 2][i].weight += 145000;
						}
					}
					break;
				case 4:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0) { //XWWWWX
							Stone_2020184006[j - 1][i].weight += 700000000;
							Stone_2020184006[j + 4][i].weight += 700000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 != 0) { //XWWWWB
							Stone_2020184006[j - 1][i].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0) { //BWWWWX
							Stone_2020184006[j + 4][i].weight += 30000000;
						}
					}
					else {
						if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWWWX
							Stone_2020184006[j - 1][i].weight += 7000000;
							Stone_2020184006[j + 1][i].weight += 700000000;
							Stone_2020184006[j + 5][i].weight += 7000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWWWB
							Stone_2020184006[j - 1][i].weight += 3000000;
							Stone_2020184006[j + 1][i].weight += 3000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //BWXWWWX
							Stone_2020184006[j + 5][i].weight += 3000000;
							Stone_2020184006[j + 1][i].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //XWWXWWX
							Stone_2020184006[j - 1][i].weight += 7000000;
							Stone_2020184006[j + 5][i].weight += 7000000;
							Stone_2020184006[j + 2][i].weight += 700000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //XWWXWWB
							Stone_2020184006[j - 1][i].weight += 3000000;
							Stone_2020184006[j + 2][i].weight += 300000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //BWWXWWX
							Stone_2020184006[j + 5][i].weight += 3000000;
							Stone_2020184006[j + 2][i].weight += 300000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //XWWWXWX
							Stone_2020184006[j - 1][i].weight += 7000000;
							Stone_2020184006[j + 5][i].weight += 7000000;
							Stone_2020184006[j + 3][i].weight += 700000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //XWWWXWB
							Stone_2020184006[j - 1][i].weight += 3000000;
							Stone_2020184006[j + 3][i].weight += 300000000;
						}
						else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //BWWWXWX
							Stone_2020184006[j + 5][i].weight += 3000000;
							Stone_2020184006[j + 3][i].weight += 300000000;
						}
					}
					break;
				default:
					break;
				}
				switch (Stone_2020184006[j][i].rdegak_line) {
				case 1:
					Stone_2020184006[j - 1][i - 1].weight += 1;
					Stone_2020184006[j - 1][i].weight += 1;
					Stone_2020184006[j - 1][i + 1].weight += 1;
					Stone_2020184006[j][i - 1].weight += 1;
					Stone_2020184006[j][i + 1].weight += 1;
					Stone_2020184006[j + 1][i - 1].weight += 1;
					Stone_2020184006[j + 1][i].weight += 1;
					Stone_2020184006[j + 1][i + 1].weight += 1;
					break;
				case 2:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (j < 17) {
							if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {
								Stone_2020184006[j - 1][i + 1].weight += 30000;
								Stone_2020184006[j + 2][i - 2].weight += 30000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 != 0) {
								Stone_2020184006[j - 1][i + 1].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {
								Stone_2020184006[j + 2][i - 2].weight += 500;
							}
						}
					}
					else {
						if (j < 16) {
							if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWX
								Stone_2020184006[j - 1][i + 1].weight += 30000;
								Stone_2020184006[j + 1][i - 1].weight += 300000;
								Stone_2020184006[j + 3][i - 3].weight += 30000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWB
								Stone_2020184006[j - 1][i + 1].weight += 500;
								Stone_2020184006[j + 1][i - 1].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //BWXWX
								Stone_2020184006[j + 1][i - 1].weight += 500;
								Stone_2020184006[j + 3][i - 3].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //BWXWB
								Stone_2020184006[j + 1][i - 1].weight += 500;
							}
						}
					}
					break;
				case 3:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (j < 16) {
							if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //XWWWX
								Stone_2020184006[j - 1][i + 1].weight += 8470000;
								Stone_2020184006[j + 3][i - 3].weight += 8470000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 != 0) { //XWWWB
								Stone_2020184006[j - 1][i + 1].weight += 145000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //BWWWX
								Stone_2020184006[j + 3][i - 3].weight += 145000;
							}
						}
					}
					else {
						if (j < 15) {
							if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) {//X0X00X
								Stone_2020184006[j - 1][i + 1].weight += 847000;
								Stone_2020184006[j + 4][i - 4].weight += 847000;
								Stone_2020184006[j + 1][i - 1].weight += 8470000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) {//BWXWWX
								Stone_2020184006[j + 4][i - 4].weight += 145000;
								Stone_2020184006[j + 1][i - 1].weight += 145000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) {//XWXWWB
								Stone_2020184006[j - 1][i + 1].weight += 145000;
								Stone_2020184006[j + 1][i - 1].weight += 145000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {//XWWXWX
								Stone_2020184006[j - 1][i + 1].weight += 847000;
								Stone_2020184006[j + 4][i - 4].weight += 847000;
								Stone_2020184006[j + 2][i - 2].weight += 8470000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {//BWWXWX
								Stone_2020184006[j + 4][i - 4].weight += 145000;
								Stone_2020184006[j + 2][i - 2].weight += 145000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {//XWWXWB
								Stone_2020184006[j - 1][i + 1].weight += 145000;
								Stone_2020184006[j + 2][i - 2].weight += 145000;
							}
						}
					}
					break;
				case 4:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (j < 15) {
							if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0) { //XWWWWX
								Stone_2020184006[j - 1][i + 1].weight += 70000000;
								Stone_2020184006[j + 4][i - 4].weight += 70000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 != 0) { //XWWWWB
								Stone_2020184006[j - 1][i + 1].weight += 30000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0) { //BWWWWX
								Stone_2020184006[j + 4][i - 4].weight += 30000000;
							}
						}
					}
					else {
						if (j < 14) {
							if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWWWX
								Stone_2020184006[j - 1][i + 1].weight += 7000000;
								Stone_2020184006[j + 1][i - 1].weight += 70000000;
								Stone_2020184006[j + 5][i - 5].weight += 7000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWWWB
								Stone_2020184006[j - 1][i + 1].weight += 3000000;
								Stone_2020184006[j + 1][i - 1].weight += 30000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //BWXWWWX
								Stone_2020184006[j + 5][i - 5].weight += 3000000;
								Stone_2020184006[j + 1][i - 1].weight += 30000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) { //XWWXWWX
								Stone_2020184006[j - 1][i + 1].weight += 7000000;
								Stone_2020184006[j + 5][i - 5].weight += 7000000;
								Stone_2020184006[j + 2][i - 2].weight += 70000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) { //XWWXWWB
								Stone_2020184006[j - 1][i + 1].weight += 3000000;
								Stone_2020184006[j + 2][i - 2].weight += 30000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) { //BWWXWWX
								Stone_2020184006[j + 5][i - 5].weight += 3000000;
								Stone_2020184006[j + 2][i + -2].weight += 30000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //XWWWXWX
								Stone_2020184006[j - 1][i + 1].weight += 7000000;
								Stone_2020184006[j + 5][i - 5].weight += 7000000;
								Stone_2020184006[j + 3][i - 3].weight += 70000000;
							}
							else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //XWWWXWB
								Stone_2020184006[j - 1][i + 1].weight += 3000000;
								Stone_2020184006[j + 3][i - 3].weight += 30000000;
							}
							else if (Stone_2020184006[j + 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //BWWWXWX
								Stone_2020184006[j + 5][i - 5].weight += 3000000;
								Stone_2020184006[j + 3][i - 3].weight += 30000000;
							}
						}
					}
					break;
				default:
					break;
				}
				switch (Stone_2020184006[j][i].garo_line) {
				case 1:
					if (j > 0) {
						Stone_2020184006[j - 1][i - 1].weight += 1;
						Stone_2020184006[j - 1][i].weight += 1;
						Stone_2020184006[j - 1][i + 1].weight += 1;
						Stone_2020184006[j][i - 1].weight += 1;
						Stone_2020184006[j][i + 1].weight += 1;
						Stone_2020184006[j + 1][i - 1].weight += 1;
						Stone_2020184006[j + 1][i].weight += 1;
						Stone_2020184006[j + 1][i + 1].weight += 1;
					}
					else {
						Stone_2020184006[j][i - 1].weight += 1;
						Stone_2020184006[j][i + 1].weight += 1;
						Stone_2020184006[j + 1][i - 1].weight += 1;
						Stone_2020184006[j + 1][i].weight += 1;
						Stone_2020184006[j + 1][i + 1].weight += 1;
					}
					break;
				case 2:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //XWWX
							Stone_2020184006[j][i - 1].weight += 30000;
							Stone_2020184006[j][i + 2].weight += 30000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 != 0) { //XWWB
							Stone_2020184006[j][i - 1].weight += 500;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //BWWX
							Stone_2020184006[j][i + 2].weight += 500;
						}
					}
					else {
						if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWX
							Stone_2020184006[j][i - 1].weight += 30000;
							Stone_2020184006[j][i + 1].weight += 300000;
							Stone_2020184006[j][i + 3].weight += 30000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWB
							Stone_2020184006[j][i - 1].weight += 500;
							Stone_2020184006[j][i + 1].weight += 500;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //BWXWX
							Stone_2020184006[j][i + 1].weight += 500;
							Stone_2020184006[j][i + 3].weight += 500;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //BWXWB
							Stone_2020184006[j][i + 1].weight += 500;
						}
					}
					break;
				case 3:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //XWWWX
							Stone_2020184006[j][i - 1].weight += 8470000;
							Stone_2020184006[j][i + 3].weight += 8470000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 != 0) { //XWWWB
							Stone_2020184006[j][i - 1].weight += 145000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //BWWWX
							Stone_2020184006[j][i + 3].weight += 145000;
						}
					}
					else {
						if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) {//X0X00X
							Stone_2020184006[j][i - 1].weight += 847000;
							Stone_2020184006[j][i + 4].weight += 847000;
							Stone_2020184006[j][i + 1].weight += 8470000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) {//BWXWWX
							Stone_2020184006[j][i + 4].weight += 145000;
							Stone_2020184006[j][i + 1].weight += 145000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) {//XWXWWB
							Stone_2020184006[j][i - 1].weight += 145000;
							Stone_2020184006[j][i + 1].weight += 145000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) {//XWWXWX
							Stone_2020184006[j][i - 1].weight += 847000;
							Stone_2020184006[j][i + 4].weight += 847000;
							Stone_2020184006[j][i + 2].weight += 8470000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) {//BWWXWX
							Stone_2020184006[j][i + 4].weight += 145000;
							Stone_2020184006[j][i + 2].weight += 145000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) {//XWWXWB
							Stone_2020184006[j][i - 1].weight += 145000;
							Stone_2020184006[j][i + 2].weight += 145000;
						}
					}
					break;
				case 4:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0) { //XWWWWX
							Stone_2020184006[j][i - 1].weight += 70000000;
							Stone_2020184006[j][i + 4].weight += 70000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 != 0) { //XWWWWB
							Stone_2020184006[j][i - 1].weight += 300000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0) { //BWWWWX
							Stone_2020184006[j][i + 4].weight += 300000000;
						}
					}
					else {
						if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWWWX
							Stone_2020184006[j][i - 1].weight += 7000000;
							Stone_2020184006[j][i + 1].weight += 70000000;
							Stone_2020184006[j][i + 5].weight += 7000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWWWB
							Stone_2020184006[j][i - 1].weight += 3000000;
							Stone_2020184006[j][i + 1].weight += 30000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //BWXWWWX
							Stone_2020184006[j][i + 5].weight += 3000000;
							Stone_2020184006[j][i + 1].weight += 30000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //XWWXWWX
							Stone_2020184006[j][i - 1].weight += 7000000;
							Stone_2020184006[j][i + 5].weight += 7000000;
							Stone_2020184006[j][i + 2].weight += 70000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //XWWXWWB
							Stone_2020184006[j][i - 1].weight += 3000000;
							Stone_2020184006[j][i + 2].weight += 30000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //BWWXWWX
							Stone_2020184006[j][i + 5].weight += 3000000;
							Stone_2020184006[j][i + 2].weight += 30000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //XWWWXWX
							Stone_2020184006[j][i - 1].weight += 7000000;
							Stone_2020184006[j][i + 5].weight += 7000000;
							Stone_2020184006[j][i + 3].weight += 70000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //XWWWXWB
							Stone_2020184006[j][i - 1].weight += 3000000;
							Stone_2020184006[j][i + 3].weight += 30000000;
						}
						else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //BWWWXWX
							Stone_2020184006[j][i + 5].weight += 3000000;
							Stone_2020184006[j][i + 3].weight += 30000000;
						}
					}
					break;
				default:
					break;
				}
				switch (Stone_2020184006[j][i].ldegak_line) {
				case 1:
					Stone_2020184006[j - 1][i - 1].weight += 1;
					Stone_2020184006[j - 1][i].weight += 1;
					Stone_2020184006[j - 1][i + 1].weight += 1;
					Stone_2020184006[j][i - 1].weight += 1;
					Stone_2020184006[j][i + 1].weight += 1;
					Stone_2020184006[j + 1][i - 1].weight += 1;
					Stone_2020184006[j + 1][i].weight += 1;
					Stone_2020184006[j + 1][i + 1].weight += 1;
					break;
				case 2:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {
							Stone_2020184006[j - 1][i - 1].weight += 30000;
							Stone_2020184006[j + 2][i + 2].weight += 30000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 != 0) {
							Stone_2020184006[j - 1][i - 1].weight += 500;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {
							Stone_2020184006[j + 2][i + 2].weight += 500;
						}
					}
					else {
						if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWX
							Stone_2020184006[j - 1][i - 1].weight += 30000;
							Stone_2020184006[j + 1][i + 1].weight += 300000;
							Stone_2020184006[j + 3][i + 3].weight += 30000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWB
							Stone_2020184006[j - 1][i - 1].weight += 500;
							Stone_2020184006[j + 1][i + 1].weight += 500;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //BWXWX
							Stone_2020184006[j + 1][i + 1].weight += 500;
							Stone_2020184006[j + 3][i + 3].weight += 500;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //BWXWB
							Stone_2020184006[j + 1][i + 1].weight += 500;
						}
					}
					break;
				case 3:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //XWWWX
							Stone_2020184006[j - 1][i - 1].weight += 8470000;
							Stone_2020184006[j + 3][i + 3].weight += 8470000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 != 0) { //XWWWB
							Stone_2020184006[j - 1][i - 1].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //BWWWX
							Stone_2020184006[j + 3][i + 3].weight += 145000;
						}
					}
					else {
						if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) {//X0X00X
							Stone_2020184006[j - 1][i - 1].weight += 847000;
							Stone_2020184006[j + 4][i + 4].weight += 847000;
							Stone_2020184006[j + 1][i + 1].weight += 8470000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) {//BWXWWX
							Stone_2020184006[j + 4][i + 4].weight += 145000;
							Stone_2020184006[j + 1][i + 1].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) {//XWXWWB
							Stone_2020184006[j - 1][i - 1].weight += 145000;
							Stone_2020184006[j + 1][i + 1].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {//XWWXWX
							Stone_2020184006[j - 1][i - 1].weight += 847000;
							Stone_2020184006[j + 4][i + 4].weight += 847000;
							Stone_2020184006[j + 2][i + 2].weight += 8470000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {//BWWXWX
							Stone_2020184006[j + 4][i + 4].weight += 145000;
							Stone_2020184006[j + 2][i + 2].weight += 145000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {//XWWXWB
							Stone_2020184006[j - 1][i - 1].weight += 145000;
							Stone_2020184006[j + 2][i + 2].weight += 145000;
						}
					}
					break;
				case 4:
					if (Stone_2020184006[j][i].gongbak == 0) {
						if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0) { //XWWWWX
							Stone_2020184006[j - 1][i - 1].weight += 70000000;
							Stone_2020184006[j + 4][i + 4].weight += 70000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 != 0) { //XWWWWB
							Stone_2020184006[j - 1][i - 1].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0) { //BWWWWX
							Stone_2020184006[j + 4][i + 4].weight += 30000000;
						}
					}
					else {
						if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWWWX
							Stone_2020184006[j - 1][i - 1].weight += 7000000;
							Stone_2020184006[j + 1][i + 1].weight += 70000000;
							Stone_2020184006[j + 5][i + 5].weight += 7000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWWWB
							Stone_2020184006[j - 1][i - 1].weight += 3000000;
							Stone_2020184006[j + 1][i + 1].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //BWXWWWX
							Stone_2020184006[j + 5][i + 5].weight += 3000000;
							Stone_2020184006[j + 1][i + 1].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) { //XWWXWWX
							Stone_2020184006[j - 1][i - 1].weight += 7000000;
							Stone_2020184006[j + 5][i + 5].weight += 7000000;
							Stone_2020184006[j + 2][i + 2].weight += 70000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) { //XWWXWWB
							Stone_2020184006[j - 1][i - 1].weight += 3000000;
							Stone_2020184006[j + 2][i + 2].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) { //BWWXWWX
							Stone_2020184006[j + 5][i + 5].weight += 3000000;
							Stone_2020184006[j + 2][i + 2].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //XWWWXWX
							Stone_2020184006[j - 1][i - 1].weight += 7000000;
							Stone_2020184006[j + 5][i + 5].weight += 7000000;
							Stone_2020184006[j + 3][i + 3].weight += 70000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //XWWWXWB
							Stone_2020184006[j - 1][i - 1].weight += 3000000;
							Stone_2020184006[j + 3][i + 3].weight += 30000000;
						}
						else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //BWWWXWX
							Stone_2020184006[j + 5][i + 5].weight += 3000000;
							Stone_2020184006[j + 3][i + 3].weight += 30000000;
						}
					}
					break;
				default:
					break;
				}
			}
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (Stone_2020184006[j][i].Stone_2020184006 == 0) {
				if (Stone_2020184006[j][i].weight > max) {
					max = Stone_2020184006[j][i].weight;
				}
			}
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (Stone_2020184006[j][i].Stone_2020184006 == 0) {
				if (max == Stone_2020184006[j][i].weight) {
					bb_2020184006 = j;
					aa_2020184006 = i;
				}
			}
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			Stone_2020184006[j][i].weight += 0;
			Stone_2020184006[j][i].weight += 0;
			Stone_2020184006[j][i].garo3 = 0;
			Stone_2020184006[j][i].sero3 = 0;
			Stone_2020184006[j][i].garo_line = 0;
			Stone_2020184006[j][i].sero_line = 0;
			Stone_2020184006[j][i].ldegak_line = 0;
			Stone_2020184006[j][i].rdegak_line = 0;
			Stone_2020184006[j][i].gongbak = 0;
		}
	}
	*x = aa_2020184006;
	*y = bb_2020184006;
	if (white_turn_2020184006 == 0) {
		*x = s_2020184006;
		*y = a_2020184006;
		white_turn_2020184006++;
	}
	Stone_2020184006[*y][*x].Stone_2020184006 = WHITE;
	board_2020184006[*y][*x] = WHITE;
}
void WhiteDefence_2020184006(int x, int y) {
	if (d_2020184006 == 0) {
		for (int i = 0;i < 19;i++) {
			for (int j = 0;j < 19;j++) {
				Stone_2020184006[i][j].Stone_2020184006 = 0;
				Stone_2020184006[i][j].garo_line = 0;
				Stone_2020184006[i][j].ldegak_line = 0;
				Stone_2020184006[i][j].rdegak_line = 0;
				Stone_2020184006[i][j].sero_line = 0;
				Stone_2020184006[i][j].weight += 0;
				Stone_2020184006[i][j].weight += 0;
				Stone_2020184006[i][j].gongbak = 0;
			}
		}
		d_2020184006++;
	}
	a_2020184006 = y;
	s_2020184006 = x - 1;
	Stone_2020184006[y][x].Stone_2020184006 = BLACK;
	board_2020184006[y][x] = BLACK;
}
void BlackAttack_2020184006(int* x, int* y) {
	if (black_turn_2020184006 == 0) {
		if (d_2020184006 == 0) {
			for (int i = 0;i < 19;i++) {
				for (int j = 0;j < 19;j++) {
					Stone_2020184006[i][j].Stone_2020184006 = 0;
					Stone_2020184006[i][j].garo_line = 0;
					Stone_2020184006[i][j].ldegak_line = 0;
					Stone_2020184006[i][j].rdegak_line = 0;
					Stone_2020184006[i][j].sero_line = 0;
					Stone_2020184006[i][j].weight = 0;
					Stone_2020184006[i][j].weight = 0;
					Stone_2020184006[i][j].gongbak = 0;
				}
			}
			d_2020184006++;
		}
		*x = 9; *y = 9;
		black_turn_2020184006++;
	}
	else {
		int max = 0;
		aa_2020184006 = 0, bb_2020184006 = 0;
		int g = 0;
		for (int j = 0; j <= 18; j++) {
			for (int i = j; i >= 0; i--) {
				if (Stone_2020184006[g][i].Stone_2020184006 != 0) {
					if (i > 0) {
						if (Stone_2020184006[g][i].Stone_2020184006 != Stone_2020184006[g + 1][i - 1].Stone_2020184006) {
							Stone_2020184006[g][i].rdegak_line = 1;
							Stone_2020184006[g][i].gongbak = 0;
						}
					}
					if (i > 1) {
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006) && (Stone_2020184006[g + 2][i - 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 2;
							Stone_2020184006[g][i].gongbak = 0;
						}
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006) && (Stone_2020184006[g + 1][i - 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 2;
							Stone_2020184006[g][i].gongbak = 1;
						}
					}
					if (i > 2) {
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006) && (Stone_2020184006[g + 3][i - 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 3;
							Stone_2020184006[g][i].rdegak3 = 1;
							Stone_2020184006[g][i].gongbak = 0;
						}
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006) && (Stone_2020184006[g + 1][i - 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 3;
							Stone_2020184006[g][i].rdegak3 = 1;
							Stone_2020184006[g][i].gongbak = 1;
						}
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006) && (Stone_2020184006[g + 2][i - 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 3;
							Stone_2020184006[g][i].rdegak3 = 1;
							Stone_2020184006[g][i].gongbak = 1;
						}
					}
					if (i > 3) {
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006) && (Stone_2020184006[g + 4][i - 4].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 4;
							Stone_2020184006[g][i].rdegak3 = 2;
							Stone_2020184006[g][i].gongbak = 0;
						}
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006 == Stone_2020184006[g + 4][i - 4].Stone_2020184006) && (Stone_2020184006[g + 1][i - 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 4;
							Stone_2020184006[g][i].rdegak3 = 2;
							Stone_2020184006[g][i].gongbak = 1;
						}
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 3][i - 3].Stone_2020184006 == Stone_2020184006[g + 4][i - 4].Stone_2020184006) && (Stone_2020184006[g + 2][i - 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 4;
							Stone_2020184006[g][i].rdegak3 = 2;
							Stone_2020184006[g][i].gongbak = 1;
						}
						if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i - 1].Stone_2020184006 == Stone_2020184006[g + 2][i - 2].Stone_2020184006 == Stone_2020184006[g + 4][i - 4].Stone_2020184006) && (Stone_2020184006[g + 3][i - 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
							Stone_2020184006[g][i].rdegak_line = 4;
							Stone_2020184006[g][i].rdegak3 = 2;
							Stone_2020184006[g][i].gongbak = 1;
						}
					}
				}
				g++;
			}
			g = 0;
		}
		g = 18;
		for (int i = 18; i > 0; i--) {
			for (int j = 17 - (18 - i); j < 19; j++) {
				if (Stone_2020184006[j][g].Stone_2020184006 != 0) {
					if (j < 18) {
						if (Stone_2020184006[j][g].Stone_2020184006 != Stone_2020184006[j + 1][g - 1].Stone_2020184006) {
							Stone_2020184006[j][g].rdegak_line = 1;
							Stone_2020184006[j][g].gongbak = 0;
						}
					}
					if (j < 17) {
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006) && (Stone_2020184006[j + 2][g - 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 2;
							Stone_2020184006[j][g].gongbak = 0;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006) && (Stone_2020184006[j + 1][g - 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
					}
					if (j < 16) {
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006) && (Stone_2020184006[j + 3][g - 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 3;
							Stone_2020184006[j][g].ldegak3 = 1;
							Stone_2020184006[j][g].gongbak = 0;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006) && (Stone_2020184006[j + 1][g - 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 3;
							Stone_2020184006[j][g].ldegak3 = 1;
							Stone_2020184006[j][g].gongbak = 1;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006) && (Stone_2020184006[j + 2][g - 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 3;
							Stone_2020184006[j][g].ldegak3 = 1;
							Stone_2020184006[j][g].gongbak = 1;
						}
					}
					if (j < 15) {
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006) && (Stone_2020184006[j + 4][g - 4].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 0;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006 == Stone_2020184006[j + 4][g - 4].Stone_2020184006) && (Stone_2020184006[j + 1][g - 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 3][g - 3].Stone_2020184006 == Stone_2020184006[j + 4][g - 4].Stone_2020184006) && (Stone_2020184006[j + 2][g - 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g - 1].Stone_2020184006 == Stone_2020184006[j + 2][g - 2].Stone_2020184006 == Stone_2020184006[j + 4][g - 4].Stone_2020184006) && (Stone_2020184006[j + 3][g - 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].rdegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
					}
				}
				g--;
			}
			g = 18;
		}
		g = 0;
		for (int i = 17; i > 0; i--) {
			for (int j = i; j < 19; j++) {
				if (Stone_2020184006[j][g].Stone_2020184006 != 0) {
					if (Stone_2020184006[j][g].Stone_2020184006 != Stone_2020184006[j + 1][g + 1].Stone_2020184006) {
						Stone_2020184006[j][g].ldegak_line = 1;
						Stone_2020184006[j][g].gongbak = 0;
					}
					if (j < 17) {
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006) && (Stone_2020184006[j + 2][g + 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 2;
							Stone_2020184006[j][g].gongbak = 0;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006) && (Stone_2020184006[j + 1][g + 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
					}
					if (j < 16) {
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006) && (Stone_2020184006[j + 3][g + 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 3;
							Stone_2020184006[j][g].ldegak3 = 1;
							Stone_2020184006[j][g].gongbak = 0;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006) && (Stone_2020184006[j + 1][g + 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 3;
							Stone_2020184006[j][g].ldegak3 = 1;
							Stone_2020184006[j][g].gongbak = 1;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006) && (Stone_2020184006[j + 2][g + 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 3;
							Stone_2020184006[j][g].ldegak3 = 1;
							Stone_2020184006[j][g].gongbak = 1;
						}
					}
					if (j < 15) {
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006) && (Stone_2020184006[j + 4][g + 4].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 0;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006 == Stone_2020184006[j + 4][g + 4].Stone_2020184006) && (Stone_2020184006[j + 1][g + 1].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 3][g + 3].Stone_2020184006 == Stone_2020184006[j + 4][g + 4].Stone_2020184006) && (Stone_2020184006[j + 2][g + 2].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
						if ((Stone_2020184006[j][g].Stone_2020184006 == Stone_2020184006[j + 1][g + 1].Stone_2020184006 == Stone_2020184006[j + 2][g + 2].Stone_2020184006 == Stone_2020184006[j + 4][g + 4].Stone_2020184006) && (Stone_2020184006[j + 3][g + 3].Stone_2020184006 != Stone_2020184006[j][g].Stone_2020184006)) {
							Stone_2020184006[j][g].ldegak_line = 4;
							Stone_2020184006[j][g].ldegak3 = 2;
							Stone_2020184006[j][g].gongbak = 1;
						}
					}
				}
				g++;
			}
			g = 0;
		}
		for (int j = 0; j < 18; j++) {
			for (int i = j; i < 19; i++) {
				if (Stone_2020184006[g][i].Stone_2020184006 != 0) {
					if (Stone_2020184006[g][i].Stone_2020184006 != Stone_2020184006[g + 1][i + 1].Stone_2020184006) {
						Stone_2020184006[g][i].ldegak_line = 1;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006) && (Stone_2020184006[g + 2][i + 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 2;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006) && (Stone_2020184006[g + 1][i + 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006) && (Stone_2020184006[g + 3][i + 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 3;
						Stone_2020184006[g][i].ldegak3 = 1;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006) && (Stone_2020184006[g + 1][i + 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 3;
						Stone_2020184006[g][i].ldegak3 = 1;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006) && (Stone_2020184006[g + 2][i + 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 3;
						Stone_2020184006[g][i].ldegak3 = 1;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006) && (Stone_2020184006[g + 4][i + 4].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 4;
						Stone_2020184006[g][i].ldegak3 = 2;
						Stone_2020184006[g][i].gongbak = 0;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006 == Stone_2020184006[g + 4][i + 4].Stone_2020184006) && (Stone_2020184006[g + 1][i + 1].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 4;
						Stone_2020184006[g][i].ldegak3 = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 3][i + 3].Stone_2020184006 == Stone_2020184006[g + 4][i + 4].Stone_2020184006) && (Stone_2020184006[g + 2][i + 2].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 4;
						Stone_2020184006[g][i].ldegak3 = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
					if ((Stone_2020184006[g][i].Stone_2020184006 == Stone_2020184006[g + 1][i + 1].Stone_2020184006 == Stone_2020184006[g + 2][i + 2].Stone_2020184006 == Stone_2020184006[g + 4][i + 4].Stone_2020184006) && (Stone_2020184006[g + 3][i + 3].Stone_2020184006 != Stone_2020184006[g][i].Stone_2020184006)) {
						Stone_2020184006[g][i].ldegak_line = 4;
						Stone_2020184006[g][i].ldegak3 = 2;
						Stone_2020184006[g][i].gongbak = 1;
					}
				}
				g++;
			}
			g = 0;
		}
		for (int i = 0;i < 19;i++) {
			for (int j = 0;j < 19;j++) {
				if (Stone_2020184006[j][i].Stone_2020184006 != 0) {
					if (Stone_2020184006[j][i].Stone_2020184006 != Stone_2020184006[j][i + 1].Stone_2020184006) {
						Stone_2020184006[j][i].garo_line = 1;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006) && (Stone_2020184006[j][i + 2].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 2;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006) && (Stone_2020184006[j][i + 1].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 2;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006) && (Stone_2020184006[j][i + 3].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 3;
						Stone_2020184006[j][i].garo3 = 1;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006) && (Stone_2020184006[j][i + 1].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 3;
						Stone_2020184006[j][i].garo3 = 1;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006) && (Stone_2020184006[j][i + 2].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 3;
						Stone_2020184006[j][i].garo3 = 1;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006) && (Stone_2020184006[j][i + 4].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 4;
						Stone_2020184006[j][i].garo3 = 2;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006 == Stone_2020184006[j][i + 4].Stone_2020184006) && (Stone_2020184006[j][i + 1].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 4;
						Stone_2020184006[j][i].garo3 = 2;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 3].Stone_2020184006 == Stone_2020184006[j][i + 4].Stone_2020184006) && (Stone_2020184006[j][i + 2].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 4;
						Stone_2020184006[j][i].garo3 = 2;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j][i + 1].Stone_2020184006 == Stone_2020184006[j][i + 2].Stone_2020184006 == Stone_2020184006[j][i + 4].Stone_2020184006) && (Stone_2020184006[j][i + 3].Stone_2020184006 != Stone_2020184006[j][i].Stone_2020184006)) {
						Stone_2020184006[j][i].garo_line = 4;
						Stone_2020184006[j][i].garo3 = 2;
						Stone_2020184006[j][i].gongbak = 1;
					}
				}
			}
		}
		for (int j = 0;j < 19;j++) {
			for (int i = 0;i < 19;i++) {
				if (Stone_2020184006[j][i].Stone_2020184006 != 0) {
					if (Stone_2020184006[j][i].Stone_2020184006 != Stone_2020184006[j + 1][i].Stone_2020184006) {
						Stone_2020184006[j][i].sero_line = 1;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006) && (Stone_2020184006[j + 2][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 2;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006) && (Stone_2020184006[j + 1][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 2;
						Stone_2020184006[j][i].gongbak = 1;

					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006) && (Stone_2020184006[j + 3][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 3;
						Stone_2020184006[j][i].sero3 = 1;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006) && (Stone_2020184006[j + 1][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 3;
						Stone_2020184006[j][i].sero3 = 1;
						Stone_2020184006[j][i].gongbak = 1;

					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006) && (Stone_2020184006[j + 2][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 3;
						Stone_2020184006[j][i].sero3 = 1;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006) && (Stone_2020184006[j + 4][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 4;
						Stone_2020184006[j][i].sero3 = 2;
						Stone_2020184006[j][i].gongbak = 0;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006 == Stone_2020184006[j + 4][i].Stone_2020184006) && (Stone_2020184006[j + 1][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 4;
						Stone_2020184006[j][i].sero3 = 2;
						Stone_2020184006[j][i].gongbak = 1;

					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 3][i].Stone_2020184006 == Stone_2020184006[j + 4][i].Stone_2020184006) && (Stone_2020184006[j + 2][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 4;
						Stone_2020184006[j][i].sero3 = 2;
						Stone_2020184006[j][i].gongbak = 1;
					}
					if ((Stone_2020184006[j][i].Stone_2020184006 == Stone_2020184006[j + 1][i].Stone_2020184006 == Stone_2020184006[j + 2][i].Stone_2020184006 == Stone_2020184006[j + 4][i].Stone_2020184006) && (Stone_2020184006[j + 3][i].Stone_2020184006 == 0)) {
						Stone_2020184006[j][i].sero_line = 4;
						Stone_2020184006[j][i].sero3 = 2;
						Stone_2020184006[j][i].gongbak = 1;
					}
				}
			}
		}
		for (int i = 0;i < 19;i++) {
			for (int j = 0;j < 19;j++) {
				if (Stone_2020184006[j][i].Stone_2020184006 != 0) {
					switch (Stone_2020184006[j][i].sero_line) {
					case 1:
						if (i > 0 && j > 0) {
							Stone_2020184006[j - 1][i - 1].weight += 1;
							Stone_2020184006[j - 1][i].weight += 1;
							Stone_2020184006[j - 1][i + 1].weight += 1;
							Stone_2020184006[j][i - 1].weight += 1;
							Stone_2020184006[j][i + 1].weight += 1;
							Stone_2020184006[j + 1][i - 1].weight += 1;
							Stone_2020184006[j + 1][i].weight += 1;
							Stone_2020184006[j + 1][i + 1].weight += 1;
						}
						else {
							Stone_2020184006[j - 1][i].weight += 1;
							Stone_2020184006[j - 1][i + 1].weight += 1;
							Stone_2020184006[j][i + 1].weight += 1;
							Stone_2020184006[j + 1][i].weight += 1;
							Stone_2020184006[j + 1][i + 1].weight += 1;
						}
						break;
					case 2:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //XWWX
								Stone_2020184006[j - 1][i].weight += 30000;
								Stone_2020184006[j + 2][i].weight += 30000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 != 0) { //XWWB
								Stone_2020184006[j - 1][i].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //BWWX
								Stone_2020184006[j + 2][i].weight += 500;
							}
						}
						else {
							if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWX
								Stone_2020184006[j - 1][i].weight += 30000;
								Stone_2020184006[j + 1][i].weight += 300000;
								Stone_2020184006[j + 3][i].weight += 30000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWB
								Stone_2020184006[j - 1][i].weight += 500;
								Stone_2020184006[j + 1][i].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //BWXWX
								Stone_2020184006[j + 1][i].weight += 500;
								Stone_2020184006[j + 3][i].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //BWXWB
								Stone_2020184006[j + 1][i].weight += 500;
							}
						}
						break;
					case 3:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //XWWWX
								Stone_2020184006[j - 1][i].weight += 84700000;
								Stone_2020184006[j + 3][i].weight += 84700000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 != 0) { //XWWWB
								Stone_2020184006[j - 1][i].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //BWWWX
								Stone_2020184006[j + 3][i].weight += 1450000;
							}
						}
						else {
							if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) {//X0X00X
								Stone_2020184006[j - 1][i].weight += 8470000;
								Stone_2020184006[j + 4][i].weight += 8470000;
								Stone_2020184006[j + 1][i].weight += 84700000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) {//BWXWWX
								Stone_2020184006[j + 4][i].weight += 1450000;
								Stone_2020184006[j + 1][i].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) {//XWXWWB
								Stone_2020184006[j - 1][i].weight += 1450000;
								Stone_2020184006[j + 1][i].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) {//XWWXWX
								Stone_2020184006[j - 1][i].weight += 8470000;
								Stone_2020184006[j + 4][i].weight += 8470000;
								Stone_2020184006[j + 2][i].weight += 84700000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) {//BWWXWX
								Stone_2020184006[j + 4][i].weight += 1450000;
								Stone_2020184006[j + 2][i].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) {//XWWXWB
								Stone_2020184006[j - 1][i].weight += 1450000;
								Stone_2020184006[j + 2][i].weight += 1450000;
							}
						}
						break;
					case 4:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0) { //XWWWWX
								Stone_2020184006[j - 1][i].weight += 7000000000;
								Stone_2020184006[j + 4][i].weight += 7000000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i].Stone_2020184006 != 0) { //XWWWWB
								Stone_2020184006[j - 1][i].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i].Stone_2020184006 == 0) { //BWWWWX
								Stone_2020184006[j + 4][i].weight += 300000000;
							}
						}
						else {
							if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWWWX
								Stone_2020184006[j - 1][i].weight += 70000000;
								Stone_2020184006[j + 1][i].weight += 7000000000;
								Stone_2020184006[j + 5][i].weight += 70000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //XWXWWWB
								Stone_2020184006[j - 1][i].weight += 30000000;
								Stone_2020184006[j + 1][i].weight += 30000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i].Stone_2020184006 == 0) { //BWXWWWX
								Stone_2020184006[j + 5][i].weight += 30000000;
								Stone_2020184006[j + 1][i].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //XWWXWWX
								Stone_2020184006[j - 1][i].weight += 70000000;
								Stone_2020184006[j + 5][i].weight += 70000000;
								Stone_2020184006[j + 2][i].weight += 7000000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //XWWXWWB
								Stone_2020184006[j - 1][i].weight += 30000000;
								Stone_2020184006[j + 2][i].weight += 3000000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i].Stone_2020184006 == 0) { //BWWXWWX
								Stone_2020184006[j + 5][i].weight += 30000000;
								Stone_2020184006[j + 2][i].weight += 3000000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //XWWWXWX
								Stone_2020184006[j - 1][i].weight += 70000000;
								Stone_2020184006[j + 5][i].weight += 70000000;
								Stone_2020184006[j + 3][i].weight += 7000000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //XWWWXWB
								Stone_2020184006[j - 1][i].weight += 30000000;
								Stone_2020184006[j + 3][i].weight += 3000000000;
							}
							else if (Stone_2020184006[j - 1][i].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i].Stone_2020184006 == 0) { //BWWWXWX
								Stone_2020184006[j + 5][i].weight += 30000000;
								Stone_2020184006[j + 3][i].weight += 3000000000;
							}
						}
						break;
					default:
						break;
					}
					switch (Stone_2020184006[j][i].rdegak_line) {
					case 1:
						Stone_2020184006[j - 1][i - 1].weight += 1;
						Stone_2020184006[j - 1][i].weight += 1;
						Stone_2020184006[j - 1][i + 1].weight += 1;
						Stone_2020184006[j][i - 1].weight += 1;
						Stone_2020184006[j][i + 1].weight += 1;
						Stone_2020184006[j + 1][i - 1].weight += 1;
						Stone_2020184006[j + 1][i].weight += 1;
						Stone_2020184006[j + 1][i + 1].weight += 1;
						break;
					case 2:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (j < 17) {
								if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {
									Stone_2020184006[j - 1][i + 1].weight += 30000;
									Stone_2020184006[j + 2][i - 2].weight += 30000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 != 0) {
									Stone_2020184006[j - 1][i + 1].weight += 500;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {
									Stone_2020184006[j + 2][i - 2].weight += 500;
								}
							}
						}
						else {
							if (j < 16) {
								if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWX
									Stone_2020184006[j - 1][i + 1].weight += 30000;
									Stone_2020184006[j + 1][i - 1].weight += 300000;
									Stone_2020184006[j + 3][i - 3].weight += 30000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWB
									Stone_2020184006[j - 1][i + 1].weight += 500;
									Stone_2020184006[j + 1][i - 1].weight += 500;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //BWXWX
									Stone_2020184006[j + 1][i - 1].weight += 500;
									Stone_2020184006[j + 3][i - 3].weight += 500;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //BWXWB
									Stone_2020184006[j + 1][i - 1].weight += 500;
								}
							}
						}
						break;
					case 3:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (j < 16) {
								if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //XWWWX
									Stone_2020184006[j - 1][i + 1].weight += 84700000;
									Stone_2020184006[j + 3][i - 3].weight += 84700000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 != 0) { //XWWWB
									Stone_2020184006[j - 1][i + 1].weight += 1450000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //BWWWX
									Stone_2020184006[j + 3][i - 3].weight += 1450000;
								}
							}
						}
						else {
							if (j < 15) {
								if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) {//X0X00X
									Stone_2020184006[j - 1][i + 1].weight += 8470000;
									Stone_2020184006[j + 4][i - 4].weight += 8470000;
									Stone_2020184006[j + 1][i - 1].weight += 84700000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) {//BWXWWX
									Stone_2020184006[j + 4][i - 4].weight += 1450000;
									Stone_2020184006[j + 1][i - 1].weight += 1450000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) {//XWXWWB
									Stone_2020184006[j - 1][i + 1].weight += 1450000;
									Stone_2020184006[j + 1][i - 1].weight += 1450000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {//XWWXWX
									Stone_2020184006[j - 1][i + 1].weight += 8470000;
									Stone_2020184006[j + 4][i - 4].weight += 8470000;
									Stone_2020184006[j + 2][i - 2].weight += 84700000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {//BWWXWX
									Stone_2020184006[j + 4][i - 4].weight += 1450000;
									Stone_2020184006[j + 2][i - 2].weight += 1450000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) {//XWWXWB
									Stone_2020184006[j - 1][i + 1].weight += 1450000;
									Stone_2020184006[j + 2][i - 2].weight += 1450000;
								}
							}
						}
						break;
					case 4:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (j < 15) {
								if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0) { //XWWWWX
									Stone_2020184006[j - 1][i + 1].weight += 700000000;
									Stone_2020184006[j + 4][i - 4].weight += 700000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 != 0) { //XWWWWB
									Stone_2020184006[j - 1][i + 1].weight += 300000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i - 4].Stone_2020184006 == 0) { //BWWWWX
									Stone_2020184006[j + 4][i - 4].weight += 300000000;
								}
							}
						}
						else {
							if (j < 14) {
								if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWWWX
									Stone_2020184006[j - 1][i + 1].weight += 70000000;
									Stone_2020184006[j + 1][i - 1].weight += 700000000;
									Stone_2020184006[j + 5][i - 5].weight += 70000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //XWXWWWB
									Stone_2020184006[j - 1][i + 1].weight += 30000000;
									Stone_2020184006[j + 1][i - 1].weight += 300000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i - 1].Stone_2020184006 == 0) { //BWXWWWX
									Stone_2020184006[j + 5][i - 5].weight += 30000000;
									Stone_2020184006[j + 1][i - 1].weight += 300000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) { //XWWXWWX
									Stone_2020184006[j - 1][i + 1].weight += 70000000;
									Stone_2020184006[j + 5][i - 5].weight += 70000000;
									Stone_2020184006[j + 2][i - 2].weight += 700000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) { //XWWXWWB
									Stone_2020184006[j - 1][i + 1].weight += 30000000;
									Stone_2020184006[j + 2][i - 2].weight += 300000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i - 2].Stone_2020184006 == 0) { //BWWXWWX
									Stone_2020184006[j + 5][i - 5].weight += 30000000;
									Stone_2020184006[j + 2][i + -2].weight += 300000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //XWWWXWX
									Stone_2020184006[j - 1][i + 1].weight += 70000000;
									Stone_2020184006[j + 5][i - 5].weight += 70000000;
									Stone_2020184006[j + 3][i - 3].weight += 700000000;
								}
								else if (Stone_2020184006[j - 1][i + 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //XWWWXWB
									Stone_2020184006[j - 1][i + 1].weight += 30000000;
									Stone_2020184006[j + 3][i - 3].weight += 300000000;
								}
								else if (Stone_2020184006[j + 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i - 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i - 3].Stone_2020184006 == 0) { //BWWWXWX
									Stone_2020184006[j + 5][i - 5].weight += 30000000;
									Stone_2020184006[j + 3][i - 3].weight += 300000000;
								}
							}
						}
						break;
					default:
						break;
					}
					switch (Stone_2020184006[j][i].garo_line) {
					case 1:
						if (j > 0) {
							Stone_2020184006[j - 1][i - 1].weight += 1;
							Stone_2020184006[j - 1][i].weight += 1;
							Stone_2020184006[j - 1][i + 1].weight += 1;
							Stone_2020184006[j][i - 1].weight += 1;
							Stone_2020184006[j][i + 1].weight += 1;
							Stone_2020184006[j + 1][i - 1].weight += 1;
							Stone_2020184006[j + 1][i].weight += 1;
							Stone_2020184006[j + 1][i + 1].weight += 1;
						}
						else {
							Stone_2020184006[j][i - 1].weight += 1;
							Stone_2020184006[j][i + 1].weight += 1;
							Stone_2020184006[j + 1][i - 1].weight += 1;
							Stone_2020184006[j + 1][i].weight += 1;
							Stone_2020184006[j + 1][i + 1].weight += 1;
						}
						break;
					case 2:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //XWWX
								Stone_2020184006[j][i - 1].weight += 30000;
								Stone_2020184006[j][i + 2].weight += 30000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 != 0) { //XWWB
								Stone_2020184006[j][i - 1].weight += 500;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //BWWX
								Stone_2020184006[j][i + 2].weight += 500;
							}
						}
						else {
							if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWX
								Stone_2020184006[j][i - 1].weight += 30000;
								Stone_2020184006[j][i + 1].weight += 300000;
								Stone_2020184006[j][i + 3].weight += 30000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWB
								Stone_2020184006[j][i - 1].weight += 500;
								Stone_2020184006[j][i + 1].weight += 500;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //BWXWX
								Stone_2020184006[j][i + 1].weight += 500;
								Stone_2020184006[j][i + 3].weight += 500;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //BWXWB
								Stone_2020184006[j][i + 1].weight += 500;
							}
						}
						break;
					case 3:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //XWWWX
								Stone_2020184006[j][i - 1].weight += 84700000;
								Stone_2020184006[j][i + 3].weight += 84700000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 != 0) { //XWWWB
								Stone_2020184006[j][i - 1].weight += 1450000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //BWWWX
								Stone_2020184006[j][i + 3].weight += 1450000;
							}
						}
						else {
							if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) {//X0X00X
								Stone_2020184006[j][i - 1].weight += 8470000;
								Stone_2020184006[j][i + 4].weight += 8470000;
								Stone_2020184006[j][i + 1].weight += 84700000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) {//BWXWWX
								Stone_2020184006[j][i + 4].weight += 1450000;
								Stone_2020184006[j][i + 1].weight += 1450000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) {//XWXWWB
								Stone_2020184006[j][i - 1].weight += 1450000;
								Stone_2020184006[j][i + 1].weight += 1450000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) {//XWWXWX
								Stone_2020184006[j][i - 1].weight += 8470000;
								Stone_2020184006[j][i + 4].weight += 8470000;
								Stone_2020184006[j][i + 2].weight += 84700000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) {//BWWXWX
								Stone_2020184006[j][i + 4].weight += 1450000;
								Stone_2020184006[j][i + 2].weight += 1450000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) {//XWWXWB
								Stone_2020184006[j][i - 1].weight += 1450000;
								Stone_2020184006[j][i + 2].weight += 1450000;
							}
						}
						break;
					case 4:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0) { //XWWWWX
								Stone_2020184006[j][i - 1].weight += 700000000;
								Stone_2020184006[j][i + 4].weight += 700000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 4].Stone_2020184006 != 0) { //XWWWWB
								Stone_2020184006[j][i - 1].weight += 3000000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 4].Stone_2020184006 == 0) { //BWWWWX
								Stone_2020184006[j][i + 4].weight += 3000000000;
							}
						}
						else {
							if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWWWX
								Stone_2020184006[j][i - 1].weight += 70000000;
								Stone_2020184006[j][i + 1].weight += 700000000;
								Stone_2020184006[j][i + 5].weight += 70000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //XWXWWWB
								Stone_2020184006[j][i - 1].weight += 30000000;
								Stone_2020184006[j][i + 1].weight += 300000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 1].Stone_2020184006 == 0) { //BWXWWWX
								Stone_2020184006[j][i + 5].weight += 30000000;
								Stone_2020184006[j][i + 1].weight += 300000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //XWWXWWX
								Stone_2020184006[j][i - 1].weight += 70000000;
								Stone_2020184006[j][i + 5].weight += 70000000;
								Stone_2020184006[j][i + 2].weight += 700000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //XWWXWWB
								Stone_2020184006[j][i - 1].weight += 30000000;
								Stone_2020184006[j][i + 2].weight += 300000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 2].Stone_2020184006 == 0) { //BWWXWWX
								Stone_2020184006[j][i + 5].weight += 30000000;
								Stone_2020184006[j][i + 2].weight += 300000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //XWWWXWX
								Stone_2020184006[j][i - 1].weight += 70000000;
								Stone_2020184006[j][i + 5].weight += 70000000;
								Stone_2020184006[j][i + 3].weight += 700000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //XWWWXWB
								Stone_2020184006[j][i - 1].weight += 30000000;
								Stone_2020184006[j][i + 3].weight += 300000000;
							}
							else if (Stone_2020184006[j][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j][i + 3].Stone_2020184006 == 0) { //BWWWXWX
								Stone_2020184006[j][i + 5].weight += 30000000;
								Stone_2020184006[j][i + 3].weight += 300000000;
							}
						}
						break;
					default:
						break;
					}
					switch (Stone_2020184006[j][i].ldegak_line) {
					case 1:
						Stone_2020184006[j - 1][i - 1].weight += 1;
						Stone_2020184006[j - 1][i].weight += 1;
						Stone_2020184006[j - 1][i + 1].weight += 1;
						Stone_2020184006[j][i - 1].weight += 1;
						Stone_2020184006[j][i + 1].weight += 1;
						Stone_2020184006[j + 1][i - 1].weight += 1;
						Stone_2020184006[j + 1][i].weight += 1;
						Stone_2020184006[j + 1][i + 1].weight += 1;
						break;
					case 2:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {
								Stone_2020184006[j - 1][i - 1].weight += 30000;
								Stone_2020184006[j + 2][i + 2].weight += 30000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 != 0) {
								Stone_2020184006[j - 1][i - 1].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {
								Stone_2020184006[j + 2][i + 2].weight += 500;
							}
						}
						else {
							if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWX
								Stone_2020184006[j - 1][i - 1].weight += 30000;
								Stone_2020184006[j + 1][i + 1].weight += 300000;
								Stone_2020184006[j + 3][i + 3].weight += 30000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWB
								Stone_2020184006[j - 1][i - 1].weight += 500;
								Stone_2020184006[j + 1][i + 1].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //BWXWX
								Stone_2020184006[j + 1][i + 1].weight += 500;
								Stone_2020184006[j + 3][i + 3].weight += 500;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //BWXWB
								Stone_2020184006[j + 1][i + 1].weight += 500;
							}
						}
						break;
					case 3:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //XWWWX
								Stone_2020184006[j - 1][i - 1].weight += 84700000;
								Stone_2020184006[j + 3][i + 3].weight += 84700000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 != 0) { //XWWWB
								Stone_2020184006[j - 1][i - 1].weight += 145000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //BWWWX
								Stone_2020184006[j + 3][i + 3].weight += 145000;
							}
						}
						else {
							if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) {//X0X00X
								Stone_2020184006[j - 1][i - 1].weight += 8470000;
								Stone_2020184006[j + 4][i + 4].weight += 8470000;
								Stone_2020184006[j + 1][i + 1].weight += 84700000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) {//BWXWWX
								Stone_2020184006[j + 4][i + 4].weight += 1450000;
								Stone_2020184006[j + 1][i + 1].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) {//XWXWWB
								Stone_2020184006[j - 1][i - 1].weight += 1450000;
								Stone_2020184006[j + 1][i + 1].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {//XWWXWX
								Stone_2020184006[j - 1][i - 1].weight += 8470000;
								Stone_2020184006[j + 4][i + 4].weight += 8470000;
								Stone_2020184006[j + 2][i + 2].weight += 84700000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {//BWWXWX
								Stone_2020184006[j + 4][i + 4].weight += 1450000;
								Stone_2020184006[j + 2][i + 2].weight += 1450000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) {//XWWXWB
								Stone_2020184006[j - 1][i - 1].weight += 1450000;
								Stone_2020184006[j + 2][i + 2].weight += 1450000;
							}
						}
						break;
					case 4:
						if (Stone_2020184006[j][i].gongbak == 0) {
							if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0) { //XWWWWX
								Stone_2020184006[j - 1][i - 1].weight += 700000000;
								Stone_2020184006[j + 4][i + 4].weight += 700000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 != 0) { //XWWWWB
								Stone_2020184006[j - 1][i - 1].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 4][i + 4].Stone_2020184006 == 0) { //BWWWWX
								Stone_2020184006[j + 4][i + 4].weight += 300000000;
							}
						}
						else {
							if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWWWX
								Stone_2020184006[j - 1][i - 1].weight += 70000000;
								Stone_2020184006[j + 1][i + 1].weight += 700000000;
								Stone_2020184006[j + 5][i + 5].weight += 70000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //XWXWWWB
								Stone_2020184006[j - 1][i - 1].weight += 30000000;
								Stone_2020184006[j + 1][i + 1].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 1][i + 1].Stone_2020184006 == 0) { //BWXWWWX
								Stone_2020184006[j + 5][i + 5].weight += 30000000;
								Stone_2020184006[j + 1][i + 1].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) { //XWWXWWX
								Stone_2020184006[j - 1][i - 1].weight += 70000000;
								Stone_2020184006[j + 5][i + 5].weight += 70000000;
								Stone_2020184006[j + 2][i + 2].weight += 700000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) { //XWWXWWB
								Stone_2020184006[j - 1][i - 1].weight += 30000000;
								Stone_2020184006[j + 2][i + 2].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 2][i + 2].Stone_2020184006 == 0) { //BWWXWWX
								Stone_2020184006[j + 5][i + 5].weight += 30000000;
								Stone_2020184006[j + 2][i + 2].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //XWWWXWX
								Stone_2020184006[j - 1][i - 1].weight += 70000000;
								Stone_2020184006[j + 5][i + 5].weight += 70000000;
								Stone_2020184006[j + 3][i + 3].weight += 700000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 == 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 != 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //XWWWXWB
								Stone_2020184006[j - 1][i - 1].weight += 30000000;
								Stone_2020184006[j + 3][i + 3].weight += 300000000;
							}
							else if (Stone_2020184006[j - 1][i - 1].Stone_2020184006 != 0 && Stone_2020184006[j + 5][i + 5].Stone_2020184006 == 0 && Stone_2020184006[j + 3][i + 3].Stone_2020184006 == 0) { //BWWWXWX
								Stone_2020184006[j + 5][i + 5].weight += 30000000;
								Stone_2020184006[j + 3][i + 3].weight += 300000000;
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (Stone_2020184006[j][i].Stone_2020184006 == 0) {
					if (Stone_2020184006[j][i].weight > max) {
						max = Stone_2020184006[j][i].weight;
					}
				}
			}
		}
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (Stone_2020184006[j][i].Stone_2020184006 == 0) {
					if (max == Stone_2020184006[j][i].weight) {
						bb_2020184006 = j;
						aa_2020184006 = i;
					}
				}
			}
		}
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				Stone_2020184006[j][i].weight += 0;
				Stone_2020184006[j][i].weight += 0;
				Stone_2020184006[j][i].garo3 = 0;
				Stone_2020184006[j][i].sero3 = 0;
				Stone_2020184006[j][i].garo_line = 0;
				Stone_2020184006[j][i].sero_line = 0;
				Stone_2020184006[j][i].ldegak_line = 0;
				Stone_2020184006[j][i].rdegak_line = 0;
				Stone_2020184006[j][i].gongbak = 0;
			}
		}
		*x = aa_2020184006;
		*y = bb_2020184006;
	}
	Stone_2020184006[*y][*x].Stone_2020184006 = BLACK;
	board_2020184006[*y][*x] = BLACK;
}
void BlackDefence_2020184006(int x, int y) {
	Stone_2020184006[y][x].Stone_2020184006 = WHITE;
	board_2020184006[y][x] = WHITE;
}