/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob5
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
    float prceYr1;       //The price of the item one year
    float prceYr2;      //The price of the item in two years
    string plAgain;      //Ask user to loop
    
    //Outputs
    float rateInf1;       //Rate of inflation over the first year
    float rateInf2;       //Rate of Inflation over the seconds year
    float avgRate;        //Average Rate of Inflation
    
    do{
        //User Input Values
        cout << "What is the price of the item today? ";
        cin >> prceTod;
        cout << "What was the price of the item one year ago? ";
        cin >> prceYr1;
        cout << "What was the price of the item two years ago? ";
        cin >> prceYr2;
    
        //Calculations for year 1
        float temp;
        temp = prceTod-prceYr1;
        rateInf1 = temp/prceYr1;
    
        //Output results
        cout << "The rate of inflation is " << rateInf1 << ". \n";
        
        //Calculations for year 2
        temp = prceYr1-prceYr2;
        rateInf2 = temp/prceYr2;
        
        //Output results
        cout << "The rate of inflation is " << rateInf2 << ". \n";
        
        //Calculate average
        avgRate = (rateInf1+rateInf2)/2;
        
        cout << "The average rate of inflation over the last two years is: " << avgRate <<endl;    
        
        //Prompt User to loop program
        cout << "Would you like to run this program again(Yes or no)? ";
        cin >> plAgain;
    }while (plAgain == "Yes"||plAgain == "yes");
    
    //Exit Stage right
    
    return 0;
}