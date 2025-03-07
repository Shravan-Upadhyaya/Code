#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100
typedef struct 
{
    char name[20];
    float price;
    int q;
} Item;

float calculateTotalBill(Item order[],int itemcount,int tip,float taxRate) 
{
    float subtotal=0.0,tax,total;
    for (int i=0;i<itemcount;i++) 
        subtotal += order[i].price*order[i].q;
    tax=subtotal*taxRate;
    total=subtotal+tax+tip;
    return total;
}

void main() 
{
    Item order[MAX_ITEMS];
    int itemcount = 0,ch,q;
    float taxRate = 0.1;

    do {
        printf("Menu:\n");
        printf("1. Burger - $10\n2. Fries - $5\n3. Drink - $3\n");
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &ch);

        if (ch == 0) 
            break;

        printf("Enter the quantity: ");
        scanf("%d",&q);
        switch (ch) 
        {
            case 1:
                strcpy(order[itemcount].name,"Burger");
                order[itemcount].price=10;
                order[itemcount].q=q;
                itemcount++;
                break;
            case 2:
                strcpy(order[itemcount].name,"Fries");
                order[itemcount].price=5;
                order[itemcount].q=q;
                itemcount++;
                break;
            case 3:
                strcpy(order[itemcount].name,"Drink");
                order[itemcount].price=3;
                order[itemcount].q=q;
                itemcount++;
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }

    } while (ch != 0);

    printf("\nBill Details:\n");
    printf("Item\t\tPrice\tQuantity\tSubtotal\n");
    for (int i=0;i<itemcount;i++) 
    {
        printf("%s\t\t$%.2f\t%d\t\t$%.2f\n", order[i].name, order[i].price, order[i].q, order[i].price * order[i].q);
    }
    int tip;
    printf("\nEnter tip:");
    scanf("%d",&tip);
    printf("Total Bill (including tax and tip): $%.2f\n",calculateTotalBill(order,itemcount,tip,taxRate));
}
