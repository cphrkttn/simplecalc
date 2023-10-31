#include <stdio.h>
#include <stdlib.h>

    /* Variable declaration */
double sum, quotient, difference, product;
char operator;

    /* Function declaration */
void doAddition(double summand1, double summand2);
void doSubtraction(double minuend, double subtrahend);
void doMultiply(double multiplier, double multiplicand);
void doDivision(double dividend, double divisor);

int main() {

    /* Local variable definition */
    double operand1, operand2;

    /* Print welcome message */
    printf("SimpleCalc v1.0\n");

    /* Ask user for input */
    printf("Please select an operator: (A)dd, (S)ubtract, (M)ultiply, (D)ivide\n");
    operator = getchar();

    printf("First operand? : ");
    scanf("%lf", &operand1);

    printf("Second operand? : ");
    scanf("%lf", &operand2);

    /* Evaluate user input */
    if ( (operator == 'a') || (operator == 'A') ) {
        doAddition(operand1, operand2);
    } else if ( (operator == 's') || (operator == 'S') ) {
        doSubtraction(operand1, operand2);
    } else if ( (operator == 'm') || (operator == 'M') ) {
        doMultiply(operand1, operand2);
    } else if ( (operator == 'd') || (operator == 'D') ) {
        doDivision(operand1, operand2);
    } else {
        fprintf(stderr, "Please select a valid operator...\n");
        exit(EXIT_FAILURE);
    }



    return 0;
}

/* Function definition */

void doAddition(double summand1, double summand2) {
    /* Add stuff together... */
    sum = summand1 + summand2;
    printf("%0.2f + %0.2f = %0.2f\n", summand1, summand2, sum);
}

void doSubtraction(double minuend, double subtrahend) {
    /* Subtract stuff... */
    difference = minuend - subtrahend;
    printf("%0.2f + %0.2f = %0.2f\n", minuend, subtrahend, difference);
}

void doMultiply(double multiplier, double multiplicand) {
    /* Multiply stuff together... */
    product = multiplier * multiplicand;
    printf("%0.2f + %0.2f = %0.2f\n", multiplier, multiplicand, product);
}

void doDivision(double dividend, double divisor) {
    /* Divide stuff apart... complete with error checking */

    if ( divisor == 0 ) {
        fprintf(stderr, "Division by zero! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    quotient = dividend / divisor;
    printf("%0.2f + %0.2f = %0.2f\n", dividend, divisor, quotient);
    exit(EXIT_SUCCESS);
}

