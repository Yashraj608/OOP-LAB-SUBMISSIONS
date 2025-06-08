//MATRIX TRANSPOSE USING POINTERS//
#include <iostream>
using namespace std;

int** allocatememory(int rows, int columns) {
    int** ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[columns];
    }
    return ptr;
}

void inputdimendions(int** ptr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        cout << "Enter the elements for row " << i + 1 << endl;
        for (int j = 0; j < columns; j++) {
            cout << "Enter the element for row " << i + 1 << " and column " << j + 1 << endl;
            cin >> ptr[i][j];
        }
    }
}

void displaymatrix(int** ptr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << ptr[i][j] << "\t";
        }
        cout << endl;
    }
}

int** computetranspose(int** ptr, int rows, int columns) {
    int** transpose = allocatememory(columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = ptr[i][j];
        }
    }
    return transpose;
}

void displaytranspose(int** ptr, int rows, int columns) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
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
    cout << "Enter the number of Rows:" << endl;
    cin >> rows;
    cout << "Enter the number of columns:" << endl;
    cin >> columns;

    int** ptr = allocatememory(rows, columns);
    inputdimendions(ptr, rows, columns);
    displaymatrix(ptr, rows, columns);

    int** transpose = computetranspose(ptr, rows, columns);
    displaytranspose(transpose, rows, columns);

    freeallocatedmemory(ptr, rows);
    freeallocatedmemory(transpose, columns);

    return 0;
}
