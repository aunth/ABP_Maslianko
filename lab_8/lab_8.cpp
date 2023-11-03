#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct star {
	char clas[3];
	double estimate_mass;
	double part;
	long int amount;
};

void sort_struct(star stars[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;  // Initialize smallest with the current index
        for (int j = i + 1; j < size; j++) {
            if (stars[j].amount < stars[smallest].amount)
                smallest = j;
        }
        // Swap the elements
        star tmp = stars[i];
        stars[i] = stars[smallest];
        stars[smallest] = tmp;
    }
}


void fill_precisions(int precision[][2], star stars[], int size) {
    for (int i = 0; i < size; i++) {
        double estimate_mass = stars[i].estimate_mass;
        double part = stars[i].part;
        int precision_estimate_mass = 0;
        int precision_part = 0;
		int j = 0;

        while ((estimate_mass = estimate_mass - (int)round(estimate_mass)) != 0) {
			if (abs(estimate_mass) < 0.000001)
				break;
			precision_estimate_mass++;
            estimate_mass *= 10;
        }

        while ((part = part - (int)round(part)) != 0) {
            if (part < 0.000001)
				break;
			precision_part++;
            part *= 10.0;
        }

        precision[i][0] = precision_estimate_mass;
        precision[i][1] = precision_part;
    }
}


int lab8() {
	int size = 10;
	char str[3];
	star stars[10];
	int precision[10][2];
	char separator = '|';
	int i;
	for (i = 0; i < 10; i++) {
		cout << i+1 << " Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n";
		cin >> str;
		if (strcmp(str, "***") == 0) {
			break;
		} else {
			strcpy(stars[i].clas, str);
			cin >> stars[i].estimate_mass >> stars[i].part >> stars[i].amount;
		}
	}
	sort_struct(stars, i);
	fill_precisions(precision, stars, i);
	cout << separator <<"------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "     Приблизна кількість зірок різних спектральних класів у Галактиці         " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "Спектральний клас   |Приблизна маса (відн. Сонця)  |Частина %  |Чисельність   " << separator << endl;
	cout << separator << "--------------------|------------------------------|-----------|--------------" << separator << endl;
	for (int n = 0; n < i; n++) {
		cout << separator << setw(20) << left << stars[n].clas << separator 
		<< setw(30)  << left << fixed << setprecision(precision[n][0]) << stars[n].estimate_mass << separator 
		<< setw(11) << left << fixed << setprecision(precision[n][1]) << stars[n].part << separator 
		<< setw(14) << left << stars[n].amount << separator << endl;
		if (n != i-1)
			cout << "|--------------------|------------------------------|-----------|--------------|\n";
	}
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "               Примітка: дані не показані для класів: B, A, G, K              " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	return 0;
}

// int main(void) {
// 	lab8();
// }

//O 32 0.00002 55000
//N 43.43 0.0000002 54545454
//M 43.3232 0.3443 43434