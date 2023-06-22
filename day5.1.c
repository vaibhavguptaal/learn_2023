#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudentsFromString(const char* input, struct Student* students, int count) {
    int i;
    const char* delimiter = " ";

    for (i = 0; i < count; i++) {
        sscanf(input, "%d %s %f", &students[i].rollno, students[i].name, &students[i].marks);
        input = strchr(input, ' ') + 1;  // Move the input pointer to the next space
    }
}

int main() {
    int n, i;
    struct Student* students;
    char input[100];

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();  // Consume the newline character

    students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter student details in the format 'RollNo Name Marks':\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove the newline character from input
        initializeStudentsFromString(input, &students[i], 1);
    }

    printf("\n\n--- Student Data ---\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
