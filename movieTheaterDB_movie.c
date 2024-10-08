
// Created by Marwa on 2023-11-29.

#include "movieTheaterDB_movie.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Delete Structure needs to be here and outside of main movie func
struct movie *delete(struct movie *head) {
    int c;
    struct movie *p;
    if (p != NULL) {
        struct movie *cur, *prev;
        for (cur = head, prev = NULL;
             cur != NULL && cur->code != c;
             prev = cur, cur = cur->next);
        if (cur == NULL)
            return head;
        if (prev == NULL)
            head = head->next;
        else
            prev->next = cur->next;
        free(cur);
        return head;
    }
    return 0;
}
// Main movie function
int movie() {

    // Variables that we will need
    char op;
    int j = 0;
    struct movie movie[200]; //create movie linked list

    int user_int, i;



    // Goto which leads us to menu
    menu:
    menu();
    scanf("%s", &op);

    // While loop for all movie prompts
    while (op != 'q') {

        // Insert(i) Prompt
        if (op == 'i') {
            printf("    Enter movie code: ");
            scanf("%d", &user_int);

            // Checks if user input code has already been imputted
            if (user_int >= 0) {
                for (int a = 0; a < j; a++) {
                    if (movie[a].code == user_int) {
                        printf("Movie already exists.\n\n");
                        goto menu;
                    }
                }
                movie[j].code = user_int;
            } else {
                printf("Movie Already Exists \n\n");
                goto menu;
            }

                // Checks if user input name is within set range and then stores in dict
                printf("    Enter movie name: ");
                scanf("%s", movie[j].name);
                if (strlen(movie[j].name) <= 25) {
                } else {
                    printf("Name longer than acceptable length \n\n");
                    goto menu;
                }

                //for genre
                printf("    Enter movie genre: ");
                scanf("%s", movie[j].genre);


                //Asking for rating to get rating from 1.0 - 10.0
                printf("    Enter movie rating 1.0-10.0: ");
                scanf("%f", &movie[j].rating); //fix for 25 chars
                //check if rating is valid
                if (movie[j].rating < 1.0 || movie[j].rating > 10.0) {
                    printf("Rating is invalid. Must be between 1.0 and 10.0.\n");
                    goto menu; // Return to the menu

                }

                    j++;
                    goto menu;
            }

            // Search(s) prompt option
        if (op == 's') {

            // local variables
            int search;
            int index = -1;

            // Prints for usr instructions
            printf("    Enter movie code: ");
            scanf("%d", &search);

            // Initializes variable
            // but only if found
            for (int b = 0; b < j; b++) {
                if (movie[b].code == search) {
                    index = b;
                }
            }

            //  If found
            if (index > -1) {
                printf("movie Code\t\tmovie Name\t\tMovie Genre\t\tMovie Rating \n");
                printf("%d\t\t\t%-24s%-16s%.1f\n", movie[index].code, movie[index].name, movie[index].genre,
                       movie[index].rating);
            } else {
                printf("Sorry, there is no movie with that code.\n");
            }
            goto menu;
        }


        // Update(u) prompt option
        if (op == 'u') {


            int search;
            int index = -1;

            // Checking if code is already in array
            printf("    Enter movie code: ");
            scanf("%d", &search);
            for (int e = 0; e < j; e++) {
                if (movie[e].code == search) {
                    index = e;
                }
            }
            // Checks if input is correct then if so, updates the info
            if (index > -1) {
                printf("    Enter movie name: ");
                scanf("%s", movie[index].name);
                if (strlen(movie[index].name) < 26) {
                } else {
                    // If not within range
                    printf("Name longer than acceptable length \n\n");
                    goto menu;
                }

                } else {
                    printf("There is no movie with that code\n");
                    goto menu;
                }

                goto menu;
            }

        // Print(p) prompt option
        if (op == 'p') {

            // Prints everything in order
            printf("|Movie Code|\t\t|Movie Name|\t\t|Movie Genre|\t|Movie Rating|\n");
            for (int c = 0; c < j + 1; c++) {
               // Printing in proper format matching above print statment
                printf("%d\t\t\t%-24s%-16s%.1f\n", movie[c].code, movie[c].name, movie[c].genre, movie[c].rating);
            }
            // Return to menu afterwards
            goto menu;
        }

        // Erase(e) option
        if (op == 'e') {

            int search;
            int index = -1;

            printf("    Enter movie code: ");
            scanf("%d", &search);

            // If index is found in array
            for (i = 0; i < j; i++) {
                if (movie[i].code == search) {
                    index = i;
                }
            }

            // After deleting, everything will be blank as instructed
            if (index >= -1) {
                movie[index].code = 0;
                strcpy(movie[index].name, ""); // Resetting name to an empty string
                strcpy(movie[index].genre, ""); // Resetting genre to an empty string
                movie[index].rating = 0;

                // Reassuring user
                printf("Operation Completed \n");
            } else {
                // if not correct code
                printf("There is no movie with that code.\n");
                goto menu;
            }
            goto menu;
        }

            return 0;

        }

        return 0;

    }

