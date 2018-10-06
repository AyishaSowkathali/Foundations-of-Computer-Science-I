//
//  PA6_Example.cpp
//  PA6
//
//  Created by Shiha on 11/7/15.
//  Copyright © 2015 ASR. All rights reserved.
//

#include "PA6_Example.hpp"
#include <iostream>
using namespace std;

int projectedNewSize(float population, float annualBirthRate, float annualDeathRate) {
    
    int newpopulation = population * (1 + annualBirthRate) * (1 - annualDeathRate);
    return newpopulation;
}

int main() {
    
    int populationStartingSize = 0;
    float annualBirthRate = 0;
    float annualDeathRate = 0;
    int numberOfYearsToDisplay = 0;
    
    do  {
        cout << "Enter starting population size: ";
        cin >> populationStartingSize;
        cout << "Enter annual birth rate: ";
        cin >> annualBirthRate;
        cout << "Enter annual death rate: ";
        cin >> annualDeathRate;
        cout << "Enter years to display: ";
        cin >> numberOfYearsToDisplay;
    } while (!(populationStartingSize >= 2) || !(numberOfYearsToDisplay >= 1));
    
    int population;
    
    for (int i = 1; i <= numberOfYearsToDisplay; i++) {
        cout << "Year " << i << ": " << populationStartingSize << " ";
        population = projectedNewSize(populationStartingSize, annualBirthRate, annualDeathRate);
        cout << population << endl;
        populationStartingSize = population;
    }
    return 0;
}
