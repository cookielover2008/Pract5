#include "Matrix.h"

int main() {
    Matrix processor;

    if (!processor.readData()) {
        return 1;
    }

    processor.printResult();

    return 0;
}