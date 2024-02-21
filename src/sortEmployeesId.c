#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL) {

    struct employee * temp = headLL;            //make temp equal to head of linked list
    int empId, position, tempId;

    if (temp == NULL) {
        printf("\nError as linked list is empty\n");      //if linked list is empty print error
    }
    else {
        int totalEm = countEmployees (headLL);    //find total employees
        int arrayId[totalEm];
        while (temp != NULL) {
            for (int i=0; i<totalEm; i++) {       //fill array with empId
                arrayId[i] = temp->empId;
                temp = temp->nextEmployee;
            }
        }

        for (int i=0; i<totalEm; i++) {        //selection sort the ids
            empId = arrayId[i];
            position = i;
           for (int j=i+1; j<totalEm; j++) {
               if (arrayId[j] < empId) {
                   position = j;
                   empId = arrayId[j];
               }
           }
           tempId = arrayId[i];
           arrayId[i] = arrayId[position];
           arrayId[position] = tempId;
        }
        for (int i=0; i<totalEm; i++) {
            empId = lookOnId (headLL, arrayId[i]);
            printOne(headLL, empId);             //call function to print info in increasing id order
        }
    }
}
