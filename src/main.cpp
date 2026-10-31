#include "Matrix.h"

int main() {
    Matrix processor;

    if (!processor.enterData()) {
        return 1;
    }

    processor.printResult();

    return 0;
}
