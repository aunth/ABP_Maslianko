#include <iostream>
#include <vector>

using namespace std;

void sorting(vector<int>& numbers) {
    int n = numbers.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numbers[j] < numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

int sumOfDifferences(const vector<int>& numbers) {
    vector<int> sorted_numbers = numbers;

    sorting(sorted_numbers);

    int sum = 0;
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        sum += sorted_numbers[i - 1] - sorted_numbers[i];
    }

    return sum;
}