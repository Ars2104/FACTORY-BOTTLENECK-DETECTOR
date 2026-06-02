#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void readCSV()
{
    FILE *fp;

    fp = fopen("../data/factory_bottleneck_dataset.csv", "r");

    if(fp == NULL)
    {
        printf("\nError Opening CSV File!\n");
        return;
    }

    char line[1024];

    fgets(line,sizeof(line),fp);

    while(fgets(line,sizeof(line),fp))
    {
        sscanf(line,
               "%[^,],%[^,],%f,%f,%f,%f,%d,%f,%f,%f,%f,%f",

               machines[totalMachines].machineID,
               machines[totalMachines].machineType,

               &machines[totalMachines].processingTime,
               &machines[totalMachines].waitingTime,
               &machines[totalMachines].downtime,

               &machines[totalMachines].throughput,

               &machines[totalMachines].workerCount,

               &machines[totalMachines].utilization,
               &machines[totalMachines].defectRate,

               &machines[totalMachines].energyConsumption,

               &machines[totalMachines].bottleneckScore,
               &machines[totalMachines].healthScore);

        totalMachines++;
    }

    fclose(fp);

    printf("\nDataset Loaded Successfully!");
    printf("\nTotal Records : %d\n", totalMachines);
}