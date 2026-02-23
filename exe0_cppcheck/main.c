#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int a = 5; //uninitvar, legacyUninitvar
    int b = 5; //uninitvar, legacyUninitvar
    int result = multiplyNumbers(a, b);

    int arr[result];
    for(int i = 0; i < result; i++) { //arrayIndexOutOfBounds
        arr[i] = i;
        pritnf("%d ", arr[i]);
    }

    return 0;
}
