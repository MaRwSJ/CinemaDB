//
// Created by Marwa on 2023-11-28.
//

#ifndef ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
#define ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H

#include <stdio.h>

// Define NULL if not defined
#ifndef NULL
#define NULL 0
#endif

// Creates Linked List
struct movie {
    int code;
    char name[100];
    char genre[25];
    float rating;
    struct movie *next;
};
struct movie *head = NULL;

struct movie *delete(struct movie *head);


struct movie *findCode(int c){
    struct movie *p;
    for (p = head;
         p != NULL && c > p->code;
         p = p->next);

    if (p != NULL && c == p->code)
        return p;
    return NULL;
}

// This Function will check and see if array fits
int check(char arr[50]) {
    char letter = arr[0];
    char num = arr[1];

    int l_ascii = (int)letter;
    int nascii = (int)num;

    if((l_ascii >= 65 && l_ascii <= 72) && (nascii >= 49 && nascii <= 52)) {
        return 1;
    } else {
        return 0;
    }
}

// Print options
void menu() {
    printf("\nEnter operation code: ");
}



#endif //ASSIGNMENT5_MOVIETHEATERDB_MOVIE_H
