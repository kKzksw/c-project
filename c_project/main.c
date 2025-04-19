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

    // Load data
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
            case 1: addStudent(&students, &studentCount); break;     // Add students, update the number of students
            case 2: displayStudents(students, studentCount); break;   // Print students' information
            case 3: {
                int id;
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                searchStudent(students, studentCount, id);   // Search student
                break;
            }
            case 4: modifyStudent(students, studentCount); break;   // Motify students' content
            case 5: {
                int id;
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&students, &studentCount, id);   // Delete student by using id
                break;
            }
            case 6: addProfessor(&professors, &professorCount); break;   // Add prof
            case 7: displayProfessors(professors, professorCount); break;   // Print prof's information
            case 8: assignStudentToProfessor(professors, professorCount, students, studentCount); break;  // Assign students to professors (multiple tutors allowed)
            case 9: displaySupervisedStudents(professors, professorCount); break;   // Displays the students supervised by a professor
            case 10: sortStudentsByGPA(students, studentCount); break;   // Sort by GPA
            case 11: sortStudentsByProgram(students, studentCount); break;   // Sort by Programe name alphabetically
            case 0:
                printf("Saving data...\n");
                saveData(students, studentCount, professors, professorCount);   // Exit the program and Save data
                printf("Data saved. Goodbye!\n");
                break;
            default: printf("Invalid choice. Try again.\n");   .// Error option prompted
        }

    } while (choice != 0);

    // Release 
    free(students);
    free(professors);

    return 0;
}

