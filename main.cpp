#include "lab_1/lab_1.cpp"
#include "lab_2/lab_2.cpp"
#include "lab_3/lab_3.cpp"
#include "lab_4/lab_4.cpp"
#include "lab_5/lab_5.cpp"
#include "lab_6/lab_6.cpp"
#include "lab_7/lab_7.cpp"
#include "lab_8/lab_8.cpp"
#include "lab_9/lab_9.cpp"
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
		case 2:
			lab2();
			break;
		case 3:
			lab3();
			break;
		case 4:
			lab4();
			break;
		case 5:
			lab5();
			break;
		case 6:
			lab6();
			break;
		case 7:
			lab7();
			break;
		case 8:
			lab8();
		case 9:
			lab9();
		case 0:
			return 0;
	}
	goto anchor;
}