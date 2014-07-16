/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Savitch_8thEd_Chap4_Prob13
 * Created on July 14, 2014, 9:56 AM
 */

//System Level Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
float calories1(float);                 //Used to calculate the basal metabolic rate
float calories2(float, float, float);   //Used to account for physical activity
float totalCalories(float);             //Taking into account the calories required for digestion

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare and Initialize Variables
    //Inputs
    float p;            //Weight in pounds
    float i;            //intensity of physical activity
    float min;          //time in minutes of the physical activity
    const float CALCB = 1.0/1000.0f;  //Calories in a cheeseburger
    float nCB;          //number of cheeseburgers required
    
    //Outputs
    float cal3;         //the total calories from bmr and physical activity, but not for digestion
    
    //User inputs weight, intensity, and minutes
    cout << "How much do you weigh(in pounds)? ";
    cin >> p;
    cout << "On a scale of 1-20, how would you classify the intensity of your daily average exercise? ";
    cin >> i;
    cout << "How many minutes per exercise activity do you spend on it?";
    cin >> min;
    
    //Set functions for each       
    float cal1 = calories1(p);                  //cal1 is the number of calories required for bmr
    float cal2 = calories2(p,i,min);            //cal2 is the number of calories required for physical activity
    cal3 = cal1+cal2;
    float totCal = totalCalories(cal3);         //totCal accounts for total calories required including digestion
    
    //Calculate total number of cheeseburgers required in accordance to the total calories required
    nCB = totCal*CALCB;
    
    //Output results
    cout << "The total number of cheeseburgers required to mantain your weight is " << nCB <<endl;
    
    
    return 0;
}

//calories1
//Function used to calculate the total calories needed for the basal metabolic rate
//p = weight of the person in pounds
float calories1(float p){
    float temp;
    temp = p/2.2f;
    return (70*pow(temp,0.756));
}

//calories2
//Function used to calculate the total calories for physical activity
//p = weight of the person in pounds
//i = intensity of physical exercise
//min = minutes for physical exercise
float calories2(float p, float i, float min){
    return(0.0385*i*p*min);
}

//totalCalories
//Function to account for calories required for the digestion of food
//cal3 = the total calories from bmr and physical activity, but not for digestion
//cal3 = cal1+cal2
float totalCalories(float cal3){
    return (cal3*1.1);
}

