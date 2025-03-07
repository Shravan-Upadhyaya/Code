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
void xorEncryptDecrypt(const char *input, char *output, const char *key, size_t length) 
{
    size_t keyLength = strlen(key);
    for (size_t i = 0; i < length; i++) 
    {
        output[i] = input[i] ^ key[i % keyLength];
    }
}
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
    struct PatientData encryptedPatient;
    struct PatientData decryptedPatient;

    const char *key = "SecretKey123";

    printf("Enter patient name: ");
    scanf(" %[^\n]", patient.name);
    printf("Enter patient age: ");
    scanf("%d", &patient.age);
    printf("Enter medical history: ");
    scanf(" %[^\n]", patient.medicalHistory);
    printf("Enter allergies: ");
    scanf(" %[^\n]", patient.allergies);
    printf("Enter medications: ");
    scanf(" %[^\n]", patient.medications);

    xorEncryptDecrypt(patient.name, encryptedPatient.name, key, strlen(patient.name));
    xorEncryptDecrypt(patient.medicalHistory, encryptedPatient.medicalHistory, key, strlen(patient.medicalHistory));
    xorEncryptDecrypt(patient.allergies, encryptedPatient.allergies, key, strlen(patient.allergies));
    xorEncryptDecrypt(patient.medications, encryptedPatient.medications, key, strlen(patient.medications));
    encryptedPatient.age = patient.age;

    printf("\nEncrypted Patient Data:\n");
    printf("Name: %s\n", encryptedPatient.name);
    printf("Age: %d\n", encryptedPatient.age);
    printf("Medical History: %s\n", encryptedPatient.medicalHistory);
    printf("Allergies: %s\n", encryptedPatient.allergies);
    printf("Medications: %s\n", encryptedPatient.medications);

    xorEncryptDecrypt(encryptedPatient.name, decryptedPatient.name, key, strlen(encryptedPatient.name));
    xorEncryptDecrypt(encryptedPatient.medicalHistory, decryptedPatient.medicalHistory, key, strlen(encryptedPatient.medicalHistory));
    xorEncryptDecrypt(encryptedPatient.allergies, decryptedPatient.allergies, key, strlen(encryptedPatient.allergies));
    xorEncryptDecrypt(encryptedPatient.medications, decryptedPatient.medications, key, strlen(encryptedPatient.medications));
    decryptedPatient.age = encryptedPatient.age;

    printf("\nDecrypted Patient Data:\n");
    displayPatientData(decryptedPatient);
    return 0;
}