#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);

// A class for Min Heap
class heap
{
	int *arr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int size; // Current number of elements in min heap
public:
	heap() = default;
	heap(int size);
	void insert(int data);
	void getmin(){
		cout << "getmin is " << arr[0] << endl;
		//return arr[0];
	};
	int deletemin();
	void heapify();
	void print() { for (int i = 0; i < size; i++) { cout << arr[i] << "-"; }; cout << endl; };
	bool isfull() {   if (size >= capacity) return true; return false; };
	bool isempty() { if (size <= 0) return true; return false; };
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1) ; };
	int right(int i) { return (2 * i + 2); };
	void decreasekey(int key, int val);
	void make(int *);
	void build(int);
};

heap::heap(int c) {
	capacity = c;
	size = 0;
	arr = (int *)new int(10);
}


void heap::insert(int data) {
	if (isfull())
		return;
	int i = 0;
	for (i = size; arr[parent(i)] > data && i>0; i = parent(i)) {
		cout << "currindex  at " << i << endl;

		arr[i] = arr[parent(i)];

	}
	cout << "insert at " << i << endl;
	arr[i] = data;
	size++;

}

void heap::build(int pos) {
	cout << "heapify " << pos << "ele " << arr[pos] << endl;
	int i = pos;
	int lc ;
	int rc ;
	int child = pos;
	int ele = arr[pos];
	for (i = pos; i < size; i = child) {
		lc = left(i);
		rc = right(i);
		if (lc<size)
			child = lc;
		if (rc < size && arr[right(i)] < arr[lc]) {
			child = right(i);
		}
		cout << "child of " << i << "is " << child << endl;;
		cout << "values child of " << arr[i] << "is " << arr[child] << endl;;

		if (ele> arr[child] && i != child) {
			cout << "swap " << i << " " << child << endl;
			cout << "values swap " << arr[i] << " " << arr[child] << endl;
			arr[i] = arr[child];
		}
		else {
			break;
		}

	}
	cout << "found pos  " << i << "for" << ele << endl;

	arr[i] = ele;

}
void heap::make(int *ar) {
	int i=0;
	if (size == 0) {
		//return ;
	}
	arr = ar;
	size = 6;
	print();
	cout << "build" << endl;
	for (i = (size - 2) / 2; i >= 0; --i) {
		build(i);
	}

}
int heap::deletemin() {
	if (isempty())
		return -1;

	int min = arr[0];
	int last = arr[size - 1];
	size--;
	if (size == 0) {
		return min;
	}
	cout << "min and last " << min << last <<endl;
	int i = 0; int child = 0;
	for (i = 0; i < size; i = child) {
		int lc = left(i);
		int rc = right(i);
		if (lc<size)
			child = lc;
		if (rc < size && arr[right(i)] < arr[lc]) {
			child = right(i);
		}
		cout << "child of " << i << "is " << child << endl;;
		if (last> arr[child] && i!=child) {
			cout << "swap " << i << " " <<child << endl;
			arr[i] = arr[child];
		}
		else {
			break;
		}

	}

	cout << "found pos is " << i << endl;
	arr[i] = last;
	return min;

}
void heap::decreasekey(int key, int val) {
	arr[key] = val;
	int i = 0;
	for (i = key; arr[parent(i)] > arr[i] && i != 0; i = parent(i)) {
		arr[i] = arr[parent(i)];
	}
	arr[i] = val;
}

int main() {
	heap h(10);
	for (int i = 0; i < 10; i++) {
		//h.insert(i + 1);
	}
	/*h.insert(3);
	h.insert(2);
	h.insert(5);
	h.insert(1);
	h.insert(15);
	h.insert(7);
	h.insert(6);
	h.insert(45);*/
	int arr[] = { 5, 6, 7, 11, 12, 13 };
	//h.print();
	heap h1(10);
	h1.make(arr);
	h1.print();
	//h.decreasekey(5, 4);
	//h.print();
	//h.decreasekey(2, 1);
	//h.print();
	/*h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	h.getmin();
	cout << "delete min " << h.deletemin() << endl;
	h.print();
	*/return 0;
}

