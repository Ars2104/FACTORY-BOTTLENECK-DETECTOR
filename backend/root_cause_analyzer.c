#include <stdio.h>
#include "common.h"

void analyzeRootCause()
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
    printf("\nROOT CAUSE ANALYSIS");
    printf("\n=================================\n");

    if(machines[bottleneckIndex].waitingTime > 40)
    {
        printf("✓ High Waiting Time Detected\n");
    }

    if(machines[bottleneckIndex].downtime > 40)
    {
        printf("✓ High Downtime Detected\n");
    }

    if(machines[bottleneckIndex].throughput < 50)
    {
        printf("✓ Low Throughput Detected\n");
    }

    if(machines[bottleneckIndex].utilization < 70)
    {
        printf("✓ Low Utilization Detected\n");
    }

    if(machines[bottleneckIndex].defectRate > 5)
    {
        printf("✓ High Defect Rate Detected\n");
    }
}