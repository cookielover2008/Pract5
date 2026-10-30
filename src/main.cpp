#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;

void readMatrix(double a[MAX_SIZE][MAX_SIZE], int n, int m) {
    cout << "Введите элементы матрицы построчно:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

bool columnHasZero(double a[MAX_SIZE][MAX_SIZE], int n, int column) {
    for (int i = 0; i < n; i++) {
        if (a[i][column] == 0.0) {
            return true;
        }
    }
    return false;
}

double sumColumnsWithZero(double a[MAX_SIZE][MAX_SIZE], int n, int m,
                         bool &hasSelectedColumns) {
    double total = 0.0;
    hasSelectedColumns = false;

    for (int j = 0; j < m; j++) {
        if (columnHasZero(a, n, j)) {
            hasSelectedColumns = true;
            for (int i = 0; i < n; i++) {
                total += a[i][j];
            }
        }
    }
    return total;
}

int main() {
    int n, m;
    double a[MAX_SIZE][MAX_SIZE];

    cout << "Введите количество строк и столбцов (от 1 до 100): ";
    if (!(cin >> n >> m) || n < 1 || n > MAX_SIZE || m < 1 || m > MAX_SIZE) {
        cout << "Ошибка: размеры матрицы должны быть от 1 до 100.\n";
        return 1;
    }

    readMatrix(a, n, m);

    bool hasSelectedColumns;
    double result = sumColumnsWithZero(a, n, m, hasSelectedColumns);

    if (!hasSelectedColumns) {
        cout << "Столбцов с нулевыми элементами нет.\n";
    }

    cout << fixed << setprecision(2);
    cout << "Общая сумма элементов столбцов с нулями: " << result << '\n';

    return 0;
}