#include <iostream>
#include "../constant.h"

using namespace std;



void fill_array(int *array, int size) {
	for (int i = 0; i < size; i++) {
		*array = rand() % 10;
		array++;
	}
}


void print_array(int *ch, int times) {
	cout << "{ ";
	while (times) {
		if (times != 1)
			cout << *ch << ", ";
		else
			cout << *ch;
		ch++;
		times--;
	}
	cout << " }";
	cout << "\n";
}


float get_num_of_sequences(int start, int end) {
	float n = end - start;
	return (float)((1 + n) / 2) * n;
}

void get_sequences(int *a, int start, int end) {
	for (int j = start; j <= end; j++) {
		for (int i = j+1; i <= end; i++) {
			print_array(&a[j], i - j);
		}
	}
}

// (1 + 4 / 2) * 4
// if i have sequence a1, a2, a3, a4, a5 and a5 < a4.A = {a1, a2, a3, a4}. 
// In this case i have growing subsequence.
// Ex:
// 1 2 3 5 3 5. A = {1, 2, 3, 4}, len(A) = 4. Subsequences are = {{1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}
// {2}, {2, 3}, {2, 3, 4}, {3}, {3, 4}, {4}}

void lab6() {
	int *array;
	int size;
	int result = 0;
	int start = 0;

	cout << "Довжина масиву\n";
	cin >> size;
	array = new int[size];
	fill_array(array, size);
	print_array(array, size);
	int cur_max = *array;
	int *ch = array;
	int i = 0;
	while (i < size) {
		if (cur_max <= *ch)
			cur_max = *ch;
		else {
			result += get_num_of_sequences(start, i);
			get_sequences(array, start, i);
			start = i;
			cur_max = *ch;
		}
		i++;
		ch++;
	}
	result += get_num_of_sequences(start, size);
	get_sequences(array, start, size);
	cout << "Кількість рядків = " << result << endl;
	delete[] array;
}