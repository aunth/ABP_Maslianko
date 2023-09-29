#include "lab_1/lab_1.cpp"
#include "lab_2/lab_2.cpp"
#include <iostream>

using namespace std;

int main(void) {
	int lab_num;
	anchor:
	cout << "Give me number of the lab you want to run" << endl;
	cin >> lab_num;

	switch (lab_num) {
		case 1:
			lab1();
			break;
		case 0:
			return 0;
	}

	goto anchor;
}