#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	int sosok = 0;
	int age = 0;
	int score = 0;
	char name[10] = "        ";
	char ID[10] = "        ";
	struct node* lchild;
	struct node* rchild;
}node;
FILE* fp;
int x = 0;
int cnt = 0;
//11,12번
void makefirst(node** root) {
	if ((*root) == NULL) {
		(*root) = (node*)malloc(sizeof(node));
	}
}
void maketree(node** root) {
	fp = fopen("midTerm.txt", "r");
	while (!feof(fp)) {
		if (x == 0) {
			fscanf(fp, "%10s\t%d\t%10s\t%d\t%d\n", &(*root)->name, &(*root)->age, &(*root)->ID, &(*root)->sosok, &(*root)->score);
			(*root)->lchild = (*root)->rchild = NULL;
			x++;
		}
		node* cu = (*root);
		node* cur = (node*)malloc(sizeof(node));
		fscanf(fp, "%10s\t%d\t%10s\t%d\t%d\n", &cur->name, &cur->age, &cur->ID, &cur->sosok, &cur->score);
		while (cu != NULL) {
			if (cu->age < cur->age) {
				if (cu->rchild == NULL) {
					cu->rchild = cur;
					cu->rchild->lchild = cu->rchild->rchild = NULL;
					break;
				}
				else {
					cu = cu->rchild;
				}
			}
			else {
				if (cu->lchild == NULL) {
					cu->lchild = cur;
					cu->lchild->lchild = cu->lchild->rchild = NULL;
					break;
				}
				else {
					cu = cu->lchild;
				}
			}
		}
	}
	fclose(fp);
	x = 0;
}
void del(node** root, int k) {
	node* cur = (*root);
	node* parent = NULL;
	node* child = NULL;
	node* pre = NULL;
	node* suc = NULL;
	while (cur != NULL) {
		if (cur->age == k) {
			break;
		}
		parent = cur;
		if (cur->age < k) { //조건 적어주기
			cur = cur->rchild;
		}
		else {
			cur = cur->lchild;
		}
	}
	if (cur == NULL) {
		printf("해당 나이를 가진 노드가 없습니다.\n");
		return;
	}
	if (cur->lchild == NULL && cur->rchild == NULL) { //자식노드 0개
		if (parent != NULL) {
			if (parent->lchild == cur) {
				parent->lchild = NULL;
			}
			else if (parent->rchild == cur) {
				parent->rchild = NULL;
			}
		}
		else {
			cur = NULL;
		}
	}
	else if (cur->lchild != NULL && cur->rchild != NULL) { //자식노드 2개
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
		sprintf(cur->ID, suc->ID);
		cur->age = suc->age;
		cur->sosok = suc->sosok;
		cur->score = suc->score;
		cur = suc;
	}
	else { //자식노드 1개
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
			(*root) = child;
		}
	}
	free(cur);
}
void print(node* root) {
	node* t = root;
	if (t != NULL) {
		print(t->lchild);
		cnt++;
		printf("%d - %10s\t%d\t%10s\t%d\t%d\n", cnt, t->name, t->age, t->ID, t->sosok, t->score);
		print(t->rchild);
	}
}
void re_print(node* root) {
	if (root != NULL) {
		re_print(root->rchild);
		cnt++;
		printf("%d - %10s\t%d\t%10s\t%d\t%d\n", cnt, root->name, root->age, root->ID, root->sosok, root->score);
		re_print(root->lchild);
	}
}
int main() {
	node* rot = NULL;
	makefirst(&rot);
	int ment = 0;
	int nai = 0;
	printf("문제 11,12번\n");
	while (1) {
		cnt = 0, ment = 0;
		printf("1.트리 생성 2.삭제 3.출력 4.역출력\n");
		printf("원하시는 명령을 선택해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			maketree(&rot);
			break;
		case 2:
			printf("삭제를 원하는 나이를 입력해주세요 - ");
			scanf_s("%d", &nai);
			del(&rot, nai);
			break;
		case 3:
			print(rot);
			break;
		case 4:
			re_print(rot);
			break;
		}
	}
}
//9,10 번
char d[10] = "         ";
node* fe;
void makefirst(node** root) {
	if ((*root) == NULL) {
		(*root) = (node*)malloc(sizeof(node));
	}
}
void maketree(node** root) {
	fp = fopen("midTerm.txt", "r");
	while (!feof(fp)) {
		if (x == 0) {
			fscanf(fp, "%10s\t%d\t%10s\t%d\t%d\n", &(*root)->name, &(*root)->age, &(*root)->ID, &(*root)->sosok, &(*root)->score);
			(*root)->lchild = (*root)->rchild = NULL;
			x++;
		}
		node* cu = (*root);
		node* cur = (node*)malloc(sizeof(node));
		fscanf(fp, "%10s\t%d\t%10s\t%d\t%d\n", &cur->name, &cur->age, &cur->ID, &cur->sosok, &cur->score);
		while (cu != NULL) {
			if (strcmp(cu->ID,cur->ID)<0) {
				if (cu->rchild == NULL) {
					cu->rchild = cur;
					cu->rchild->lchild = cu->rchild->rchild = NULL;
					break;
				}
				else {
					cu = cu->rchild;
				}
			}
			else {
				if (cu->lchild == NULL) {
					cu->lchild = cur;
					cu->lchild->lchild = cu->lchild->rchild = NULL;
					break;
				}
				else {
					cu = cu->lchild;
				}
			}
		}
	}
	fclose(fp);
	x = 0;
}
void search(node* root) {
	node* t = root;
	while (t != NULL) {
		if (strcmp(t->ID, d) == 0) {
			printf("%10s\t%d\t%10s\t%d\t%d\n",t->name, t->age, t->ID, t->sosok, t->score);
			return;
		}
		else {
			search(t->lchild);
			search(t->rchild);
			break;
		}
	}
}
void insert(node** root) {
	node* t = (*root);
	if ((*root) == NULL) {
		(*root) = fe;
		return;
	}
	while (t != NULL) {
		if (strcmp(t->ID, fe->ID) < 0) {
			if (t->rchild == NULL) {
				t->rchild = fe;
				t->rchild->lchild = t->rchild->rchild = NULL;
				break;
			}
			else {
				t = t->rchild;
			}
		}
		else {
			if (t->lchild == NULL) {
				t->lchild = fe;
				t->lchild->lchild = t->lchild->rchild = NULL;
				break;
			}
			else {
				t = t->lchild;
			}
		}
	}
}
void print(node* t) {
	if (t != NULL) {
		print(t->lchild);
		cnt++;
		printf("%d - %10s\t%d\t%10s\t%d\t%d\n", cnt, t->name, t->age, t->ID, t->sosok, t->score);
		print(t->rchild);
	}
}
int main() {
	node* rot = NULL;
	makefirst(&rot);
	int ment = 0;
	int nai = 0;
	printf("문제 9,10번\n");
	while (1) {
		cnt = 0, ment = 0;
		printf("1.트리 생성 2.검색 3.삽입 4.출력\n");
		printf("원하시는 명령을 선택해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			maketree(&rot);
			break;
		case 2:
			printf("찾으시는 ID를 입력해주세요(최대 10자) - ");
			scanf("%s", &d);
			search(rot);
			break;
		case 3:
			while (1) {
				fe = (node*)malloc(sizeof(node));
				fe->lchild = fe->rchild = NULL;
				printf("새로운 노드의 age 값을 입력해주세요 - ");
				scanf("%d", &fe->age);
				printf("새로운 노드의 name 값을 입력해주세요 - ");
				scanf("%s", &fe->name);
				printf("새로운 노드의 ID 값을 입력해주세요 - ");
				scanf("%s", &fe->ID);
				printf("새로운 노드의 sosok 값을 입력해주세요 - ");
				scanf("%d", &fe->sosok);
				printf("새로운 노드의 score 값을 입력해주세요 - ");
				scanf("%d", &fe->score);
				break;
			}
			insert(&rot);
			break;
		case 4:
			print(rot);
			break;
		}
	}
}
//트리 삭제 연습 - 이름
void del(node** root) {
	node* cu = (*root);
	node* parent = NULL;
	node* child = NULL;
	node* pre = NULL;
	node* suc = NULL;
	while (cu != NULL) {
		if (strcmp(cu->name, d) == 0) {
			return;
		}
		parent = cu;
		if (strcmp(cu->name, d) < 0) {
			cu = cu->rchild;
		}
		else {
			cu = cu->lchild;
		}
	}
	if (cu == NULL) {
		printf("그런 노드는 없당께\n");
	}
	if (cu->lchild == NULL && cu->rchild == NULL) {//노드 0개
		if (parent != NULL) {
			if (parent->lchild == cu) {
				parent->lchild = NULL;
			}
			else if (parent->rchild == cu) {
				parent->rchild = NULL;
			}
		}
		else {
			cu = NULL;
		}
	}
	else if (cu->lchild != NULL && cu->rchild != NULL) {//노드 2개
		pre = cu;
		suc = cu->lchild;
		while (suc->rchild != NULL) {
			pre = suc;
			suc = suc->rchild;
		}
		if (pre->lchild == suc) {
			pre->lchild = suc->lchild;
		}
		else if (pre->rchild == suc) {
			pre->rchild = suc->rchild;
		}
		sprintf(cu->name, suc->name);
		sprintf(cu->ID, suc->ID);
		cu->sosok = suc->sosok;
		cu->score = suc->score;
		cu->age = suc->age;
		cu = suc;
	}
	else {
		if (cu->lchild != NULL) {
			child = cu->lchild;
		}
		else if (cu->rchild != NULL) {
			child = cu->rchild;
		}
		if (parent != NULL) {
			if (parent->lchild == cu) {
				parent->lchild = child;
			}
			else if (parent->rchild == cu) {
				parent->rchild = child;
			}
		}
		else {
			(*root) = child;
		}
	}
	free(cu);
}
void dela(node** t) {
	node* cu = (*t);
	node* parent = NULL;
	node* child = NULL;
	node* pre = NULL;
	node* suc = NULL;
	while (cu != NULL) {
		if (strcmp(cu->ID, d) == 0) {
			return;
		}
		parent = cu;
		if (strcmp(cu->ID, d) < 0) {
			cu = cu->rchild;
		}
		else {
			cu = cu->lchild;
		}
	}
	if (cu == NULL) {
		printf("그런 노드 없음\n");
		return;
	}
	if (cu->lchild == NULL && cu->rchild == NULL) {
		if (parent != NULL) {
			if (parent->lchild == cu) {
				parent->lchild = NULL;
			}
			else {
				parent->rchild = NULL;
			}
		}
		else {
			cu = NULL;
		}
	}
	else if (cu->lchild != NULL && cu->rchild != NULL) {
		pre = cu;
		suc = cu->lchild;
		while (suc->rchild != NULL) {
			pre = suc;
			suc = suc->rchild;
		}
		if (pre->lchild == suc) {
			pre->lchild = suc->lchild;
		}
		else {
			pre->rchild = suc->rchild;
		}
		sprintf(cu->name, suc->name);
		sprintf(cu->ID, suc->ID);
		cu->sosok = suc->sosok;
		cu->score = suc->score;
		cu->age = suc->age;
		cu = suc;
	}
	else {
		if (cu->lchild != NULL) {
			child = cu->lchild;
		}
		else if (cu->rchild != NULL) {
			child = cu->rchild;
		}
		if (parent != NULL) {
			if (parent->lchild == cu) {
				parent->lchild = child;
			}
			else {
				parent->rchild = child;
			}
		}
		else {
			(*t) = child;
		}
	}
	free(cu);
}