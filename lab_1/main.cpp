#include <stdio.h>


int main() {
	char spectral_class1, spectral_class2, spectral_class3;
	float estimate_mass1, estimate_mass2, estimate_mass3;
	float part1, part2, part3;
	long int number1, number2, number3;


	printf("1. Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n");
	scanf(" %c %f %f %li", &spectral_class1, &estimate_mass1, &part1, &number1);

	printf("2. Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n");
	scanf(" %c %f %f %li", &spectral_class2, &estimate_mass2, &part2, &number2);

	printf("3. Введіть 'Cпектральний клас', 'Приблизну масу', 'Частину', 'Чисельність'\n");
	scanf(" %c %f %f %li", &spectral_class3, &estimate_mass3, &part3, &number3); 

	printf("--------------------------------------------------------------------------------\n");
	printf("|     Приблизна кількість зірок різних спектральних класів у Галактиці         |\n");
	printf("|------------------------------------------------------------------------------|\n");
	printf("|  Спектральний клас | Приблизна маса (відн. Сонця) | Частина %% | Чисельність  |\n");
	printf("|                    |                              |           |              |\n");
	printf("|--------------------|------------------------------|-----------|--------------|\n");

	printf("| %18c | %28.0f | %9.5f | %12li |\n", spectral_class1, estimate_mass1, part1, number1);
	printf("| %18c | %28.2f | %9.1f | %12li |\n", spectral_class2, estimate_mass2, part2, number2);
	printf("| %18c | %28.1f | %9.1f | %12li |\n", spectral_class3, estimate_mass3, part3, number3);


	printf("|------------------------------------------------------------------------------|\n");
	printf("|               Примітка: дані не показані для класів: B, A, G, K              |\n");
	printf("|                                                                              |\n");
	printf("--------------------------------------------------------------------------------\n");
	return 0;
}