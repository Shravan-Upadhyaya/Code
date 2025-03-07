#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_TRANSACTIONS 100

void main() 
{
    int failed_transactions = 0;
    srand(time(NULL));
    for (int i=0;i<TOTAL_TRANSACTIONS;i++) 
    {
        double random_value = (double)rand()/RAND_MAX;
        if (random_value <0.1) 
        {
            failed_transactions++;
        }
    }
    printf("Total transactions: %d\n", TOTAL_TRANSACTIONS);
    printf("Failed transactions: %d\n", failed_transactions);
}