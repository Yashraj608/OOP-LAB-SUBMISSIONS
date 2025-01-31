//2D Matrix Operations//
#include<iostream>
using namespace std;

int** allocatememory(int rows, int columns) {
    int **ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[columns];
    }
    return ptr;
}

void arrayinput(int **ptr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        cout << "Enter the elements for row " << i + 1 << endl;
        for (int j = 0; j < columns; j++) {
            cout << "Enter the element for row " << i + 1 << " and column " << j + 1 << endl;
            cin >> ptr[i][j];
        }
    }
}

void displayarray(int** ptr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << ptr[i][j] << "\t";
        }
        cout << endl;
    }
}

void freeallocatedmemory(int** ptr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
   
    int** ptr = allocatememory(rows, columns);
    arrayinput(ptr, rows, columns);
    displayarray(ptr, rows, columns);
    freeallocatedmemory(ptr, rows);

    return 0;
}