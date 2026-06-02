#include <stdio.h>
#include "common.h"

// Function Prototypes
void exportResults();
void readCSV();
void sortMachinesByBottleneck();

void detectBottleneck();
void analyzeRootCause();

void predictFutureRisk();

void generateRecommendations();

void calculateHealthScore();

void generateHTMLReport();

// Global Variables

Machine machines[MAX_RECORDS];
int totalMachines = 0;

// Main Function

int main()
{
    printf("\n====================================");
    printf("\n FACTORY BOTTLENECK DETECTOR");
    printf("\n====================================\n");

    readCSV();

    sortMachinesByBottleneck();

    detectBottleneck();

    analyzeRootCause();

    predictFutureRisk();

    generateRecommendations();

    calculateHealthScore();
    exportResults();

    printf("\n\nAnalysis Completed Successfully!\n");

    return 0;
}