#ifndef COMMON_H
#define COMMON_H

#define MAX_RECORDS 10000

typedef struct
{
    char machineID[20];
    char machineType[10];

    float processingTime;
    float waitingTime;
    float downtime;

    float throughput;

    int workerCount;

    float utilization;
    float defectRate;

    float energyConsumption;

    float bottleneckScore;
    float healthScore;

} Machine;

extern Machine machines[MAX_RECORDS];
extern int totalMachines;

#endif
void sortMachinesByBottleneck();