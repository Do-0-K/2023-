#include<stdio.h>
int main() {
	int x, y;
	int p1=0;
	int a[19][19];
	int w=0, b=0;
	for (int i = 0;i < 19;i++) {
		for (int j = 0;j < 19;j++) {
			a[i][j] = '*';
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
	while (1) {
		printf("��ǥ�� �Է��Ͻÿ� : ");
		scanf_s("%d %d", &x, &y);
		if (a[x][y] != '*') {
			printf("�̹� ���� �����ֽ��ϴ�.\n");
			continue;
		}
		for (int i = 0;i < 19;i++) {
			for (int j = 0;j < 19;j++) {
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
		printf("O�� ���� : %d       X�� ���� : %d\n", w,b);
	}
}