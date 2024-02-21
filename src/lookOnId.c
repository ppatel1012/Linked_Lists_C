#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {

    struct employee * temp = headLL;      //temp equal to head of linked list
    int empPosition = 1;

    if (temp == NULL) {      //if linked list is empty, return -1 (error)
        return -1;
    }
    else {
        while (temp != NULL) {
            if (whichEmpId == temp->empId) {
                return empPosition;           //if employee id found, return position
            }
            temp = temp->nextEmployee;
            empPosition++;
        }
    }
    return 0;        //if employee id not found, return 0
}
