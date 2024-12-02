#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearInputBuffer()
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int validateInputNumber(int validInput, int* randNum){
            while(validInput != 1 || *randNum > 20){
                printf("Error: Invalid input! Please enter number between (0, to 20) : ");
                clearInputBuffer();
                validInput = scanf("%d", randNum);
            }
        return *randNum;
    }

int main()
{
    srand(time(NULL)); // seeding the rand()

    int secretNum = rand() % 21 ; // random number between 0 and 20 inclusive
    int guessNum = 0, countAttempt = 0, totalAttemptLeft = 4;

    do {

        printf("Guess a number: ");
        int validNum = scanf("%d", &guessNum);

        int validGuessNum = validateInputNumber(validNum, &guessNum);

        guessNum = validGuessNum;


        if(guessNum > secretNum)
            printf("Too High\n");
        else if(guessNum < secretNum)
            printf("Too Low\n");
        countAttempt++;
        if(totalAttemptLeft > 0)
            printf("You have left %d %s\n" , totalAttemptLeft , (totalAttemptLeft != 1) ? "tries": "try");
        totalAttemptLeft--;

    }while( guessNum != secretNum && countAttempt < 5);

    if(guessNum != secretNum && countAttempt >= 5){
        printf("Sorry! You have exceeded the attempt amount. The secrete number was %d.  Try again later\n", secretNum);
        return 1;
    }
    if(guessNum == secretNum ){
         printf("Bingo You got it ! the number is : %d\n", secretNum);
         printf("You have successful in %d trials\n", countAttempt );
    }





    return 0;
}
