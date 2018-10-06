
// File Name: assign2_asr36
//
// Author Name: Ayisha S. R. Sowkathali
// Date: 09/14/2015
// Assignment Number: 2
// CS 1428.004 Fall 2015
// Instructor: Jill Seaman
//
// The purpose of this assignment is to implement what I learned about arithmetic operators and
// cin by calculating the profit from selling books on amabay.com


#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    
    double priceOfBook;
    double weightOfBook;
    double amabayPrct = 0.15;       // Amabay commission percent
    double feebuddyPrct = 0.029;    // Feebuddy commission percent
    double shipRembrmt = 3.99;      // Shipping Reimbersment
    double shipCost = 2.22;
    double amabayComm;              // Amabay Commission
    double feebuddyComm;            // Feebuddy Commission
    double revenue;
    double expenses;
    double shippingCost;            // Final shipping cost
    double totalProfit;
    
    
    cout << "Enter the selling price of the book: ";
    cin >> priceOfBook;
    
    cout << "Enter the weight of the book in pounds: ";
    cin >> weightOfBook;
    
    amabayComm = amabayPrct * priceOfBook;
    
    cout << "amabay commission: $" << amabayComm <<endl;
    
    feebuddyComm = (priceOfBook + shipRembrmt) * feebuddyPrct;
    
    cout << "feebuddy commission: $" << feebuddyComm <<endl;
    
    shippingCost = ceil(weightOfBook) * 0.50 + shipCost;
    
    cout << "Shipping cost: $" << shippingCost << endl;
    
    revenue = priceOfBook + shipRembrmt;
    
    expenses = amabayComm + feebuddyComm + shippingCost;
    
    totalProfit = revenue - expenses;
    
    cout << "Total profit: $" << totalProfit <<endl;
    
    return 0;
}

