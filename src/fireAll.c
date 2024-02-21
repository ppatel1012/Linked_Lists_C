#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL) {

    struct employee * temp = (*headLL)->nextEmployee;    //make temp equal to head of linked list

    if (temp == NULL) {                              //if linked list is empty, print error
        printf("\nError as linked list is empty\n");
    }

    else {
        while (temp != NULL) {
            for (int i=0; i<(*headLL)->numDependents; i++) {
                  free ((*headLL)->dependents[i]);            //free all dependents
            }
            free ((*headLL)->dependents);
            free (*headLL);               //free head
            *headLL = temp;               //make head point to next employee
            temp = temp->nextEmployee;
        }
        for (int i=0; i<(*headLL)->numDependents; i++) {   //when reach last employee, repeat process
            free ((*headLL)->dependents[i]);      //free all dependents
        }
        free ((*headLL)->dependents);
        free (*headLL);                //free head
        free (temp);                   //free temp
        *headLL = NULL;
        printf("\nAll Fired. Linked list is now empty\n");
    }
}

