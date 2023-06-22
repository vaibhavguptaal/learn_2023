#include <stdio.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t size) {
    char* p = (char*)a;
    char* q = (char*)b;

    while (size--) {
        char temp = *p;
        *p++ = *q;
        *q++ = temp;
    }
}

int main() {
    int choice;

    printf("Select the data type:\n");
    printf("1. int\n");
    printf("2. double\n");
    printf("3. char\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int a, b;

        printf("Enter the value of a (int): ");
        scanf("%d", &a);

        printf("Enter the value of b (int): ");
        scanf("%d", &b);

        printf("Before swap: a = %d, b = %d\n", a, b);

        swap(&a, &b, sizeof(int));

        printf("After swap: a = %d, b = %d\n", a, b);
    } else if (choice == 2) {
        double a, b;

        printf("Enter the value of a (double): ");
        scanf("%lf", &a);

        printf("Enter the value of b (double): ");
        scanf("%lf", &b);

        printf("Before swap: a = %lf, b = %lf\n", a, b);

        swap(&a, &b, sizeof(double));

        printf("After swap: a = %lf, b = %lf\n", a, b);
    } else if (choice == 3) {
        char a, b;

        printf("Enter the value of a (char): ");
        scanf(" %c", &a);

        printf("Enter the value of b (char): ");
        scanf(" %c", &b);

        printf("Before swap: a = %c, b = %c\n", a, b);

        swap(&a, &b, sizeof(char));

        printf("After swap: a = %c, b = %c\n", a, b);
    } else {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    return 0;
}