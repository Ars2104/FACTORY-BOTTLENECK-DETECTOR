#include <stdio.h>
#include "common.h"

void detectBottleneck()
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
    printf("\nCURRENT BOTTLENECK");
    printf("\n=================================\n");

    printf("Machine ID       : %s\n",
           machines[bottleneckIndex].machineID);

    printf("Machine Type     : %s\n",
           machines[bottleneckIndex].machineType);

    printf("Processing Time  : %.2f\n",
           machines[bottleneckIndex].processingTime);

    printf("Waiting Time     : %.2f\n",
           machines[bottleneckIndex].waitingTime);

    printf("Downtime         : %.2f\n",
           machines[bottleneckIndex].downtime);

    printf("Throughput       : %.2f\n",
           machines[bottleneckIndex].throughput);

    printf("Bottleneck Score : %.2f\n",
           machines[bottleneckIndex].bottleneckScore);
}