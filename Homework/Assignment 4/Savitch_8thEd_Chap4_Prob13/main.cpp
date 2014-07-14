/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob13
 * Created on July 14, 2014, 9:56 AM
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
    
    unsigned short nBottles;
    unsigned short count = 0;
    
    
    cout << "Let's sing Bottles of Beer on the wall!\n";
    cout << "How many bottles would you like to start with? ";
    cin >> nBottles;
    
    while(nBottles > count){
        
        cout << "-------------------------------------------------------------";
   
        cout << "There are " << nBottles << " bottles of beer on the wall, \n";
        cout << nBottles << " bottles of beer, \n";
        cout << "take one down, pass it around, \n";
        nBottles--;
        cout << nBottles << " bottles of beer on the wall!\n" <<endl;
                
    }
    
    return 0;
}

