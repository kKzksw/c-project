#include <stdio.h>
#include "utils.h"

int inputPositiveInt() {
    int val;
    while (1) {
        scanf("%d", &val);
        if (val > 0) return val;
        printf("Invalid input. Enter a positive integer: ");
    }
}

float inputGPA() {
    float gpa;
    while (1) {
        scanf("%f", &gpa);
        if (gpa >= 0.0 && gpa <= 4.0) return gpa;
        printf("Invalid GPA. Enter a value between 0.0 and 4.0: ");
    }
}
