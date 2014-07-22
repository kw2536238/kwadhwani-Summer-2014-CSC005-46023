/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob2
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
    //Inputs for Car 1
    float liters1;       //User inputted number of liters
    float miles1;        //User inputted number of miles traveled
    
    //Inputs for Car 2
    float liters2;       //User inputted number of liters
    float miles2;        //User inputted number of miles traveled
    string plAgain;      //User loops program
    
    //Outputs Car 1
    float gals1;         //Conversion to the number of gallons
    float mpg1;          //Miles per gallon
    
    //Outputs for Car 2
    float gals2;         //Conversion to the number of gallons
    float mpg2;          //Miles per gallon
    
    
    
    cout << "Lets calculate your car's MPG! \n";
    
    do{
    
        //Car 1's conversions
        //Car 1 Input
        cout << "How many liters of gasoline have been consumed by car one? ";
        cin >> liters1;
        cout << "How many miles has car one traveled on this amount of liters? ";
        cin >> miles1;
        
        //Car 1 calculation
        gals1 = liters1*CNVGL;
        mpg1 = miles1/gals1;
    
        cout << "Car 1's MPG is " << mpg1 << " miles per gallon!\n";
        cout << "---------------------------------------------\n";
        
        //Car 2 conversions
        //Car 2 Input
        cout << "How many liters of gasoline have been consumed by car two? ";
        cin >> liters2;
        cout << "How many miles has car two traveled on this amount of liters? ";
        cin >> miles2;
    
        //Car 2 calculations
        gals2 = liters2*CNVGL;
        mpg2 = miles2/gals2;
    
        cout << "Car 2's MPG is " << mpg2 << " miles per gallon!\n";
        cout << "---------------------------------------------\n";
        
        if (mpg1>mpg2)
            cout << "Car 1 has a better MPG than car 2!\n";
        else if (mpg2>mpg1)
            cout << "Car 2 has a better MPG than car 1!\n";
        
        cout << "Would you like to run again (Yes or No)? ";
        cin >> plAgain;
        
    }while (plAgain == "yes"||plAgain == "Yes");

    return 0;
}
