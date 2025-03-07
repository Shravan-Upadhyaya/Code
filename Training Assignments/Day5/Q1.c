#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct MedicalData 
{
    int heartRate;          
    float bloodPressure[2]; 
    int oxygenSaturation;   
};

int getHeartRate() 
{
    return 60 + rand() % 41;
}
void getBloodPressure(float *systolic, float *diastolic) 
{
    *systolic = 90 + (rand() % 51);
    *diastolic = 60 + (rand() % 31);
}

int getOxygenSaturation() 
{
    return 95 + rand() % 6;
}

int main() 
{
    srand(time(NULL));
    struct MedicalData patientData;
    patientData.heartRate = getHeartRate();
    getBloodPressure(&patientData.bloodPressure[0], &patientData.bloodPressure[1]);
    patientData.oxygenSaturation = getOxygenSaturation();

    printf("Collected Medical Data:\n");
    printf("Heart Rate: %d BPM\n", patientData.heartRate);
    printf("Blood Pressure: %.1f/%.1f mmHg\n", patientData.bloodPressure[0], patientData.bloodPressure[1]);
    printf("Oxygen Saturation: %d%%\n", patientData.oxygenSaturation);

    return 0;
}