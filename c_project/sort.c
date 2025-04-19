#include <stdio.h>
#include <string.h>
#include "sort.h"

void sortStudentsByGPA(Student *students, int count) {
    // Simple bubble sort algorithm
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {// Compare GPA values
            if (students[i].gpa < students[j].gpa) {// Swap if student j has higher GPA than student i
                Student tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
    printf("Sorted by GPA (highest to lowest):\n");
    displayStudents(students, count);
}

void sortStudentsByProgram(Student *students, int count) {
    // Simple bubble sort algorithm
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) { // Use strcmp to compare program names alphabetically
            if (strcmp(students[i].program, students[j].program) > 0) {// Swap if program of student i comes after student j
                Student tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
    printf("Sorted by Program (A-Z):\n");
    displayStudents(students, count);
}
