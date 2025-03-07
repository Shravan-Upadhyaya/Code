#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_t 100
typedef struct 
{
    char type[10];
    float amount;
    char date[20];
} Transaction;

void getdate(char *date) 
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}
void main() 
{
    float balance = 1000.0;
    Transaction t[MAX_t];
    int tcount=0;
    int ch;
    float amount;

    do {
        printf("\nMenu:\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Display Transaction History\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) 
        {
            case 1:
                printf("Enter deposit amount: ");
                scanf("%f",&amount);
                balance+=amount;
                strcpy(t[tcount].type,"Deposit");
                t[tcount].amount=amount;
                getdate(t[tcount].date);
                tcount++;
                printf("Amount deposited successfully!\n");
                break;
            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f",&amount);
                if (amount<=balance) 
                {
                    balance-=amount;
                    strcpy(t[tcount].type,"Withdraw");
                    t[tcount].amount=amount;
                    getdate(t[tcount].date);
                    tcount++;
                    printf("Amount withdrawn successfully!\n");
                } else 
                {
                    printf("Insufficient balance for withdrawal!\n");
                }
                break;
            case 3:
                printf("Current balance: $%.2f\n",balance);
                break;
            case 4:
                printf("\nTransaction History:\n");
                printf("Type\t\tAmount\t\tDate\n");
                for (int i=0;i<tcount;i++) 
                {
                    printf("%s\t\t$%.2f\t\t%s\n",t[i].type,t[i].amount,t[i].date);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (ch != 5);
}
