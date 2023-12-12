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
FILE* fp;
char nam[12];
int cnt = 0;
void makefirst(node** head, node** tail) {
	if ((*head) == NULL) {
		(*head) = (*tail) = (node*)malloc(sizeof(node));
	}
}
void MAKE_SL(node** head, node** tail, double start, double end) {
	fp = fopen("DS_Large.txt", "r");
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
void PrintALL_SL(node* head, node* tail, double start, double end) {
	node* cu = (head)->next;
	start = (double)clock() / CLOCKS_PER_SEC;
	while (cu != NULL) {
		cnt++;
		if (cnt % 1000 == 0) {
			printf("%d - %12s\t\t%12s\t\t%d\t\t%d\t\t%d\n", cnt,cu->position, cu->name, cu->hp, cu->ak, cu->ad);
		}
		cu = cu->next;
	}
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("PrintALL_SL() 함수 실행시간 = %1f\n", (end - start));
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
	if ((*newHead) == NULL){
		(*newHead) = pivot;
	}
	(*newTail) = localTail;
	return pivot;
}
node* getTail(node* now){
	while (now != NULL && now->next != NULL) {
		now = now->next;
	}
	return now;
}
node* QuickSort(node* head, node* tail){
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
void FindTarget_SL(node* head,node* tail,double start,double end) {
	node* cu = head;
	start = (double)clock() / CLOCKS_PER_SEC;
	while (cu->next != NULL) {
		if (strcmp(cu->name,nam)==0) {
			printf("%s %s %d %d %d\n", cu->position, cu->name, cu->hp, cu->ak, cu->ad);
		}
		cu = cu->next;
	}
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("SortByName_SL() 함수 실행시간 = %1f\n", (end - start));
}
int main() {
	int ment;
	int p = 0;
	node* head = NULL;
	node* tail = NULL;
	double start, end;
	makefirst(&head, &tail);
	while (1) {
		ment = 0;
		start = 0; end = 0; cnt = 0;
		printf("1. MAKE_SL() 2.PrintALL_SL() 3.SortByName_SL() 4.FindTarget_SL()\n");
		printf("명령어를 입력해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			MAKE_SL(&head, &tail, start, end);
			break;
		case 2:
			PrintALL_SL(head, tail, start, end);
			break;
		case 3:
			SortByName_SL(&head, &tail, start, end);
			break;
		case 4:
			while (1) {
				printf("찾을 유닛의 이름을 입력해주세요 - ");
				scanf("%s",&nam);
				break;
			}
			FindTarget_SL(head, tail, start, end);
			break;
		default:
			printf("잘못된 명령어입니다.\n");
			break;
		}
	}
}