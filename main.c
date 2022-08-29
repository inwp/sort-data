#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ino/type.h"
int disp(stu a[], int, int);
int process(stu a[], int);
int d=0;
int main()
{
    int n, i;
    printf("How many data you want to process: ");
    scanf("%d", &n);
    stu var[n];
    for (i=0;i<n;i++)
    {
        printf("Enter Roll no: ");
        scanf("%d", &var[i].roll);
        printf("Enter Name: ");
        scanf("%s", var[i].name);
        printf("Enter Address: ");
        scanf("%s", var[i].address);
        printf("Enter Contact: ");
        scanf("%s", var[i].tell);
    }
    disp(var, n, 1);
    printf("How you want to sort?\n a) 0 for name\t b) 1 for roll\n c) 2 for address\t d) 3 for contact\n");
    printf("=>");
    scanf("%d", &d);
    printf("------------------------------------------------------------\n");
    process(var, n);
    return 0;
}
int process(stu var[], int n)
{
    stu temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((strcmp(var[i].name, var[j].name) > 0) && d==0)
            {
                temp = var[i];
                var[i] = var[j];
                var[j] = temp;
            }
            else if(var[i].roll>var[j].roll && d==1)
            {
                temp = var[i];
                var[i] = var[j];
                var[j] = temp;
            }
            else if(strcmp(var[i].address, var[j].address) > 0 && d==2)
            {
                temp = var[i];
                var[i] = var[j];
                var[j] = temp;
            }

        }
    }
    disp(var, n, 2);
    return 0;
}
int disp(stu var[], int n, int a)
{
    int i;
    if(a==1)
    {
        printf("Your input\n");
        printf("------------------------------------------------------------\n");
    }
    else
    {
        printf("Sort by: ");
        switch(d)
        {
            case 0:
                printf("Name \n");
                break;
            case 1:
                printf("Roll No \n");
                break;
            case 2:
                printf("Address \n");
                break;
            case 3:
                printf("Contact \n");
                break;
        }
        printf("------------------------------------------------------------\n");
    }
    for(i=0;i<n;i++)
    {
        printf("Roll no.: %d,\tName: %s, \tAddress: %s, \tContact: %s\n", var[i].roll, var[i].name, var[i].address, var[i].tell);
    }
    printf("------------------------------------------------------------\n");

    return 0;
}
