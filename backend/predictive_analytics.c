#include <stdio.h>
#include "common.h"

void predictFutureRisk()
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

    float riskScore =
    (
        machines[bottleneckIndex].bottleneckScore * 0.4 +
        machines[bottleneckIndex].waitingTime * 0.2 +
        machines[bottleneckIndex].downtime * 0.2 +
        machines[bottleneckIndex].defectRate * 0.2
    );

    printf("\n=================================");
    printf("\nFUTURE RISK PREDICTION");
    printf("\n=================================\n");

    printf("Risk Score : %.2f\n", riskScore);

    if(riskScore > 60)
    {
        printf("Future Bottleneck Risk : HIGH\n");
    }
    else if(riskScore > 40)
    {
        printf("Future Bottleneck Risk : MEDIUM\n");
    }
    else
    {
        printf("Future Bottleneck Risk : LOW\n");
    }
}