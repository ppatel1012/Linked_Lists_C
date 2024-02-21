#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL) {

    struct employee * addEmployee, * temp;
    addEmployee = malloc (sizeof(a3Emp));     //allocate space
    addEmployee->empId = 0;
    int numDep = 0;
    char depName[MAX_LENGTH], userChoice = 'y';

    printf("Enter the first name of the employee: ");    //get name of employee
    scanf("%s", addEmployee->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", addEmployee->lname);

    if (*headLL == NULL) {        //if linked list is empty
        temp = (addEmployee);
        temp->nextEmployee = NULL;
        *headLL = temp;            //make head equal to new employee
    }

    else {                    //if linked list is not empty
        temp = *headLL;       //make temp equal to head
        while (temp->nextEmployee != NULL) {
            temp = temp->nextEmployee;          //go to end of linked list
        }
        temp->nextEmployee = addEmployee;       //add to end of linked list
        temp->nextEmployee->nextEmployee = NULL;
    }

    while (userChoice == 'y') {    //while user has dependents
        numDep++;
        if (numDep == 1) {        //if first dependent
            addEmployee->dependents = malloc(sizeof(char*));    //allocate space
            printf("\nEnter name of dependent #%d: ", numDep);
            scanf("%s", depName);                               //get name
            addEmployee->dependents[numDep-1] = malloc (sizeof(char)*(strlen(depName)+1));   //malloc space
            strcpy (addEmployee->dependents[numDep-1], depName);    //add name to linked list
            printf("Do you have any more dependents? y/n: ");
            scanf(" %c", &userChoice);
        }

        else {      //if not first dependent
            addEmployee->dependents = realloc (addEmployee->dependents, sizeof(char*)*numDep);  //realloc space
            printf("\nEnter name of dependent #%d: ", numDep);
            scanf("%s", depName);                                  //get name
            addEmployee->dependents[numDep-1] = malloc (sizeof(char)*(strlen (depName)+1));
            strcpy (addEmployee->dependents[numDep-1], depName);  //add name to linked list
            printf("Do you have any more dependents? y/n ");
            scanf(" %c", &userChoice);
        }
    }

    addEmployee->numDependents = numDep;
    printf("\nYou have %d dependents\n", numDep);
    for (int i=0; i<(strlen(addEmployee->fname)); i++) {                 //get empId
        addEmployee->empId = addEmployee->empId + addEmployee->fname[i];
    }
    addEmployee->empId = addEmployee->empId + strlen(addEmployee->lname);
    temp = *headLL;
    while (temp->nextEmployee != NULL) {        //go through list find same empId if found
        if (temp->empId == addEmployee->empId) {
            addEmployee->empId = addEmployee->empId + rand() % 1000;    //add random number from 1-999
            temp = *headLL;
        }
        else {
            temp = temp->nextEmployee;
        }
    }
    printf("\nYour computer generated employee ID is %d\n", addEmployee->empId);  //print empId

}
