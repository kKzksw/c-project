#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "student.h"

#define MAX_SUPERVISED 10

typedef struct Professor{
    int id;
    char name[100];
    char department[100];
    Student* supervised[MAX_SUPERVISED];
    int supervisedCount;
} Professor;

void addProfessor(Professor **professors, int *count);
void displayProfessors(Professor *professors, int count);
void assignStudentToProfessor(Professor *professors, int profCount, Student *students, int studCount);
void displaySupervisedStudents(Professor *professors, int count);

#endif
