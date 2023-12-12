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
		printf("좌표를 입력하시오 : ");
		scanf_s("%d %d", &x, &y);
		if (a[x][y] != '*') {
			printf("이미 돌이 놓여있습니다.\n");
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
		printf("O의 개수 : %d       X의 개수 : %d\n", w,b);
	}
}