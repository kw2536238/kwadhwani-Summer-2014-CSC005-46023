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
    
    //The players card values
    short i;    //Index Variable for player
    short cdVal[10];     //The cardValue where the card will be randomized
    char cdName[10]={0,0,0,0,0,0,0,0,0,0};     //The actual name of the card to be displayed. 
    short value[10];     //The value of the respecting card
    short playVal = 0;  //The total value of the users cards
    string hit;
    
    //The dealers card values
    short d;    //Index variable for the dealer
    short ct2 = 0;
    short dCdVal[10];    //The cardValue where the card will be randomized
    char dCdName[10]={0,0,0,0,0,0,0,0,0,0};    //The actual name of the card to be displayed at the end
    short dValue[10];    //The value of the respecting cards
    short dealVal = 0;  //The total value of the dealers cards
    short numLoop = 2;
    short fdAce = 0;
    

    short endLoop = 0;
    short count = 0;
    short wins = 0, losses = 0;
    short nGames = 0;
    
    
    
    cout << "Let's play some BlackJack!!\n";
    cout << "How many Games would you like to play? ";
    cin >> nGames;
    do {
        //Set random seed
        srand(static_cast<unsigned short>(time(0)));
    
        //****Drawing the cards for the dealer****
        //Randomly choose cards
        for (d=10; d>=ct2; d--){
            dCdVal[d] = rand()%13+1;
            
            //Convert the random value to a card type (for output purposes)
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
        //Create a blackjack value for each type of card (e.g. King is worth 10)
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
        
        //Output one card (Because one of them is face down. )
        cout << "The dealer cards are " << dCdName[0] << "-" << dCdName[1] <<endl;
    
        //Calculate the total of the dealers cards
        dealVal = dValue[1]+dValue[0];
    
        //Account for if the dealer wants to hit again
        d=2;
        while(dealVal < 17){
            cout << "The dealer hits a " << dCdName[d]<<endl;
            dealVal += dValue[d];
            d++;
            numLoop++;
            
            //Account for if the ace causes the total to be over 11.
            for(d=0; d<numLoop; d++){
                if (dealVal > 21 && dValue[d] == 11){
                    dealVal -=10;
                    fdAce++;
                }
            }
            //Accounts for the fact that the above 'for' loop runs twice (due to loop embedding)
            dealVal = dealVal + 10*(fdAce/2);
        }
    
        cout << "The dealers total card value is "  << dealVal <<endl;
        //****Drawing the first two cards for the user****
    
        for (i=10; i>=0; i--){
            cdVal[i] = rand()%13+1;
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
        
        //
        cout << "Your cards are " << cdName[1] << "-" << cdName[0]<<endl;
        i = 10;
        while (i>=0){
            if (cdName[i] == '2'||cdName[i] == '3'||cdName[i] == '4'||cdName[i] == '5'||
                cdName[i] == '6'||cdName[i] == '7'||cdName[i] == '8'||cdName[i] == '9'){
                value[i] = cdVal[i];
            }
            else if (cdName[i] == 'K'||cdName[i] == 'Q'||cdName[i] == 'J' || cdName[i] == 'T'){
                value[i] = 10;
            }
            else if (cdName[i] = 'A'){
                value[i] = 11;
            }
            i--;
        }
          
        playVal = value[0] + value[1];
        cout << "The total value of your cards is " << playVal <<endl;
        
        while(playVal < 21 && endLoop == 0){
            cout << "Would you like to hit? " ;
            cin >> hit;
        
            i = 2;
            numLoop = 2;
            fdAce = 0;
            if (hit == "yes" || hit == "Yes"){
                do{
                    cout << "You drew a  " << cdName[i]<<endl;
                    playVal += value[i];
                    i++;
                    numLoop++;
            
                    //Account for if the ace causes the total to be over 11.
                    for(i=0; i<numLoop; i++){
                        if (playVal > 21 && value[i] == 11){
                            playVal -=10;
                            fdAce++;
                        }
                    }
                    //Accounts for the fact that the above 'for' loop runs twice (due to loop embedding)
                    playVal = playVal + 10*(fdAce/2);
                }while (playVal);
                
                cout << "Your new total is " << playVal <<endl;
            }
            else{
                endLoop = 1;
            } 
        }
    
        endLoop = 0;
        count ++;
        numLoop = 2;
    }while(nGames>count);

}

