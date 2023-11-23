#include <iostream>

using namespace std;

class Car {
	private:
		int p_cost;
		float p_speed;

		void print_private_variable() {
			cout << "Cost is " << p_cost << endl;
			cout << "Speed is " << p_speed << endl;
		}

	public:
		int cost;
		float speed;
};

int main() {
	Car car{};
	car.p_cost;

}
