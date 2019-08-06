// The Machine Learning K-Means Algorithm
// By: Karen Proft
// Semptember 27, 2018


#include <iostream>
#include <array>
#include <math.h>
#include <algorithm>

using namespace std;

//Prints the total set of samples
void printSet(float s[][2], int setSize)
{
    for (int i = 0; i < setSize; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                cout << "(" << s[i][j] << ", ";
            }
            else
            {
                cout << s[i][j] << ") ";
            }
        }
    }
}

//Assigns a random centoid between (0, 0) and (10, 10)
void assignRandomCenters(float c[][2], int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            float randCenter = ((float)rand()) /( (float) (RAND_MAX/(10)));
            c[i][j] = randCenter;
        }
    }
}

//Finds the center of a cluster based on the average of all samples in that
//cluster and assigns the centoid to that location
void assignAveragedCenters(float c[][2], float s[8][2], int  a[8], int k)
{
    for (int i = 0; i < k; i++)
    {
        float samplesInCluster = 0;
        float addXs = 0;
        float addYs = 0;
        for(int j = 0; j < 8; j++)
        {
            if(a[j] == i)
            {
                addXs += s[j][0];
                addYs += s[j][1];
                samplesInCluster++;
            }
        }

        float xValue = addXs / samplesInCluster;
        float yValue = addYs / samplesInCluster;
        c[i][0] = xValue;
        c[i][1] = yValue;
    }
}

//Calculates the similarity/distance function between two vectors using the function |x1 - x2| + |y1 - y2|
float calculateDistance(float s[8][2], float c[][2], int sample, int centoid)
{
    float distance = abs(s[sample][0] - c[centoid][0]) + abs(s[sample][1] - c[centoid][1]);
    return distance;
}

//Calculates the distance from each sample to each centoid and stores it in a 2d array
void calculateAllDistances(float s[8][2], float c[][2], float dArray[][8], int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dArray[i][j] = calculateDistance(s, c, j, i);
        }
    }
}

//Determines which sample belongs in which cluster based on similarity/distance
void decideClusters(float dArray[][8], int a[8], int k)
{
    float minDistance;
    for (int i = 0; i < 8; i++)
    {
        minDistance = dArray[0][i];
        a[i] = 0;
        for (int j = 0; j < k; j++)
        {
            if (dArray[j][i] < minDistance)
            {
                minDistance = dArray[j][i];
                a[i] = j;
            }
        }
    }
}

//Prints the final output of which samples belong in which cluster
void printClusterOutput(int a[8], int k)
{
    cout << "The final clustering result is:\n";
    for (int i = 0; i < k; i++)
    {
        cout << "Cluster " << i + 1 << " : (";
        for (int j = 0; j < 8; j++)
        {
            if (a[j] == i)
            {
                cout << "A" << j + 1 << ", ";
            }
        }
        cout << ")\n";
    }
}

int main()
{
    //Initialize Variables
    int k = 3;
    float s[8][2] = {{2, 10},
                  {2, 5},
                  {8, 4},
                  {5, 8},
                  {7, 5},
                  {6, 4},
                  {1, 2},
                  {4, 9}};
    int a[8];

    cout << "The Data set contains 8 samples:\n";
    printSet(s, 8);

    // Run the program 5 times starting with different initial cluster centoids
    float c[k][2];
    for (int i = 0; i < 5; i++)
    {
        switch(i)
        {
            case 0:
                c[0][0] = 2;//x1 - A1
                c[0][1] = 10;//y1
                c[1][0] = 1;//x2 - A7
                c[1][1] = 2;//y2
                c[2][0] = 4;//x3 - A8
                c[2][1] = 9;//y3
                break;
            case 1:
                c[0][0] = 2;//x1 - A2
                c[0][1] = 5;//y1
                c[1][0] = 6;//x2 - A6
                c[1][1] = 4;//y2
                c[2][0] = 4;//x3 - A8
                c[2][1] = 9;//y3
                break;
            case 2:
                c[0][0] = 8;//x1 - A3
                c[0][1] = 4;//y1
                c[1][0] = 7;//x2 - A5
                c[1][1] = 5;//y2
                c[2][0] = 6;//x3 - A6
                c[2][1] = 4;//y3
                break;
            case 3:
                c[0][0] =2;//x1 - A2
                c[0][1] =5;//y1
                c[1][0] =8;//x2 - A3
                c[1][1] =4;//y2
                c[2][0] =1;//x3 - A7
                c[2][1] =2;//y3
                break;
            case 4:
                assignRandomCenters(c, k); //Random centoids
                break;
            default:
                break;
        };

        cout <<"\n\nRound "<< i + 1 << ". The initial centoids are:\n";
        printSet(c, k);
        cout << "\n";

        // Calculate the distance from each sample to each centoid and store it in a 2d array - distancesArray.
        float distancesArray[k][8];
        bool centoidsChanged = true;
        float oldCentoids[k][2];
        int iterationsRun = 0;
        while(centoidsChanged == true)
        {
            calculateAllDistances(s, c, distancesArray, k);

            decideClusters(distancesArray, a, k);

            // Save off old centoid locations and assign new locations for each centoid
            for (int j = 0; j < k; j++)
            {
                oldCentoids[j][0] = c[j][0];
                oldCentoids[j][1] = c[j][1];
            }
            assignAveragedCenters(c, s, a, k);

            // If the new centoids are all the same as the old centoids, stop loop
            if ((c[0][0] == oldCentoids[0][0]) && (c[0][1] == oldCentoids[0][1]) &&
                (c[1][0] == oldCentoids[1][0]) && (c[1][1] == oldCentoids[1][1]) &&
                (c[2][0] == oldCentoids[2][0]) && (c[2][1] == oldCentoids[2][1]))
            {
                centoidsChanged = false;
            }

            iterationsRun++;
        }

        cout << iterationsRun << " iterations of reclustering have been run for this round.\n\n";
        printClusterOutput(a, k);
        cout << "--------------------------------";

    }

    return 0;
}
