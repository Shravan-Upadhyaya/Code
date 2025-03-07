#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<time.h>
struct MedicalData 
{
    int heartRate;          
    float bloodPressure[2]; 
    int oxygenSaturation;   
};
#define HEART_RATE_MIN 60
#define HEART_RATE_MAX 100
#define OXYGEN_SAT_MIN 95
#define OXYGEN_SAT_MAX 100
int getHeartRate() 
{
    return 50 + rand() % 71;
}
void getBloodPressure(float *systolic, float *diastolic) 
{
    *systolic = 80 + (rand() % 71);
    *diastolic = 50 + (rand() % 51);
}
int getOxygenSaturation() 
{
    return 90 + rand() % 11;
}
void notifyHealthcare(char message[]) 
{
    printf("NOTIFICATION SENT TO HEALTHCARE PROFESSIONALS: %s\n", message);
}
void checkForAnomalies(struct MedicalData data) 
{
    if (data.heartRate < HEART_RATE_MIN || data.heartRate > HEART_RATE_MAX) 
    {
        printf("ALERT: Irregular Heart Rate Detected: %d BPM (Normal Range: %d-%d BPM)\n",
               data.heartRate, HEART_RATE_MIN, HEART_RATE_MAX);
        notifyHealthcare("Irregular Heart Rate");
    }
    if (data.bloodPressure[0] < 90 || data.bloodPressure[0] > 140) 
    {
        printf("ALERT: Irregular Systolic Blood Pressure Detected: %.1f mmHg (Normal Range: 90-140 mmHg)\n",
               data.bloodPressure[0]);
        notifyHealthcare("Irregular Systolic Blood Pressure");
    }
    if (data.bloodPressure[1] < 60 || data.bloodPressure[1] > 90) 
    {
        printf("ALERT: Irregular Diastolic Blood Pressure Detected: %.1f mmHg (Normal Range: 60-90 mmHg)\n",
               data.bloodPressure[1]);
        notifyHealthcare("Irregular Diastolic Blood Pressure");
    }
    if (data.oxygenSaturation < OXYGEN_SAT_MIN || data.oxygenSaturation > OXYGEN_SAT_MAX) 
    {
        printf("ALERT: Irregular Oxygen Saturation Detected: %d%% (Normal Range: %d-%d%%)\n",
               data.oxygenSaturation, OXYGEN_SAT_MIN, OXYGEN_SAT_MAX);
        notifyHealthcare("Irregular Oxygen Saturation");
    }
}
int main() 
{
    srand(time(NULL));
    while (1) 
    {
        struct MedicalData patientData;
        patientData.heartRate = getHeartRate();
        getBloodPressure(&patientData.bloodPressure[0], &patientData.bloodPressure[1]);
        patientData.oxygenSaturation = getOxygenSaturation();

        printf("\nCollected Medical Data:\n");
        printf("Heart Rate: %d BPM\n", patientData.heartRate);
        printf("Blood Pressure: %.1f/%.1f mmHg\n", patientData.bloodPressure[0], patientData.bloodPressure[1]);
        printf("Oxygen Saturation: %d%%\n", patientData.oxygenSaturation);

        checkForAnomalies(patientData);

        sleep(2);
    }

    return 0;
}