/*
Student Name: Pooja Patel
Student ID: 1225060
Due Date: April 4th, 2023
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 25

struct employee
{
   char fname[MAX_LENGTH];
   char lname[MAX_LENGTH];
   int empId;              // this is auto-generated by the program
   int numDependents;
   char  ** dependents;
   struct employee * nextEmployee;
};

typedef struct employee a3Emp;

void recruitEmployee (struct employee ** headLL);
void printAll (struct employee * headLL);
void printOne (struct employee * headLL, int whichOne);

int lookOnId (struct employee * headLL, int whichEmpId);

int lookOnFullName (struct employee * headLL, char whichName [100]);

void sortEmployeesId (struct employee * headLL);

void loadEmpData (struct employee ** headLL, char fileName [MAX_LENGTH]);

int countEmployees (a3Emp * headLL);

void fireAll (a3Emp ** headLL);
void fireOne (a3Emp ** headLL, int whichOne);
