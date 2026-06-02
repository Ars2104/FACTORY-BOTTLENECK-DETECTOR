#include <stdio.h>
#include "common.h"

void exportResults()
{
FILE *fp;

fp = fopen("../frontend/results.txt", "w");

if(fp == NULL)
{
    printf("Error Creating Results File!\n");
    return;
}

float riskScore =
(
    machines[0].bottleneckScore * 0.4 +
    machines[0].waitingTime * 0.2 +
    machines[0].downtime * 0.2 +
    machines[0].defectRate * 0.2
);

int healthyMachines = 0;
int criticalMachines = 0;

float totalUtilization = 0;
float totalThroughput = 0;
float totalHealth = 0;

for(int i = 0; i < totalMachines; i++)
{
    totalUtilization += machines[i].utilization;
    totalThroughput += machines[i].throughput;
    totalHealth += machines[i].healthScore;

    if(machines[i].healthScore >= 70)
        healthyMachines++;
    else
        criticalMachines++;
}

float avgUtilization =
totalUtilization / totalMachines;

float avgThroughput =
totalThroughput / totalMachines;

float avgHealth =
totalHealth / totalMachines;

fprintf(fp,"HealthScore=%.2f\n",avgHealth);
fprintf(fp,"TotalMachines=%d\n",totalMachines);

fprintf(fp,"TopMachine=%s\n",
machines[0].machineID);

fprintf(fp,"MachineType=%s\n",
machines[0].machineType);

fprintf(fp,"BottleneckScore=%.2f\n",
machines[0].bottleneckScore);

fprintf(fp,"WaitingTime=%.2f\n",
machines[0].waitingTime);

fprintf(fp,"Downtime=%.2f\n",
machines[0].downtime);

fprintf(fp,"Throughput=%.2f\n",
machines[0].throughput);

fprintf(fp,"RiskScore=%.2f\n",
riskScore);

fprintf(fp,"HealthyMachines=%d\n",
healthyMachines);

fprintf(fp,"CriticalMachines=%d\n",
criticalMachines);

fprintf(fp,"AverageUtilization=%.2f\n",
avgUtilization);

fprintf(fp,"AverageThroughput=%.2f\n",
avgThroughput);

/* TOP 10 MACHINES */

for(int i = 0; i < 10; i++)
{
    fprintf(fp,
    "Top%d=%s,%.2f\n",
    i + 1,
    machines[i].machineID,
    machines[i].bottleneckScore);
}

fclose(fp);

printf("\nResults Exported Successfully!\n");

}