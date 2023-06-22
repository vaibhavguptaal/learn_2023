#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box *box) {
    double volume, surfaceArea;

    volume = box->length * box->width * box->height;
    surfaceArea = 2 * ((box->length * box->width) + (box->width * box->height) + (box->height * box->length));

    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    struct Box *boxPtr;

    boxPtr = &myBox;

    printf("Enter the length of the box: ");
    scanf("%lf", &(boxPtr->length));

    printf("Enter the width of the box: ");
    scanf("%lf", &(boxPtr->width));

    printf("Enter the height of the box: ");
    scanf("%lf", &(boxPtr->height));

    // Accessing members using -> Arrow Operator
    printf("\nBox Details:\n");
    printf("Length: %.2f\n", boxPtr->length);
    printf("Width: %.2f\n", boxPtr->width);
    printf("Height: %.2f\n", boxPtr->height);

    // Calculate volume and surface area
    printf("\nBox Calculations:\n");
    calculateVolumeAndSurfaceArea(boxPtr);

    return 0;
}
