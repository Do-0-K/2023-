#pragma once
int board_2020184028[19][19];

//��		1
//������	-1
#define BLACK -1
#define WHITE 1

typedef struct omok {
	int stone;//���� ������ Ȯ��
	int cons; //���ӵ� �� Ȯ��
	int weight;//����ġ
}omok;

omok stone[19][19];
int stonenum = 0;

void WhiteAttack_2020184028(int* x, int* y)
{
	// ���� �����Ͻ� �� ���� ������ �־��ּ���
	int check = 0;//�� �پ� �˻��ϰ� �ϴ� ����

	int Echeck = 0;//�� ���� üũ
	int Estone = 1;//���� ���� üũ���ִ� ����
	int b = 0; //������ �ѹ��� ã�� �ϴ� ����
	int savex = 0; //�����϶��� ��ǥ ���庯��
	int savey = 0; //�����϶��� ��ǥ ���庯��
	//�밢�� ���� ����
	int linenum = 1;//�밢�� ����Ȯ�� ����
	int max = 0;//����ġ�� �ִ밪 ����


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
		//���� �ΰ� ���࿡ ���� �ִٸ� �ٸ��� �ΰ�
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK) {
					stone[i - 1][j].weight += 10;
				}
			}
		}
	}
	else if (stonenum == 1) {
		//�����ϰ� �δ� �� �ٵ� �ǿ� ���� ������쿡�� �ߵ��ǰ��Ѵ�.
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				//�鵹�� �������� �ֺ� 8�ڸ��� ����ġ�� �÷��ش�.
				if (stone[i][j].stone == WHITE) {
					if (stone[i + 1][j].stone == 0) {//��(��)��ĭ�ϰ��
						stone[i + 1][j].weight += 10;//����ġ�� �ø���.
					}
					if (stone[i][j + 1].stone == 0) {//��(��)��ĭ�ϰ��
						stone[i][j + 1].weight += 10;//����ġ�� �ø���.
					}
					if (stone[i + 1][j + 1].stone == 0) {//��(����)��ĭ�ϰ��
						stone[i + 1][j + 1].weight += 10;//����ġ�� �ø���.
					}

					if (i > 0) {
						if (stone[i - 1][j].stone == 0) {//��(��)��ĭ�ϰ��
							stone[i - 1][j].weight += 10;//����ġ�� �ø���.
						}
						if (stone[i - 1][j + 1].stone == 0) {//��(�ϵ�)��ĭ�ϰ��
							stone[i - 1][j + 1].weight += 10;//����ġ�� �ø���.
						}
					}
					if (j > 0) {
						if (stone[i][j - 1].stone == 0) {//��(��)��ĭ�ϰ��
							stone[i][j - 1].weight += 10;//����ġ�� �ø���.
						}
						if (stone[i + 1][j - 1].stone == 0) {//��(����)��ĭ�ϰ��
							stone[i + 1][j - 1].weight += 10;//����ġ�� �ø���.
						}
					}
					if (i > 0 && j > 0) {
						if (stone[i - 1][j - 1].stone == 0) {//��(�ϼ�)��ĭ�ϰ��
							stone[i - 1][j - 1].weight += 10;//����ġ�� �ø���.
						}
					}
				}
			}
		}
		//���� ���� ���� üũ(����)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0) {//2ĭ������ ���
						stone[i][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == WHITE && stone[i][j - 1].stone == 0) {//2ĭ �����ε� �����ִ°��
						stone[i][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == WHITE && stone[i][j - 1].stone == 0) {//3ĭ �����ε� �����ִ°��
						stone[i][j - 1].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == 0) {//3ĭ�����ϰ��
						stone[i][j + 3].weight += 40;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == WHITE && stone[i][j - 1].stone == 0) {//4ĭ �����ε� ���� �ִ°��
						stone[i][j - 1].weight += 60;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == 0) {//4ĭ�����ϰ��
						stone[i][j + 4].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		//���� ���� ���� üũ(����)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0) {//2ĭ������ ���
						stone[i + 2][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == WHITE && stone[i - 1][j].stone == 0) {//2ĭ �����ε� �����ִ°��
						stone[i - 1][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == WHITE && stone[i - 1][j].stone == 0) {//3ĭ �����ε� �����ִ°��
						stone[i - 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == 0) {//3ĭ�����ϰ��
						stone[i + 3][j].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == WHITE && stone[i - 1][j].stone == 0) {//4ĭ �����ε� ���� �ִ°��
						stone[i - 1][j].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == 0) {//4ĭ�����ϰ��
						stone[i + 4][j].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//������ �밢�� ����
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == 0) {//������ 2ĭ �����ϰ��
						stone[i + 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//������ 2ĭ �����϶� �������
						stone[i - 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == 0) {//������ 3ĭ �����ϰ��
						stone[i + 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//������ 3ĭ �����϶� �������
						stone[i - 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == 0) {//������ 4ĭ �����ϰ��
						stone[i + 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//������ 4ĭ �����϶� �������
						stone[i - 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//�»��� �밢�� ����
		for (int i = 18; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == 0) {//�»��� 2ĭ�����϶�
						stone[i - 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == WHITE && stone[i + 1][j - 1].stone == 0) { //�»��� 2ĭ�����϶� �������
						stone[i + 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == 0) { //�»��� 3ĭ�����϶�
						stone[i - 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == WHITE && stone[i + 1][j - 1].stone == 0) { //�»��� 3ĭ�����϶� �������
						stone[i + 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == 0) { //�»��� 4ĭ�����϶�
						stone[i - 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == WHITE && stone[i + 1][j - 1].stone == 0) { //�»��� 4ĭ�����϶� �������
						stone[i + 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//���� ���� üũ
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK) {//OXO�̰��
						stone[i][j + 1].weight += 20;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == BLACK) {//OOXO���
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK) {//OXOO���
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == 0 && stone[i][j + 4].stone == BLACK) {//OOOXO���
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == BLACK) {//OXOOO���
						stone[i][j + 1].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == BLACK) {//OOXOO���
						stone[i][j + 2].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//���� ���� üũ
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK) {//OXO�̰��
						stone[i + 1][j].weight += 20;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == BLACK) {//OOXO���
						stone[i + 2][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK) {//OXOO���
						stone[i + 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == 0 && stone[i + 4][j].stone == BLACK) {//OOOXO���
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == BLACK) {//OXOOO���
						stone[i + 1][j].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == BLACK) {//OOXOO���
						stone[i + 2][j].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//�̱�� �ִ°���� ����ġ(����)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == 0) {//������� WWWWX
						stone[i][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == BLACK && stone[i][j - 1].stone == 0) {//������� XWWWWB
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
		//�̱�� �ִ°���� ����ġ(����)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == 0) {//������� WWWWX
						stone[i + 4][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == BLACK && stone[i - 1][j].stone == 0) {//������� XWWWWB
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
		//�̱�� �ִ°���� ����ġ(�밢�� ������)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == 0) {//������� WWWWX
						stone[i + 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//������� XWWWWB
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
		//�̱�� �ִ°���� ����ġ(�밢�� �»���)
		for (int i = 18; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == 0) {//������� WWWWX
						stone[i - 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == BLACK && stone[i + 1][j - 1].stone == 0) {//������� XWWWWB
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
	//���� ���� ������ ����ġ�� 0���� �ʱ�ȭ
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (stone[i][j].stone != 0) {
				stone[i][j].weight = 0;
			}
		}
	}
	//����ġ�� �ִ밪 ã��
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (max < stone[i][j].weight) {
				max = stone[i][j].weight;
			}
		}
	}
	//����ġ�� ���� ������ ���
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
	//����ġ �ʱ�ȭ
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			stone[i][j].weight = 0;
		}
	}
	board_2020184028[*y][*x] = WHITE;
}
void WhiteDefence_2020184028(int x, int y)
{
	// ��밡 ���� ���� ��ġ�� ���޹޾Ƽ� �����մϴ�
	board_2020184028[y][x] = BLACK;
}
void BlackAttack_2020184028(int* x, int* y)
{
	// ���� �����Ͻ� �� ���� ������ �־��ּ���
	int check = 0;//�� �پ� �˻��ϰ� �ϴ� ����

	int Echeck = 0;//�� ���� üũ
	int Estone = 1;//���� ���� üũ���ִ� ����
	int b = 0; //������ �ѹ��� ã�� �ϴ� ����
	int savex = 0; //�����϶��� ��ǥ ���庯��
	int savey = 0; //�����϶��� ��ǥ ���庯��
	//�밢�� ���� ����
	int linenum = 1;//�밢�� ����Ȯ�� ����


	int max = 0;//����ġ�� �ִ밪 ����


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
		//ó�� �浹�� ������ġ�� �д�.
		stone[8][8].weight += 10;
	}
	else if (stonenum == 1) {
		//�����ϰ� �δ� �� �ٵ� �ǿ� ���� ������쿡�� �ߵ��ǰ��Ѵ�.
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				//�浹�� �������� �ֺ� 8�ڸ��� ����ġ�� �÷��ش�.
				if (stone[i][j].stone == BLACK) {
					if (stone[i + 1][j].stone == 0) {//��(��)��ĭ�ϰ��
						stone[i + 1][j].weight += 10;//����ġ�� �ø���.
					}
					if (stone[i][j + 1].stone == 0) {//��(��)��ĭ�ϰ��
						stone[i][j + 1].weight += 10;//����ġ�� �ø���.
					}
					if (stone[i + 1][j + 1].stone == 0) {//��(����)��ĭ�ϰ��
						stone[i + 1][j + 1].weight += 10;//����ġ�� �ø���.
					}

					if (i > 0) {
						if (stone[i - 1][j].stone == 0) {//��(��)��ĭ�ϰ��
							stone[i - 1][j].weight += 10;//����ġ�� �ø���.
						}
						if (stone[i - 1][j + 1].stone == 0) {//��(�ϵ�)��ĭ�ϰ��
							stone[i - 1][j + 1].weight += 10;//����ġ�� �ø���.
						}
					}
					if (j > 0) {
						if (stone[i][j - 1].stone == 0) {//��(��)��ĭ�ϰ��
							stone[i][j - 1].weight += 10;//����ġ�� �ø���.
						}
						if (stone[i + 1][j - 1].stone == 0) {//��(����)��ĭ�ϰ��
							stone[i + 1][j - 1].weight += 10;//����ġ�� �ø���.
						}
					}
					if (i > 0 && j > 0) {
						if (stone[i - 1][j - 1].stone == 0) {//��(�ϼ�)��ĭ�ϰ��
							stone[i - 1][j - 1].weight += 10;//����ġ�� �ø���.
						}
					}
				}
			}
		}
		//���� ���� ���� üũ(����)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0) {//2ĭ������ ���
						stone[i][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == BLACK && stone[i][j - 1].stone == 0) {//2ĭ �����ε� �����ִ°��
						stone[i][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == BLACK && stone[i][j - 1].stone == 0) {//3ĭ �����ε� �����ִ°��
						stone[i][j - 1].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == 0) {//3ĭ�����ϰ��
						stone[i][j + 3].weight += 40;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == BLACK && stone[i][j - 1].stone == 0) {//4ĭ �����ε� ���� �ִ°��
						stone[i][j - 1].weight += 60;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == 0) {//4ĭ�����ϰ��
						stone[i][j + 4].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		//���� ���� ���� üũ(����)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0) {//2ĭ������ ���
						stone[i + 2][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == BLACK && stone[i - 1][j].stone == 0) {//2ĭ �����ε� �����ִ°��
						stone[i - 1][j].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == BLACK && stone[i - 1][j].stone == 0) {//3ĭ �����ε� �����ִ°��
						stone[i - 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == 0) {//3ĭ�����ϰ��
						stone[i + 3][j].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == BLACK && stone[i - 1][j].stone == 0) {//4ĭ �����ε� ���� �ִ°��
						stone[i - 1][j].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == 0) {//4ĭ�����ϰ��
						stone[i + 4][j].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//������ �밢�� ����
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == 0) {//������ 2ĭ �����ϰ��
						stone[i + 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//������ 2ĭ �����϶� �������
						stone[i - 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == 0) {//������ 3ĭ �����ϰ��
						stone[i + 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//������ 3ĭ �����϶� �������
						stone[i - 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == 0) {//������ 4ĭ �����ϰ��
						stone[i + 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == WHITE && stone[i + 2][j + 2].stone == WHITE && stone[i + 3][j + 3].stone == WHITE && stone[i + 4][j + 4].stone == BLACK && stone[i - 1][j - 1].stone == 0) {//������ 4ĭ �����϶� �������
						stone[i - 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//�»��� �밢�� ����
		for (int i = 19; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == 0) {//�»��� 2ĭ�����϶�
						stone[i - 2][j + 2].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == BLACK && stone[i + 1][j - 1].stone == 0) { //�»��� 2ĭ�����϶� �������
						stone[i + 1][j - 1].weight += 10;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == 0) { //�»��� 3ĭ�����϶�
						stone[i - 3][j + 3].weight += 30;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == BLACK && stone[i + 1][j - 1].stone == 0) { //�»��� 3ĭ�����϶� �������
						stone[i + 1][j - 1].weight += 40;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == 0) { //�»��� 4ĭ�����϶�
						stone[i - 4][j + 4].weight += 60;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == WHITE && stone[i - 2][j + 2].stone == WHITE && stone[i - 3][j + 3].stone == WHITE && stone[i - 4][j + 4].stone == BLACK && stone[i + 1][j - 1].stone == 0) { //�»��� 4ĭ�����϶� �������
						stone[i + 1][j - 1].weight += 60;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//���� ���� üũ
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE) {//OXO�̰��
						stone[i][j + 1].weight += 20;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == WHITE) {//OOXO���
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE) {//OXOO���
						stone[i][j + 2].weight += 30;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == 0 && stone[i][j + 4].stone == WHITE) {//OOOXO���
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == 0 && stone[i][j + 2].stone == WHITE && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == WHITE) {//OXOOO���
						stone[i][j + 1].weight += 50;
						check = 1;
					}
					else if (stone[i][j + 1].stone == WHITE && stone[i][j + 2].stone == 0 && stone[i][j + 3].stone == WHITE && stone[i][j + 4].stone == WHITE) {//OOXOO���
						stone[i][j + 2].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//���� ���� üũ
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == WHITE && check == 0) {
					if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE) {//OXO�̰��
						stone[i + 1][j].weight += 20;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == WHITE) {//OOXO���
						stone[i + 2][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE) {//OXOO���
						stone[i + 1][j].weight += 30;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == 0 && stone[i + 4][j].stone == WHITE) {//OOOXO���
						stone[i][j + 3].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == 0 && stone[i + 2][j].stone == WHITE && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == WHITE) {//OXOOO���
						stone[i + 1][j].weight += 50;
						check = 1;
					}
					else if (stone[i + 1][j].stone == WHITE && stone[i + 2][j].stone == 0 && stone[i + 3][j].stone == WHITE && stone[i + 4][j].stone == WHITE) {//OOXOO���
						stone[i + 2][j].weight += 50;
						check = 1;
					}
				}
			}
			check = 0;
		}
		check = 0;
		//�̱�� �ִ°���� ����ġ(����)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == 0) {//������� BBBBX
						stone[i][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i][j + 1].stone == BLACK && stone[i][j + 2].stone == BLACK && stone[i][j + 3].stone == BLACK && stone[i][j + 4].stone == WHITE && stone[i][j - 1].stone == 0) {//������� XBBBBW
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
		//�̱�� �ִ°���� ����ġ(����)
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == 0) {//������� BBBBX
						stone[i + 4][j].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j].stone == BLACK && stone[i + 2][j].stone == BLACK && stone[i + 3][j].stone == BLACK && stone[i + 4][j].stone == WHITE && stone[i - 1][j].stone == 0) {//������� XBBBBW
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
		//�̱�� �ִ°���� ����ġ(�밢�� ������)
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == 0) {//������� BBBBX
						stone[i + 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i + 1][j + 1].stone == BLACK && stone[i + 2][j + 2].stone == BLACK && stone[i + 3][j + 3].stone == BLACK && stone[i + 4][j + 4].stone == WHITE && stone[i - 1][j - 1].stone == 0) {//������� XBBBBW
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
		//�̱�� �ִ°���� ����ġ(�밢�� �»���)
		for (int i = 18; i >= 0; i--) {
			for (int j = 0; j < 19; j++) {
				if (stone[i][j].stone == BLACK && check == 0) {
					if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == 0) {//������� BBBBX
						stone[i - 4][j + 4].weight += 200;
						check = 1;
					}
					else if (stone[i - 1][j + 1].stone == BLACK && stone[i - 2][j + 2].stone == BLACK && stone[i - 3][j + 3].stone == BLACK && stone[i - 4][j + 4].stone == WHITE && stone[i + 1][j - 1].stone == 0) {//������� XBBBBW
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
	//���� ���� ������ ����ġ�� 0���� �ʱ�ȭ
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (stone[i][j].stone != 0) {
				stone[i][j].weight = 0;
			}
		}
	}
	//����ġ�� �ִ밪 ã��
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (max < stone[i][j].weight) {
				max = stone[i][j].weight;
			}
		}
	}
	//����ġ�� ���� ������ ���
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
	//����ġ �ʱ�ȭ
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			stone[i][j].weight = 0;
		}
	}
	board_2020184028[*y][*x] = BLACK;
}
void BlackDefence_2020184028(int x, int y)
{
	// ��밡 ���� ���� ��ġ�� ���޹޾Ƽ� �����մϴ�
	board_2020184028[y][x] = WHITE;
}