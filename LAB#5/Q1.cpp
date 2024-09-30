#include <iostream>
#include <cstdlib> 
#include <ctime>   

using  namespace std;

void solve(int player,int Random){

    int guess;
    cout << "Player : " << player << " Enter Number To Guess : " << endl;
    cin >> guess;

    if( guess == Random){
        cout << " You Guess the right Number : " << guess << endl;
        return;
    }
    if( guess < Random){
        cout << "The Number You Guess is Less than Number : " << endl;
    }
    else{
        cout << "The Number You Guess is Greater than Number : " << endl;
    }

    if(player == 1) player = 2;
    else            player = 1;

    return solve(player,Random);

}
int main() {
    
    srand(time(nullptr));

    int Random = rand() % 100 + 1;
    cout << "Random Number to Guess : " << Random << endl;
    cout << "Suppose 2 players are playing and player 1 is taking first turn : " << endl;
    solve(1,Random);
   
}

