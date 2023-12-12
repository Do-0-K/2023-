#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct node {
	int numbe = 0;
	char name[12] = "           ";
	struct node* next;
	struct node* prev;
	node* head;
	node* tail;
}node;
node* partition(node* head, node* tail, node** newhead, node** newtail) {
	node* now = head;
	node* prev = NULL;
	node* pivot = tail;
	node* localtail = pivot;
	while (now != pivot) {
		if (strcmp(now->name, pivot->name) < 0) {
			if ((*newhead) == NULL) {
				(*newhead) = now;
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
			localtail->next = now;
			localtail = now;
			now = temp;
		}
	}
	if ((*newhead) == NULL) {
		(*newhead) = pivot;
	}
	(*newtail) = pivot;
	return pivot;
}
node* gettail(node* now) {
	while (now != NULL && now->next != NULL) {
		now = now->next;
	}
	return now;
}
node* Quick(node* head, node* tail) {
	if (!head || head == tail) {
		return head;
	}
	node* newhead = NULL;
	node* newtail = NULL;
	node* pivot = partition(head, tail, &newhead, &newtail);
	while (newhead != pivot) {
		node* temp = newhead;
		while (temp->next != pivot) {
			temp = temp->next;
		}
		temp->next = NULL;
		newhead = Quick(newhead, temp);
		temp = gettail(newhead);
		temp->next = pivot;
	}
	pivot->next = Quick(pivot->next, newtail);
	return newhead;
}
void sort(node** head, node** tail) {
	(*head)->next = Quick((*head)->next, (*tail));
}