#include <stdio.h>
#define TOTAL_LINES 1000
#define INITIAL_DEBT 0.1
#define DEBT_REDUCTION_RATE 0.01 

void main() 
{
    double technicalDebt[TOTAL_LINES];
    double totalDebt = 0.0;
    int iterations = 0;
    for (int i=0;i<TOTAL_LINES;i++) 
    {
        technicalDebt[i] = INITIAL_DEBT;
        totalDebt += technicalDebt[i];
    }
    printf("Initial total technical debt: %.2f\n", totalDebt);
    while (totalDebt > 0) 
    {
        totalDebt = 0.0;
        for (int i=0;i<TOTAL_LINES;i++) 
        {
            if (technicalDebt[i] > 0) 
            {
                technicalDebt[i] -= DEBT_REDUCTION_RATE;
                if (technicalDebt[i] < 0) 
                {
                    technicalDebt[i] = 0;
                }
            }
            totalDebt += technicalDebt[i];
        }
        iterations++;
        printf("Iteration %d: Total technical debt: %.2f\n", iterations, totalDebt);
    }
    printf("Technical debt has been completely reduced after %d iterations.\n", iterations);
}
