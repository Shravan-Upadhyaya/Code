#include <stdio.h>
#include <string.h>
#define MAX_BOOKINGS 50
typedef struct 
{
    char name[50];
    int age;
    char contactNumber[15];
    char travelDate[15];
    char busType[20];
    int ticketPrice;
    int bookingID;
} Booking;

typedef struct 
{
    char paymentMethod[20];
    int amount;
    char transactionID[20];
} Payment;

Booking bookings[MAX_BOOKINGS];
Payment payments[MAX_BOOKINGS];
int bookingCount = 0;

void acceptBookingDetails() 
{
    Booking b;
    printf("Enter passenger name: ");
    scanf("%s", b.name);
    printf("Enter age: ");
    scanf("%d", &b.age);
    printf("Enter contact number: ");
    scanf("%s", b.contactNumber);
    printf("Enter travel date: ");
    scanf("%s", b.travelDate);
    printf("Enter bus type (AC/NonAC): ");
    scanf("%s", b.busType);
    b.ticketPrice = strcmp(b.busType, "AC") == 0 ? 500 : 300;
    b.bookingID = bookingCount + 1;
    bookings[bookingCount++] = b;
    printf("Booking ID: %d\n", b.bookingID);
}

void acceptPaymentDetails(int bookingID) 
{
    Payment p;
    printf("Enter payment method (Credit/Debit/Cash): ");
    scanf("%s", p.paymentMethod);
    p.amount = bookings[bookingID - 1].ticketPrice;
    printf("Enter transaction ID: ");
    scanf("%s", p.transactionID);
    payments[bookingID - 1] = p;
    printf("Payment successful\n");
}

void displayBookingConfirmation(int bookingID) 
{
    Booking b = bookings[bookingID - 1];
    Payment p = payments[bookingID - 1];
    printf("\nBooking Confirmation:\n");
    printf("Passenger Name: %s\n", b.name);
    printf("Age: %d\n", b.age);
    printf("Contact Number: %s\n", b.contactNumber);
    printf("Travel Date: %s\n", b.travelDate);
    printf("Bus Type: %s\n", b.busType);
    printf("Ticket Price: %d\n", b.ticketPrice);
    printf("Payment Method: %s\n", p.paymentMethod);
    printf("Transaction ID: %s\n", p.transactionID);
}

void cancelBooking(int bookingID) 
{
    for (int i=bookingID-1;i<bookingCount-1;i++) 
    {
        bookings[i] = bookings[i + 1];
        payments[i] = payments[i + 1];
    }
    bookingCount--;
    printf("Booking ID %d cancelled and refunded\n", bookingID);
}

void main() 
{
    int ch, bookingID;
    while (ch!=5) 
    {
        printf("\nMenu:\n1. Book Ticket\n2. Make Payment\n3. Display Booking Confirmation\n4. Cancel Booking\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                acceptBookingDetails();
                break;
            case 2:
                printf("Enter booking ID for payment: ");
                scanf("%d", &bookingID);
                acceptPaymentDetails(bookingID);
                break;
            case 3:
                printf("Enter booking ID for confirmation: ");
                scanf("%d", &bookingID);
                displayBookingConfirmation(bookingID);
                break;
            case 4:
                printf("Enter booking ID to cancel: ");
                scanf("%d", &bookingID);
                cancelBooking(bookingID);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
