#include <iostream>

using namespace std;

int lab2() {
	double x, y;

	cout << "Give me x: \n";
	cin >> x;
	cout << "Give me y: \n";
	cin >> y;

	if (x >= -1 && x <= 1 && y >= -1 && y <= 1 && !(y < 0 && x < 0))
		cout << "Точка попадає в область\n";
	else
		cout << "Точка не попадає в область\n";

	return (0);
}