#include<stdio.h>
int main() {
	int x, y;
	int x1=0, y1=0;
	int x2 = 0, y2 = 0;
	int p1 = 0;
	int a[20][20];
	int w = 0, b = 0, k = 0;
	char check = 0, check1 = 0, check2 = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int i = 0;i < 20;i++) {
		for (int j = 0;j < 20;j++) {
			a[i][j] = '*';
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
	while (1) {
		printf("�Ʒ� ���� - x��, ���ι��� - y��\n(0, 0)���� ���� �Ʒ��� ������ �밢�� ����, (19, 0)���� ���� ��� ����� �밢�� ����\n");
		printf("��ǥ�� �Է��Ͻÿ� : ");
		scanf_s("%d %d", &x, &y);
		if (a[x][y] != '*') {
			printf("�̹� ���� �����ֽ��ϴ�.\n");
			continue;
		}
		for (int i = 0;i < 20;i++) {
			for (int j = 0;j < 20;j++) {
				if (x == i && y == j) {
					if (p1 % 2 == 0) {
						a[i][j] = 'O';
						printf("%c ", a[i][j]);
						w++;
					}
					else {
						a[i][j] = 'X';
						printf("%c ", a[i][j]);
						b++;
					}
				}
				else {
					printf("%c ", a[i][j]);
				}
			}
			printf("\n");
		}
		p1++;
		printf("O�� �� ���� : %d       X�� �� ���� : %d\n", w, b);
		printf("======================================================\n");
		w = 0;b = 0;
		for (int i = 0;i < 20;i++) {
			for (int j = 0;j < 20;j++) {
				if (a[i][j] == 'O') {
					w++;
				}
				if (a[i][j] == 'X') {
					b++;
				}
			}
			if (w > 0 || b > 0) {
				printf("%d��° ���� �� - O�� ���� : %d       X�� ���� : %d\n", i + 1, w, b);
			}
			w = 0;b = 0;
		}
		printf("======================================================\n");
		for (int j = 0;j < 20;j++) {
			for (int i = 0;i < 20;i++) {
				if (a[i][j] == 'O') {
					w++;
				}
				if (a[i][j] == 'X') {
					b++;
				}
			}
			if (w > 0 || b > 0) {
				printf("%d��° ���� �� - O�� ���� : %d       X�� ���� : %d\n", j + 1, w, b);
			}
			w = 0;b = 0;
		}
		printf("======================================================\n");
		for (int i = 0;i < 20;i++) {
			for (int j = 0;j < 20;j++) {
				if (check != a[i][j]) {
					if (count > count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							x1 = i;
							y1 = j-1;
						}
					}
					else if (count == count1) {
						if (check != check1) {
							check2 = check;
							count2 = count;
							x2 = i;
							y2 = j - 1;
						}
					}
					check = a[i][j];
					count = 1;
				}
				else {
					count++;
					if (j == 19) {
						if (check != '*') {
							check1 = check;
							count1 = count;
							x1 = i;
							y1 = j - 1;
						}
					}
				}
			}
			if (count1 > 1) {
				if (count1 > count2) {
					printf("%d��° ���� �ٿ��� ���ӵǴ� �� - %c : %d\t", i + 1, check1, count1);
					printf("���ӵǴ� ���� ��ǥ = \t");
					for (int l = count1-1;l > -1;l--) {
						printf("(%d, %d). ", x1, y1-l);
					}
					printf("\n");
				}
				if (count1 == count2) {
					printf("%d��° ���� �ٿ��� ���ӵǴ� �� - %c : %d - %c : %d\t", i + 1, check1, count1,check2,count2);
					printf("���ӵǴ� ���� ��ǥ = \t");
					for (int l = count1 - 1;l > -1;l--) {
						printf("(%d, %d). ", x1, y1 - l);
					}
					printf("\t");
					for (int l = count2 - 1;l > -1;l--) {
						printf("(%d, %d). ", x2, y2 - l);
					}
					printf("\n");
				}
				if (count2 > count1) {
					printf("%d��° ���� �ٿ��� ���ӵǴ� �� - %c : %d\t", i + 1, check2, count2);
					printf("���ӵǴ� ���� ��ǥ = \t");
					for (int l = count2 - 1;l > -1;l--) {
						printf("(%d, %d). ", x2, y2 - l);
					}
					printf("\n");
				}
			}
			check = 0;count = 0;count1 = 0;check1 = 0;
		}
		printf("======================================================\n");
		for (int j = 0;j < 20;j++) {
			for (int i = 0;i < 20;i++) {
				if (check != a[i][j]) {
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
					check = a[i][j];
					count = 1;
				}
				else {
					count++;
					if (i == 19) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
				}
			}if (count1 > 1) {
				printf("%d��° ���� �ٿ��� ���ӵǴ� �� - %c : %d\n", j + 1, check1, count1);
			}
			check = 0;count = 0;count1 = 0;check1 = 0;
		}
		printf("======================================================\n");
		for (int j = 18;j > 0;j--) {
			for (int i = j;i < 20;i++) {
				if (check != a[i][k]) {
					if (check != '*') {
						count = 0;
						if (count >= count1) {
							check1 = check;
							count1 = count;
						}
					}
					check = a[i][k];
					count = 1;
				}
				else {
					count++;
					if (i == 19) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
				}
				k++;
			}
			if (count1 > 1) {
				printf("(������)%d��° �밢�� �ٿ��� ���ӵǴ� �� - %c : %d\n", 20 - j, check1, count1);
			}
			check = 0;count = 0;count1 = 0;check1 = 0;k = 0;
		}
		for (int i = 0;i < 19;i++) {
			for (int j = i;j < 20;j++) {
				if (check != a[k][j]) {
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
					check = a[k][j];
					count = 1;
				}
				else {
					count++;
					if (j == 19) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
				}
				k++;
			}
			if (count1 > 1) {
				printf("(������)%d��° �밢�� �ٿ��� ���ӵǴ� �� - %c : %d\n", i + 20, check1, count1);
			}
			check = 0;count = 0;count1 = 0;check1 = 0;k = 0;
		}
		printf("======================================================\n");
		for (int i = 1;i <= 19;i++) {
			for (int j = i;j >= 0;j--) {
				if (check != a[k][j]) {
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
					check = a[k][j];
					count = 1;
				}
				else {
					count++;
					if (j == 0) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
				}
				k++;
			}
			if (count1 > 1) {
				printf("(������)%d��° �밢�� �ٿ��� ���ӵǴ� �� - %c : %d\n", i+1, check1, count1);
			}
			check = 0;count = 0;count1 = 0;check1 = 0;k = 0;
		}
		k = 19;
		for (int j = 19;j >0 ;j--) {
			for (int i = 18-(19-j);i <20;i++) {
				if (check != a[i][k]) {
					if (count >= count1) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
					check = a[i][k];
					count = 1;
				}
				else {
					count++;
					if (i == j) {
						if (check != '*') {
							check1 = check;
							count1 = count;
						}
					}
				}
				k--;
			}
			if (count1 > 1) {
				printf("(������)%d��° �밢�� �ٿ��� ���ӵǴ� �� - %c : %d\n", 19 + j, check1, count1);
			}
			check = 0;count = 0;count1 = 0;check1 = 0;k = 19;
		}
	}
}