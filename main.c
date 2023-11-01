#include <stdio.h>
#include <stdlib.h>

    /* Global variable initialization */
char operator = '\0';

    /* Function declaration */
double doAddition(double summand1, double summand2);
double doSubtraction(double minuend, double subtrahend);
double doMultiply(double multiplier, double multiplicand);
double doDivision(double dividend, double divisor);
void doInteractive(void);

int main(int argc, char *argv[]) {

    /* Check if command line args are passed. If none are present, continue interactively. */
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
            default:
                fprintf(stderr, "Invalid operator! Please see usage. Exiting...\n");
                exit(EXIT_FAILURE);
        };
    } else if (argc < 4 || argc > 4) {
        fprintf(stderr, "Invalid number of arguments! Please see usage. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/* Function definition */

void doInteractive(void) {
        /* Local variable definition */
    double operand1, operand2;

        /* Print welcome message */
    printf("SimpleCalc v1.2 by ex0\n");


    /* Ask user for input */
    printf("Please select an operator: (A)dd, (S)ubtract, (M)ultiply, (D)ivide\n");
    operator = getchar();

    /* Check if operator is valid */
    if (!( (operator == 'a' || operator == 'A') || (operator == 's' || operator == 'S') || (operator == 'm' || operator == 'M') || (operator == 'd' || operator == 'D') )) {
        fprintf(stderr, "Invalid operator! Please select a valid operator from the list...\n");
        exit(EXIT_FAILURE);
    }

    printf("First operand? : ");
    if (scanf("%lf", &operand1) != 1) {
        fprintf(stderr, "Invalid input! Please provide a number...\n");
        exit(EXIT_FAILURE);
    }

    printf("Second operand? : ");
    if (scanf("%lf", &operand2) != 1) {
        fprintf(stderr, "Invalid input! Please provide a number...\n");
        exit(EXIT_FAILURE);
    }

    /* Evaluate user input */
    switch (operator) {
        case 'a':
            doAddition(operand1, operand2);
            break;
        case 'A':
            doAddition(operand1, operand2);
            break;
        case 's':
            doSubtraction(operand1, operand2);
            break;
        case 'S':
            doSubtraction(operand1, operand2);
            break;
        case 'm':
            doMultiply(operand1, operand2);
            break;
        case 'M':
            doMultiply(operand1, operand2);
            break;
        case 'd':
            doDivision(operand1, operand2);
            break;
        case 'D':
            doDivision(operand1, operand2);
            break;
    }

}

double doAddition(const double summand1, const double summand2) {
    /* Add stuff together... */
    double sum = summand1 + summand2;
    printf("%0.2f + %0.2f = %0.2f\n", summand1, summand2, sum);
    return sum;
}

double doSubtraction(const double minuend, const double subtrahend) {
    /* Subtract stuff... */
    double difference = minuend - subtrahend;
    printf("%0.2f - %0.2f = %0.2f\n", minuend, subtrahend, difference);
    return difference;
}

double doMultiply(const double multiplier, const double multiplicand) {
    /* Multiply stuff together... */
    double product = multiplier * multiplicand;
    printf("%0.2f x %0.2f = %0.2f\n", multiplier, multiplicand, product);
    return product;
}

double doDivision(const double dividend, const double divisor) {
    /* Divide stuff apart... complete with error checking */

    if ( divisor == 0 ) {
        fprintf(stderr, "Division by zero! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    double quotient = dividend / divisor;
    printf("%0.2f / %0.2f = %0.2f\n", dividend, divisor, quotient);
    return quotient;
}

