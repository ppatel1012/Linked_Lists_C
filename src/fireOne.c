#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne) {

    int totalEmp = countEmployees (*headLL);      //get total employees
    struct employee * previous, * temp = *headLL;   //make temp equal to head of linked list

    if (temp == NULL) {
        printf("\nError has linked list is empty\n");    //if linked list is empty, print error
    }

    else if (whichOne == 1) {                           //if user picked 1 (head of linked list)
        if (totalEmp != 1) {
            temp = (*headLL)->nextEmployee;                 //temp equal next employee
        }
        for (int i=0; i<(*headLL)->numDependents; i++) {
            free ((*headLL)->dependents[i]);            //free dependents
        }
        free ((*headLL)->dependents);
        free (*headLL);                //free head
        if (totalEmp != 1) {
            *headLL = temp;                //head = temp
        }
        else {
            *headLL = NULL;
        }
    }
    else if (whichOne == totalEmp) {          //if user pick the last employee
        while (temp->nextEmployee != NULL) {  //go through entire linked list
            previous = temp;
            temp = temp->nextEmployee;
        }
        previous->nextEmployee = NULL;
        for (int i=0; i<temp->numDependents; i++) {
            free (temp->dependents[i]);              //free dependents
        }
        free (temp->dependents);
        free (temp);                    //free temp
    }
    else {                                  //if user pick middle of linked list
        for (int i=0; i<whichOne-1; i++) {   //go to position in linked list
            previous = temp;
            temp = temp->nextEmployee;
        }
        previous->nextEmployee = temp->nextEmployee;
        for (int i=0; i<temp->numDependents; i++) {
            free (temp->dependents[i]);             //free dependents
        }
        free (temp->dependents);
        free (temp);                    //free temp
    }
}
