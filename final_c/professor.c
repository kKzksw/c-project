#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"
#include "utils.h"

void addProfessor(Professor **professors, int *count) {
    Professor newProf;
    printf("Enter Professor ID (positive): ");
    newProf.id = inputPositiveInt();

    printf("Enter Name: ");
    scanf(" %[^\n]", newProf.name);

    printf("Enter Department: ");
    scanf(" %[^\n]", newProf.department);

    newProf.supervisedCount = 0;
    for (int i = 0; i < MAX_SUPERVISED; i++) {
        newProf.supervised[i] = NULL;
    }

    *professors = realloc(*professors, (*count + 1) * sizeof(Professor));
    (*professors)[*count] = newProf;
    (*count)++;

    printf("Professor added successfully!\n");
}

void displayProfessors(Professor *professors, int count) {
    printf("\n--- Professors ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Department: %s | Supervising: %d students\n",
               professors[i].id, professors[i].name,
               professors[i].department, professors[i].supervisedCount);
    }
}

void assignStudentToProfessor(Professor *professors, int profCount, Student *students, int studCount) {
    int pid, sid;
    printf("Enter Professor ID: ");
    scanf("%d", &pid);
    printf("Enter Student ID to assign: ");
    scanf("%d", &sid);

    Professor *prof = NULL;
    Student *stud = NULL;

    for (int i = 0; i < profCount; i++) {
        if (professors[i].id == pid) {
            prof = &professors[i];
            break;
        }
    }
    if (!prof) {
        printf("Professor not found.\n");
        return;
    }
    if (prof->supervisedCount >= MAX_SUPERVISED) {
        printf("This professor already supervises %d students.\n", MAX_SUPERVISED);
        return;
    }

    for (int i = 0; i < studCount; i++) {
        if (students[i].id == sid) {
            stud = &students[i];
            break;
        }
    }
    if (!stud) {
        printf("Student not found.\n");
        return;
    }

    // 检查学生是否已经被这个教授指导过
    for (int i = 0; i < prof->supervisedCount; i++) {
        if (prof->supervised[i]->id == stud->id) {
            printf("This student is already supervised by this professor.\n");
            return;
        }
    }

    // 检查学生是否还能被共导
    if (stud->supervisorCount >= MAX_SUPERVISORS) {
        printf("This student already has %d supervisors (maximum).\n", MAX_SUPERVISORS);
        return;
    }

    // 互相添加
    prof->supervised[prof->supervisedCount++] = stud;
    stud->supervisors[stud->supervisorCount++] = prof;

    printf("Student assigned successfully for supervision.\n");
}

void displaySupervisedStudents(Professor *professors, int count) {
    int pid;
    printf("Enter Professor ID: ");
    scanf("%d", &pid);

    for (int i = 0; i < count; i++) {
        if (professors[i].id == pid) {
            Professor *p = &professors[i];
            printf("\n--- Students supervised by Professor %s ---\n", p->name);
            if (p->supervisedCount == 0) {
                printf("No students assigned.\n");
            }
            for (int j = 0; j < p->supervisedCount; j++) {
                Student *s = p->supervised[j];
                printf("ID: %d | Name: %s | Program: %s | GPA: %.2f\n",
                       s->id, s->name, s->program, s->gpa);
            }
            return;
        }
    }
    printf("Professor not found.\n");
}
