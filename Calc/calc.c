#include <stdio.h>

float num1, num2;
char operator;

int main() {
    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter an operator (+)/(-)/(*)/(/): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    if (operator == '+') {
        printf("Result: %f\n", num1 + num2);
    } else if (operator == '-') {
        printf("Result: %f\n", num1 - num2);
    } else if (operator == '*') {
        printf("Result: %f\n", num1 * num2);
    } else if (operator == '/') {
        if (num2 != 0) {
            printf("Result: %f\n", num1 / num2);
        } else {
            printf("Error: division by zero!\n");
        }
    } else {
        printf("Invalid operator!\n");
    }

    return 0;
}
