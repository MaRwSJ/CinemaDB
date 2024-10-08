//
// Created by Marwa on 2023-11-28.
//
#include "movieTheaterDB_actor.h"
#include <stdio.h>
#include <string.h>

// Main function act - actor
int act(){

    // Variables that will be useful
    char op;
    int j=0;
    struct actor actor[2200];
    int user_int, i;
    char actor_name;

    // Goto that calls me
    me:
    me();
    scanf("%s", &op);

    // While loop which will have all options whithin
    while(op != 'q'){

        // Insert Prompt (1)
        if (op=='i'){
            printf("    Enter Actor code: ");
            scanf("%d", &user_int);

            // Checking if usr imput is in the specified range
            if (user_int>=0){
                for (i = 0; i < j; i++){
                    if(actor[i].code == user_int){
                        printf("Actor Already Exists.\n\n");
                        goto me;
                    }}
                actor[j].code = user_int;
            } else {
                // If actor is already existing
                printf("Actor Already Exists \n\n");
                goto me;
            }

            // Making sure name is within range
            // if not will gve error statement
            printf("    Enter Actor name: ");
            char temp3;
            scanf("%c",&temp3);
            scanf("%[^\n]", actor[j].name);
            // str length
            if(strlen(actor[j].name) <= 50){
            } else {
                printf("Name longer than acceptable length \n\n");
                goto me;
            }


            // Make sure Actor age is within range
            // if not will disregard and re input command
            printf("    Enter Actor Age: ");
            scanf("%d", &actor[j].age);
            if (actor[j].age >= 0 && actor[j].age <=120){
            } else {
                printf("Actor Age is not in Range. \n\n");
                goto me;
            }

            // Inputs IMDB website
            printf("    Enter the Actor's IMDB website: ");
            char temp;
            scanf("%c",&temp);
            scanf("%[^\n]", actor[j].imdb);
            j++;
            goto me;

        }

        // Search(s) option
        // searches for existing imput if theres any
        if(op == 's'){


            int search;
            int index = -1;

            // If code exists then it will print out actor info
            printf("    Enter actor code: ");
            scanf("%d", &search);

            for (i = 0; i<j; i++){
                if(actor[i].code == search){
                    index = i;
                }
            }

            // Prints if found
            if (index > -1){
                printf("|Actor Code|\t\t|Actor Name|\t\t|Actor Age|\t\t|Actor IMDB|\n");
                printf("%d\t\t\t%-24s%.2d\t\t\t%s\n", actor[index].code, actor[index].name, actor[index].age, actor[index].imdb);
            } else {
                printf("Sorry, there is no actor with that code.\n");
            }
            goto me;
        }

        // Update(u) option
        // If this is selected, user can update existing info about actor
        if(op == 'u'){


            int search;
            int index = -1;

            // does code exist in array
            printf("    Enter actor code: ");
            scanf("%d", &search);
            for (i = 0; i<j; i++){
                if(actor[i].code == search){
                    index = i;
                }
            }

            // checking if user meets criteria and then updates
            if (index > -1){
                printf("    Enter Actor name: ");
                char temp4;
                scanf("%c",&temp4);
                scanf("%[^\n]", actor[index].name);
                if(strlen(actor[index].name) <= 50){
                } else {
                    printf("Actor Name Longer than Acceptable length \n\n");
                    goto me;
                }
                printf("    Enter Actor Age: ");
                scanf("%d", &actor[index].age);
                if (actor[index].age >= 17 && actor[index].age <=99){
                } else {
                    printf("Actor Age is Not Acceptable. \n\n");
                    goto me;
                }
                printf("    Enter the Actor's IMDB: ");
                char temp2;
                scanf("%c", &temp2);
                scanf("%[^\n]", actor[index].imdb);
            } else {
                printf("There is no actor with that IMDB\n");
                goto me;
            }

            goto me;
        }

        // Print(p) option to print everything
        if (op == 'p'){

            // Prints everything in structured array
            printf("|Actor Code|\t\t|Actor Name|\t\t|Actor Age|\t\t|Actor IMDB|\n");
            for(i = 0; i<j+1; i++){
                if(actor[i].age >= 1 && actor[i].age <= 120)
                    printf("%d\t\t\t%-24s%.2d\t\t\t%s\n", actor[i].code, actor[i].name, actor[i].age, actor[i].imdb);
            }
            goto me;
        }

        // Erase(e) option
        // Will erase specific actor using their code
        if (op == 'e'){

            int search;
            int index = -1;

            // Asks for code to erase
            printf("    Enter actor code: ");
            scanf("%d", &search);

            for (i = 0; i<j; i++){
                if(actor[i].code == search){
                    index = i;
                }
            }

            if (index >= -1){
                actor[index].code = 0;
                strcpy(actor[index].name, ""); // Resetting name to an empty string
                strcpy(actor[index].imdb, ""); // Resetting imdb to an empty string
                actor[index].age = 0;
                printf("Operation Complete \n");
            } else {
                printf("There is no actor with that code.\n");
                goto me;
            }
            goto me;
        }

        return 0;

    }

    return 0;

}
