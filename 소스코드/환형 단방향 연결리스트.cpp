#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNNING_
typedef struct node {
	int numbe = 0;
	char name[12] = "           ";
	struct node* next;
	struct node* prev;
	node* head;
	node* tail;
}node;
FILE* fp;
int x = 0;
int c_hp = 0;
char nam[12] = "";
int cnt = 0;
void makefirst(node** head, node** tail) {
	if ((*head) == NULL) {
		(*head) = (*tail) = (node*)malloc(sizeof(node));
	}
}
void makeSL(node** head, node** tail) {
	node* cu = (*head);
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s\n", &(*tail)->next->numbe, &(*tail)->next->name);
		(*tail) = (*tail)->next;
	}
	(*tail)->next = (*head); //다 할당해주고 머리와 꼬리 연결
}
void search(node* head, node* tail) {
	node* cu = head->next;
	node* cur = head;
	do {
		if (strcmp(cu->name, nam) == 0) { //조건에 맞으면 출력
			printf("%d\t%s\n", cu->numbe, cu->name);
		}
		cu = cu->next;
	} while (cu != cur);
}
void insert(node** head, node** tail) {
	node* cu = (node*)malloc(sizeof(node));
	printf("새로운 노드의 number 값과 name 값을 입력해주세요 - ");
	scanf("%d %s", &cu->numbe, &cu->name);
	(*tail)->next = cu;
	(*tail) = cu; //꼬리 재정의
	(*tail)->next = (*head); //머리와 연결
}
void del(node** head, node** tail) {
	node* cur = (*head);
	node* cu = (*head);
	if (strcmp(cur->name, nam) == 0) { //머리 값을 지워야하는 경우
		(*tail)->next = cur->next;
		free(cur);
		(*head) = (*tail)->next;
		cur = (*head);
	}
	do {
		if (strcmp(cur->next->name, nam) == 0) {
			node* del = cur->next;
			if (cur->next == (*tail)) { //지워야하는 노드가 꼬리일 경우
				cur->next = cur->next->next; //전 노드와 머리 연결
				(*tail) = cur; //꼬리 재정의
			}
			else {
				cur->next = cur->next->next; //꼬리가 아닐 경우 그냥 연결
			}
			free(del); //방생
		}
		cur = cur->next;
	} while (cur != cu); //다시 머리로 오기 전까지
}
node* Partition_SL(node* head, node* tail, node** newHead, node** newTail) {
	node* pivot = tail;
	node* prev = NULL;
	node* now = head;
	node* localTail = pivot;
	while (now != pivot) {
		if (strcmp(now->name, pivot->name) < 0) { //pivot보다 작으면 다음 노드로 이동
			if ((*newHead) == NULL) {
				(*newHead) = now;
			}
			prev = now;
			now = now->next;
		}
		else { //pivot이 더 클 경우
			if (prev != NULL) {
				prev->next = now->next; //이동할 노드의 전 노드와 다음 노드 연결
			}
			node* temp = now->next;
			now->next = NULL; //null로 바꿔주기
			localTail->next = now; //맨뒤에 연결
			localTail = now; //맨뒤 재정의
			now = temp; //이어서 진행
		}
	}
	if ((*newHead) == NULL) {
		(*newHead) = pivot;
	}
	(*newTail) = localTail;
	return pivot;
}
node* getTail(node* now) { //꼬리 찾기
	while (now != NULL && now->next != NULL) {
		now = now->next;
	}
	return now;
}
node* QuickSort(node* head, node* tail) {
	if (!head || head == tail) { //노드의 개수가 1개만 남았을 경우
		return head;
	}
	node* newHead = NULL;
	node* newTail = NULL;
	node* pivot = Partition_SL(head, tail, &newHead, &newTail); //정리하는 함수
	if (newHead != pivot) {
		node* temp = newHead;
		while (temp->next != pivot) { //정리된 후 pivot 전 노드 찾기
			temp = temp->next;
		}
		temp->next = NULL; //잠시 분리
		newHead = QuickSort(newHead, temp); //머리부터 pivot 전 노드까지 정리 시작
		temp = getTail(newHead); //꼬리 재정의
		temp->next = pivot; //다시 연결
	}
	pivot->next = QuickSort(pivot->next, newTail); //pivot 다음 노드부터 꼬리까지 정리 시작
	return newHead;
}
void sort(node** head, node** tail) {
	(*head)->next = QuickSort((*head)->next, (*tail)); //head 노드는 비워뒀었기 때문에 head->next부터 tail까지 노드를 바꿔준다.
	(*tail) = getTail((*head)->next); //꼬리값 재정의 필요
	(*tail)->next = (*head); //꼬리랑 머리 연결
}
void print(node* head, node* tail) {
	node* cu = head->next;
	node* cur = head;
	do {
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->next;
	} while (cu != cur); //값이 있는 첫 노드부터 머리까지 돌면서 출력
}
int main() {
	node* head = NULL;
	node* tail = NULL;
	int ment = 0;
	makefirst(&head, &tail);
	while (1) {
		printf("1.만들기 2.검색 3.삽입 4.삭제 5.정렬 6.출력\n");
		ment = 0;
		printf("실행할 명령을 선택하세요 - ");
		scanf("%d", &ment);
		switch (ment) {
		case 1:
			makeSL(&head, &tail);
			break;
		case 2:
			while (1) {
				printf("찾을 노드의 이름을 입력해주세요 - ");
				scanf(" %s", &nam);
				break;
			}
			search(head, tail);
			break;
		case 3:
			insert(&head, &tail);
			break;
		case 4:
			while (1) {
				printf("삭제할 노드의 이름을 입력해주세요 - ");
				scanf(" %s", &nam);
				break;
			}
			del(&head, &tail);
			break;
		case 5:
			sort(&head, &tail);
			break;
		case 6:
			print(head, tail);
			break;
		}
	}
}