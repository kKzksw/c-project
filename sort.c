#include <stdio.h>
#include <string.h>
#include "sort.h"

void sortStudentsByGPA(Student *students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].gpa < students[j].gpa) {
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
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].program, students[j].program) > 0) {
                Student tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
    printf("Sorted by Program (A-Z):\n");
    displayStudents(students, count);
}
