#include <iostream>
#include <iomanip>

using namespace std;


struct Star{
	char clas[3];
	double estimate_mass;
	double part;
	long int amount;
};


struct queue {
	Star value;
	queue *next;
};


queue *create_queue_element(Star value) {
	queue *result = new queue;
	result->value = value;
	result->next = nullptr;
	return result;
}


void enqueue(queue **q, Star value) {
    queue *new_element = create_queue_element(value);
    if (*q == nullptr) {
        *q = new_element;
    } else {
        queue *temp = *q;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_element;
    }
}


queue *dequeue(queue **q) {
    if (*q == nullptr) {
        return nullptr;
    }
    queue *temp = *q;
    *q = (*q)->next;
    temp->next = nullptr;
    return temp;
}


void print_queue(queue *q, int i) {
	queue *current;
	char separator = '|';
	cout << separator <<"------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "     Приблизна кількість зірок різних спектральних класів у Галактиці         " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "Спектральний клас   |Приблизна маса (відн. Сонця)  |Частина %  |Чисельність   " << separator << endl;
	cout << separator << "--------------------|------------------------------|-----------|--------------" << separator << endl;
	for (int n = 0; n < i; n++) {
		current = dequeue(&q);
		cout << separator << setw(20) << left << current->value.clas << separator 
		<< setw(30)  << left << current->value.estimate_mass << separator 
		<< setw(11) << left << current->value.part << separator 
		<< setw(14) << left << current->value.amount << separator << endl;
		if (n != i-1)
			cout << "|--------------------|------------------------------|-----------|--------------|\n";
	}
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "               Примітка: дані не показані для класів: B, A, G, K              " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	
}

void lab9() {
	Star current;
	queue *q;

	int precision[10][2];
	char separator = '|';
	int i;
	for (i = 0; i < 10; i++) {
		cout << i+1 << " Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n";
		cin >> current.clas;
		if (strcmp(current.clas, "***") == 0) {
			break;
		} else {
			cin >> current.estimate_mass >> current.part >> current.amount;
			if (i == 0)
				q = create_queue_element(current);
			else
				enqueue(&q, current);
		}
	}
	print_queue(q, i);
}