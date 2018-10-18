#include <iostream>
#include <string>
#include "player.h"

template<typename F>
class connectfour {
    const static int invalid=-1;
    const static int ok=0;
    const static int tie=1;
    const static int win=2;
    const static int error=-2;
public:
    connectfour(playfield &field, player<F> *player1, player<F> *player2) : 
        field(field), player1(player1), player2(player2), current_player(player1)
        {/* void */}

    //Simply
    void game() {
        int status = 0;
        while(status == ok || status == invalid) { //if ok repeat and switch player, if invalid ask again
            cout << "Player " << field.get_current_player() << endl; // Print current player
            status = field.insert_stone(current_player->play(field)); //Insert stone where the player wants it
            if (status == invalid) { //Here is where we ask the player to stop drinking and play correctly
                cout << "Invalid move! Repeat" << endl;
            } else { //If everything is fine switch players
                switch_player();
            }
            
        }

        if (status == tie) {
            cout << "Tie!" << endl;
        } else if (status == win) {
            cout << "Win! Player " << field.get_current_player() << " won the game" << endl;
        } else {
            cout << "Error with status " << status << endl;
        }

    }

private:
    playfield field;
    player<F> *player1;
    player<F> *player2;

    player<F> *current_player;
    
    void switch_player() {
        current_player = (current_player == player2) ? player1 : player2;
    }

};