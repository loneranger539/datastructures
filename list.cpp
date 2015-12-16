#include <stdio.h>
#include <stdlib.h>
int len = 5;
// A linked list node
typedef struct node
{
	int data;
	node *next;
}node;
void print(node *temp) {
	node *head = temp;
	while (head != NULL) {
		printf("%d ->", head->data);
		head = head->next;
	}
	printf("\n");
}

node * insert(node *head,int data) {
	node *temp = head;
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->next = NULL;
	printf("insert\n");
	if (temp == NULL) {
		printf("put head\n");
		head = t;
		return head;
	}
	while (temp->next != NULL) {
		temp = temp->next;

	}
	temp->next = t;
	return head;
}

void push(node **head, int data) {
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->next = *head ;
	*head = t;
}

void deletenode(node **head,int key) {
	node *temp = *head;
	node *prev = *head;
	if (temp->data == key) {
		*head = temp->next;
		delete temp;
		return;
	}
	while (temp != NULL) {
		if (temp->data == key) {
			prev->next = temp->next;
			delete temp;
			return;
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
}

void deletepos(node **head, int pos) {
	node *temp = *head;
	node *prev = NULL;
	if (pos == 0) {
		*head = temp->next;
		delete temp;
		return;
	}
	int count = 0;
	prev = temp;
	while (count < pos-1) {
		prev = prev->next;
		count++;
	}
	temp = prev->next;
	prev->next = temp->next;
	delete temp;
}


void swap(node **head, int x, int y) {
	node *temp = *head;
	node *t = temp,*n1=NULL,*n2=NULL,*p1=NULL,*p2=NULL;
	p1 = NULL;
	while (t != NULL) {
		if (t->data == x) {
			n1 = t;
			break;
		}
		else {
			p1 = t;
			t = t->next;
		}

	}

	t = temp; p2 = NULL;
	while (t != NULL) {
		if (t->data == y) {
			n2 = t;
			break;
		}
		else {
			p2 = t;
			t = t->next;
		}

	}
	if (n1 == NULL || n2 == NULL)
		return; 
	//printf("found %d %d \n",p1->data,p2->data);
	if (p1 != NULL) {
		p1->next = n2;
	} 	else {
		printf("p1 head");
		*head = n2;
	}
	if (p2 != NULL) {
		p2->next = n1;
	}
	else {
		printf("p2 head");
		*head = n1;

	}
	node *tt = n2->next;
	n2->next = n1->next;
	n1->next = tt;


}


void printn(node **head, int n) {
	if (*head == NULL)
		return;
	static int count = 0;
//	count++;
	printn(&(*head)->next, n);
	printf("count is %d \n", count);
	if (++count == n)
		printf("%d", (*head)->data);

}

void reverse(node **head) {
	node *cur = *head;
	node *priv = NULL;
	node *next = NULL;
	while (cur != NULL) {
		next=cur->next;
		cur->next = priv;
		priv = cur;
		cur = next;
	}
	*head = priv;
}

void recursiveReverse(struct node** head_ref)
{
	struct node* first;
	struct node* rest;

	/* empty list */
	if (*head_ref == NULL)
		return;

	/* suppose first = {1, 2, 3}, rest = {2, 3} */
	first = *head_ref;
	rest = first->next;

	printf("first is %d \n", first->data);
	printf("head is %d \n", (*head_ref)->data);
	printf("The address of rest is at %u\n", &rest);
	/* List has only one node */
	if (rest == NULL)
		return;

	printf("rest is %d \n", rest->data);

	/* reverse the rest list and put the first element at the end */
	recursiveReverse(&rest);
	printf("rest after rev is %d \n", rest->data);
	printf("head after rev %d \n", (*head_ref)->data);
	printf("The address of rest is at %u\n", &rest);
	first->next->next = first;

	/* tricky step -- see the diagram */
	first->next = NULL;

	printf("head ref is %d \n", rest->data);
	printf("The address of rest is at %u\n", &rest);
	/* fix the head pointer */
	*head_ref = rest;
}

void func(int *i) {
	*i = 10;
	printf("i is %d \n",*i);

}

int main() {
	node *head = NULL;
	for (int i = 0; i < len; i++) {
		head = insert(head,i+1);
		//push(&head, i);
	}
	print(head);
	//deletepos(&head,3);
	//print(head);
	//swap(&head,2, 3);
	//print(head);

	//printn(&head, 2);
	recursiveReverse(&head);
	print(head);
	//int j = 1;
	//int *k = NULL;

	//func(k);
	//printf("j is %d \n", j);

	return 0;
}