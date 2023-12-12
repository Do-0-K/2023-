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
	(*tail)->next = (*head); //�� �Ҵ����ְ� �Ӹ��� ���� ����
}
void search(node* head, node* tail) {
	node* cu = head->next;
	node* cur = head;
	do {
		if (strcmp(cu->name, nam) == 0) { //���ǿ� ������ ���
			printf("%d\t%s\n", cu->numbe, cu->name);
		}
		cu = cu->next;
	} while (cu != cur);
}
void insert(node** head, node** tail) {
	node* cu = (node*)malloc(sizeof(node));
	printf("���ο� ����� number ���� name ���� �Է����ּ��� - ");
	scanf("%d %s", &cu->numbe, &cu->name);
	(*tail)->next = cu;
	(*tail) = cu; //���� ������
	(*tail)->next = (*head); //�Ӹ��� ����
}
void del(node** head, node** tail) {
	node* cur = (*head);
	node* cu = (*head);
	if (strcmp(cur->name, nam) == 0) { //�Ӹ� ���� �������ϴ� ���
		(*tail)->next = cur->next;
		free(cur);
		(*head) = (*tail)->next;
		cur = (*head);
	}
	do {
		if (strcmp(cur->next->name, nam) == 0) {
			node* del = cur->next;
			if (cur->next == (*tail)) { //�������ϴ� ��尡 ������ ���
				cur->next = cur->next->next; //�� ���� �Ӹ� ����
				(*tail) = cur; //���� ������
			}
			else {
				cur->next = cur->next->next; //������ �ƴ� ��� �׳� ����
			}
			free(del); //���
		}
		cur = cur->next;
	} while (cur != cu); //�ٽ� �Ӹ��� ���� ������
}
node* Partition_SL(node* head, node* tail, node** newHead, node** newTail) {
	node* pivot = tail;
	node* prev = NULL;
	node* now = head;
	node* localTail = pivot;
	while (now != pivot) {
		if (strcmp(now->name, pivot->name) < 0) { //pivot���� ������ ���� ���� �̵�
			if ((*newHead) == NULL) {
				(*newHead) = now;
			}
			prev = now;
			now = now->next;
		}
		else { //pivot�� �� Ŭ ���
			if (prev != NULL) {
				prev->next = now->next; //�̵��� ����� �� ���� ���� ��� ����
			}
			node* temp = now->next;
			now->next = NULL; //null�� �ٲ��ֱ�
			localTail->next = now; //�ǵڿ� ����
			localTail = now; //�ǵ� ������
			now = temp; //�̾ ����
		}
	}
	if ((*newHead) == NULL) {
		(*newHead) = pivot;
	}
	(*newTail) = localTail;
	return pivot;
}
node* getTail(node* now) { //���� ã��
	while (now != NULL && now->next != NULL) {
		now = now->next;
	}
	return now;
}
node* QuickSort(node* head, node* tail) {
	if (!head || head == tail) { //����� ������ 1���� ������ ���
		return head;
	}
	node* newHead = NULL;
	node* newTail = NULL;
	node* pivot = Partition_SL(head, tail, &newHead, &newTail); //�����ϴ� �Լ�
	if (newHead != pivot) {
		node* temp = newHead;
		while (temp->next != pivot) { //������ �� pivot �� ��� ã��
			temp = temp->next;
		}
		temp->next = NULL; //��� �и�
		newHead = QuickSort(newHead, temp); //�Ӹ����� pivot �� ������ ���� ����
		temp = getTail(newHead); //���� ������
		temp->next = pivot; //�ٽ� ����
	}
	pivot->next = QuickSort(pivot->next, newTail); //pivot ���� ������ �������� ���� ����
	return newHead;
}
void sort(node** head, node** tail) {
	(*head)->next = QuickSort((*head)->next, (*tail)); //head ���� ����׾��� ������ head->next���� tail���� ��带 �ٲ��ش�.
	(*tail) = getTail((*head)->next); //������ ������ �ʿ�
	(*tail)->next = (*head); //������ �Ӹ� ����
}
void print(node* head, node* tail) {
	node* cu = head->next;
	node* cur = head;
	do {
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->next;
	} while (cu != cur); //���� �ִ� ù ������ �Ӹ����� ���鼭 ���
}
int main() {
	node* head = NULL;
	node* tail = NULL;
	int ment = 0;
	makefirst(&head, &tail);
	while (1) {
		printf("1.����� 2.�˻� 3.���� 4.���� 5.���� 6.���\n");
		ment = 0;
		printf("������ ����� �����ϼ��� - ");
		scanf("%d", &ment);
		switch (ment) {
		case 1:
			makeSL(&head, &tail);
			break;
		case 2:
			while (1) {
				printf("ã�� ����� �̸��� �Է����ּ��� - ");
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
				printf("������ ����� �̸��� �Է����ּ��� - ");
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