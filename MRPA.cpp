// Cody Blake
// CSC 222
// Marathon Runners Parallel Arrays Project (MRPA)
//September 10th, 2026

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

    return 0;
}