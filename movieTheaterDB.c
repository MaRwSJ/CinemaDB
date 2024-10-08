// Created by Marwa Jamali
// 2023-11-28
// CS2211A
// Assignment 5

#include "movieTheaterDB_actor.c"
#include "movieTheaterDB_movie.c"
#include "movieTheaterDB.h"
#include<stdio.h>
int main(){
    char op;
    start();


// Calls Menu Display

    display:
    display();
    scanf("%s", &op);

    // Quit prompt - if user wants to quit the program
    while (op != 'q'){

        // If the user needs "help" at first prompt
        // This statemnet will print
        if (op == 'h'){

            printf("\nWelcome to the Updated Movie Theater Database! "
                   "Now that you're here, you will be able to control, "
                   "Actors and movies included within the movie theater.\n"
                   "You can choose from one of the following prompts: \n"
                   "Press 'm' to Control Movie \n"
                   "Press 'a' to Control Actors\n"
                   "Press 'q' to Quit Program\n");
        }

        // movie Prompt, if m is imputted after asked for,
        // it will Call Function within movieTheaterDB_movie.c
        if (op == 'm'){
            printf("\nYou Are now in Control of the Movies");
            printf("\nPrompts: Insert(i), Select(s), Update(u), Print(p) or Erase(e)\n");
            movie();
        }

        // actor Prompt will then direct the user to what we had the function as in movieTheaterDB_actor.c
        if (op == 'a'){
            printf("\nYou Are Now in Control of the Actors");
            printf("\n Insert(i), Select(s), Update(u), Print(p) or Erase(e)\n");
            act();
        }

        // Calling Display
        goto display;

    }

    return 0;
}



