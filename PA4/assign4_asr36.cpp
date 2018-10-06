
// File Name: assign4_asr36.cpp
//
// Author Name: Ayisha S. R. Sowkathali
// Date: 10/07/2015
// Assignment Number: 4
// CS 1428.004 Fall 2015
// Instructor: Jill Seaman
//
// The purpose of this assignment to calculate the amount of the bill given which talk plan
//  the customer subscribes to and how many voice minutes they used during the month.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    char    talkPlan;       // The talk plan the customer chooses.
    int     minutesUsed;    // Total number of minutes used during the month.
    double  totalCost;      // The amount due for the month
    double  amountSaved;    // Amount the customer could have saved by choosing other talkplans.
    
    const int    PLAN_A_MIN     =   450;    // Minutes limited for Plan A.
    const int    PLAN_B_MIN     =   900;    // Minutes limited for Plan B.
    const double PLAN_A_COST    =   39.99;  // Package A costs $39.99 for 450 minutes.
    const double PLAN_A_ADD_MIN =   0.45;   // Package A costs $0.45 for each additional minute.
    const double PLAN_B_COST    =   59.99;  // Package B costs $59.99 for 900 minutes.
    const double PLAN_B_ADD_MIN =   0.40;   // Package B costs $0.40 for each additional minute.
    const double PLAN_C_COST    =   69.99;  // Package C costs $69.99 for unlimited minutes.
    
    cout << "Talk Plans:" << endl;
    cout << "A. The 450 minute plan" << endl;
    cout << "B. The 900 minute plan" << endl;
    cout << "C. The unlimited plan" << endl;
    cout << "Enter which talk plan the customer subscribes to: ";
    cin >> talkPlan;
    
        if (talkPlan != 'A' && talkPlan != 'B' && talkPlan !='C') {
            cout << "Please enter A, B, or C: ";
            cin >> talkPlan;
        }

    cout << "Enter the total number of minutes used during the month: ";
    cin >> minutesUsed;
    
        if (minutesUsed < 0 || minutesUsed > 44640) {
            cout << "Invalid Input.\nRe-enter the total number of minutes used during the month: ";
            cin >> minutesUsed;
        }
    
    cout << fixed << setprecision(2) << endl;
    
    switch (talkPlan) {
        case 'A':
            if (minutesUsed <= PLAN_A_MIN)
            {
                totalCost = PLAN_A_COST;
                cout << "The amount due for the month is $" << totalCost << endl;
            }
            if (minutesUsed > PLAN_A_MIN)
            {
                totalCost = ((minutesUsed - PLAN_A_MIN) * PLAN_A_ADD_MIN) + PLAN_A_COST;
                
                cout << "The amount due for the month is $" << totalCost << endl;
                
                amountSaved = totalCost - PLAN_B_COST;
                
                if (amountSaved <= 0) {
                    cout << " " << endl;
                }
                else
                    cout << "Amount saved if you were on Plan B: $" << amountSaved << endl;
                
                amountSaved = totalCost - PLAN_C_COST;
                
                if (amountSaved <= 0) {
                    cout << " " << endl;
                }
                else
                    cout << "Amount saved if you were on Plan C: $" << amountSaved << endl;
            }
            break;
        case 'B':
            if (minutesUsed <= PLAN_B_MIN)
            {
                totalCost = PLAN_B_COST;
                cout << "The amount due for the month is $" << totalCost << endl;
            }
            if (minutesUsed > PLAN_B_MIN)
            {
                totalCost = ((minutesUsed - PLAN_B_MIN) * PLAN_B_ADD_MIN) + PLAN_B_COST;
                
                cout << "The amount due for the month is $" << totalCost << endl;
                
                amountSaved = totalCost - PLAN_C_COST;
                
                if (amountSaved <= 0) {
                    cout << " " << endl;
                }
                else
                cout << "Amount saved if you were on Plan C: $" << amountSaved << endl;
            }
            break;
        case 'C':
            totalCost = PLAN_C_COST;
            cout << "The amount due for this month is $" << totalCost << endl;
            break;
        default:
            break;
    }
    
    return 0;
}