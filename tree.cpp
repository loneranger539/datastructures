#include<iostream>
#include<cstdio>
using namespace std;

class node {
public:
	int data;
	node *left;
	node *right;
public:
	node() = default;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	};
	void print() {
		cout << data << endl;
	};

};
class tree {
public:
	node *root;
	int size;
public:
		tree();
		void insert(int data);
		node * deleteT(node *,int data);
		void print(node *ele);
		int parent(int i) { return (i - 1) / 2; }
		int left(int i) { return (2 * i + 1); };
		int right(int i) { return (2 * i + 2); };
		node * min(node *c = NULL);
};


tree::tree() {
	size = 0 ;
	root = NULL;
}

node * tree::min(node *c) {
	node *min = c;
	while (min->left) {
			min = min->left;
	}
	return min;
}
void tree::insert(int data) {
	printf("insert %d \n", data);
	if (size == 0) {
		node *e = new node(data);
		size++;
		root = e;
		return; 
	}

	node *temp = root;
	int done = 0;
	node *e = new node(data);
	size++;

	while (!done) {
		printf("compare %d %d \n", data, temp->data);
		if (data < temp->data) {
			if (temp->left == NULL) {
				cout << "found left" << endl;
				done = 1;
				temp->left = e;
			}
			temp = temp->left;
		}
		else {
			cout << "rigth child" << endl;
			if (temp->right == NULL) {
				done = 1;
				temp->right = e;
			}
			temp = temp->right;
		}
	}
}

void tree::print(node *r) {
	if (r) {
		cout << r->data << endl;
		print(r->left);
		print(r->right);
		//cout << root->left->data << endl;
		//cout << root->right->data << endl;


	}
}


node * tree::deleteT(node *r, int k) {
	node *t = r;
	if (t == NULL)
		return t;
	printf("delete %d %d \n", k, r->data);
	if (k < t->data) {
		printf("ldu \n");
		t->left = deleteT(t->left, k);
	}
	else if (k > t->data) {
		printf("rsub \n");
		t->right = deleteT(t->right, k);
	}
	else {
		printf("found \n");
		if (t->left == NULL) {
			node *temp = t->right;
			free(t);
			return temp;
		}
		if (t->right == NULL) {
			node *temp = t->left;
			free(t);
			return temp;
		}
		node *m = min(t->right);
		printf("min node is %d \n", m->data);
		t->data = m->data;
		t->right = deleteT(t->right, m->data);
	}
	return t;
}

int main() {
	tree *t = new tree();
	t->insert(6);
	t->insert(2);
	t->insert(8);
	t->insert(1);
	//t->insert(5);
	t->insert(3);
	t->insert(4);
	t->print(t->root);
	/*t->deleteT(t->root,3);
	cout << "after 3 del " << endl;
	t->print(t->root);
	t->root = t->deleteT(t->root, 2);
	cout << " after 2 del" << endl;
	t->print(t->root);
	t->root = t->deleteT(t->root, 6);
	cout << " after 6 del" << endl;
	t->print(t->root);*/
	node *n = t->min(t->root);
	cout << "min is " << n->data << endl;
	return 0;
}