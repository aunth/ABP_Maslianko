#include <iostream>
#include <cstring>

using namespace std;

class Row {
private:
    char* rowData;

public:
    Row() {
        rowData = nullptr;
    }

    // Constructor
    Row(const char* data) {
        int length = strlen(data) + 1;
        rowData = new char[length];
        strcpy(rowData, data);
    }

    Row(const Row& existed_row) {
        int length = strlen(existed_row.rowData);
        rowData = new char[length];
        strcpy(rowData, existed_row.rowData);
    }

    void set_data(const char* str) {
        int length = strlen(str);
        rowData = new char[length];
        strcpy(rowData, str);
    }

    void insert(int position, char c) {
        int currentLength = strlen(rowData);
        if (position < 0 || position > currentLength) {
            cerr << "Invalid position for insertion." << endl;
            return;
        }

        char* newString = new char[currentLength + 2]; // +2 for the new character and null terminator

        strncpy(newString, rowData, position);
        newString[position] = c;
        strncpy(newString + position + 1, rowData + position, currentLength - position);

        newString[currentLength + 1] = '\0';

        delete[] rowData;
        rowData = newString;
    }

    ~Row() {
        delete[] rowData;
    }

    const char* getData() const {
        return rowData;
    }
};

class Text {
private:
    Row** rows;
    int numberOfRows;

public:
    Text() : rows(nullptr), numberOfRows(0) {}

    Text(Row* initialData[], int numberOfLines) {
        numberOfRows = numberOfLines;
        rows = new Row*[numberOfRows];

        for (int i = 0; i < numberOfRows; ++i) {
            rows[i] = new Row(initialData[i]->getData());
        }
    }

    Text(const Text& other) : numberOfRows(other.numberOfRows) {
        rows = new Row*[numberOfRows];

        for (int i = 0; i < numberOfRows; ++i) {
            rows[i] = new Row(other.rows[i]->getData());
        }
    }

    ~Text() {
        for (int i = 0; i < numberOfRows; ++i) {
            delete rows[i];
        }
        delete[] rows;
    }

    void insertCharacter(int rowIndex, int position, char character) {
        if (rowIndex >= 0 && rowIndex < numberOfRows) {
            rows[rowIndex]->insert(position, character);
        }
    }

    void deleteRow(int rowIndex) {
        if (rowIndex >= 0 && rowIndex < numberOfRows) {
            delete rows[rowIndex];

            for (int i = rowIndex; i < numberOfRows - 1; ++i) {
                rows[i] = rows[i + 1];
            }

            --numberOfRows;
        }
    }

    void insertRow(int rowIndex, const char* newData) {
        if (rowIndex >= 0 && rowIndex <= numberOfRows) {
            Row** newRows = new Row*[numberOfRows + 1];

            for (int i = 0; i < rowIndex; ++i) {
                newRows[i] = rows[i];
            }

            newRows[rowIndex] = new Row(newData);

            for (int i = rowIndex; i < numberOfRows; ++i) {
                newRows[i + 1] = rows[i];
            }

            delete[] rows;
            rows = newRows;
            ++numberOfRows;
        }
    }

    void clearText() {
        for (int i = 0; i < numberOfRows; ++i) {
            delete rows[i];
        }

        delete[] rows;
        rows = nullptr;
        numberOfRows = 0;
    }

    void displayText() const {
        for (int i = 0; i < numberOfRows; ++i) {
            std::cout << rows[i]->getData() << std::endl;
        }
    }
};

int lab14_1() {
    const char* initialData[] = {"Hello, ", "world!"};
    Row** rows = new Row*[2];

    for (int i = 0; i < 2; i++) {
        rows[i] = new Row(initialData[i]);
    }

    Text myText(rows, 2);
    myText.insertRow(0, "Greetings, ");
    myText.insertCharacter(1, 5, 'X');
    myText.deleteRow(2);

    myText.displayText();

    for (int i = 0; i < 2; i++) {
        delete rows[i];
    }
    delete[] rows;

    return 0;
}
