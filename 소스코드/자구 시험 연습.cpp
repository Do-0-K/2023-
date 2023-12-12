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
typedef struct kode {
	int numbe = 0;
	char name[12] = "           ";
	kode* tree;
	struct kode* lchild;
	struct kode* rchild;
}kode;
kode* cu;
FILE* fp;
int x = 0;
char nam[12] = "";
int cnt = 0;
//���� �ܹ��� ���Ḯ��Ʈ
void makefirst(node** head, node** tail) {
	if ((*head) == NULL) {
		(*head) = (*tail) = (node*)malloc(sizeof(node)); //ù ��� �Ҵ� - �� ���� ����� ����
	}
}
void makeSL(node** head, node** tail) {
	node* cu = (*head);
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s\n", &(*tail)->next->numbe, &(*tail)->next->name);
		(*tail) = (*tail)->next; //����
	}
	(*tail)->next = NULL; //�� �����ϰ� ������ �۾�
}
void search(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) {
		if (strcmp(cu->name, nam) == 0) { //������ �´� ��� ���
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
	(*tail)->next = cu; //������ ����
	(*tail) = cu; //���� ������
	(*tail)->next = NULL;
}
void del(node** head, node** tail) {
	node* cur = (*head)->next;
	node* cu = (*head)->next;
	if (strcmp(cur->name, nam) == 0) { //�Ӹ� ��带 �������ϴ� ���
		(*head)->next = cur->next; //�Ӹ� ������
		free(cur);
		cur = (*head)->next; //cur ������
	}
	while (cur->next != NULL) {
		if (strcmp(cur->name, nam) == 0) {
			node* del = cur->next;
			if (cur->next == (*tail)) { //���� ��带 �������ϴ� ���
				(*tail) = cur; //���� ����
				(*tail)->next = NULL;
			}
			else {
				cur->next = cur->next->next; //���� ��带 �������ϴ� ���
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
	(*head)->next = QuickSort((*head)->next, (*tail)); //���� �ִ� ù ������ ���� ����
}
void print(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) { //�� ����Ǿ��ֳ� Ȯ��
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->next;
	}
}
//���� ����� ���Ḯ��Ʈ
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
//ȯ�� �ܹ��� ���Ḯ��Ʈ
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
node* realTail(node* ta) {
	//���ο� tail ��� ã��
	while (ta->next != NULL) {
		ta = ta->next;
	}
	return ta;
}
void sort(node** head, node** tail) {
	(*head)->next = QuickSort((*head)->next, (*tail)); //head ���� ����׾��� ������ head->next���� tail���� ��带 �ٲ��ش�.
	(*tail) = realTail((*head)->next); //������ ������ �ʿ�
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
//���� Ž�� Ʈ��(�̸� �������� ����)
void maketree(kode** head) {
	//��Ʈ ��带 ����� �۾�
	if ((*head) == NULL) {
		(*head) = (kode*)malloc(sizeof(kode));
	}
}
void maketr(kode** head) {
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		if (x == 0) {
			//��Ʈ ��忡 ���� �ְ� �����ϱ� ���ؼ� ���ǹ��� ���
			fscanf(fp, "%d %s\n", &(*head)->numbe, &(*head)->name);
			(*head)->lchild = (*head)->rchild = NULL;
			x++;
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
	x = 0;
	fclose(fp);
}
void search(kode* node) {
	while (node != NULL) {
		if (strcmp(nam, node->name) == 0) { //���ϴ� ��� ã���� ���
			printf("%d\t%12s\n", node->numbe, node->name);
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
//���� �Լ�
int main() {
	//���Ḯ��Ʈ
	node* head = NULL;
	node* tail = NULL;
	makefirst(&head, &tail);
	//Ʈ��
	kode* root = NULL;
	maketree(&root);
	int ment = 0;
	while (1) {
		x = 0, cnt = 0, ment = 0;
		//��ɾ�� �Լ� �����ָ� ��
		//ment�� switch�� ó�����ָ� �� ��
		//������ ��
		//���� ����� ���Ḯ��Ʈ�� ��� sort ���ְ� rebuld�� �������
		//���� ����� ���Ḯ��Ʈ�� ȯ�� �ܹ��� ���Ḯ��Ʈ�� ��� sort���ְ� realTail�� ���� ������
	}
}