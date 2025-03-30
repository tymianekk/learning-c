#include <stdio.h>

float num1, num2;
char operator;

int main() {
    printf("Wpisz pierwszą liczbę: ");
    scanf("%f", &num1);

    printf("Wpisz (+)/(-)/(*)/(/): ");
    scanf(" %c", &operator);

    printf("Wpisz drugą liczbę: ");
    scanf("%f", &num2);

    if (operator == '+') {
        printf("Wynik: %f\n", num1 + num2);
    } else if (operator == '-') {
        printf("Wynik: %f\n", num1 - num2);
    } else if (operator == '*') {
        printf("Wynik: %f\n", num1 * num2);
    } else if (operator == '/') {
        if (num2 != 0) {
            printf("Wynik: %f\n", num1 / num2);
        } else {
            printf("Błąd: dzielenie przez zero!\n");
        }
    } else {
        printf("Niepoprawny operator!\n");
    }

    return 0;
}
