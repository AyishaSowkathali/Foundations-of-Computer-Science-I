

// File Name: assign6_asr36.cpp
//
// Author Name: Ayisha S. R. Sowkathali
// Date: 11/09/2015
// Assignment Number: 6
// CS 1428.004 Fall 2015
// Instructor: Jill Seaman
//
// This program computes the population of rabbits, its average birth and death rates
// used in the lab using functions.


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void getInput(double &, double &, double &, int &);
double calculatePop(double, double, double);
void outputTable(double, double, double, int);
double yearsToDouble(double);
double yearsToZero(double, double);

int main()
{
    char option;        // Option to choose to re calculate
    do {
        double popSize;     // Initial population size
        double birthRate;   // Birth rate of the rabbits
        double deathRate;   // Death rate of the rabbits
        int years;          // Years
        
        getInput(popSize, birthRate, deathRate, years);
        cout << endl;
        
        outputTable(popSize, birthRate, deathRate, years);
        cout << endl;
        
        if (birthRate > deathRate) {
            int years = ceil(yearsToDouble(birthRate-deathRate));
            cout << endl;
            cout << "Population will double in " << years << " years" << endl;
            cout << endl;
        }
        else if (birthRate < deathRate ) {
            int years = ceil(yearsToZero(popSize, birthRate-deathRate));
            cout << endl;
            cout << "Population will be zero in " << years << " years" << endl;
            cout << endl;
        }
        else
            cout << "Population is stable." << endl;
    
        cout << "Would you like to run the calculator again(Y/N): ";
        cin >> option;
        cout << endl;
    }
    while(option=='y'||option=='Y');

    return 0;
}

// Function to get
void getInput(double &iniPop, double &bRate, double &dRate, int &year)
 {
    cout << "Enter the initial population: ";
    cin >> iniPop;
    while (iniPop < 100 || iniPop > 1000000) {
        cout << "Please enter a value between 100 and 1,000,000: ";
        cin >> iniPop;
     }
    double rate;
    cout << "Enter the annual birth rate (as % of current population): ";
    cin >> rate;
     while (rate <=0 || rate > 100) {
         cout << "Please enter a value between 1 and 100: ";
         cin >> rate;
     }
     bRate = rate/100.0;
     
    cout << "Enter the annual death rate (as % of current population): ";
    cin >> rate;
     while (rate <=0 || rate > 100) {
         cout << "Please enter a value between 1 and 100: ";
         cin >> rate;
     }
     dRate = rate/100.0;
     
    cout << "Enter the number of years of population changes: ";
    cin >> year;
     while (year <=0) {
         cout << "Please enter a value greater than 0: ";
         cin >> year;
     }
 }

// Fuction to output the table
void outputTable(double iniPop, double bRate, double dRate, int year)
{
    double newPop;
    
    cout << "Year" << setw(20) << "Population" << endl;
    cout << "----  ------------------"  << endl;
    //cout << setw(4) << 0 << setw(20) << newPop << endl;
    for (int i = 0; i<=year; i++) {
        newPop = calculatePop(iniPop, bRate, dRate);
        cout << setw(4) << i << setw(20) << floor(newPop) << endl;
        newPop = iniPop;
    }
}


// Function to calculate the new population
double calculatePop(double iniPop, double bRate, double dRate)
{
    return (iniPop + bRate*iniPop - dRate*iniPop);
}

// Function to show after which year the population will double in size
double yearsToDouble(double r)
{
    return (log(2)/log(1+r));;
}

// Function to show after which year the population will become zero
double yearsToZero(double iniPop, double gRate)
{
    return (log(1/iniPop)/log(1+gRate));;
}


