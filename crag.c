#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice();

int play_computer();

int play_user();

void scoresheet(int, int);


int roll_a_dice() {
//    generating random numbers for the dice.
    int random;


    return random = (rand() % 6) + 1;;
}


int play_user() {
    int dice_1, dice_2, dice_3;
    dice_1 = roll_a_dice();
    dice_2 = roll_a_dice();
    dice_3 = roll_a_dice();

    printf("You got:[dice1]:%d [dice2]:%d [dice3]:%d", dice_1, dice_2, dice_3);

    char response;

//    if to roll dice again.

    printf("\nShall I roll for you (Y/N)?\n");
    scanf("\n%c", &response);

    int finish = 0, temp_a, temp_b;

//    repeat if Y or N is not entered
    while (finish != 1) {
        if (response == 'Y') {
            fflush(stdin);
            printf("Which ones do you want to keep?\n");
            scanf("\n%d %d", &temp_a, &temp_b);
            if (temp_a == 1 && temp_b == 2 || temp_a == 2 && temp_b == 1) {
                dice_3 = roll_a_dice();
                finish = 1;
                printf("You got:[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);
            } else if (temp_a == 3 && temp_b == 1 || temp_a == 1 && temp_b == 3) {
                dice_2 = roll_a_dice();
                finish = 1;
                printf("You got:[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);
            } else if (temp_a == 2 && temp_b == 3 || temp_a == 3 && temp_b == 2) {
                dice_1 = roll_a_dice();
                finish = 1;
                printf("You got:[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);
            }
            else{
                printf("Wrong input!\n");
            }

//            printf("You got:[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);

        } else if (response == 'N') {
            finish = 1;
        } else {
            fflush(stdin);
            printf("Sorry, I don't understand!\n");
            printf("Shall I roll for you (Y/N)?\n");
            scanf("\n%c", &response);
            finish = 0;

        }
    }
//  calculating the score

    int your_score;
    if ((dice_1 == dice_2 || dice_2 == dice_3) && dice_1 + dice_2 + dice_3 == 13) {
        your_score = 50;
        printf("\nGrag!");
    } else if (dice_1 + dice_2 + dice_3 == 13) {
        your_score = 26;

    } else if (dice_1 == dice_2 && dice_2 == dice_3) {
        your_score = 25;

    } else if (dice_1 == 1 && dice_2 == 2 && dice_3 == 3) {
        your_score = 20;

    } else if (dice_1 == 4 && dice_2 == 5 && dice_3 == 6) {
        your_score = 20;

    } else if (dice_1 % 2 != 0 && dice_2 % 2 != 0 && dice_3 % 2 != 0) {
        your_score = 20;

    } else if (dice_1 % 2 == 0 && dice_2 % 2 == 0 && dice_3 % 2 == 0) {
        your_score = 20;

    } else
        your_score = dice_1 + dice_2 + dice_3;

    return your_score;
}


int play_computer() {
    int dice_1 = roll_a_dice(), dice_2 = roll_a_dice(), dice_3 = roll_a_dice();
    printf("\nI rolled them and I got:[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);

    if (dice_1 == 4 && dice_2 == 5 && dice_3 != 6) {
        dice_3 = roll_a_dice();
        printf("Rolled dice 3\n");
        printf("[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);
    } else if (dice_1 != 4 && dice_2 == 5 && dice_3 == 6) {
        dice_1 = roll_a_dice();
        printf("Rolled dice 1\n");
        printf("[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);
    } else if (dice_1 == 4 && dice_2 != 5 && dice_3 == 6) {
        dice_2 = roll_a_dice();
        printf("[dice1]:%d [dice2]:%d [dice3]:%d\n", dice_1, dice_2, dice_3);
    }


    //  calculating the score

    int my_score;
    if ((dice_1 == dice_2 || dice_2 == dice_3) && dice_1 + dice_2 + dice_3 == 13) {
        my_score = 50;
        printf("\nGrag!\n");
    } else if (dice_1 + dice_2 + dice_3 == 13) {
        my_score = 26;

    } else if (dice_1 == dice_2 && dice_2 == dice_3) {
        my_score = 25;

    } else if (dice_1 == 1 && dice_2 == 2 && dice_3 == 3) {
        my_score = 20;

    } else if (dice_1 == 4 && dice_2 == 5 && dice_3 == 6) {
        my_score = 20;

    } else if (dice_1 % 2 != 0 && dice_2 % 2 != 0 && dice_3 % 2 != 0) {
        my_score = 20;

    } else if (dice_1 % 2 == 0 && dice_2 % 2 == 0 && dice_3 % 2 == 0) {
        my_score = 20;

    } else
        my_score = dice_1 + dice_2 + dice_3;
    return my_score;
}


void scoresheet(int total_user, int total_computer) {
    printf("\nMy score %d \t Your score %d\n", total_computer, total_user);
}

int main() {
    int num_rounds, dice_user, dice_computer, i, j, k, l;
    printf("Welcome to Crag game.\nLet's get started.\n\n");


// number of rounds and determine who will start the game.

    printf("How many rounds would you like to play? ");
    scanf("%d", &num_rounds);

    srand(time(NULL));
    dice_user = roll_a_dice();
    dice_computer = roll_a_dice();
    while(dice_user == dice_computer){
        dice_user = roll_a_dice();
        dice_computer = roll_a_dice();
    }

    printf("\nI have rolled the dice and got %d!\n", dice_computer);
    printf("I have rolled the dice for you and you got %d!\n\n", dice_user);
//
//if(dice_user == dice_computer){
//    dice_user = roll_a_dice();
//    dice_computer = roll_a_dice();
//}

    int my_score, user_score, total_user = 0, total_computer = 0;
    if (dice_user > dice_computer) {

        for (i = 1; i <= num_rounds; i++) {
            printf("\nRound %d,   --  your turn:\n", i);
            printf("----------------------------------------------------------------------------------------\n");
            srand(time(NULL));
            user_score = play_user();
            total_user += user_score;
            printf("Your score:%d    Total score:%d\n", user_score, total_user);

            printf("\n\nRound %d,   --  My turn:\n", i);
            printf("------------------------------------------------------------------------------------------\n");
            my_score = play_computer();
            total_computer += my_score;
            printf("My score:%d    Total score:%d\n\n", my_score, total_computer);

            printf("Our scoresheet after round %d:\n",i);
            printf("------------------------------------\n");
            scoresheet(total_user, total_computer);
        }
    } else if (dice_computer > dice_user) {

        for (k = 1; k <= num_rounds; k++) {
            printf("\n\nRound %d    --  My turn.\n", k);
            printf("-----------------------------------------------------------------------------------------\n");
            srand(time(NULL));
            my_score = play_computer();
            total_computer += my_score;
            printf("My score:%d    Total score:%d\n", my_score, total_computer);

            printf("\n\nRound %d  --  Your Turn.\n",k);
            printf("-----------------------------------------------------------------------------------------\n");
            user_score = play_user();
            total_user += user_score;
            printf("Your score:%d    Total score:%d\n\n", user_score, total_user);

            printf("our scoresheet after round %d",k);
            printf("--------------------------------\n");
            scoresheet(total_user, total_computer);


        }
    }


    if(total_user > total_computer)
        printf("\nCongratulations! You are the winner!");
    else if(total_computer > total_user)
        printf("\nI am the winner!");

    else
        printf("\nIt was a tie. We both won.");

    return 0;
}
