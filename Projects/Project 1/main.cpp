/* 
 * File:   main.cpp
 * Author: Krishen Wadhwani
 * Purpose: Blackjack Player
 * Created on July 9, 2014, 10:16 AM
 */

//System Level libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare and Initialize Variables
    
    //The dealers card values
    short d;    //Index variable for the dealer
    const short ct = 0; //A count variable set equal to 0
    short dCdVal[10];    //The cardValue where the card will be randomized
    char dCdName[10]={0,0,0,0,0,0,0,0,0,0};    //The actual name of the card to be displayed at the end
    short dValue[10];    //The value of the respecting cards
    short dealVal = 0;  //The total value of the dealers cards
    short numLoop = 1;  //The number of loops where the user hits (so that aces can be checked for)
    short fdAce = 0;    //The number of aces found
    
    //The players card values
    short i;    //Index Variable for player
    short f = 2;    //Second Index Variable for player
    short cdVal[10];     //The cardValue where the card will be randomized
    char cdName[10]={0,0,0,0,0,0,0,0,0,0};     //The actual name of the card to be displayed. 
    short value[10];     //The value of the respecting card
    short playVal = 0;  //The total value of the users cards
    string hit;     //Whether or not the player would like to hit

    short count = 0;    //count variable
    short wins = 0;     //total number of wins
    short losses = 0;   //total number of losses
    short draws = 0;    //total number of draws
    short nGames = 0;   //total number of games played.
    
    
    //Introduction
    cout << "Let's play some BlackJack!!\n";
    cout << "The goal of this game is to simply attain a number close to 21 \nwithout going over 21. ";
    cout << "Each card is valued by its number (a 3 card is \nworth 3 points) while face cards (King, Queen, Jack) are worth 10." <<endl;
    cout << "The Ace is worth either 1 or 11 points, which will be determined by \nthe program for you. In this program, the cards are represnted by \ntheir first letter (e.g. ten = t)." <<endl<<endl;
    //User inputs how many games to play
    cout << "How many games would you like to play? ";
    cin >> nGames;
    
    //Loop the program for number of games
    do {
        short temp;
        temp = count+1;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Game " << temp <<endl;
                
        //********************Creating the total values for the dealer and user********************
        //Set random seed
        srand(static_cast<unsigned short>(time(0)));
    
        //****Drawing the cards for the dealer****
        //Randomly pick a number between 1 and 13
        for (d=10; d>=ct; d--){
            dCdVal[d] = rand()%13+1;
            
            //Correlate the random value to a card type (for output purposes)
            if (dCdVal[d] == 1)
                dCdName[d] = 'A';
            else if (dCdVal[d] == 2)
                dCdName[d] = '2';
            else if (dCdVal[d] == 3)
                dCdName[d] = '3';
            else if (dCdVal[d] == 4)
                dCdName[d] = '4';
            else if (dCdVal[d] == 5)
                dCdName[d] = '5';
            else if (dCdVal[d] == 6)
                dCdName[d] = '6';
            else if (dCdVal[d] == 7)
                dCdName[d] = '7';
            else if (dCdVal[d] == 8)
                dCdName[d] = '8';
            else if (dCdVal[d] == 9)
                dCdName[d] = '9';
            else if (dCdVal[d] == 10)
                dCdName[d] = 'T';
            else if (dCdVal[d] == 11)
                dCdName[d] = 'J';
            else if (dCdVal[d] == 12)
                dCdName[d] = 'Q';
            else if (dCdVal[d] == 13)
                dCdName[d] = 'K';
            else
                dCdName[d] = 'E';
        }
        
        d=10;    //reset the index value
        //Assign a blackjack value for each type of card (e.g. King is worth 10)
        while (d>=0){
            //Number cards
            if (dCdName[d] == '2'||dCdName[d] == '3'||dCdName[d] == '4'||dCdName[d] == '5'||
                dCdName[d] == '6'||dCdName[d] == '7'||dCdName[d] == '8'||dCdName[d] == '9'){
                dValue[d] = dCdVal[d];
            }
            //letter cards
            else if (dCdName[d] == 'K'||dCdName[d] == 'Q'||dCdName[d] == 'J' || dCdName[d] == 'T'){
                dValue[d] = 10;
            }
            //Ace
            else if (dCdName[d] = 'A'){
                dValue[d] = 11;
            }
            d--;
        }                
        
        //Output one card (Because one of them is face down on the table )
        cout << "One of the dealer's cards is a " << dCdName[0] <<endl;
    
        //Calculate the total of the dealers cards
        dealVal = dValue[1]+dValue[0];
    
        //Account for if the dealer wants to hit again (he must do if his total is less than 17)
        d=1;
        x=1;
        while(dealVal < 17 || dealVal == 22){
            cout << "The dealer hits a " << dCdName[x]<<endl;
            dealVal += dValue[x];
            numLoop++;
            x++;
            
            //Account for if the ace causes the total to be over 11.
            for(d=0; d<=numLoop; d++){
                if (dealVal > 21 && dValue[d] == 11){
                    dValue[d] = 1;
                    dealVal -=10;
                    fdAce++;
                }
            }
            //Accounts for the fact that the above 'for' loop runs twice (due to loop embedding)
            //dealVal = dealVal + 10*(fdAce/2);
        }
    
        //Extra line of code for testing purposes if needed
        // cout << "The dealers total card value is "  << dealVal <<endl;
        
        //****Drawing the first two cards for the user****
        //Randomly pick a number between 1 and 13
        for (i=10; i>=ct; i--){
            cdVal[i] = rand()%13+1;
            
            //Correlate the random value to a card type (for output purposes)
            if (cdVal[i] == 1)
                cdName[i] = 'A';
            else if (cdVal[i] == 2)
                cdName[i] = '2';
            else if (cdVal[i] == 3)
                cdName[i] = '3';
            else if (cdVal[i] == 4)
                cdName[i] = '4';
            else if (cdVal[i] == 5)
                cdName[i] = '5';
            else if (cdVal[i] == 6)
                cdName[i] = '6';
            else if (cdVal[i] == 7)
                cdName[i] = '7';
            else if (cdVal[i] == 8)
                cdName[i] = '8';
            else if (cdVal[i] == 9)
                cdName[i] = '9';
            else if (cdVal[i] == 10)
                cdName[i] = 'T';
            else if (cdVal[i] == 11)
                cdName[i] = 'J';
            else if (cdVal[i] == 12)
                cdName[i] = 'Q';
            else if (cdVal[i] == 13)
                cdName[i] = 'K';
            else
                cdName[i] = 'E';
        }
        //Output the user's card values
        cout << "Your cards are " << cdName[1] << "-" << cdName[0]<<endl;
        
        //Reset the Index Variable
        i = 10;
        
        //Assign a blackjack value for each type of card (e.g. King is worth 10)
        while (i>=0){
            //Number cards
            if (cdName[i] == '2'||cdName[i] == '3'||cdName[i] == '4'||cdName[i] == '5'||
                cdName[i] == '6'||cdName[i] == '7'||cdName[i] == '8'||cdName[i] == '9'){
                value[i] = cdVal[i];
            }
            //Face cards
            else if (cdName[i] == 'K'||cdName[i] == 'Q'||cdName[i] == 'J' || cdName[i] == 'T'){
                value[i] = 10;
            }
            //The Ace is initially given a value of 11, but later may be changed
            else if (cdName[i] = 'A'){
                value[i] = 11;
            }
            i--;
        }
        
        //To account for double aces in the initial hand
        if (value[0] == 11 && value[1] == 11){
            value[0] = 1;
        }
        //Calculate the value of the first two cards
        playVal = value[0] + value[1];
        cout << "The total value of your cards is " << playVal <<endl;
        
        //First player hit
        if (playVal < 21){
            cout << "Would you like to hit(Yes or no)?" ;
            cin >> hit;
        }
        //Account for if the player would like to hit
        while(hit == "yes" || hit == "Yes"){
            //reset the index variable, numLoop, and fdAce
            numLoop = 2;
            fdAce = 0;
            
            //Output pre-calculated value of the next card
            cout << "You drew a  " << cdName[f]<<endl;
            
            //Add it to the total
            playVal += value[f];
             
            //increment numLoop to loop ace program
            numLoop++;
            f++;
                 
            //Account for if the ace causes the total to be over 11.
            for(i=0; i<numLoop; i++){
                if (playVal > 21 && value[i] == 11){
                    value[i] = 1;
                    playVal -=10;
                    fdAce++;
                    cout << "Your ace has changed from an 11 to a 1."<<endl;
                }
            }
            
            //output the new total
            cout << "Your new total is " << playVal <<endl;
                
            //If total value is still under 21, allow the user to hit again
            if (playVal <21){
                cout << "Would you like to hit again(Yes or no)?";
                cin >> hit;
            }
            else {
                hit = "no";
            }
        }
        /*
        x--;
        cout << "The dealer's cards were: " <<dCdName[0];
        while (x>=ct){
            cout << "-" << dCdName[x];
            x--;
        }
         */
        
        //Output the dealers total
        cout << "The dealer's total was " << dealVal <<endl<<endl;
        
        //********************Compare the dealer and player values********************
        
        //If player has 21
        if (playVal == 21 && dealVal != 21){
            cout << "Congratulations you got BlackJack! You win!";
            wins++;
        }
        //If dealer has 21
        else if (dealVal == 21 && playVal != 21){
            cout << "The dealer got BlackJack! You lose!";
            losses++;
        }
        //If dealer and player bust
        else if(dealVal > 21 && playVal > 21){
            cout << "You and the dealer bust! It is a draw";
            draws++;
        }
        //If dealer bust
        else if (dealVal > 21){
            cout << "The dealer bust! You win!";
            wins++;
        }
        //If player bust
        else if (playVal > 21){
            cout << "You bust! You lose!";
            losses++;
        }
        //If player and dealer tie above 17
        else if(playVal == dealVal && playVal >=17){
            cout << "You and the dealer tied and were above 17! It is a draw!";
            draws++;
        }
        //If player and dealer tie under 17 (Should never happen)
        else if (playVal == dealVal && playVal < 17){
            cout << "You and the dealer tied and were below 17! You lose!";
            losses++;
        }
        //If player has a higher hand than dealer
        else if (playVal > dealVal){
            cout << "You have a larger number than the dealer! You win!";
            wins++;
        }
        //If player has a lower hand than dealer
        else if (playVal < dealVal){
            cout << "You have a lower number than the dealer! You lose!";
            losses++;
        }
        
        //reset initial values for next loop
        cout <<endl;
        d=1;
        numLoop = 1;
        count ++;
    }while(nGames>count);
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ End " <<endl;
    
    //Output wins, losses, and draws
    cout << "Your total number of wins was: " << wins <<endl;
    cout << "Your total number of losses was: " <<losses <<endl;
    cout << "Your total number of draws was: " << draws <<endl;
    
    //Exit Stage Right  
}

