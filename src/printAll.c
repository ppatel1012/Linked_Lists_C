#include "../include/headerA3.h"      //include header

void printAll (struct employee * headLL) {

    struct employee * temp = headLL;   //make temp = head of linked list
    int empNum = 1;

    if (temp == NULL) {
        printf("\nError as linked list is empty");    //if list empty print error
    }
    else {
        while (temp != NULL) {                      //print data of all employees
            printf("\nEmployee #: %d ", empNum);
            printf("\n\tEmployee id: %d", temp->empId);
            printf("\n\tFirst Name: %s \n\tLast Name: %s ", temp->fname, temp->lname);
            printf("\n\tDependents[%d]:", temp->numDependents);   //print all dependents
            for (int i=0; i<temp->numDependents; i++) {
                printf(" %s", temp->dependents[i]);
            }
            printf("\n");
            temp = temp->nextEmployee;    //go to next employee
            empNum++;
        }
    }
    printf("\nCurrently there are %d employees\n", empNum-1);   //print total employees

}

