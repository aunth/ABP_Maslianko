#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	char spectral_class1, spectral_class2, spectral_class3;
	float estimate_mass1, estimate_mass2, estimate_mass3;
	float part1, part2, part3;
	long int number1, number2, number3;
	char separator = '|';	
	cout << "1. Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n";
	cin >> spectral_class1 >> estimate_mass1 >> part1 >> number1;	
	cout << "2. Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n";
	cin >> spectral_class2 >> estimate_mass2 >> part2 >> number2;	
	cout << "3. Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n";
	cin >> spectral_class3 >> estimate_mass3 >> part3 >> number3; 	
	cout << separator <<"------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "     Приблизна кількість зірок різних спектральних класів у Галактиці         " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "  Спектральний клас | Приблизна маса (відн. Сонця) | Частина % | Чисельність  " << separator << endl;
	cout << separator << "--------------------|------------------------------|-----------|--------------" << separator << endl;	
	cout << separator << setw(20) << left << spectral_class1 << separator 
		<< setw(30) << left << estimate_mass1 << separator 
		<< setw(11) << left << fixed << setprecision(5) << part1 << separator 
		<< setw(14) << left << number1 << separator << endl;
	
	cout << "|--------------------|------------------------------|-----------|--------------|\n";
	cout << separator << setw(20) << left << spectral_class2 << separator
		<< setw(30) << left << fixed << setprecision(2) << estimate_mass2 << separator
		<< setw(11) << left << fixed << setprecision(1) << part2 << separator
		<< setw(14) << left << number2 << separator << endl;
	
	cout << "|--------------------|------------------------------|-----------|--------------|\n";
	cout << separator << setw(20) << left << spectral_class3 << separator
		<< setw(30) << left << fixed << setprecision(1) << estimate_mass3 << separator
		<< setw(11) << left << fixed << setprecision(1) << part3 << separator
		<< setw(14) << left << number3 << separator << endl;
	
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	cout << separator << "               Примітка: дані не показані для класів: B, A, G, K              " << separator << endl;
	cout << separator << "------------------------------------------------------------------------------" << separator << endl;
	return 0;
}