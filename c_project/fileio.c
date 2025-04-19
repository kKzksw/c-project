#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

#define STUDENT_FILE "students.txt"
#define PROFESSOR_FILE "professors.txt" //Define two text file names for reading and writing student and professor data.

void saveData(Student *students, int studentCount, Professor *professors, int professorCount) {
    FILE *sf = fopen(STUDENT_FILE, "w");//save and open
    if (!sf) { printf("Error writing students file.\n"); return; }

    fprintf(sf, "%d\n", studentCount);//all
    for (int i = 0; i < studentCount; i++) {
        fprintf(sf, "%d|%s|%s|%.2f|%d", students[i].id, students[i].name,
                students[i].program, students[i].gpa, students[i].supervisorCount);
        for (int j = 0; j < students[i].supervisorCount; j++) {
            fprintf(sf, "|%d", students[i].supervisors[j]->id);
        }
        fprintf(sf, "\n");
    }
    fclose(sf);//every student and their professor id and close

    FILE *pf = fopen(PROFESSOR_FILE, "w");
    if (!pf) { printf("Error writing professors file.\n"); return; }//save and open

    fprintf(pf, "%d\n", professorCount);//all
    for (int i = 0; i < professorCount; i++) {
        fprintf(pf, "%d|%s|%s|%d", professors[i].id, professors[i].name,
                professors[i].department, professors[i].supervisedCount);
        for (int j = 0; j < professors[i].supervisedCount; j++) {
            fprintf(pf, "|%d", professors[i].supervised[j]->id);
        }
        fprintf(pf, "\n");//every professor and their student id and close
    }
    fclose(pf);
}

void loadData(Student **students, int *studentCount, Professor **professors, int *professorCount) {
    FILE *sf = fopen(STUDENT_FILE, "r");
    if (sf) {
        fscanf(sf, "%d\n", studentCount);
        *students = malloc(sizeof(Student) * (*studentCount));//Allocation of memory
        for (int i = 0; i < *studentCount; i++) {
            Student *s = &(*students)[i];
            s->supervisorCount = 0;
            char line[512];
            fgets(line, sizeof(line), sf);//whole line
            char *token = strtok(line, "|");
            s->id = atoi(token);
            token = strtok(NULL, "|");
            strcpy(s->name, token);
            token = strtok(NULL, "|");
            strcpy(s->program, token);
            token = strtok(NULL, "|");
            s->gpa = atof(token);
            token = strtok(NULL, "|");
            s->supervisorCount = atoi(token);
            for (int j = 0; j < s->supervisorCount; j++) {
                token = strtok(NULL, "|");
                s->supervisors[j] = (Professor*)(long)atoi(token); 
            }
        }
        fclose(sf);// Store the professor ID 
    }//information of every student

    FILE *pf = fopen(PROFESSOR_FILE, "r");
    if (pf) {
        fscanf(pf, "%d\n", professorCount);
        *professors = malloc(sizeof(Professor) * (*professorCount));
        for (int i = 0; i < *professorCount; i++) {
            Professor *p = &(*professors)[i];
            p->supervisedCount = 0;
            char line[512];
            fgets(line, sizeof(line), pf);
            char *token = strtok(line, "|");
            p->id = atoi(token);
            token = strtok(NULL, "|");
            strcpy(p->name, token);
            token = strtok(NULL, "|");
            strcpy(p->department, token);
            token = strtok(NULL, "|");
            p->supervisedCount = atoi(token);
            for (int j = 0; j < p->supervisedCount; j++) {
                token = strtok(NULL, "|");
                p->supervised[j] = (Student*)(long)atoi(token); 
            }
        }
        fclose(pf);// Store the student ID (temporarily as a pointer integer first)
    }

    for (int i = 0; i < *studentCount; i++) {
        Student *s = &(*students)[i];
        for (int j = 0; j < s->supervisorCount; j++) {
            int pid = (int)(long)(s->supervisors[j]);
            for (int k = 0; k < *professorCount; k++) {
                if ((*professors)[k].id == pid) {
                    s->supervisors[j] = &(*professors)[k];
                }
            }
        }
    }//Student Supervisor Pointing to the object of the professor

    for (int i = 0; i < *professorCount; i++) {
        Professor *p = &(*professors)[i];
        for (int j = 0; j < p->supervisedCount; j++) {
            int sid = (int)(long)(p->supervised[j]);
            for (int k = 0; k < *studentCount; k++) {
                if ((*students)[k].id == sid) {
                    p->supervised[j] = &(*students)[k];
                }
            }
        }
    }//professor Supervisor Pointing to the object of the student
}
