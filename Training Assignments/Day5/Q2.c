#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>
#define HEART_RATE_MIN 60
#define HEART_RATE_MAX 100
#define OXYGEN_SAT_MIN 95
#define OXYGEN_SAT_MAX 100
struct MedicalData 
{
    int heartRate;          
    float bloodPressure[2]; 
    int oxygenSaturation;  
};
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
void checkForAnomalies(struct MedicalData data) 
{
    if (data.heartRate < HEART_RATE_MIN || data.heartRate > HEART_RATE_MAX) 
    {
        printf("Anomaly Detected: Heart Rate is %d BPM (Normal Range: %d-%d BPM)\n",
               data.heartRate, HEART_RATE_MIN, HEART_RATE_MAX);
    }
    if (data.bloodPressure[0] < 90 || data.bloodPressure[0] > 140) 
    {
        printf("Anomaly Detected: Systolic Blood Pressure is %.1f mmHg (Normal Range: 90-140 mmHg)\n",
               data.bloodPressure[0]);
    }
    if (data.bloodPressure[1] < 60 || data.bloodPressure[1] > 90) 
    {
        printf("Anomaly Detected: Diastolic Blood Pressure is %.1f mmHg (Normal Range: 60-90 mmHg)\n",
               data.bloodPressure[1]);
    }
    if (data.oxygenSaturation < OXYGEN_SAT_MIN || data.oxygenSaturation > OXYGEN_SAT_MAX) 
    {
        printf("Anomaly Detected: Oxygen Saturation is %d%% (Normal Range: %d-%d%%)\n",
               data.oxygenSaturation, OXYGEN_SAT_MIN, OXYGEN_SAT_MAX);
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