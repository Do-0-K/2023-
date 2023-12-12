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
	//루트 노드를 만드는 작업
	if ((*head) == NULL) {
		(*head) = (kode*)malloc(sizeof(kode));
	}
}
void maketr(kode** head) {
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		if (xcnt == 0) {
			//루트 노드에 값을 넣고 시작하기 위해서 조건문을 사용
			fscanf(fp, "%d %s\n", &(*head)->numbe, &(*head)->name);
			(*head)->lchild = (*head)->rchild = NULL;
			xcnt++;
		}
		kode* cur = (*head); //계속 머리로 초기화를 해줘야함
		kode* cu = (kode*)malloc(sizeof(kode));
		fscanf(fp, "%d %s\n", &cu->numbe, &cu->name);
		while (cur != NULL) { //비교 작업
			if (strcmp(cur->name, cu->name) < 0) { //새로 생긴 노드가 더 크면 오른쪽으로
				if (cur->rchild == NULL) { //NULL일 경우에만 노드를 넣어준다.
					cur->rchild = cu;
					cur->rchild->lchild = cur->rchild->rchild = NULL;
					break;
				}
				else {
					cur = cur->rchild; //NULL이 아니면 다음 오른쪽으로 넘어감
				}
			}
			else { //작으면 왼쪽
				if (cur->lchild == NULL) { //NULL일 경우에만 노드를 넣어준다.
					cur->lchild = cu;
					cur->lchild->lchild = cur->lchild->rchild = NULL;
					break;
				}
				else {
					cur = cur->lchild; //NULL이 아니면 다음 왼쪽으로 넘어감
				}
			}
		}
	}
	xcnt = 0;
	fclose(fp);
}
void search(kode* node) {
	while (node != NULL) {
		if (strcmp(nam, node->name) == 0) { //원하는 노드 찾으면 출력
			printf("%d\t%12s\n",node->numbe, node->name);
			return;
		}
		else { //왼쪽이랑 오른쪽으로 동시에 들어감
			search(node->rchild);
			search(node->lchild);
			break;
		}
	}
}
void insert(kode** t, kode* cu) {
	//cu 노드는 메인에서 새로운 값을 받고 들어온다
	kode* ne = (*t);
	if ((*t) == NULL) { //루트가 비어있을 경우
		(*t) = cu;
	}
	while (ne != NULL) {
		if (strcmp(ne->name, cu->name) < 0) { //크면 오른쪽으로
			if (ne->rchild == NULL) { //NULL값인 경우에만 노드교체
				ne->rchild = cu;
				ne->rchild->lchild = ne->rchild->rchild = NULL;
				break;
			}
			else {
				ne = ne->rchild;
			}
		}
		else { //작으면 왼쪽으로
			if (ne->lchild == NULL) { //NULL값인 경우에만 노드교체
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
	//트리부분에서 제일 어려운 부분이라고 생각함
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
		printf("노드 값이 없습니다.\n");
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
	if (t != NULL) { //전위순회 -> 위에서부터 내려가는 형식이지만 왼쪽 먼저 감
		cnt++;
		printf("%d - %d\t%12s\n", cnt, t->numbe, t->name);
		print(t->lchild);
		print(t->rchild);
	}
}
void sort(kode* t) {
	if (t != NULL) { //중위 순회 - 가장 왼쪽에 있는 노드부터 출력 - 순서대로 출력
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
		printf("1.만들기 2.검색 3.삽입 4.삭제 5.정렬 6.출력\n");
		ment = 0;
		printf("실행할 명령을 선택하세요 - ");
		scanf("%d", &ment);
		switch (ment) {
		case 1:
			maketr(&rot);
			break;
		case 2:
			while (1) {
				printf("찾을 노드의 이름을 입력해주세요 - ");
				scanf(" %s", &nam);
				break;
			}
			search(rot);
			break;
		case 3:
			while (1) {
				cu = (kode*)malloc(sizeof(kode));
				cu->lchild = cu->rchild = NULL;
				printf("새로운 노드의 number 값을 입력해주세요 - ");
				scanf("%d", &cu->numbe);
				printf("새로운 노드의 name 값을 입력해주세요 - ");
				scanf("%s", &cu->name);
				break;
			}
			insert(&rot,cu);
			break;
		case 4:
			while (1) {
				printf("삭제할 노드의 이름을 입력해주세요 - ");
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