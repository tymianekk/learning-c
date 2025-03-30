#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game();   
void random1();
void startGame();

int min = 0, max;
int inputNumber;
int difficulty;
int proby;
float score;
char tryAgain;
char start;
char end;

int main() {
    printf("Najlepszy wynik:\n");
    printf("Wpisz \"s\" aby rozpocząć: ");
    scanf("%c", &start);
    if (start == 's') {
        startGame();
    }
    printf("\"r\" - powtórz\n");
    printf("\"p\" - powrót do menu głównego\n");
    printf("\"z\" - zakończ\n");
    scanf("%c", &end);

    if (end == 'r')
    {
        startGame();
    } else if (end == 'p')
    {
        main();
    } else if (end == 'z')
    {
        printf("Zakończono\n");
    }

    return 0;
}

void startGame() {
    printf("Wybierz poziom trudności:\n");
    printf("Łatwy (0-25) wpisz \"1\"\n");
    printf("Średni (0-50) wpisz \"2\"\n");
    printf("Trudny (0-100) wpisz \"3\"\n");
    scanf("%d", &difficulty);
    if (difficulty == 1)
    {
        max = 25;
    } else if (difficulty == 2) {
        max = 50;
    } else if (difficulty == 3) {
        max = 100;
    } else {
        max = 50;
        printf("Error!\n");
        printf("Poziom trudności domyślnie ustawiony na średni (0-50)\n");
    }

    printf("Wpisz liczbę od 0 do %d\n", max);
    
    random1();
    game(random() % (min - max));
}

void game(int randomNumber) {

    scanf("%d", &inputNumber);
    if (inputNumber == randomNumber)
    {
        proby += 1;
        score = (float) max / proby * 10;
        printf("Wygrałeś!\n");
        printf("Liczba: %d\n", randomNumber);
        printf("Liczba prób: %d\n", proby);
        printf("Wynik: %f pkt\n", score);
        score = 0;
    } else if (inputNumber > randomNumber) {
        proby += 1;
        printf("Liczba jest mniejsza niż %d\n", inputNumber);
        game(randomNumber);
    } else if (inputNumber < randomNumber)
    {
        proby += 1;
        printf("Liczba jest większa niż %d\n", inputNumber);
        game(randomNumber);
    }
}

void random1() {
    srandom(time(NULL));
    int randomNumber = random() % (min - max);
}