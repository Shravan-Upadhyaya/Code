#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PatientData 
{
    char name[100];        
    int age;                 
    char medicalHistory[500]; 
    char allergies[500];     
    char medications[500];   
};
void displayPatientData(struct PatientData patient) 
{
    printf("\nPatient Name: %s\n", patient.name);
    printf("Age: %d\n", patient.age);
    printf("Medical History: %s\n", patient.medicalHistory);
    printf("Allergies: %s\n", patient.allergies);
    printf("Medications: %s\n", patient.medications);
}
void updatePatientData(struct PatientData *patient) 
{
    printf("Enter patient name: ");
    scanf(" %[^\n]", patient->name); 
    printf("Enter patient age: ");
    scanf("%d", &patient->age);
    printf("Enter medical history: ");
    scanf(" %[^\n]", patient->medicalHistory);
    printf("Enter allergies: ");
    scanf(" %[^\n]", patient->allergies);
    printf("Enter medications: ");
    scanf(" %[^\n]", patient->medications);
}

int main() 
{
    struct PatientData patient;
    int choice;

    while (1) 
    {
        printf("\nPatient Data Management System\n");
        printf("1. Add/Update Patient Data\n");
        printf("2. View Patient Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                updatePatientData(&patient);
                printf("Patient data updated successfully!\n");
                break;

            case 2:
                if (strlen(patient.name) == 0) 
                {
                    printf("No patient data available. Please add data first.\n");
                } else 
                {
                    displayPatientData(patient);
                }
                break;

            case 3:
                printf("Exiting the program......\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}