#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	int sosok = 0;
	int age = 0;
	int score = 0;
	char name[10] = "        ";
	char ID[10] = "        ";
	struct node* next;
	struct node* daum;
	node* head;
	node* tail;
}node;
FILE* fp;
node* fe;
//6,8번
void makefn(node** head,node** tail) {
	if ((*head) == NULL) {
		(*head) = (*tail) = (node*)malloc(sizeof(node));
	}
}
void makelist(node** head, node** tail) {
	fp = fopen("midTerm.txt", "r");
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%10s\t%d\t%10s\t%d\t%d\n", &(*tail)->next->name, &(*tail)->next->age, &(*tail)->next->ID, &(*tail)->next->sosok, &(*tail)->next->score);
		(*tail) = (*tail)->next;
	}
	(*tail)->next = (*head);
}
void insert(node** head, node** tail) {
	node* cu = (*head)->next;
	node* cur = (*head);
	while (cu != cur) {
		if (strcmp(cu->ID, fe->ID) == 0) {
			return;
		}
		cu = cu->next;
	}
	(*tail)->next = (node*)malloc(sizeof(node));
	sprintf((*tail)->next->name, fe->name);
	sprintf((*tail)->next->ID, fe->ID);
	(*tail)->next->age = fe->age;
	(*tail)->next->sosok = fe->sosok;
	(*tail)->next->score = fe->score;
	(*tail) = (*tail)->next;
	(*tail)->next = (*head);
}
node* Partition_ID(node* head, node* tail, node** newHead, node** newTail) {
	node* pivot = tail;
	node* prev = NULL;
	node* now = head;
	node* localTail = pivot;
	while (now != pivot) {
		if (strcmp(now->ID, pivot->ID) < 0) {
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
node* gettail_ID(node* now) {
	while (now != NULL && now->next != NULL) {
		now = now->next;
	}
	return now;
}
node* Quick_ID(node* head, node* tail) {
	if (!head || head == tail) {
		return head;
	}
	node* newHead = NULL;
	node* newTail = NULL;
	node* pivot = Partition_ID(head, tail, &newHead, &newTail);
	if (newHead != pivot) {
		node* temp = newHead;
		while (temp->next != pivot) {
			temp = temp->next;
		}
		temp->next = NULL;
		newHead = Quick_ID(newHead, temp);
		temp = gettail_ID(newHead);
		temp->next = pivot;
	}
	pivot->next = Quick_ID(pivot->next, newTail);
	return newHead;
}
void sort_ID(node** head, node** tail) {
	(*head)->next = Quick_ID((*head)->next, (*tail));
	(*tail) = gettail_ID((*head)->next);
	(*tail)->next = (*head);
}
node* partition_age(node* head, node* tail, node** newhead, node** newtail) {
	node* now = head;
	node* prev = NULL;
	node* pivot = tail;
	node* localtail = pivot;
	while (now != pivot) {
		if (now->age < pivot->age) {
			if ((*newhead) == NULL) {
				(*newhead) = now;
			}
			prev = now;
			now = now->daum;
		}
		else {
			if (prev != NULL) {
				prev->daum = now->daum;
			}
			node* temp = now->daum;
			now->daum = NULL;
			localtail->daum = now;
			localtail = now;
			now = temp;
		}
	}
	if ((*newhead) == NULL) {
		(*newhead) = pivot;
	}
	(*newtail) = localtail;
	return pivot;
}
node* gettail_age(node* now) {
	while (now != NULL && now->daum != NULL) {
		now = now->daum;
	}
	return now;
}
node* Quick_age(node* head, node* tail) {
	if (!head || head == tail) {
		return head;
	}
	node* newHead = NULL;
	node* newTail = NULL;
	node* pivot = partition_age(head, tail, &newHead, &newTail);
	if (newHead != pivot) {
		node* temp = newHead;
		while (temp->daum != pivot) {
			temp = temp->daum;
		}
		temp->daum = NULL;
		newHead = Quick_age(newHead, temp);
		temp = gettail_age(newHead);
		temp->daum = pivot;
	}
	pivot->daum = Quick_age(pivot->daum, newTail);
	return newHead;
}
void sort_age(node** head, node** tail) {
	(*head)->daum = Quick_age((*head)->daum, (*tail));
	(*tail) = gettail_age((*head)->daum);
	(*tail)->daum = (*head);
}
void daumd(node** head, node** tail) {
	node* cu = (*head);
	node* cur = (*head)->next;
	while (cur != (*head)) {
		cu->daum = cur;
		cu = cu->next;
		cur = cur->next;
	}
	(*tail)->daum = (*head);
}
void print_ID(node* head, node* tail) {
	node* cu = head->next;
	node* cur = head;
	do {
		printf("%10s\t%d\t%10s\t%d\t%d\n",  cu->ID,cu->age, cu->name, cu->sosok, cu->score);
		cu = cu->next;
	} while (cu != cur);
}
void print_age(node* head, node* tail) {
	node* cu = head->daum;
	node* cur = head;
	do {
		printf("%10s\t%d\t%10s\t%d\t%d\n", cu->name, cu->age, cu->ID, cu->sosok, cu->score);
		cu = cu->daum;
	} while (cu != cur);
}
int main() {
	node* head = NULL;
	node* tail = NULL;
	makefn(&head, &tail);
	int ment = 0;
	printf("문제 6,8번\n");
	while (1) {
		ment = 0;
		printf("1.연결리스트 생성 2.삽입 3.ID 순 정렬 4.나이 순 정렬\n");
		printf("원하시는 명령을 선택해주세요 - ");
		scanf_s("%d", &ment);
		switch (ment) {
		case 1:
			makelist(&head, &tail);
			break;
		case 2:
			while (1) {
				fe = (node*)malloc(sizeof(node));
				printf("새로운 노드의 age 값을 입력해주세요 - ");
				scanf_s("%d", &fe->age);
				printf("새로운 노드의 name 값을 입력해주세요 - ");
				scanf("%s", &fe->name);
				printf("새로운 노드의 ID 값을 입력해주세요 - ");
				scanf("%s", &fe->ID);
				printf("새로운 노드의 sosok 값을 입력해주세요 - ");
				scanf_s("%d", &fe->sosok);
				printf("새로운 노드의 score 값을 입력해주세요 - ");
				scanf_s("%d", &fe->score);
				break;
			}
			insert(&head,&tail);
			break;
		case 3:
			sort_ID(&head, &tail);
			print_ID(head, tail);
			break;
		case 4:
			daumd(&head, &tail);
			sort_age(&head, &tail);
			print_age(head, tail);
			break;
		}
	}
}