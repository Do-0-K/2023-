#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING_
typedef struct kode {
	int numbe = 0;
	char name[12] = "           ";
	kode* tree;
	struct kode* lchild;
	struct kode* rchild;
}kode;
FILE* fp;
char nam[12] = "           ";
char pos[12] = "           ";
int hv = 0;
int av = 0;
int ab = 0;
int cnt = 0;
int xcnt = 0;
kode* cu;
void maketree(kode** head) {
	//��Ʈ ��带 ����� �۾�
	if ((*head) == NULL) {
		(*head) = (kode*)malloc(sizeof(kode));
	}
}
void maketr(kode** head) {
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		if (xcnt == 0) {
			//��Ʈ ��忡 ���� �ְ� �����ϱ� ���ؼ� ���ǹ��� ���
			fscanf(fp, "%d %s\n", &(*head)->numbe, &(*head)->name);
			(*head)->lchild = (*head)->rchild = NULL;
			xcnt++;
		}
		kode* cur = (*head); //��� �Ӹ��� �ʱ�ȭ�� �������
		kode* cu = (kode*)malloc(sizeof(kode));
		fscanf(fp, "%d %s\n", &cu->numbe, &cu->name);
		while (cur != NULL) { //�� �۾�
			if (strcmp(cur->name, cu->name) < 0) { //���� ���� ��尡 �� ũ�� ����������
				if (cur->rchild == NULL) { //NULL�� ��쿡�� ��带 �־��ش�.
					cur->rchild = cu;
					cur->rchild->lchild = cur->rchild->rchild = NULL;
					break;
				}
				else {
					cur = cur->rchild; //NULL�� �ƴϸ� ���� ���������� �Ѿ
				}
			}
			else { //������ ����
				if (cur->lchild == NULL) { //NULL�� ��쿡�� ��带 �־��ش�.
					cur->lchild = cu;
					cur->lchild->lchild = cur->lchild->rchild = NULL;
					break;
				}
				else {
					cur = cur->lchild; //NULL�� �ƴϸ� ���� �������� �Ѿ
				}
			}
		}
	}
	xcnt = 0;
	fclose(fp);
}
void search(kode* node) {
	while (node != NULL) {
		if (strcmp(nam, node->name) == 0) { //���ϴ� ��� ã���� ���
			printf("%d\t%12s\n",node->numbe, node->name);
			return;
		}
		else { //�����̶� ���������� ���ÿ� ��
			search(node->rchild);
			search(node->lchild);
			break;
		}
	}
}
void insert(kode** t, kode* cu) {
	//cu ���� ���ο��� ���ο� ���� �ް� ���´�
	kode* ne = (*t);
	if ((*t) == NULL) { //��Ʈ�� ������� ���
		(*t) = cu;
	}
	while (ne != NULL) {
		if (strcmp(ne->name, cu->name) < 0) { //ũ�� ����������
			if (ne->rchild == NULL) { //NULL���� ��쿡�� ��屳ü
				ne->rchild = cu;
				ne->rchild->lchild = ne->rchild->rchild = NULL;
				break;
			}
			else {
				ne = ne->rchild;
			}
		}
		else { //������ ��������
			if (ne->lchild == NULL) { //NULL���� ��쿡�� ��屳ü
				ne->lchild = cu;
				ne->lchild->lchild = ne->lchild->rchild = NULL;
				break;
			}
			else {
				ne = ne->lchild;
			}
		}
	}
}
void del(kode** t) {
	//Ʈ���κп��� ���� ����� �κ��̶�� ������
	kode* cur = (*t);
	kode* parent = NULL;
	kode* child = NULL;
	kode* pre = NULL;
	kode* suc = NULL;
	while (cur != NULL) {
		if (strcmp(cur->name, nam) == 0) {
			break;
		}
		parent = cur;
		if (strcmp(cur->name, nam) < 0) {
			cur = cur->rchild;
		}
		else {
			cur = cur->lchild;
		}
	}
	if (cur == NULL) {
		printf("��� ���� �����ϴ�.\n");
		return;
	}
	if (cur->lchild == NULL && cur->rchild == NULL) {
		if (parent != NULL) {
			if (parent->lchild == cur) {
				parent->lchild = NULL;
			}
			else {
				parent->rchild = NULL;
			}
		}
		else {
			cur = NULL;
		}
	}
	else if (cur->lchild != NULL && cur->rchild != NULL) {
		pre = cur;
		suc = cur->lchild;
		while (suc->rchild != NULL) {
			pre = suc;
			suc = suc->rchild;
		}
		if (pre->lchild == suc) {
			pre->lchild = suc->lchild;
		}
		else {
			pre->rchild = suc->lchild;
		}
		sprintf(cur->name, suc->name);
		cur->numbe = suc->numbe;
		cur = suc;
	}
	else {
		if (cur->lchild != NULL) {
			child = cur->lchild;
		}
		else if (cur->rchild != NULL) {
			child = cur->rchild;
		}
		if (parent != NULL) {
			if (parent->lchild == cur) {
				parent->lchild = child;
			}
			else if (parent->rchild == cur) {
				parent->rchild = child;
			}
		}
		else {
			(*t) = child;
		}
	}
	free(cur);
}
void print(kode* t) {
	if (t != NULL) { //������ȸ -> ���������� �������� ���������� ���� ���� ��
		cnt++;
		printf("%d - %d\t%12s\n", cnt, t->numbe, t->name);
		print(t->lchild);
		print(t->rchild);
	}
}
void sort(kode* t) {
	if (t != NULL) { //���� ��ȸ - ���� ���ʿ� �ִ� ������ ��� - ������� ���
		sort(t->lchild);
		cnt++;
		printf("%d - %d\t%12s\n", cnt, t->numbe, t->name);
		sort(t->rchild);
	}
}
int main() {
	kode* rot = NULL;
	int ment = 0;
	maketree(&rot);
	while (1) {
		cnt = 0;
		printf("1.����� 2.�˻� 3.���� 4.���� 5.���� 6.���\n");
		ment = 0;
		printf("������ ����� �����ϼ��� - ");
		scanf("%d", &ment);
		switch (ment) {
		case 1:
			maketr(&rot);
			break;
		case 2:
			while (1) {
				printf("ã�� ����� �̸��� �Է����ּ��� - ");
				scanf(" %s", &nam);
				break;
			}
			search(rot);
			break;
		case 3:
			while (1) {
				cu = (kode*)malloc(sizeof(kode));
				cu->lchild = cu->rchild = NULL;
				printf("���ο� ����� number ���� �Է����ּ��� - ");
				scanf("%d", &cu->numbe);
				printf("���ο� ����� name ���� �Է����ּ��� - ");
				scanf("%s", &cu->name);
				break;
			}
			insert(&rot,cu);
			break;
		case 4:
			while (1) {
				printf("������ ����� �̸��� �Է����ּ��� - ");
				scanf(" %s", &nam);
				break;
			}
			del(&rot);
			break;
		case 5:
			sort(rot);
			break;
		case 6:
			print(rot);
			break;
		}
	}
}