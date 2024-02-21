#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {

    struct employee * temp = headLL;
    char fname[MAX_LENGTH], lname[MAX_LENGTH], * j;
    int empPosition = 1;

    if (temp == NULL) {       //if linked list is empty, return -1 (error)
        return -1;
    }
    else {
        j = strtok(whichName, " ");     //remove spaces from user input
        strcpy (fname, j);
        j = strtok(NULL, " ");
        strcpy (lname, j);
        lname[strlen(lname)-1] = '\0';     //remove newline character from last name
        while (temp != NULL) {
            if (strcmp (fname, temp->fname) == 0) {      //if userfname is equal to employee name
                if (strcmp (lname, temp->lname) == 0) {  //and userlname is equal to employee name
                    return empPosition;                  //return position of employee
                }
            }
            temp = temp->nextEmployee;
            empPosition++;
        }
    }
    return 0;        //if employee name not found, return 0

}
