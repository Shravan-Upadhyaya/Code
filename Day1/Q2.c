#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100
typedef struct 
{
    char name[20];
    float price;
    int q;
} Item;

float calculateTotalCost(Item cart[],int itemcount) 
{
    float totalCost=0.0;
    for (int i=0;i<itemcount;i++) 
    {
        totalCost+=cart[i].price*cart[i].q;
    }
    return totalCost;
}

void main() 
{
    Item cart[MAX_ITEMS];
    int itemcount=0,ch,q,updatechoice;

    do {
        printf("Available Products:\n");
        printf("1. Shirt - $15\n2. Pants - $20\n3. Shoes - $30\n");
        printf("Enter the product number to add to cart (0 to finish): ");
        scanf("%d",&ch);

        if (ch==0)
            break;

        printf("Enter the quantity: ");
        scanf("%d",&q);
        switch (ch) 
        {
            case 1:
                strcpy(cart[itemcount].name,"Shirt");
                cart[itemcount].price=15;
                cart[itemcount].q=q;
                itemcount++;
                break;
            case 2:
                strcpy(cart[itemcount].name,"Pants");
                cart[itemcount].price=20;
                cart[itemcount].q=q;
                itemcount++;
                break;
            case 3:
                strcpy(cart[itemcount].name,"Shoes");
                cart[itemcount].price=30;
                cart[itemcount].q=q;
                itemcount++;
                break;
            default:
                printf("Invalid Choice, please try again.\n");
                break;
        }

        printf("Do you want to update any item in the cart? (1/0): ");
        scanf("%d",&updatechoice);

        if (updatechoice==1) 
        {
            char itemname[20];
            int newq;
            printf("Enter the name of the item to update: ");
            scanf("%s",itemname);
            printf("Enter the new quantity: ");
            scanf("%d",&newq);

            for (int i=0;i<itemcount;i++) 
            {
                if (strcmp(cart[i].name, itemname)==0) 
                {
                    cart[i].q=newq;
                    break;
                }
            }
        }

        printf("Do you want to remove any item from the cart? (1/0): ");
        scanf("%d",&updatechoice);

        if (updatechoice==1) 
        {
            char itemname[20];
            printf("Enter the name of the item to remove: ");
            scanf("%s",itemname);

            for (int i=0;i<itemcount;i++) 
            {
                if (strcmp(cart[i].name,itemname)==0) 
                {
                    for (int j=i;j<itemcount-1;j++) 
                    {
                        cart[j] = cart[j+1];
                    }
                    itemcount--;
                    break;
                }
            }
        }

    }while(ch != 0);
    printf("\nCart Contents:\n");
    printf("Item\t\tPrice\tQuantity\n");
    for (int i=0;i<itemcount;i++) 
    {
        printf("%s\t\t$%.2f\t\t%d\n", cart[i].name, cart[i].price, cart[i].q);
    }
    printf("Total Cost: $%.2f\n", calculateTotalCost(cart, itemcount));
}
