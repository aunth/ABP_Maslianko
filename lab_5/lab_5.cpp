#include <iostream>

using namespace std;


int get_sum(int matrix[9][9], int i, int j) {
	int result = 0;
	result += matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1];
	result += matrix[i][j-1] + matrix[i][j+1];
	result += matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
	return result;
}

void print_matrix(int a[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << a[i][j];
            if (j < 8) {
                cout << " | "; // Vertical separator
            }
        }
        cout << endl;
        if (i < 8) {
            cout << "---------------------------------" << endl; // Horizontal line
        }
    }
}

int lab5() {
	int matrix[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
	for (int i = 1; i < 9; i += 3) {
		for (int j = 1; j < 9; j += 3)
			matrix[i][j] = get_sum(matrix, i, j);
	}
	print_matrix(matrix);
	return (1);
}
