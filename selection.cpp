#include <stdio.h>
#include <stdlib.h>


void selectionSort(int *a, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int temp = a[i];
		int min = a[i];
		int pos = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < min) {
				min = a[j];
				pos = j;
			}
		}
		a[i] = a[pos];
		a[pos] = temp;
	}
}


void bubble(int *a, int n) {

	int i, j;
	//for (i = 0; i < n-1 ; i++) {
	//	for (j = 0; j < n-i-1; i++) {
	//		if (a[j]>a[j+1])
	//	}
	int swap = false;
	while (1) {
		swap = false;
		printf("one round \n");
		for (i = 0; i < n - 1; i++) {
			if (a[i]>a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swap = true;
			}
		}
		if (swap == false)
			break;

	}
}



void insertion(int *a, int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int pos = i;
		int ele = a[i];
		for (j = i; j>0; j--) {
			if (a[j - 1] > ele) {
				//int temp = a[j];
				a[j] = a[j - 1];
				pos = j - 1;

			}
		}
		a[pos] = ele;

	}

}
void print(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ->", a[i]);
	}
	printf("\n");

}

void merge(int *a, int l, int m, int r) {
	printf("mergeing from %d to %d via mid  %d \n", l, r,m);

	const int n1 = m - l + 1;
	const int n2 = r - m;
	const int n3=n1;
	int temp[10];
	int i = l;
	int j = m + 1;
	int count = 0;
	while (i <= m&&j <= r) {
		if (a[i] < a[j]) {
			temp[count++] = a[i];
			i++;
		}
		else {
			temp[count++] = a[j];
			j++;
		}
	}

	while (i <= m) {
		temp[count++] = a[i++];
	}
	while (j <= r) {
		temp[count++] = a[j++];

	}
	print(temp, 7); int k = l;
	printf("k and r %d %d \n", k, r);
	for (k = l,count=0; k <= r; k++,count++) {
		a[k] = temp[count];
	}
	print(a, 7);
}
void msort(int *a,  int l, int r) {
	printf("lower and upper are %d %d \n", l, r);
	if (l < r) {
		int m = l + (r - l) / 2;
		msort(a, l, m);
		msort(a, m + 1, r);
		merge(a, l, m, r);
	}

}

int main()
{
	int arr[] = {38,27,43,3,9,82,10};
	//int arr[] = { 1, 2, 4, 5, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//int qrr[n];
	msort(arr,0, n-1);
	printf("Sorted array: \n");
	print(arr, n);
	return 0;
}