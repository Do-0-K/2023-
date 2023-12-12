#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING_
typedef struct node {
	char position[12] = "           ";
	char name[12] = "           ";
	int hp = 0;
	int ak = 0;
	int ad = 0;
	struct node* next;
	node* head;
	node* tail;
}node;
typedef struct kode {
	char position[12] = "           ";
	char name[12] = "           ";
	int hp = 0;
	int ak = 0;
	int ad = 0;
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
void makefirst(node** head, node** tail) {
	if ((*head) == NULL) {
		(*head) = (*tail) = (node*)malloc(sizeof(node));
	}
}
void maketree(kode** head) {
	if ((*head) == NULL) {
		(*head) = (kode*)malloc(sizeof(kode));
	}
}
void MAKE_SL(node** head, node** tail, double start, double end) {
	fp = fopen("akakak.txt", "r");
	start = (double)clock() / CLOCKS_PER_SEC;
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%s %s %d %d %d\n", &(*tail)->next->position, &(*tail)->next->name, &(*tail)->next->hp, &(*tail)->next->ak, &(*tail)->next->ad);
		(*tail) = (*tail)->next;
	}
	(*tail)->next = NULL;
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("MAKE_SL() 함수 실행시간 = %1f\n", (end - start));
	fclose(fp);
}
node* Partition_SL(node* head, node* tail, node** newHead, node** newTail) {
	node* pivot = tail;
	node* prev = NULL;
	node* now = head;
	node* localTail = pivot;
	while (now != pivot) {
		if (strcmp(now->name, pivot->name) < 0) {
			if ((*newHead) == NULL) {
				(*newHead) = now;
			}
			prev = now;
			now = now->next;
		}
		else {
			if (prev != NULL) {
				prev->next = now->next;
			}
			node* temp = now->next;
			now->next = NULL;
			localTail->next = now;
			localTail = now;
			now = temp;
		}
	}
	if ((*newHead) == NULL) {
		(*newHead) = pivot;
	}
	(*newTail) = localTail;
	return pivot;
}
node* getTail(node* now) {
	while (now != NULL && now->next != NULL) {
		now = now->next;
	}
	return now;
}
node* QuickSort(node* head, node* tail) {
	if (!head || head == tail) {
		return head;
	}
	node* newHead = NULL;
	node* newTail = NULL;
	node* pivot = Partition_SL(head, tail, &newHead, &newTail);
	if (newHead != pivot) {
		node* temp = newHead;
		while (temp->next != pivot) {
			temp = temp->next;
		}
		temp->next = NULL;
		newHead = QuickSort(newHead, temp);
		temp = getTail(newHead);
		temp->next = pivot;
	}
	pivot->next = QuickSort(pivot->next, newTail);
	return newHead;
}
void SortByName_SL(node** head, node** tail, double start, double end) {
	start = (double)clock() / CLOCKS_PER_SEC;
	(*head)->next = QuickSort((*head)->next, *tail);
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("SortByName_SL() 함수 실행시간 = %1f\n", (end - start));
}
void PrintALL_SL(node* head, node* tail, double start, double end) {
	node* cu = (head)->next;
	start = (double)clock() / CLOCKS_PER_SEC;
	while (cu != NULL) {
		cnt++;
		printf("%d - %12s\t\t%12s\t\t%d\t\t%d\t\t%d\n", cnt, cu->position, cu->name, cu->hp, cu->ak, cu->ad);
		cu = cu->next;
	}
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("PrintALL_SL() 함수 실행시간 = %1f\n", (end - start));
}
void MAKE_BT(kode** head, double start, double end) {
	fp = fopen("akakak.txt", "r");
	start = (double)clock() / CLOCKS_PER_SEC;
	while (!feof(fp)) {
		if (xcnt == 0) {
			fscanf(fp, "%s %s %d %d %d\n", &(*head)->position, &(*head)->name, &(*head)->hp, &(*head)->ak, &(*head)->ad);
			(*head)->lchild = (*head)->rchild = NULL;
			xcnt++;
		}
		kode* cur = (*head);
		kode* cu = (kode*)malloc(sizeof(kode));
		fscanf(fp, "%s %s %d %d %d\n", &cu->position, &cu->name, &cu->hp, &cu->ak, &cu->ad);
		while (cur != NULL) {
			if (strcmp(cur->name, cu->name) < 0) {
				if (cur->rchild == NULL) {
					cur->rchild = cu;
					cur->rchild->lchild = cur->rchild->rchild = NULL;
					break;
				}
				else {
					cur = cur->rchild;
				}
			}
			else {
				if (cur->lchild == NULL) {
					cur->lchild = cu;
					cur->lchild->lchild = cur->lchild->rchild = NULL;
					break;
				}
				else {
					cur = cur->lchild;
				}
			}
		}
	}
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("MAKE_BT() 함수 실행시간 = %1f\n", (end - start));
	xcnt = 0;
	fclose(fp);
}
void SearchByName_BT(kode* node, double start, double end) {
	if (xcnt == 0) {
		start = (double)clock() / CLOCKS_PER_SEC;
		xcnt++;
	}
	while (node != NULL) {
		if (strcmp(nam, node->name) == 0) {
			printf("%12s\t\t%12s\t\t%d\t\t%d\t\t%d\n", node->position, node->name, node->hp, node->ak, node->ad);
			end = (((double)clock()) / CLOCKS_PER_SEC);
			printf("SearchByName_BT() 함수 실행시간 = %1f\n", (end - start));
			break;
		}
		else {
			SearchByName_BT(node->rchild, start, end);
			SearchByName_BT(node->lchild, start, end);
			break;
		}
	}
}
void Insert_BT(kode** t, kode* cu) {
	kode* ne = (*t);
	if ((*t) == NULL) {
		(*t) = cu;
	}
	while (ne != NULL) {
		if (strcmp(ne->name, cu->name) < 0) {
			if (ne->rchild == NULL) {
				ne->rchild = cu;
				ne->rchild->lchild = ne->rchild->rchild = NULL;
				break;
			}
			else {
				ne = ne->rchild;
			}
		}
		else {
			if (ne->lchild == NULL) {
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
void Delete_BT(kode** t) {
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
		sprintf(cur->position, suc->position);
		sprintf(cur->name, suc->name);
		cur->hp = suc->hp;
		cur->ak = suc->ak;
		cur->ad = suc->ad;
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
void PrintAll_BT(kode* t) {
	if (t != NULL) {
		cnt++;
		printf("%d - %12s\t\t%12s\t\t%d\t\t%d\t\t%d\n", cnt, t->position, t->name, t->hp, t->ak, t->ad);
		PrintAll_BT(t->lchild);
		PrintAll_BT(t->rchild);
	}
}
void SortByName_BT(kode* t) {
	if (t != NULL) {
		SortByName_BT(t->lchild);
		cnt++;
		printf("%d - %12s\t\t%12s\t\t%d\t\t%d\t\t%d\n", cnt, t->position, t->name, t->hp, t->ak, t->ad);
		SortByName_BT(t->rchild);
	}
}
int main() {
	int ment;
	int p = 0;
	node* head = NULL;
	node* tail = NULL;
	kode* tree = NULL;
	double start, end;
	makefirst(&head, &tail);
	maketree(&tree);
	while (1) {
		ment = 0;
		start = 0; end = 0; cnt = 0; xcnt = 0;
		printf("1. MAKE_SL() 2.SortByName_SL() 3.MAKE_BT() 4.SearchByName_BT() 5.Insert_BT() 6.Delete_BT() 7.PrintAll_BT() 8.SortByName_BT()\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			MAKE_SL(&head, &tail, start, end);
			break;
		case 2:
			SortByName_SL(&head, &tail, start, end);
			PrintALL_SL(head, tail, start, end);
			break;
		case 3:
			MAKE_BT(&tree, start, end);
			break;
		case 4:
			while (1) {
				printf("찾을 유닛의 이름을 입력해주세요 - ");
				scanf("%s", &nam);
				break;
			}
			SearchByName_BT(tree, start, end);
			break;
		case 5:
			while (1) {
				cu = (kode*)malloc(sizeof(kode));
				cu->lchild = cu->rchild = NULL;
				printf("새로운 노드의 position 값을 입력해주세요 - ");
				scanf("%s", &cu->position);
				printf("새로운 노드의 name 값을 입력해주세요 - ");
				scanf("%s", &cu->name);
				printf("새로운 노드의 hp 값을 입력해주세요 - ");
				scanf("%d", &cu->hp);
				printf("새로운 노드의 ak 값을 입력해주세요 - ");
				scanf("%d", &cu->ak);
				printf("새로운 노드의 ad 값을 입력해주세요 - ");
				scanf("%d", &cu->ad);
				break;
			}
			start = (double)clock() / CLOCKS_PER_SEC;
			Insert_BT(&tree, cu);
			end = (((double)clock()) / CLOCKS_PER_SEC);
			printf("Insert_BT() 함수 실행시간 = %1f\n", (end - start));
			break;
		case 6:
			while (1) {
				printf("삭제할 노드의 name 값을 입력해주세요 - ");
				scanf("%s", &nam);
				break;
			}
			start = (double)clock() / CLOCKS_PER_SEC;
			Delete_BT(&tree);
			end = (((double)clock()) / CLOCKS_PER_SEC);
			printf("Delete_BT() 함수 실행시간 = %1f\n", (end - start));
			break;
		case 7:
			start = (double)clock() / CLOCKS_PER_SEC;
			PrintAll_BT(tree);
			end = (((double)clock()) / CLOCKS_PER_SEC);
			printf("PrintAll_BT() 함수 실행시간 = %1f\n", (end - start));
			break;
		case 8:
			start = (double)clock() / CLOCKS_PER_SEC;
			SortByName_BT(tree);
			end = (((double)clock()) / CLOCKS_PER_SEC);
			printf("SortByName_BT() 함수 실행시간 = %1f\n", (end - start));
			break;
		default:
			printf("잘못된 명령어입니다.\n");
			break;
		}
	}
}
