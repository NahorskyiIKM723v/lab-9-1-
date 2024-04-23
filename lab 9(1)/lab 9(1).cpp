#include <iostream>
using namespace std;

const int rows_lim = 5;
const int cols_lim = 5;

bool isSymmetric(int matrix[rows_lim][cols_lim], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int matrix[rows_lim][cols_lim];
    int rows, cols;

    cout << "Введіть кількість рядків (не більше " << rows_lim << "): ";
    cin >> rows;
    cout << "Введіть кількість стовпців (не більше " << cols_lim << "): ";
    cin >> cols;

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    if (isSymmetric(matrix, rows, cols)) {
        cout << "Матриця симетрична відносно головної діагоналі.\n";
    }
    else {
        cout << "Матриця не симетрична відносно головної діагоналі.\n";
    }

    int evenCounts[rows_lim] = { 0 };
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 2 == 0) {
                evenCounts[i]++;
            }
        }
    }

    cout << "Кількість парних елементів у кожному рядку:\n";
    for (int i = 0; i < rows; ++i) {
        cout << "Рядок " << i << ": " << evenCounts[i] << " парних елементів.\n";
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
