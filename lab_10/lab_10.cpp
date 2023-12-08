#include <iostream>
#include <fstream>

using namespace std;

struct STAR {
    char clas;
    double estimate_mass;
    double part;
    long int amount;
};

fstream file;

void initf(const char *filename) {
    file.open(filename, ios::in | ios::out | ios::app| ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    if (!file.good()) {
        cerr << "File state is not good." << endl;
        return;
    }
}


void commit() {
    file.close();
}

void f_add(STAR *data) {
    file.write(reinterpret_cast<char*>(data), sizeof(STAR));
}

int fcheck_number(int number) {
    STAR temp;
    file.seekg((number - 1) * sizeof(STAR), ios::beg);
    if (file.read(reinterpret_cast<char*>(&temp), sizeof(STAR))) {
        cout << "Record " << number << " found: " << temp.clas << " " << temp.estimate_mass << " " << temp.part << " " << temp.amount << endl;
        return 0; // Record found
    } else {
        return -1; // Record not found
    }
}

void fdel_item(int number) {
    fstream temp("temp.txt", ios::out | ios::binary);

    if (!temp.is_open()) {
        cerr << "Error opening temporary file" << endl;
        return;
    }

    file.seekg(0, ios::beg);
    int i = 1;
    STAR tempStar;
    bool recordFound = false;

    while (file.read(reinterpret_cast<char*>(&tempStar), sizeof(STAR))) {
        if (i == number) {
            recordFound = true;
            continue; // Skip writing the found record
        }
        temp.write(reinterpret_cast<char*>(&tempStar), sizeof(STAR));
        i++;
    }

    temp.close();
    file.close();

    if (!recordFound) {
        cerr << "Record not found" << endl;
        remove("temp.txt");
        return;
    }

    if (remove("new.txt") != 0) {
        cerr << "Error deleting file" << endl;
    } else {
        if (rename("temp.txt", "new.txt") != 0) {
            cerr << "Error renaming file" << endl;
        }
    }

    file.open("new.txt", ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Error reopening the file" << endl;
    }
}


void fshow_all() {
    file.seekg(0, ios::beg);
    STAR tempStar;
	char separator = '|';
	cout << separator <<"------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "     Приблизна кількість зірок різних спектральних класів у Галактиці         " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "Спектральний клас   |Приблизна маса (відн. Сонця)  |Частина %  |Чисельність   " << separator << endl;
	cout << separator << "--------------------|------------------------------|-----------|--------------" << separator << endl;
	
    while (file.read(reinterpret_cast<char*>(&tempStar), sizeof(STAR))) {
        cout << separator << setw(20) << left << tempStar.clas << separator 
		<< setw(30) << left << tempStar.estimate_mass << separator 
		<< setw(11) << left << tempStar.part << separator
		<< setw(14) << left << tempStar.amount << separator << endl;
		cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	}
	cout << separator << "               Примітка: дані не показані для класів: B, A, G, K              " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	commit();
}

STAR *create_struct(char clas, double estimate_mass, double part, long int amout) {
	STAR *tmp = new STAR;
	tmp->clas = clas;
	tmp->estimate_mass = estimate_mass;
	tmp->part = part;
	tmp->amount = amout;
	return tmp;
}

int lab10() {
    const char *filename = "new.txt";

    initf(filename);

    STAR *data = create_struct('I', 12.2, 4.4, 1234);

    f_add(data);
    data->amount += 1;
    f_add(data);
    fshow_all();
    initf(filename);
    cout << fcheck_number(1) << endl;
    cout << fcheck_number(2) << endl;
    // commit();
    // initf(filename);

    fshow_all();
    initf(filename);
    fdel_item(2);
    commit();
    initf("new.txt");
    fshow_all();

    return 0;
}
