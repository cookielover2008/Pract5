#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() {
    n = 0;
    m = 0;
}

bool Matrix::enterData() {
    cout << "Введите количество строк и столбцов (от 1 до 100): ";

    if (!(cin >> n >> m) ||
        n < 1 || n > MAX_SIZE ||
        m < 1 || m > MAX_SIZE) {

        cout << "Ошибка: размеры матрицы должны быть от 1 до 100.\n";
        return false;
    }

    cout << "Введите элементы матрицы построчно:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(cin >> a[i][j])) {
    cout << "Ошибка: элементы матрицы должны быть числами.\n";
                
    return false;
};
        }
    }

    return true;
}

bool Matrix::columnHasZero(int column) const {
    for (int i = 0; i < n; i++) {
        if (a[i][column] == 0.0) {
            return true;
        }
    }

    return false;
}

double Matrix::calculate(bool &hasSelectedColumns) const {
    double total = 0.0;
    hasSelectedColumns = false;

    for (int j = 0; j < m; j++) {
        if (columnHasZero(j)) {
            hasSelectedColumns = true;

            for (int i = 0; i < n; i++) {
                total += a[i][j];
            }
        }
    }
    
    return total;
}

void Matrix::printResult() const {
    bool hasSelectedColumns;

    double result = calculate(hasSelectedColumns);

    if (!hasSelectedColumns) {
        cout << "Столбцов с нулевыми элементами нет.\n";
    }

    cout << fixed << setprecision(2);
    cout << "Общая сумма элементов столбцов c нулями: "
         << result << '\n';
}
