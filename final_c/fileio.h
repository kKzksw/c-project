#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"
#include "professor.h"

void saveData(Student *students, int studentCount, Professor *professors, int professorCount);
void loadData(Student **students, int *studentCount, Professor **professors, int *professorCount);

#endif