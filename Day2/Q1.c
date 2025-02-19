#include <stdio.h>
#include <string.h>
#define MAX_S 50
#define MAX_P 50
typedef struct 
{
    int busNumber;
    char route[50];
    char departureTime[10];
    int totalSeats;
    int availableSeats;
}Bus;

typedef struct 
{
    char name[50];
    int age;
    char contactNumber[15];
    int seatNumber;
    int busNumber;
} Passenger;

Bus bus;
Passenger passengers[MAX_P];
int passengerCount = 0;

void acceptBusDetails() 
{
    printf("Enter bus number: ");
    scanf("%d", &bus.busNumber);
    printf("Enter route: ");
    scanf("%s", bus.route);
    printf("Enter departure time: ");
    scanf("%s", bus.departureTime);
    printf("Enter number of seats: ");
    scanf("%d", &bus.totalSeats);
    bus.availableSeats = bus.totalSeats;
}

void acceptPassengerDetails() 
{
    if (bus.availableSeats <= 0) 
    {
        printf("No available seats\n");
        return;
    }
    Passenger p;
    printf("Enter name: ");
    scanf("%s", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter contact number: ");
    scanf("%s", p.contactNumber);
    p.busNumber = bus.busNumber;
    p.seatNumber = bus.totalSeats - bus.availableSeats + 1;
    passengers[passengerCount++] = p;
    bus.availableSeats--;
    printf("Seat allocated: %d\n", p.seatNumber);
}

void displayAllocatedSeats() 
{
    printf("Allocated Seats:\n");
    for (int i=0;i<passengerCount;i++) 
    {
        printf("Seat Number: %d, Name: %s, Age: %d, Contact: %s\n",
               passengers[i].seatNumber, passengers[i].name, passengers[i].age, passengers[i].contactNumber);
    }
}

void cancelSeat(int seatNumber) 
{
    int found = 0;
    for (int i=0;i<passengerCount;i++) 
    {
        if (passengers[i].seatNumber == seatNumber) 
        {
            found = 1;
            bus.availableSeats++;
            for (int j=i;j<passengerCount-1;j++) 
            {
                passengers[j] = passengers[j + 1];
            }
            passengerCount--;
            printf("Seat %d canceled and reallocated\n", seatNumber);
            break;
        }
    }
    if (!found) 
    {
        printf("Seat number %d not found\n", seatNumber);
    }
}

void main() 
{
    acceptBusDetails();
    int ch, seatNumber;
    while (ch!=4) 
    {
        printf("\nMenu:\n1. Allocate Seat\n2. Display Allocated Seats\n3. Cancel Seat\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                acceptPassengerDetails();
                break;
            case 2:
                displayAllocatedSeats();
                break;
            case 3:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seatNumber);
                cancelSeat(seatNumber);
                break;
            case 4:
                printf("Exiting.....");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
