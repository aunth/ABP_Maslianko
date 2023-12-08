#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
    char *mark;
    int year;
    char *color;

public:
	Car() {
		mark = nullptr;
        year = 0;
        color = nullptr;
	}

    Car(const char *m, int y, const char *c) {
        int mark_length = strlen(m);
        int color_length = strlen(c);
        mark = new char[mark_length];
        color = new char[color_length];
        strcpy(mark, m);
        strcpy(color, c);
        year = y;
    }

	Car(const Car&other) {
        int mark_length = strlen(other.mark);
        int color_length = strlen(other.color);
        mark = new char[mark_length];
        color = new char[color_length];
        strcpy(mark, other.mark);
        year = other.year;
        strcpy(color, other.color);
	}

    void set_mark(const char* m) {
        mark = new char[strlen(m)+1];
        strcpy(mark, m);
    }

    void show_year() {
        cout << "Рік випуску " << year << endl;
    }

    void set_year(int num) {
        year = num;
    }

    void set_color(const char* c) {
        color = new char[strlen(c)+1];
        strcpy(color, c);
    }

    void show_info() const {
        cout << endl;
        cout << "Марка: " << mark << endl;
        cout << "Рік випуску: " << year << endl;
        cout << "Колір: " << color << endl;
    }

    ~Car() {
        delete[] mark;
        delete[] color;
    };
};

class RegisteredCar : public Car {
private:
    char* register_number;

public:
    // Constructors
	RegisteredCar() : Car() {
		register_number = nullptr;
	}

    RegisteredCar(char *m, int y, char *c, const char* regNumber)
        : Car(m, y, c) {
        register_number = new char[strlen(regNumber)+1];
        strcpy(register_number, regNumber);
    }

    RegisteredCar(RegisteredCar &other) : Car(other){
        register_number = new char[strlen(other.get_register_number())+1];
        strcpy(register_number, other.get_register_number());
    }

    // Destructor
    ~RegisteredCar(){
        delete[] register_number;
    }

    const char* get_register_number() const {
        return register_number;
    }

    void set_register_number(const char* newRegNumber) {
        delete[] register_number;
        register_number = new char[strlen(newRegNumber) + 1];
        strcpy(register_number, newRegNumber);
    }

    void show_info() const {
        Car::show_info();
        cout << "Register Number: " << register_number << endl;
    }
};

int lab12() {
    Car a = Car("Мерседес", 2005, "Червоний");
    a.show_info();
    a.set_color("Білий");
    a.show_info();
    return 0;
}