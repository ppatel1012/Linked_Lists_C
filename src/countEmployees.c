#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {

    struct employee * temp = headLL;    //make temp equal to head of linked list
    int totalEmp = 0;

    if (temp == NULL) {             //if linked list is empty, return 0
        return totalEmp;
    }
    while (temp != NULL) {
        temp = temp->nextEmployee;   //go through list and increment counter
        totalEmp++;
    }
    return totalEmp;       //return total number employees
}
