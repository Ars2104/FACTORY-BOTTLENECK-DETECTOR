#include <stdio.h>
#include "common.h"

void generateRecommendations()
{
    int bottleneckIndex = 0;

    for(int i = 1; i < totalMachines; i++)
    {
        if(machines[i].bottleneckScore >
           machines[bottleneckIndex].bottleneckScore)
        {
            bottleneckIndex = i;
        }
    }

    printf("\n=================================");
    printf("\nRECOMMENDATIONS");
    printf("\n=================================\n");

    if(machines[bottleneckIndex].waitingTime > 40)
    {
        printf("✓ Reduce Waiting Time by 15 Minutes\n");
    }

    if(machines[bottleneckIndex].downtime > 40)
    {
        printf("✓ Schedule Preventive Maintenance\n");
        printf("✓ Reduce Downtime by 10 Minutes\n");
    }

    if(machines[bottleneckIndex].throughput < 50)
    {
        printf("✓ Increase Production Capacity\n");
    }

    if(machines[bottleneckIndex].utilization < 70)
    {
        printf("✓ Improve Machine Utilization\n");
    }

    if(machines[bottleneckIndex].workerCount < 4)
    {
        printf("✓ Add 1 Additional Worker\n");
    }

    printf("\nExpected Throughput Improvement : 15%%");
    printf("\nExpected Bottleneck Reduction   : 20%%\n");
}