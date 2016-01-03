#include <iostream>
#include<vector>
#include <stdio.h>
using namespace std;

class node {
public:
	int data;
	node *next;
public:
	node() = default;
	node(int d) {
		data = d;
		next = NULL;
	};
	void print() {
		cout << data << endl;
	};

};


class hashing {
	int size;
	node **arr;
public:
	hashing(int s) {
		size = s+1;
		arr = (node **)malloc(size*sizeof(node *));
		for (int i = 0; i < size; i++) {
			arr[i] = NULL;
			//memset(arr[i], 0, sizeof(node));
		}
	};
	int hashfunc(int data);
	void insert(int );
	int find(int data);
	void remove(int data);

	void print() {
		for (int i = 0; i < size; i++) {
			node *temp = arr[i];
			printf("print %d : ",i);
			while (temp) {
				printf("%d->", temp->data);
				temp = temp->next;
			}
			printf("\n");
		}
	};
};

int hashing::hashfunc(int data) {
	int val;
	val = data%size;
	return val;
}

void hashing::insert(int data) {
	int key = hashfunc(data);
	printf("hash key of %d is %d \n",data, key);
	if (arr[key] == NULL) {
		node *temp = new node(data);
		arr[key] = temp;
		//*arr = temp;
		return;

	}
	node *temp = new node(data);
	temp->next = arr[key];
	printf("temp is %d \n", temp);
	printf("arr is %d \n", arr);
	printf("arr[key is %d \n", arr[key]);
	printf("*temp is %d \n", *temp);
	printf("*arr is %d \n", *arr[key]);
	arr[key] = temp;
	printf("temp is %d \n", temp);
	printf("arr is %d \n", arr);
	printf("arr[key is %d \n", arr[key]);
	printf("*temp is %d \n", *temp);
	printf("*arr is %d \n", *arr[key]);

}

int hashing::find(int data) {
	int key = hashfunc(data);
	printf("hash key of %d is %d \n", data, key);

	if (arr[key] == NULL) {
		return -1;
	}

	node *temp = arr[key];
	while (temp) {
		if (temp->data == data) {
			return key;
		}
		temp = temp->next;

	}
	return -1;
}

void hashing::remove(int data) {
	int key = hashfunc(data);
	printf("remove: hash key of %d is %d \n", data, key);

	if (find(data) == -1) {
		cout << "element not found" << endl;
		return;
	}

	node *temp = arr[key];
//	node *temp = *head;
	node *prev = arr[key];
	if (temp->data == data) {
		arr[key] = temp->next;
		delete temp;
		cout << "removed " << endl;
		return;
	}
	while (temp != NULL) {
		if (temp->data == key) {
			prev->next = temp->next;
			delete temp;
			cout << "removed" << endl;
			return;
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
}

int main() {
	hashing *h = new hashing(6);
	h->insert(50);
	h->insert(700);
	h->insert(76);
	h->insert(76);
	h->insert(85);
	h->insert(92);
	h->insert(73);
	h->insert(101);

	h->print();

	cout << "find key 101: " << h->find(101) << endl;
	cout << "find key 80: " << h->find(80) << endl;
	
	h->remove(76);
	h->print();

	h->remove(75);
	h->print();
	h->remove(76);
	h->print();
	h->remove(76);
	h->print();

	h->insert(76);
	h->print();
	return 0;



}