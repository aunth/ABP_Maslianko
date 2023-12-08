#include <iostream>
#include <iomanip>
#include <cstring>
#include "../constant.h"

using namespace std;


void shapka(void) {
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|     Приблизна кількість зірок різних спектральних класів у Галактиці         |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|Спектральний клас   |Приблизна маса (відн. Сонця)  |Частина %  |Чисельність   |" << endl;
    cout << "|--------------------|------------------------------|-----------|--------------|" << endl;
}

void linebuild(void) {
    cout << "|------------------------------------------------------------------------------|" << endl;
}

void end_of_table(void) {
    char separator = '|';
    cout << separator << "------------------------------------------------------------------------------" << separator << endl;
    cout << separator << "               Примітка: дані не показані для класів: B, A, G, K              " << separator << endl;
    cout << separator << "------------------------------------------------------------------------------" << separator << endl;
}

int isvalid(int a, int b) {
    return (a > 0 && b > 0) ? 1 : 0;
}

star::star() : clas(nullptr), estimate_mass(0), part(0), amount(0) {}

star::star(const char* c, double e, double p, long int a) : estimate_mass(e), part(p), amount(a) {
    clas = new char[strlen(c) + 1];
    strcpy(clas, c);
}

star::~star() {
    delete[] clas;
}

star::star(const star& s) : estimate_mass(s.estimate_mass), part(s.part), amount(s.amount) {
    clas = new char[strlen(s.clas) + 1];
    strcpy(clas, s.clas);
}

ostream& operator<<(ostream& stream, const star& o1) {
    char separator = '|';
    shapka();
    stream << separator << setw(20) << left << o1.clas << separator
           << setw(30) << left << o1.estimate_mass << separator
           << setw(11) << left << o1.part << separator
           << setw(14) << left << o1.amount << separator << endl;
    linebuild();
    return stream;
}

istream& operator>>(istream& stream, star& o1) {
    cout << "Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n";
    char buf[50];
    stream >> buf >> o1.estimate_mass >> o1.part >> o1.amount;

    if (o1.clas != nullptr) {
        delete[] o1.clas;
    }

    o1.clas = new char[strlen(buf) + 1];
    strcpy(o1.clas, buf);

    return stream;
}

star& star::operator=(const star& s) {
    if (this != &s) {
        delete[] clas;
        estimate_mass = s.estimate_mass;
        part = s.part;
        amount = s.amount;
        clas = new char[strlen(s.clas) + 1];
        strcpy(clas, s.clas);
    }
    return *this;
}

bool star::operator==(const star& s) const {
    return strcmp(clas, s.clas) == 0 &&
           estimate_mass == s.estimate_mass &&
           part == s.part &&
           amount == s.amount;
}

star star::operator+(const star& s) const {
    star result;
    result.clas = new char[strlen(clas) + strlen(s.clas) + 1];
    strcpy(result.clas, clas);
    strcat(result.clas, s.clas);
    result.estimate_mass = estimate_mass + s.estimate_mass;
    result.part = part + s.part;
    result.amount = amount + s.amount;
    return result;
}

void star::show_row() const {
    char separator = '|';
    shapka();
    cout << separator << setw(20) << left << clas << separator
              << setw(30) << left << estimate_mass << separator
              << setw(11) << left << part << separator
              << setw(14) << left << amount << separator << endl;
    end_of_table(); // Added call to end_of_table
}

int lab13() {
    star *star_array = new star[3];

    star_array[0] = star("A", 2.2, 10.434, 1234);
    star_array[1] = star("B", 1, 1, 1);
    star_array[2] = star("C", 123, 312, 003);
    *(star_array+1) = *(star_array+1) + star("A", 2.2, 10.434, 1234);
    cin >> *(star_array+2);
    for (int i = 0; i < 3; i++) {
        cout << star_array[i];
    }
    return 0;
}

