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
		(*head) = (*tail) = (node*)malloc(sizeof(node)); //첫 노드 할당
	}
}
void makeSL(node** head, node** tail) {
	node* cu = (*head);
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s\n", &(*tail)->next->numbe, &(*tail)->next->name);
		(*tail)->next->prev = (*tail); //거꾸로 연결
		(*tail) = (*tail)->next; //꼬리 정의
	}
	(*tail)->next = NULL; //다 연결한 뒤 꼬리 끝처리
}
void search(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) {
		if (strcmp(cu->name, nam) == 0) { //조건에 맞으면 출력
			printf("%d\t%s\n", cu->numbe, cu->name);
			return;
		}
		cu = cu->next;
	}
}
void insert(node** head, node** tail) {
	node* cu = (node*)malloc(sizeof(node));
	printf("새로운 노드의 number 값과 name 값을 입력해주세요 - ");
	scanf("%d %s", &cu->numbe, &cu->name);
	//환형
	(*tail)->next = cu; //꼬리 뒤에 연결
	cu->prev = (*tail); //거꾸로 연결
	(*tail) = cu; //꼬리 정의
	(*tail)->next = NULL; //꼬리 뒤에 NULL 연결
}
void del(node** head, node** tail) {
	node* cur = (*head)->next;
	node* cu = (*head)->next;
	if (strcmp(cur->name, nam) == 0) { //머리를 삭제해야 할 경우
		(*head)->next = cur->next; //머리 재정의
		cur->next->prev = (*head); //거꾸로도 연결
		free(cur);
		cur = (*head)->next;
	}
	while (cur->next != NULL) {
		if (strcmp(cur->name, nam) == 0) {
			node* del = cur->next;
			if (cur->next == (*tail)) { //꼬리를 삭제해야 할 경우
				(*tail) = cur; //꼬리 재정의
				(*tail)->next = NULL; //꼬리와 NULL 연결
			}
			else {
				cur->next = cur->next->next; //몸통을 삭제해야 할 경우
			}
			free(del); //방생
		}
		cur = cur->next;
	}
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
			now->prev = localTail; //거꾸로도 연결
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
node* getTail(node* now) {
	while (now != NULL && now->next != NULL) { //꼬리 찾기
		now = now->next;
	}
	return now;
}
node* QuickSort(node* head, node* tail) {
	if (!head || head == tail) { //노드 개수가 1개 남았을 경우
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
		pivot->prev = temp; //거꾸로도 연결
	}
	pivot->next = QuickSort(pivot->next, newTail); //pivot 다음 노드부터 꼬리까지 정리 시작
	return newHead;
}
void rebuld(node** head, node** tail) {
	node* cu = (*head)->next->next;
	node* cur = (*head)->next;
	while (cu != NULL) { //단순히 꼬리에서 머리까지 prev 연결 작업
		cu->prev = cur;
		cu = cu->next;
		cur = cur->next;
	}
	(*tail)->next = NULL;
}
node* realTail(node* ta) {
	while (ta->next != NULL) { //진짜 꼬리 찾기
		ta = ta->next;
	}
	return ta;
}
void sort(node** head, node** tail) {
	(*head)->next = QuickSort((*head)->next, (*tail)); //첫 노드부터 정리 시작
	(*head)->next->prev = (*head); //거꾸로 연결
	(*tail) = realTail((*head)->next); //정리가 끝나고 꼬리 찾기
	(*tail)->next = NULL; //꼬리에 NULL 값 연결
}
void print(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) { //머리부터 꼬리까지 연결 확인
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->next;
	}
}
void re_print(node* head, node* tail) {
	node* cu = tail;
	while (cu != head) { //꼬리부터 머리까지 잘 연결이 되어있나 확인
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->prev;
	}
}
int main() {
	node* head = NULL;
	node* tail = NULL;
	int ment = 0;
	makefirst(&head, &tail);
	while (1) {
		printf("1.만들기 2.검색 3.삽입 4.삭제 5.정렬 6.출력 7.역출력\n");
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
			rebuld(&head, &tail);
			break;
		case 6:
			print(head, tail);
			break;
		case 7:
			re_print(head, tail);
			break;
		}
	}
}