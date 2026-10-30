#pragma once

class Matrix {
private:
    static const int MAX_SIZE = 100;

    int n, m;
    double a[MAX_SIZE][MAX_SIZE];

public:
    Matrix();

    bool readData();

    bool columnHasZero(int column) const;

    double calculate(bool &hasSelectedColumns) const;

    void printResult() const;
};
