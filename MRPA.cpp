// Cody Blake
// CSC 222
// Marathon Runners Parallel Arrays Project (MRPA)
// September 10th, 2026

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;
void readRunnerData(string names[], double miles[][NUM_DAYS]);
void calculateTotalsAndAverages(
    double miles[][NUM_DAYS],
    double totals[],
    double averages[]);
void displayResults(
    string names[],
    double miles[][NUM_DAYS],
    double totals[],
    double averages[]);

int main()
{
    string runnerNames[NUM_RUNNERS];

    double miles[NUM_RUNNERS][NUM_DAYS];

    double totals[NUM_RUNNERS];

    double averages[NUM_RUNNERS];

    readRunnerData(runnerNames, miles);

    calculateTotalsAndAverages(
        miles,
        totals,
        averages);


    return 0;
}

void readRunnerData(string names[],
    double miles[][NUM_DAYS])
{
    ifstream inputFile("runners.txt");

    for (int row = 0; row < NUM_RUNNERS; row++)
    {
        inputFile >> names[row];

        for (int col = 0; col < NUM_DAYS; col++)
        {
            inputFile >> miles[row][col];
        }
    }

    inputFile.close();
}

void calculateTotalsAndAverages(
    double miles[][NUM_DAYS],
    double totals[],
    double averages[])
{
    for (int row = 0; row < NUM_RUNNERS; row++)
    {
        totals[row] = 0;

        for (int col = 0; col < NUM_DAYS; col++)
        {
            totals[row] += miles[row][col];
        }

        averages[row] = totals[row] / NUM_DAYS;
    }
}
