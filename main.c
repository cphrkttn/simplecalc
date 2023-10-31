#include <stdio.h>
#include <stdlib.h>

    /* Variable declaration */
double sum = 0, quotient = 0, difference = 0, product = 0;
char operator = '\0';

    /* Function declaration */
void doAddition(double summand1, double summand2);
void doSubtraction(double minuend, double subtrahend);
void doMultiply(double multiplier, double multiplicand);
void doDivision(double dividend, double divisor);
void doInteractive();

int main(int argc, char *argv[]) {

    /* Check if command line args are passed. If none are present, continue interactively. Throw error if too many or few arguements are passed. This is probably a dirty hack. */
    if (argc == 1) {
        doInteractive();

    } else if (*argv[1] == '?') {
    printf("Usage: simplecalc <space separated arguments here>\n");
    printf("Example: simplecalc a 2 2\n");
    printf("Result: Add 2 + 2\n");
    exit(EXIT_SUCCESS);

    } else if (argc == 4) {
        operator = *argv[1];
        switch (operator) {
            case 'a':
                doAddition(atof( argv[2] ), atof( argv[3] ));
                break;
            case 's':
                doSubtraction(atof( argv[2] ), atof( argv[3] ));
                break;
            case 'm':
                doMultiply(atof( argv[2] ), atof( argv[3] ));
                break;
            case 'd':
                doDivision(atof( argv[2] ), atof( argv[3] ));
                break;
        };
    } else if (argc < 4) {
        fprintf(stderr, "Too few arguements!");
        exit(EXIT_FAILURE);
    } else if (argc > 4) {
        fprintf(stderr, "Too many arguements!");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/* Function definition */

void doInteractive() {
        /* Local variable definition */
    double operand1, operand2;

        /* Print welcome message */
    printf("SimpleCalc v1.2 by ex0\n");


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

}

void doAddition(double summand1, double summand2) {
    /* Add stuff together... */
    sum = summand1 + summand2;
    printf("%0.2f + %0.2f = %0.2f\n", summand1, summand2, sum);
    exit(EXIT_SUCCESS);
}

void doSubtraction(double minuend, double subtrahend) {
    /* Subtract stuff... */
    difference = minuend - subtrahend;
    printf("%0.2f - %0.2f = %0.2f\n", minuend, subtrahend, difference);
    exit(EXIT_SUCCESS);
}

void doMultiply(double multiplier, double multiplicand) {
    /* Multiply stuff together... */
    product = multiplier * multiplicand;
    printf("%0.2f x %0.2f = %0.2f\n", multiplier, multiplicand, product);
    exit(EXIT_SUCCESS);
}

void doDivision(double dividend, double divisor) {
    /* Divide stuff apart... complete with error checking */

    if ( divisor == 0 ) {
        fprintf(stderr, "Division by zero! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    quotient = dividend / divisor;
    printf("%0.2f / %0.2f = %0.2f\n", dividend, divisor, quotient);
    exit(EXIT_SUCCESS);
}

