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
//선형 단방향 연결리스트
void makefirst(node** head, node** tail) {
	if ((*head) == NULL) {
		(*head) = (*tail) = (node*)malloc(sizeof(node)); //첫 노드 할당 - 빈 노드로 사용할 예정
	}
}
void makeSL(node** head, node** tail) {
	node* cu = (*head);
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		(*tail)->next = (node*)malloc(sizeof(node));
		fscanf(fp, "%d %s\n", &(*tail)->next->numbe, &(*tail)->next->name);
		(*tail) = (*tail)->next; //연결
	}
	(*tail)->next = NULL; //다 연결하고 마무리 작업
}
void search(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) {
		if (strcmp(cu->name, nam) == 0) { //조건이 맞는 경우 출력
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
	(*tail)->next = cu; //꼬리에 연결
	(*tail) = cu; //꼬리 재정의
	(*tail)->next = NULL;
}
void del(node** head, node** tail) {
	node* cur = (*head)->next;
	node* cu = (*head)->next;
	if (strcmp(cur->name, nam) == 0) { //머리 노드를 지워야하는 경우
		(*head)->next = cur->next; //머리 재정의
		free(cur);
		cur = (*head)->next; //cur 재정의
	}
	while (cur->next != NULL) {
		if (strcmp(cur->name, nam) == 0) {
			node* del = cur->next;
			if (cur->next == (*tail)) { //꼬리 노드를 지워야하는 경우
				(*tail) = cur; //꼬리 정의
				(*tail)->next = NULL;
			}
			else {
				cur->next = cur->next->next; //몸통 노드를 지워야하는 경우
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
	(*head)->next = QuickSort((*head)->next, (*tail)); //값이 있는 첫 노드부터 정리 시작
}
void print(node* head, node* tail) {
	node* cu = head->next;
	while (cu != NULL) { //잘 연결되어있나 확인
		printf("%d\t%s\n", cu->numbe, cu->name);
		cu = cu->next;
	}
}
//선형 양방향 연결리스트
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
//환형 단방향 연결리스트
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
node* realTail(node* ta) {
	//새로운 tail 노드 찾기
	while (ta->next != NULL) {
		ta = ta->next;
	}
	return ta;
}
void sort(node** head, node** tail) {
	(*head)->next = QuickSort((*head)->next, (*tail)); //head 노드는 비워뒀었기 때문에 head->next부터 tail까지 노드를 바꿔준다.
	(*tail) = realTail((*head)->next); //꼬리값 재정의 필요
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
//이진 탐색 트리(이름 기준으로 연결)
void maketree(kode** head) {
	//루트 노드를 만드는 작업
	if ((*head) == NULL) {
		(*head) = (kode*)malloc(sizeof(kode));
	}
}
void maketr(kode** head) {
	fp = fopen("akakak.txt", "r");
	while (!feof(fp)) {
		if (x == 0) {
			//루트 노드에 값을 넣고 시작하기 위해서 조건문을 사용
			fscanf(fp, "%d %s\n", &(*head)->numbe, &(*head)->name);
			(*head)->lchild = (*head)->rchild = NULL;
			x++;
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
	x = 0;
	fclose(fp);
}
void search(kode* node) {
	while (node != NULL) {
		if (strcmp(nam, node->name) == 0) { //원하는 노드 찾으면 출력
			printf("%d\t%12s\n", node->numbe, node->name);
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
//메인 함수
int main() {
	//연결리스트
	node* head = NULL;
	node* tail = NULL;
	makefirst(&head, &tail);
	//트리
	kode* root = NULL;
	maketree(&root);
	int ment = 0;
	while (1) {
		x = 0, cnt = 0, ment = 0;
		//명령어랑 함수 적어주면 끝
		//ment로 switch문 처리해주면 될 듯
		//주의할 점
		//선형 양방향 연결리스트일 경우 sort 해주고 rebuld를 해줘야함
		//선형 양방향 연결리스트랑 환형 단방향 연결리스트일 경우 sort해주고 realTail로 꼬리 재정의
	}
}