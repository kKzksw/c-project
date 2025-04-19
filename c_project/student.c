#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "utils.h"

void addStudent(Student **students, int *count) {
    Student newStudent;
    printf("Enter ID (positive): ");
    newStudent.id = inputPositiveInt();

    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);

    printf("Enter Program: ");
    scanf(" %[^\n]", newStudent.program);

    printf("Enter GPA (0.0 - 4.0): ");
    newStudent.gpa = inputGPA();

    newStudent.supervisorCount = 0;
    for (int i = 0; i < MAX_SUPERVISORS; i++) {
        newStudent.supervisors[i] = NULL;
    }

    *students = realloc(*students, (*count + 1) * sizeof(Student));
    (*students)[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}

void displayStudents(Student *students, int count) {
    printf("\n--- Students ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Program: %s | GPA: %.2f | Supervisors: %d\n",
               students[i].id, students[i].name, students[i].program,
               students[i].gpa, students[i].supervisorCount);
    }
}

void searchStudent(Student *students, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found Student: %s | Program: %s | GPA: %.2f\n",
                   students[i].name, students[i].program, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void modifyStudent(Student *students, int count) {
    int id;
    printf("Enter Student ID to modify: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new Program: ");
            scanf(" %[^\n]", students[i].program);
            printf("Enter new GPA: ");
            students[i].gpa = inputGPA();
            printf("Student updated.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent(Student **students, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if ((*students)[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }
            (*count)--;
            *students = realloc(*students, (*count) * sizeof(Student));
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

