#include <iostream>

using namespace std;

void fill(int *row, int n) {
	for (int i = 0; i < n; i++) {
		*row = rand() % 10;
		row++;
	}
}

void print_matrix(int **matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j];
			if (j < n - 1) {
				cout << " | ";
			}
		}
		cout << endl;
		if (i < n - 1) {
			for (int i = 0; i < n; i++)
				cout << "----";
			cout << endl;
		}
	}
}

int lab7() {
	int S;
	cout << "Напиши мені розмірність матриці: " << endl;
	cin >> S;
	int **matrix = new int*[S];
	for (int i = 0; i < S; i++) {
		matrix[i] = new int[S];
	}
	int **arr = matrix;
	for (int i = 0; i < S; i++){
		fill(*arr, S);
		arr++;
	}
	print_matrix(matrix, S);
	cout << "\nРезультат:\n";
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			if (j > i) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}
	}
	print_matrix(matrix, S);
	return 0;
}