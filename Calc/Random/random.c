#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game();   
void random1();
void startGame();

int min = 0, max;
int inputNumber;
int difficulty;
int attempts;
float score;
char tryAgain;
char end;

int main() {
    startGame();

    return 0;
}

void startGame() {
    printf("Choose difficulty level:\n");
    printf("Easy (0-25) - enter \"1\"\n");
    printf("Medium (0-50) - enter \"2\"\n");
    printf("Hard (0-100) - enter \"3\"\n");
    scanf("%d", &difficulty);
    
    if (difficulty == 1) {
        max = 25;
    } else if (difficulty == 2) {
        max = 50;
    } else if (difficulty == 3) {
        max = 100;
    } else {
        max = 50;
        printf("Error!\n");
        printf("Difficulty level set to medium (0-50) by default\n");
    }

    printf("Enter a number between 0 and %d\n", max);
    
    random1();
    game(random() % (min - max));
}

void game(int randomNumber) {
    scanf("%d", &inputNumber);
    
    if (inputNumber == randomNumber) {
        attempts += 1;
        score = (float) max / attempts * 10;
        printf("You won!\n");
        printf("Number: %d\n", randomNumber);
        printf("Attempts: %d\n", attempts);
        printf("Score: %f pts\n", score);
        score = 0;
        attempts = 0;
        printf("\"r\" - repeat\n");
        printf("\"q\" - quit\n");
        scanf(" %c", &end);

        if (end == 'r') {
            startGame();
        } else if (end == 'q') {
            printf("Game Over\n");
    }
    } else if (inputNumber > randomNumber) {
        attempts += 1;
        printf("The number is smaller than %d\n", inputNumber);
        game(randomNumber);
    } else if (inputNumber < randomNumber) {
        attempts += 1;
        printf("The number is greater than %d\n", inputNumber);
        game(randomNumber);
    }
}

void random1() {
    srandom(time(NULL));
    int randomNumber = random() % (min - max);
}
