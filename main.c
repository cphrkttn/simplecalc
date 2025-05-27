#include <stdio.h>
#include <stdlib.h>

char oper = '\0';
double operand1 = 0.0;
double operand2 = 0.0;
double result = 0.0;

double doAdd(double a, double b);
double doSub(double a, double b);
double doMul(double a, double b);
double doDiv(double a, double b);
void doInteractive();

int main(int argc, char **argv) {
    if (argc < 2) {
        doInteractive();
    } else if ((*argv[1] == '?') || (*argv[1] == 'h')) {
        printf("Usage: %s <operator> <operand1> <operand2> \n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    if (argc < 4 || argc > 4) {
        fprintf(stderr, "Invalid number of arguments! Please see usage. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 4) {
        oper = *argv[1];
        switch (oper) {
            case 'a':
                result = doAdd(atof( argv[2] ), atof( argv[3] ));
                printf("Result: %0.2f\n", result);
                break;
            case 's':
                result = doSub(atof( argv[2] ), atof( argv[3] ));
                printf("Result: %0.2f\n", result);
                break;
            case 'm':
                result = doMul(atof( argv[2] ), atof( argv[3] ));
                printf("Result: %0.2f\n", result);
                break;
            case 'd':
                result = doDiv(atof( argv[2] ), atof( argv[3] ));
                printf("Result: %0.2f\n", result);
                break;
            default:
                fprintf(stderr, "Invalid input! Please see usage. Exiting...\n");
                exit(EXIT_FAILURE);
        }

    }
}

void doInteractive() {

        printf("Please select an operator: (A)dd, (S)ubtract, (M)ultiply, (D)ivide\n"); // Ask for user input
        oper = getchar();

        // handle errors
        if (!( (oper == 'a' || oper == 'A') || (oper == 's' || oper == 'S') ||
            (oper == 'm' || oper == 'M') || (oper == 'd' || oper == 'D') )) {
            fprintf(stderr, "Invalid operator! Exiting...");
            exit(EXIT_FAILURE);
            }

        printf("Enter a number: ");
        if (scanf("%lf", &operand1) != 1) {
            fprintf(stderr, "Invalid input! Exiting...");
            exit(EXIT_FAILURE);
        }
        printf("Enter another number: ");
        if (scanf("%lf", &operand2) != 1) {
            fprintf(stderr, "Invalid input! Exiting...");
            exit(EXIT_FAILURE);
        }

        switch (oper) {
            case 'a':
                result = doAdd(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 'A':
                result = doAdd(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 's':
                result = doSub(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 'S':
                result = doSub(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 'm':
                result = doMul(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 'M':
                result = doMul(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 'd':
                result = doDiv(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            case 'D':
                result = doDiv(operand1, operand2);
                printf("Result: %0.2f\n", result);
                break;
            default:
                fprintf(stderr, "Unexpected error! exiting...");
                exit(EXIT_FAILURE);
        }

    }

double doAdd(const double a, const double b) {
    return a + b;
}

double doSub(const double a, const double b) {
    return a - b;
}

double doMul(const double a, const double b) {
    return a * b;
}

double doDiv(const double a, const double b) {
    if (!b) {
        fprintf(stderr, "Division by zero\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

