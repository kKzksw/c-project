#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SUPERVISORS 3

typedef struct Professor Professor;

typedef struct {
    int id;
    char name[100];
    char program[100];
    float gpa;
    Professor* supervisors[MAX_SUPERVISORS];
    int supervisorCount;
} Student;

void addStudent(Student **students, int *count);
void displayStudents(Student *students, int count);
void searchStudent(Student *students, int count, int id);
void modifyStudent(Student *students, int count);
void deleteStudent(Student **students, int *count, int id);

#endif
