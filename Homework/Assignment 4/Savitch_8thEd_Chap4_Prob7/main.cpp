/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob7
 * Created on July 14, 2014, 9:56 AM
 */

//System Level Libraries
#include <iostream>
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants
const float UNGRAVC = 6.673e-8f;        //The Universal gravitational constant  = 6.673*10^-8 in (cm^3)/(g*sec^2)

//Function Prototypes
void gravityCalc();

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare and Initialize Variables
    //Inputs
    float mass1,        //Mass of the first object
          mass2,        //Mass of the second object
          dist;         //distance between the two objects
    string plAgain;
    
    //Outputs
    float g;            //the force of gravity
    
    //Looping the program
    do {
        
    //Retrieve data from user
    cout << "Let's calculate the force of gravity between two masses!" <<endl;
    cout << "What is the mass of the first object(in grams)? ";
    cin >> mass1;
    cout << "What is the mass of the second object(in grams)? ";
    cin >> mass2;
    cout << "What is the distance between the two objects(in centimeters)? ";
    cin >> dist;
   
    //Calculate the gravity from user inputted data
    g = UNGRAVC*mass1*mass2/dist/dist;
    
    //Output the data
    cout << "The force between these two objects is " << g << " dynes." <<endl;
    
    cout << "-----------------------------------------------------------------\n";
    
    //Allows user to run program again
    cout << "Would you like to run this program again? ";
    cin >> plAgain;
            
    }while (plAgain == "Yes"||plAgain == "yes");
    
    //Exit Stage Right
    return 0;
}
