#include <iostream>
#include <iomanip>
#include "../constant.h"

using namespace std;


void star::set(const char* c, double e, double p, long int a) {
    delete[] clas;
    clas = new char[strlen(c) + 1];
    strcpy(clas, c);
    estimate_mass = e;
    part = p;
    amount = a;
}

void star::get(char *&c, double &e, double &p, long int &a) const {
    c = clas;
    e = estimate_mass;
    p = part;
    a = amount;
}

void star::show() const {
    char separator = '|';
    cout << separator << "------------------------------------------------------------------------------" << separator << endl;
    cout << separator << "     Приблизна кількість зірок різних спектральних класів у Галактиці         " << separator << endl;
    cout << separator << "------------------------------------------------------------------------------" << separator << endl;
    cout << separator << "Спектральний клас   |Приблизна маса (відн. Сонця)  |Частина %  |Чисельність   " << separator << endl;
    cout << separator << "--------------------|------------------------------|-----------|--------------" << separator << endl;

    cout << separator << setw(20) << left << clas << separator
        << setw(30) << left << estimate_mass << separator
        << setw(11) << left << part << separator
        << setw(14) << left << amount << separator << endl;
    cout << separator << "------------------------------------------------------------------------------" << separator << endl;
    cout << separator << "               Примітка: дані не показані для класів: B, A, G, K              " << separator << endl;
    cout << separator << "------------------------------------------------------------------------------" << separator << endl;
}


int lab11() {
	star *s = new star;
	(*s).set("A", 1, 1, 1);
	(*s).show();
	cout << "\n";
	(*s).set("B", 20.2, 12.2, 4);
	(*s).show();
	return 0;
}