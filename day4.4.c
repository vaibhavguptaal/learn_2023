#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char *name;
    int age;
};

int main() {
    int n, i;
    struct Student *students;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &(students + i)->rollNumber);

        printf("Enter Name: ");
        char name[50];
        scanf("%s", name);
        (students + i)->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy((students + i)->name, name);

        printf("Enter Age: ");
        scanf("%d", &(students + i)->age);
    }

    printf("\n\n--- Student Data ---\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", (students + i)->rollNumber);
        printf("Name: %s\n", (students + i)->name);
        printf("Age: %d\n", (students + i)->age);
    }

    for (i = 0; i < n; i++) {
        free((students + i)->name);
    }
    free(students);

    return 0;
}
