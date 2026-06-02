#include <stdio.h>
#include "common.h"

void calculateHealthScore()
{
    float totalHealth = 0;

    for(int i = 0; i < totalMachines; i++)
    {
        totalHealth += machines[i].healthScore;
    }

    float averageHealth = totalHealth / totalMachines;

    printf("\n=================================");
    printf("\nFACTORY HEALTH SCORE");
    printf("\n=================================\n");

    printf("Average Health Score : %.2f\n", averageHealth);

    if(averageHealth >= 80)
    {
        printf("Factory Status : HEALTHY\n");
    }
    else if(averageHealth >= 60)
    {
        printf("Factory Status : MODERATE\n");
    }
    else
    {
        printf("Factory Status : CRITICAL\n");
    }
}