// Enter a positive integer (e.g. ID)  and a valid GPA value (range is 0.0 ~ 4.0)

#include <stdio.h>
#include "utils.h"

// Enter a positive integer
int inputPositiveInt() {
    int val;
    while (1) {
        scanf("%d", &val);
        if (val > 0) return val;
        printf("Invalid input. Enter a positive integer: ");    //
    }
}

// Enter a GPA value
float inputGPA() {
    float gpa;
    while (1) {
        scanf("%f", &gpa);
        if (gpa >= 0.0 && gpa <= 4.0) return gpa;
        printf("Invalid GPA. Enter a value between 0.0 and 4.0: "); 
    }
}
