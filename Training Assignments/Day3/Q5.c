#include <stdio.h>
#include <unistd.h>
#define num 10

void communicate_with_microservice(int microservice_id) 
{
    printf("Communicating with microservice %d\n", microservice_id);
    usleep(100000);
}

void main() 
{
    printf("Simulating microservices architecture on Flipkart's platform...\n");
    float total_latency = 0.0;
    for(int i = 1; i <= num; i++) 
    {
        communicate_with_microservice(i);
        total_latency += 0.1;
    }
    printf("Total latency: %.1f seconds\n", total_latency);
}
