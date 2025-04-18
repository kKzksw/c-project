#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "professor.h"
#include "utils.h"
#include "fileio.h"
#include "sort.h"

int main() {
    Student *students = NULL;
    int studentCount = 0;

    Professor *professors = NULL;
    int professorCount = 0;

    // 启动时加载数据
    loadData(&students, &studentCount, &professors, &professorCount);

    int choice;
    do {
        printf("\n====== EM Lyon Student & Professor Management ======\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Add Professor\n");
        printf("7. Display Professors\n");
        printf("8. Assign Student to Professor (Co-supervision allowed)\n");
        printf("9. Display Students supervised by a Professor\n");
        printf("10. Sort Students by GPA\n");
        printf("11. Sort Students by Program\n");
        printf("0. Exit (Save and Quit)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(&students, &studentCount); break;
            case 2: displayStudents(students, studentCount); break;
            case 3: {
                int id;
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                searchStudent(students, studentCount, id);
                break;
            }
            case 4: modifyStudent(students, studentCount); break;
            case 5: {
                int id;
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&students, &studentCount, id);
                break;
            }
            case 6: addProfessor(&professors, &professorCount); break;
            case 7: displayProfessors(professors, professorCount); break;
            case 8: assignStudentToProfessor(professors, professorCount, students, studentCount); break;
            case 9: displaySupervisedStudents(professors, professorCount); break;
            case 10: sortStudentsByGPA(students, studentCount); break;
            case 11: sortStudentsByProgram(students, studentCount); break;
            case 0:
                printf("Saving data...\n");
                saveData(students, studentCount, professors, professorCount);
                printf("Data saved. Goodbye!\n");
                break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    // 程序结束时释放内存
    free(students);
    free(professors);

    return 0;
}

