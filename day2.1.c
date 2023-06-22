#include <stdio.h>
#include <stdint.h>

void printExponent(double x) {
    uint64_t* ptr = (uint64_t*)&x;
    uint64_t bits = *ptr;
    uint64_t exponentMask = 0x7FF0000000000000;
    uint64_t exponent = (bits & exponentMask) >> 52;

    printf("Exponent in hexadecimal: 0x%lx\n", exponent);
    
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        uint64_t bit = (exponent >> i) & 1;
        printf("%ld", bit);
    }
    printf("\n");
}

int main() {
    double x;
    printf("Enter a double value: ");
    scanf("%lf", &x);
    printf("Double value: %lf\n", x);
    printExponent(x);

    return 0;
}
