#include <iostream>

using namespace std;

struct star {
    char clas[3];
    double estimate_mass;
    double part;
    long int amount;
};

void fill_precisions(int precision[][2], star stars[], int size) {
    for (int i = 0; i < size; i++) {
        double estimate_mass = stars[i].estimate_mass;
        double part = stars[i].part;
        int precision_estimate_mass = 0;
        int precision_part = 0;
		int j = 0;

        while ((estimate_mass = estimate_mass - (int)round(estimate_mass)) != 0) {
			if (abs(estimate_mass) < 0.00001)
				break;
			cout << "Before\n";
			cout << estimate_mass << endl;
			cout << (int)round(estimate_mass) << endl;
			precision_estimate_mass++;
            estimate_mass *= 10;
			cout << "After\n";
			cout << estimate_mass << endl;
			cout << (int)round(estimate_mass) << endl;
        }

        while ((part = part - (int)part) != 0) {
            if (part < 0.00001)
				break;
			precision_part++;
            part *= 10.0;
        }

        precision[i][0] = precision_estimate_mass;
        precision[i][1] = precision_part;

        cout << "Star " << i + 1 << " precision_estimate_mass = " << precision_estimate_mass << endl;
        cout << "Star " << i + 1 << " precision_part = " << precision_part << endl;
    }
}

int main() {
    star stars[3];
    int precision[3][2];

    stars[0].estimate_mass = 123.456;
    stars[0].part = 0.789;

    stars[1].estimate_mass = 45.678;
    stars[1].part = 12.345;

    stars[2].estimate_mass = 0.123;
    stars[2].part = 0.456;

    fill_precisions(precision, stars, 3);

    return 0;
}
