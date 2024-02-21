#include "../include/headerA3.h"

int main() {

    int userInt = 1, whichOne, empId, whichEmpId;
    struct employee * headLL = NULL;            //head of linked list
    char whichName [100], userChoice;

    struct employee * node = NULL;       //temp head of linked list
    loadEmpData (&node, "proFile.txt");
    headLL = node;                      //get head of linked list

    while (userInt != 10) {             //print menu
        printf("\n1. Add new employee \n2. Print data of all employees");
        printf("\n3. Print data for nth employee \n4. Search for employee based on employee ID");
        printf("\n5. Search for employee based on full name \n6. Count total number of employees");
        printf("\n7. Sort employees based on employee ID \n8. Remove the nth employee in current linked list");
        printf("\n9. Remove all employees in current linked list \n10. Exit \nEnter Your Choice: ");

        scanf("%d", &userInt);               //while valid input
        while (userInt > 10 || userInt < 1) {
            printf("Please enter number from 1-10: ");
            scanf("%d", &userInt);
        }

        switch(userInt) {
            case 1:
                recruitEmployee (&node);      //call function to add employee
                headLL = node;
                break;
            case 2:
                printAll (node);              //call function to print all employees in linked list
                break;
            case 3:
                printf("\nEnter a position: ");   //get position from user
                scanf("%d", &whichOne);
                while (whichOne < 0) {
                    printf("\nPlease enter a positive number: ");
                    scanf("%d", &whichOne);
                }
                printOne (node, whichOne);      //call function to print employee in position
                break;
            case 4:
                printf("\nEnter an employee ID: ");    //get id from user
                scanf("%d", &whichEmpId);
                empId = lookOnId (node, whichEmpId);    //call function to find employee with id
                if (empId == -1) {
                    printf("\nError as linked list is empty\n");   //if function returned -1, linked list is empty
                }
                else if (empId == 0) {
                    printf("\nEmployee ID not found\n");            //if function returned 0, employee id not found
                }
                else {
                    printOne (node, empId);         //else call printOne to print info of employee found
                }
                break;
            case 5:
                printf("\nEnter the Full Name of the Employee: ");
                getchar();
                fgets (whichName, MAX_LENGTH, stdin);        //get full name from user
                empId = lookOnFullName (node, whichName);    //call function to find employee with name
                if (empId == -1) {
                    printf("\nError as linked list is empty\n");   //if returned -1, linked list is empty
                }
                else if (empId == 0) {
                    printf("\nNo employee with that %s name found\n", whichName);   //if return 0, no employee found
                }
                else {
                    printOne (node, empId);      //else call printOne to print info of employee found
                }
                break;
            case 6:
                empId = countEmployees (node);    //call function to find total employees
                if (empId == 0) {
                    printf("\nError as linked list is empty\n");   //if returned 0, linked list is empty
                }
                else {
                    printf("\nTotal Number of Employees: %d\n", empId);    //else print total number
                }
                break;
            case 7:
                sortEmployeesId (node);       //call function to sort employees by ID
                break;
            case 8:
                empId = countEmployees (node);              //get total number of employees to validate user input
                printf("\nCurrently there are %d employees\n", empId);
                printf("Which employee do you want to fire? Enter value between 1 and %d: ", empId);
                scanf("%d", &whichOne);
                while (empId < whichOne || whichOne <= 0) {
                    printf("Please enter a value between 1 and %d: ", empId);
                    scanf("%d", &whichOne);
                }
                fireOne (&node, whichOne);      //call function to fire employee
                headLL = node;
                break;
            case 9:
                if (headLL == NULL) {            //if headLL is null, linked list empty print error
                    printf("\nError as linked list is empty\n");
                }
                else {
                    printf("\nAre you sure you wish to fire everyone? y/n: ");   //else confirm with user
                    getchar();
                    userChoice = getchar();
                    if (userChoice == 'y' || userChoice == 'Y') {
                        fireAll (&node);           //call function to fire all employees
                        headLL = node;
                    }
                    else {
                        printf("\nNo employees fired\n");
                    }
                }
                break;
            case 10:
                if (headLL != NULL) {      //if linked list is not freed, free it
                    fireAll (&node);
                }
                break;
        }
    }
    return 0;
}
