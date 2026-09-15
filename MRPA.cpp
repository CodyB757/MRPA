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

    displayResults(
        runnerNames,
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

void displayResults(
    string names[],
    double miles[][NUM_DAYS],
    double totals[],
    double averages[])
{
    cout << left << setw(12) << "Runner";

    for (int day = 1; day <= NUM_DAYS; day++)
    {
        cout << setw(8) << day;
    }

    cout << setw(10) << "Total";
    cout << setw(10) << "Average";
    cout << endl;

    for (int row = 0; row < NUM_RUNNERS; row++)
    {
        cout << left << setw(12) << names[row];

        for (int col = 0; col < NUM_DAYS; col++)
        {
            cout << setw(8) << miles[row][col];
        }

        cout << setw(10) << totals[row];

        cout << fixed
            << setprecision(2)
            << setw(10)
            << averages[row];

        cout << endl;
    }
}