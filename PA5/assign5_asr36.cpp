

// File Name: assign5_asr36.cpp
//
// Author Name: Ayisha S. R. Sowkathali
// Date: 10/26/2015
// Assignment Number: 5
// CS 1428.004 Fall 2015
// Instructor: Jill Seaman
//
// This program computes some statistics based on daily high temperatures
// of summer months (June, July and August) using arrays and loops.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{

    const int   SIZE = 90;  // Number of days in all summer months.
    const int   DAYS = 30;  // Number of days in each summer months.

    string      title;      // The title of the input file.
    string      june[DAYS]; // Dates of June
    string      july[DAYS]; // Dates of July
    string      aug[DAYS];  // Dates of August

    double      average;    // Average of temperatures of Summer months.
    int         counter=0;  // To find the number of days reached 100.
    int         count;      // Variable to iterate the days
    int         sum=0;      // Sum of temperatures of Summer months.
    // Daily temperatures in the month of June, July and August
    int         juneTemp[DAYS];
    int         julyTemp[DAYS];
    int         augTemp[DAYS];
    // To find Maximum temperature within each summer months.
    int         maxJune=0;
    int         maxJuly=0;
    int         maxAugust=0;
    // To find the date, the maximum temperature occur
    int         juneDate=0;
    int         julyDate=0;
    int         augDate=0;

    // Opening the input file
    ifstream    fin;
    fin.open("tempdata.txt");

    if(!fin){
        cout << "File Not found" << endl;
    }

    // Reading the title from the input file
    getline(fin, title);

    // Calculating the statistics of daily temperature
    for(count=0; count < DAYS; count++){
        fin >> june[count] >> juneTemp[count];
        sum = sum + juneTemp[count];
        if (juneTemp[count]==100){
            counter++;
        }
        if (juneTemp[count]>maxJune){
            maxJune = juneTemp[count];
            juneDate = count+1;
        }
    }

    for(count=0; count < DAYS; count++){
        fin >> july[count] >> julyTemp[count];
        sum = sum + julyTemp[count];
        if (julyTemp[count]==100){
            counter++;
        }
        if (julyTemp[count]>maxJuly) {
            maxJuly = julyTemp[count];
            julyDate = count+1;
        }
    }

    for(count=0; count < DAYS; count++) {
        fin >> aug[count] >> augTemp[count];
        sum = sum + augTemp[count];
        if (augTemp[count]==100){
            counter++;
        }
        if(augTemp[count]>maxAugust) {
            maxAugust = augTemp[count];
            augDate = count+1;
        }
    }

    // calculating the average temperature of the summer months.
    average = static_cast<double>(sum)/SIZE;

    // Output
    cout << fixed << setprecision(1);
    cout << "High temperature statistics for the summer: "
         << endl << endl;
    cout << "Average daily high temperature: "
         << average << endl << endl;
    cout << "Number of days that reached 100 degrees: "
         << counter << endl << endl;
    cout << "Maximum temperature for June: " << maxJune
         << " occured on June " << juneDate << endl;
    cout << "Maximum temperature for July: " << maxJuly
         << " occured on July " << julyDate << endl;
    cout << "Maximum temperature for August: " << maxAugust
         << " occured on August " << augDate << endl;
    cout << endl;

   // Closing the input file
   fin.close();

  return 0;
}
