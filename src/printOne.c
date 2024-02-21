#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) {

    int empNum = 0;
    struct employee * temp = headLL;    //make temp equal head of linked list

    if (temp == NULL) {
        printf("\nError as linked list is empty\n");    //if linked list is empty print error
    }
    else {
        while (temp != NULL) {     //find total employees
            empNum++;
            temp = temp->nextEmployee;
        }
        temp = headLL;

        if (whichOne > empNum) {    //if position is out of range, print error
            printf("Not enough employees index is out of range.");
        }
        else {
            for (int i=0; i<whichOne-1; i++) {    //find employee position
                temp = temp->nextEmployee;
            }                                     //and print info
            printf("\nEmployee id: %d\nFirst Name: %s", temp->empId, temp->fname);
            printf("\nLast Name: %s\nDependents: ", temp->lname);
            for (int i=0; i<temp->numDependents; i++) {
                printf("%s ", temp->dependents[i]);
            }
        }
        printf("\n");
    }
}
