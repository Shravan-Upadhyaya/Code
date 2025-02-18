#include <stdio.h>
#include<string.h>
void main() 
{
    int ch,q,confirm;
    float subtotal = 0.0,tax,total;
    char orderStatus[6] ="unpaid";

    do {
        printf("Menu:\n");
        printf("1. Pizza - $15\n2. Burger - $10\n3. Fries - $5\n4. Drink - $3\n");
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d",&ch);
        if(ch==0)
            break;
        printf("Enter the quantity: ");
        scanf("%d",&q);
        switch(ch) 
        {
            case 1:
                subtotal+=15*q;
                break;
            case 2:
                subtotal+=10*q;
                break;
            case 3:
                subtotal+=5*q;
                break;
            case 4:
                subtotal+=3*q;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    }while(ch!= 0);
    tax=subtotal*0.1;
    total=subtotal+tax;
    printf("Order summary:\nSubtotal: $%.2f\nTax: $%.2f\nTotal: $%.2f\n",subtotal,tax,total);
    printf("Confirm order? (1/0)\n");
    scanf("%d",&confirm);
    if(confirm==1) 
    {
        strcpy(orderStatus,"paid");
        printf("Order has been processed and marked as '%s'.\n", orderStatus);
    } else 
    {
        printf("Order has not been processed.\n");
    }
}