#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student *students, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int n, i;
    struct Student *students;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();  // Consume the newline character

    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &(students[i].rollno));
        getchar();  // Consume the newline character

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  // Remove the newline character

        printf("Marks: ");
        scanf("%f", &(students[i].marks));
        getchar();  // Consume the newline character
        printf("\n");
    }

    displayStudents(students, n);

    free(students);

    return 0;
}
