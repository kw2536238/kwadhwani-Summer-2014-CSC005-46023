/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob1
 * Created on July 10, 2014, 8:49 PM
 */

//System Level Libraries
#include <iostream>
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants
const float CNVGL = 0.264179f;      //Conversion between gallons and liters 

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    
    //Declare and Initialize Variables
    //Inputs
    float liters;       //User inputted number of liters
    float miles;        //User inputted number of miles traveled
    string plAgain;      //User loops program
    
    //Outputs
    float gals;         //Conversion to the number of gallons
    float mpg;          //Miles per gallon
    
    cout << "Lets calculate your car's MPG! \n";
    
    do{
    
        cout << "How many liters of gasoline have been consumed by your car? ";
        cin >> liters;
        cout << "How many miles has your car traveled on this amount of liters? ";
        cin >> miles;
    
        gals = liters*CNVGL;
        mpg = miles/gals;
    
        cout << "Your car's MPG is " << mpg << " miles per gallon!\n";
        cout << "---------------------------------------------\n";
        
        cout << "Would you like to run again (Yes or No)? ";
        cin >> plAgain;
        
    }while (plAgain == "yes"||plAgain == "Yes");

    return 0;
}

