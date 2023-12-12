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
		(*head) = (*tail) = (node*)malloc(sizeof(node)); //ù ��� �Ҵ�
	}
}
void makeSL(node** head, node** tail) {
	node* cu = (*head);
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s\n", &(*tail)->next->numbe, &(*tail)->next->name);
		(*tail)->next->prev = (*tail); //�Ųٷ� ����
		(*tail) = (*tail)->next; //���� ����
	}
	(*tail)->next = NULL; //�� ������ �� ���� ��ó��
}
void search(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) {
		if (strcmp(cu->name, nam) == 0) { //���ǿ� ������ ���
			printf("%d\t%s\n", cu->numbe, cu->name);
			return;
		}
		cu = cu->next;
	}
}
void insert(node** head, node** tail) {
	node* cu = (node*)malloc(sizeof(node));
	printf("���ο� ����� number ���� name ���� �Է����ּ��� - ");
	scanf("%d %s", &cu->numbe, &cu->name);
	//ȯ��
	(*tail)->next = cu; //���� �ڿ� ����
	cu->prev = (*tail); //�Ųٷ� ����
	(*tail) = cu; //���� ����
	(*tail)->next = NULL; //���� �ڿ� NULL ����
}
void del(node** head, node** tail) {
	node* cur = (*head)->next;
	node* cu = (*head)->next;
	if (strcmp(cur->name, nam) == 0) { //�Ӹ��� �����ؾ� �� ���
		(*head)->next = cur->next; //�Ӹ� ������
		cur->next->prev = (*head); //�Ųٷε� ����
		free(cur);
		cur = (*head)->next;
	}
	while (cur->next != NULL) {
		if (strcmp(cur->name, nam) == 0) {
			node* del = cur->next;
			if (cur->next == (*tail)) { //������ �����ؾ� �� ���
				(*tail) = cur; //���� ������
				(*tail)->next = NULL; //������ NULL ����
			}
			else {
				cur->next = cur->next->next; //������ �����ؾ� �� ���
			}
			free(del); //���
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
			now->prev = localTail; //�Ųٷε� ����
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
node* getTail(node* now) {
	while (now != NULL && now->next != NULL) { //���� ã��
		now = now->next;
	}
	return now;
}
node* QuickSort(node* head, node* tail) {
	if (!head || head == tail) { //��� ������ 1�� ������ ���
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
		pivot->prev = temp; //�Ųٷε� ����
	}
	pivot->next = QuickSort(pivot->next, newTail); //pivot ���� ������ �������� ���� ����
	return newHead;
}
void rebuld(node** head, node** tail) {
	node* cu = (*head)->next->next;
	node* cur = (*head)->next;
	while (cu != NULL) { //�ܼ��� �������� �Ӹ����� prev ���� �۾�
		cu->prev = cur;
		cu = cu->next;
		cur = cur->next;
	}
	(*tail)->next = NULL;
}
node* realTail(node* ta) {
	while (ta->next != NULL) { //��¥ ���� ã��
		ta = ta->next;
	}
	return ta;
}
void sort(node** head, node** tail) {
	(*head)->next = QuickSort((*head)->next, (*tail)); //ù ������ ���� ����
	(*head)->next->prev = (*head); //�Ųٷ� ����
	(*tail) = realTail((*head)->next); //������ ������ ���� ã��
	(*tail)->next = NULL; //������ NULL �� ����
}
void print(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) { //�Ӹ����� �������� ���� Ȯ��
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->next;
	}
}
void re_print(node* head, node* tail) {
	node* cu = tail;
	while (cu != head) { //�������� �Ӹ����� �� ������ �Ǿ��ֳ� Ȯ��
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
		printf("1.����� 2.�˻� 3.���� 4.���� 5.���� 6.��� 7.�����\n");
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