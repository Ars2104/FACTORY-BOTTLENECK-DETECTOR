#include "common.h"

void sortMachinesByBottleneck()
{
    Machine temp;

    for(int i = 0; i < totalMachines - 1; i++)
    {
        for(int j = 0; j < totalMachines - i - 1; j++)
        {
            if(machines[j].bottleneckScore <
               machines[j + 1].bottleneckScore)
            {
                temp = machines[j];
                machines[j] = machines[j + 1];
                machines[j + 1] = temp;
            }
        }
    }
}