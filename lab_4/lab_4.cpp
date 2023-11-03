#include <iostream>
#include "../constant.h"

using namespace std;

int get_averege_sum(int a[], int start) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += a[start + i];
	}

	return result / 10;
}

void print_array(int a[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << a[i] << ' ';
	}
}

void lab4() {
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 101;
	}
	int result[2]; // [index of the first element, average sum of the 10 element]
	result[0] = 0;
	result[1] = 0;
	for (int i = 0; i < SIZE-10; i++) {
		int cur_av_sum = get_averege_sum(arr, i);
		if (cur_av_sum > result[1]){
			result[1] = cur_av_sum;
			result[0] = i;
		}
	}


	for (int i = result[0]; i < result[0] + 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	cout << "sum = " << result[1] << endl;
}