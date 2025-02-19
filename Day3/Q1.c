#include <stdio.h>
#include <stdlib.h>
#define MAX_USERS 1000

void main() 
{
    int users;

    printf("Enter the number of concurrent users: ");
    scanf("%d", &users);
    if (users > MAX_USERS) 
    {
        printf("Platform crashed! Too many users.\n");
        exit(0);
    } else 
    {

        printf("Platform is running smoothly with %d concurrent users.\n", users);
    }
}