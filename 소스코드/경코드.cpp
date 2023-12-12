#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct NODE {
	string position;
	string name;
	int HP;
	int AK;
	int DF;
	NODE* next;
};

void Make_SL(NODE*);
void PrintAll_SL(NODE*);
void FindTarget_SL(NODE*);
void SortByName_SL(NODE*);
void QuickSort(NODE*, NODE*, NODE*);

int main() {
	int command;
	NODE* head = new NODE;
	head->next = NULL;
	while (1) {
		cout << "1. Make_SL, 2. PrintAll_SL, 3. SortByName, 4. FindTarget_SL: ";
		cin >> command;
		switch (command) {
		case 1:
			Make_SL(head);
			break;
		case 2:
			PrintAll_SL(head);
			break;
		case 3:
			SortByName_SL(head);
			break;
		case 4:
			FindTarget_SL(head);
			break;
		default:
			cout << "종료" << endl;
			exit(1);
		}
	}
}

void Make_SL(NODE* head) {
	ifstream fin;
	clock_t start_time = clock();
	fin.open("DS_Large.txt");
	NODE* p = new NODE;
	int i = 0;
	while (i != 20000000) {
		NODE* node = new NODE;
		fin >> node->position >> node->name >> node->HP >> node->AK >> node->DF;
		if (head->next == NULL) {
			node->next = NULL;
			head->next = node;
			p = node;
		}
		else {
			node->next = NULL;
			p->next = node;
			p = p->next;
		}
		i++;
	}
	fin.close();
	clock_t curr_time = clock() - start_time;
	double time_double = (double)curr_time / 1000;
	printf("수행 시간: %.3lf\n", time_double);
	p = NULL;
	delete p;
	cout << "생성 완료" << endl;
}

void PrintAll_SL(NODE* head) {
	int i = 0;
	clock_t start_time = clock();
	NODE* p = new NODE;
	p = head;
	do {
		p = p->next;
		i++;
		if (i == 1000) {
			cout << p->position << " " << p->name << " " << p->HP << " " << p->AK << " " << p->DF << endl;
			i = 0;
		}
	} while (p != NULL);
	clock_t current_time = clock() - start_time;
	double time_double = (double)current_time / 1000;
	printf("수행 시간: %.3lf\n", time_double);
	p = NULL;
	delete p;
}

void FindTarget_SL(NODE* head) {
	string f_name = "";
	bool exist = false;
	cout << "찾을 이름 입력: ";
	cin >> f_name;
	NODE* p = new NODE;
	clock_t start_time = clock();
	p = head;
	do {
		p = p->next;
		if (p != NULL) {
			if (p->name == f_name) {
				cout << p->position << " " << p->name << " " << p->HP << " " << p->AK << " " << p->DF << endl;
				exist = true;
				break;
			}
		}
	} while (p != NULL);
	if (exist == false) {
		cout << "이름이 없음" << endl;
	}
	clock_t curr_time = clock() - start_time;
	double dou_time = (double)curr_time / 1000;
	printf("수행 시간: %.3lf\n", dou_time);
}

void SortByName_SL(NODE* head) {
	clock_t start_time = clock();
	NODE* low = new NODE; NODE* high = new NODE;
	low = head->next;
	for (high = head->next; high->next != NULL; high = high->next);
	QuickSort(head, low, high);
	low = high = NULL;
	delete low, high;
	clock_t cur_time = clock() - start_time;
	double dou_time = (double)cur_time / 1000;
	printf("수행 시간: %.3lf\n", dou_time);
	cout << "정렬 완료" << endl;
}

void QuickSort(NODE* head, NODE* low, NODE* high) {
	NODE* left = new NODE; NODE* right = new NODE; NODE* pivot = new NODE;
	NODE* p_low = new NODE;
	left = right = low; pivot = high;
	do {
		while (left->name < pivot->name && left != pivot) {
			if (left == right) {
				left = left->next;
				right = right->next;
			}
			else {
				left = left->next;
			}
		}
		while (right->name > pivot->name && right != pivot) {
			right = right->next;
		}
		if (head->next == left && left->next == right) {
			left->next = right->next;
			right->next = left;
			head->next = right;
			right = left;
			left = head->next;
			low = left;
			if (high == left) {
				high = right;
			}
		}
		else if (head->next == left) {
			NODE* p = new NODE; NODE* p1 = new NODE;
			p = left->next;
			for (p1 = head; p1->next != right; p1 = p1->next);
			left->next = right->next;
			p1->next = left;
			right->next = p;
			head->next = right;
			right = left;
			left = head->next;
			low = left;
			if (high == left) {
				high = right;
			}
			p = p1 = NULL;
			delete p, p1;
		}
		else if (left->next == right) {
			NODE* p = new NODE;
			for (p = head; p->next != left; p = p->next);
			left->next = right->next;
			right->next = left;
			p->next = right;
			right = left;
			left = p->next;
			if (high == left) {
				high = right;
			}
			p = NULL;
			delete p;
		}
		else {
			NODE* p = new NODE; NODE* p1 = new NODE; NODE* p2 = new NODE;
			for (p = head; p->next != left; p = p->next);
			for (p1 = head; p1->next != right; p1 = p1->next);
			p2 = left->next;
			left->next = right->next;
			p1->next = left;
			right->next = p2;
			p->next = right;
			right = left;
			left = p->next;
			if (high == left) {
				high = right;
			}
			p = p1 = p2 = NULL;
			delete p, p1, p2;
		}
	} while (left != pivot);
	NODE* p = new NODE;

	p = high;
	low = head->next;
	for (high = head; high->next != pivot; high = high->next);
	if (low != high && high->next != low) {
		QuickSort(head, low, high);
	}
	low = pivot->next; for (high = head; high->next != p->next; high = high->next);
	if (low != high && high->next != low) {
		QuickSort(head, low, high);
	}

	left = right = pivot = p = p_low = NULL;
	delete left, right, pivot, p, p_low;
}