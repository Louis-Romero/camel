// Name: Louis Romero, Ali Fenton
// Date: November 10, 2015
// Programming: Camel Game

#include <iostream> 
#include <cctype> 
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
This game is about how you stole a camel to get across the great Mobi desert. The natives are after you and want there camel back. To get though the desert you have to travel 200 miles. You have to becareful when traveling the desert you need to make sure you have enough water, the camel isn't tired, the natives aren't getting close, and other types of danger. For example, sandstorm can come out of no where or poisonous snakes, that could pop out and kill you. But if you are lucky you could find an oasis, so the camal can rest, you can drink some water and fill up your canteen. If you do make it out of the great Mobi desert you win the game or you die trying.
*/

void askUserToContinue(int& miles, int& drinksLeft, int& nativesMiles);
void camelTired(int& tiredness, int& nDistance);
void fullSpeed(int& miles, int& thirst, int& tiredness, int& natives);
void normalSpeed(int& miles, int& thirst, int& tiredness, int& natives);
void drinkWater(int& thirstyness, int& drinks);
void oasis(int& drinks, int& thirst, int& tiredness);
void sandstorm(int& thirst, int& tiredness, int& natives);
void snakeKills(bool& snake);

int main() 
{
    
    
    bool done = false; 
    char userInput;
    int milesTraveled = 0, thirst = 0, camelTiredness = 0, nativeDistance = -20, drinksCanteen = 5, oasisValue;
    
        
    cout << "Welcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your dessert trek and out run the natives." << endl;
                                      
    while(done==false)
    {   
        srand(time(0));
                                     
        cout << "A. Drink from your canteen." << endl;
        cout << "B. Ahead moderate speed." << endl;
        cout << "C. Ahead full speed." << endl;
        cout << "D. Stop for the night." << endl;
        cout << "E. Status check." << endl;
        cout << "Q. Quit." << endl;                                                              
        cout << "Your choice ";
        cin >> userInput;
        userInput = toupper(userInput);
                                                                                                 
        switch(userInput)
        {
            case 'A':
                drinkWater(thirst, drinksCanteen);
                oasis(drinksCanteen, thirst, camelTiredness);
                sandstorm(thirst, camelTiredness, nativeDistance);
                snakeKills(done);
                break;
            case 'B':
                
                normalSpeed(milesTraveled, thirst, camelTiredness, nativeDistance);
                oasis(drinksCanteen, thirst, camelTiredness);
                sandstorm(thirst, camelTiredness, nativeDistance);
                snakeKills(done);
                break;
            case 'C':
                fullSpeed(milesTraveled, thirst, camelTiredness, nativeDistance);
                oasis(drinksCanteen, thirst, camelTiredness);
                sandstorm(thirst, camelTiredness, nativeDistance);
                snakeKills(done);
                break;
            case 'D':
                camelTired(camelTiredness, nativeDistance);
                oasis(drinksCanteen, thirst, camelTiredness);
                sandstorm(thirst, camelTiredness, nativeDistance);
                snakeKills(done);
                break;
            case 'E': 
                askUserToContinue(milesTraveled, drinksCanteen, nativeDistance);
                oasis(drinksCanteen, thirst, camelTiredness);
                sandstorm(thirst, camelTiredness, nativeDistance);
                snakeKills(done);
                break;
            case 'Q':
                done = true;
                cout << "The game is over native got you." << endl;
                break;
            default:
                cout << "Invalid Input!" << endl;
        }//end of switch
        
//*************************Thirst**********************************
        if(thirst > 4)
        {
            cout << "You are thirsty!" << endl;
        }
        if(thirst > 6)
        {
          cout << "You died of thirst!" << endl;
          done = true;
          continue;
        }
//************************Camel Tiredness****************************
        if(camelTiredness > 5)
        {
            cout << "Your camel is getting tired!" << endl;
        }
        if(camelTiredness > 8)
        {
            cout << "Your camel is dead!" << endl;
            done = true;
            continue;
        }
        
//************************Native Distance**************************
        if(nativeDistance >= milesTraveled)
        {
            cout << "The natives have caught you!" << endl;
            return 0;
            continue;
        }
        else if (milesTraveled - abs(nativeDistance) < 15)
        {
            cout << "The natives are getting close!" << endl;
        }
        
//***********************Miles you Traveled***************************
        if(milesTraveled >= 200)
        {
            cout << "You have escaped the natives!" << endl;
            return 0;
            continue;
        }
        
      }//end of while
      
      return 0;
}// end of main

//**********************Continue Function********************************
void askUserToContinue(int& miles, int& drinksLeft, int& nativesMiles)
{
    cout << "Miles traveled: " << miles << endl;
    cout << "Drinks in Canteen: " << drinksLeft << endl;
    cout << "The natives are " << nativesMiles << " miles behind you." << endl;
}

//**********************Camel Tiredness Function****************************
void camelTired(int& tiredness, int& nDistance)
{
    srand(time(0));
    int nativesMoveUp;    
    
    nativesMoveUp = rand() % 8 + 7;
    nDistance = nDistance + nativesMoveUp; 
    
    tiredness = 0;
    cout << "You have traveled " << nDistance << " miles." << endl;
    cout << "Camel is happy!" << endl;  
}

//*********************Full Speed Function*********************************
void fullSpeed(int& miles, int& thirst, int& tiredness, int& natives)
{
    srand(time(0));
    int nativesMoveUp =0;
    int cameltired=0; 
    int milesTraveled=0;  
      
    nativesMoveUp = rand() % 8 + 7;
    natives = natives + nativesMoveUp;
    
    thirst++;
    
    cameltired = rand() % 3 + 1;
    tiredness = tiredness + cameltired;
    
    milesTraveled = rand() % 11 + 10;
    miles = miles + milesTraveled; 
    cout << "You have traveled: " << miles << endl;  
}

//***********************Normal Funciton*********************************
void normalSpeed(int& miles, int& thirst, int& tiredness, int& natives){
    srand(time(0));
    int nativesMoveUp;  
    int milesTraveled; 
    int cameltired;
    
    nativesMoveUp = rand() % 8 + 7;
    natives = natives + nativesMoveUp;
    
    milesTraveled = rand() % 8 + 5;
    miles = miles + milesTraveled; 
    cout << "You have traveled " << miles << " miles." << endl;
    
    thirst++;
    
    cameltired = rand() % 2 + 0;
    tiredness = tiredness + cameltired;
    
}

//**********************Drinks Water Function************************
void drinkWater(int& thirstyness, int& drinks)
{
    if(drinks > 0)
    {
        drinks--;
        thirstyness = 0;
    }
    else
    {
        cout << "Error" << endl;
    }
    return;
}

//***********************Oasis Function**************************
void oasis(int& drinks, int& thirst, int& tiredness){
    int oasisValue;
    oasisValue = rand()% 20 + 1;
    if(oasisValue == 1){
        drinks = 5;
        thirst = 0;
        tiredness = 0;
        cout << "You've found an oasis!" << endl;
    }
    
    return;
}

//************************Sand Storm Function************************
void sandstorm(int& thirst, int& tiredness, int& natives){
    int nativeTravel, sandStorm, stuckInStorm;
    sandStorm = rand() % 20 + 1; 
    if(sandStorm == 2){
        cout << "OH NO! You hit a sandstorm!" << endl;
        cout << "You have to wait until the sandstorm ends before moving on." << endl;
    
        nativeTravel = rand()% 5 + 1;
        natives = natives + nativeTravel;
    
        thirst++;
        
        stuckInStorm--;
    }
    return;
}

//*************************Poisonous Snake Function*********************************
void snakeKills(bool& done){
    int animal;
    animal = rand() % 30 + 1;
    if(animal == 5){
        done = true;
        cout << "You died because of a poisonous snake bite." << endl;
    }
    return;
}

