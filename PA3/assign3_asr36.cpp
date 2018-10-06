

// File Name: assign3_asr36.cpp
//
// Author Name: Ayisha S. R. Sowkathali
// Date: 09/28/2015
// Assignment Number: 3
// CS 1428.004 Fall 2015
// Instructor: Jill Seaman
//
// The purpose of this assignment is to implement what I learned about cin functions
// and fstream library to calculate and output the average of a result of an
// experiment.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string  name1,      // Name of Rat # 1
            name2,      // Name of Rat # 2
            name3;      // Name of Rat # 3
    
    double  time1_1,    // Time taken for Rat 1 to run through the maze on day 1
            time2_1,    // Time taken for Rat 1 to run through the maze on day 2
            time3_1;    // Time taken for Rat 1 to run through the maze on day 3
    
    double  time1_2,    // Time taken for Rat 2 to run through the maze on day 1
            time2_2,    // Time taken for Rat 2 to run through the maze on day 2
            time3_2;    // Time taken for Rat 2 to run through the maze on day 3
    
    double  time1_3,    // Time taken for Rat 3 to run through the maze on day 1
            time2_3,    // Time taken for Rat 3 to run through the maze on day 2
            time3_3;    // Time taken for Rat 3 to run through the maze on day 3
    
    double  average1,   // Average time it took for Rat 1
            average2,   // Average time it took for Rat 2
            average3;   // Average time it took for Rat 3
    
    string  rating;     // Rating for the rats based on the average time it took to run through the maze.
    
    
    ofstream fout;
    fout.open("lab_report.txt");
    
    cout << "Please enter the name of the first rat." << endl;
    getline(cin, name1);
    
    cout << "Please enter three maze times for the first rat." << endl;
    cin >> time1_1 >> time2_1 >> time3_1;
    
    cin.ignore();
    
    cout << "Please enter the name of the second rat." << endl;
    getline(cin, name2);
    
    cout << "Please enter three maze times for the second rat." << endl;
    cin >> time1_2 >> time2_2 >> time3_2;
    
    cin.ignore();
    
    cout << "Please enter the name of the third rat." << endl;
    getline(cin, name3);
    
    cout << "Please enter three maze times for the third rat." << endl;
    cin >> time1_3 >> time2_3 >> time3_3;
    
    
    // Average Calculations of time for each rats.
    average1 = (time1_1+time2_1+time3_1)/3;
    average2 = (time1_2+time2_2+time3_2)/3;
    average3 = (time1_3+time2_3+time3_3)/3;
    
    // Ratings for the rats based on the average time it took to run through the maze
    
    if (average1 > 30 || average2 > 30 || average3 > 30)
    {
        rating = "Normal";
   
    }
    else
    {
       if (average1 < 30 || average2 < 30 || average3 < 30)
        {
            
            rating = "Smart";
        }
    }
    
    
    // Output to the the screen
    
    cout << "Name \t\t\t   Time 1 Time 2 Time 3    Avg   Rating" << endl;
    
    cout    << left << setw(20) << name1
            << setw(7) << fixed << setprecision(0) << time1_1
            << setw(7) << time2_1 << setw(7) << time3_1
            <<  setw(7) << setprecision(1) << average1
            << setw(7) << rating << endl;
    
    cout    << left << setw(20) << name2
            << setw(7)  << fixed << setprecision(0) << time1_2
            << setw(7)<< time2_2 << setw(7) << time3_2
            << setw(7) << setprecision(1) << average2
            << setw(7) << rating << endl;
    
    cout    << left << setw(20) << name3
            << setw(7)  << setprecision(0) << time1_3
            << setw(7) << time2_3 << setw(7) << time3_3
            << setw(7) << setprecision(1) << average3
            << setw(7) << rating << endl;
    
    // Data output to the file named "lab_report.txt".
    
    fout << "Name \t\t  Time 1 Time 2 Time 3    Avg   Rating" << endl;
    
    fout    << left << setw(20) << name1
            << setw(7) << fixed << setprecision(0) << time1_1
            << setw(7) << time2_1 << setw(7) << time3_1
            <<  setw(7) << setprecision(1) << average1
            << setw(7) << rating<< endl;
    
    fout    << left << setw(20) << name2
            << setw(7)  << setprecision(0) << time1_2
            << setw(7)<< time2_2 << setw(7) << time3_2
            << setw(7) << setprecision(1) << average2
            << setw(7) << rating<< endl;
    
    fout    << left << setw(20) << name3
            << setw(7)  << setprecision(0) << time1_3
            << setw(7) << time2_3 << setw(7) << time3_3
            << setw(7) << setprecision(1) << average3
            << setw(7) << rating<< endl;
    
    fout.close();
    
    return 0;
    
}

