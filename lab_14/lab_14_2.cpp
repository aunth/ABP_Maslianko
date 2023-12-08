#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VALUE = 1000;

void copy_array(int* dest, const int* src, int len) {
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
}

class Queue {
private:
    int length;
    int value[MAX_VALUE];

public:
    Queue() {
        length = 0;
    }

    Queue(int* arr, int len) {
        copy_array(value, arr, len);
        length = len;
    }

    Queue(const Queue& other) {
        length = other.length;
        copy_array(value, other.value, other.length);
    }

    ~Queue() {

	}

    void show_queue() const {
        cout << "Queue:\n";
        for (int i = 0; i < length; i++) {
            cout << value[i] << ' ';
        }
        cout << "\n";
    }

    void enqueue(int a) {
        if (length >= MAX_VALUE) {
            cout << "You cannot add an element to the queue. It's full." << endl;
        } else {
            value[length] = a;
            length++;
        }
    }

    void dequeue() {
        if (length > 0) {
            for (int i = 0; i < length - 1; i++) {
                value[i] = value[i + 1];
            }
            length--;
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    void delete_elements() {
        length = 0;
    }
};

int lab14_2() {
    int initialArray[] = {1, 2, 3, 4, 5};
    Queue myQueue(initialArray, 5);

    myQueue.show_queue();

    myQueue.enqueue(6);
    myQueue.show_queue();

    myQueue.dequeue();
    myQueue.show_queue();

    myQueue.delete_elements();
    myQueue.show_queue();

    return 0;
}
