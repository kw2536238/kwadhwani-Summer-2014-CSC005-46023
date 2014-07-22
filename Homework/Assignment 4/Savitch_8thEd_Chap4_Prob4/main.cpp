/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob4
 * Created on July 10, 2014, 10:18 PM
 */

//System Level Libraries
#include <iostream>
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Initialize and Declare Variables
    //Inputs
    float prceTod;      //The price of the item today
    float prceYr;       //The price of the item one year
    string plAgain;      //Ask user to loop
    
    //Outputs
    float rateInf;       //Rate of inflation
    
    do{
        //User Input Values
        cout << "What is the price of the item today? ";
        cin >> prceTod;
        cout << "What was the price of the item one year ago? ";
        cin >> prceYr;
    
        //Calculations
        float temp;
        temp = prceTod-prceYr;
        rateInf = temp/prceYr;
    
        //Output results
        cout << "The rate of inflation is " << rateInf << ". \n";
        
        //Prompt User to loop program
        cout << "Would you like to run this program again(Yes or no)? ";
        cin >> plAgain;
    }while (plAgain == "Yes"||plAgain == "yes");
    
    //Exit Stage right
    
    return 0;
}