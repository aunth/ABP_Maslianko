#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int lab3() {
	double sum = 0;
	long n;
	double current;
	short k1 = -1;
	long k2 = 1;
	double dbln;
	double esp = 0.000001;
	for (n = 0; ; n++, k1 = -k1, k2 *= 3) {
		dbln = static_cast<double>(n);
		current = k1 * (1 + 3 * dbln) / k2;
		if (fabs(current) >= esp)
			sum += current;
		else
			break;
		if (n == 9)
			cout << "Cума 10 членів послідовності = " << sum << endl;
	}
	cout << "Повна сума ряду = " << fixed << setprecision(7) << sum << endl;


	return 0;
}