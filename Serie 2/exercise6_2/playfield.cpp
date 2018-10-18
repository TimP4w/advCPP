#include "playfield.h"

//Prints the field
void playfield::print_field() {

    for(int i = 0; i < width*2+1; i++) {
        cout << "=";
    }

    cout << endl;

    for(int i = 0; i < height; i++) {
        cout << "|";
        for(int j = 0; j < width; j++) {
            cout << player_to_symbol(stoneat(j, i)) << "|";
        }
        cout << endl;
    }

    for(int i = 0; i < width*2+1; i++) {
        cout << "=";
    }

    cout << endl;
}

//Just converts player1 to x and player2 to o
char playfield::player_to_symbol(int p) {
    if (p == 1) {
        return 'x';
    } else if (p == 2) {
        return 'o';
    } else {
        return ' ';
    }
}

int playfield::insert_stone(int c) {
    // Check column in boundaries
    if (c > width - 1 || c < 0) {
        return invalid;
    }

    //Check how many stones are in the column already
    int stones_count = stones_in_column(c);

    //If column not full
    if (stones_count < height) {
        rep[c][height - stones_count - 1] = current_player;
        print_field();
        //Check if player wins with the move <- this could be done better: Just check the for the current move (TODO)
        if (check_win(current_player)) {
            return win;
        }
        //Check if the game is a tie
        if (check_tie()) {
            return tie;
        }
        //Otherwise switch the player
        switch_player(); 
        return ok;  
    } else if (stones_count == height) { // if column full
        return invalid;
    } else { // WTF?! 
        cout << "An error occurred (wrong stone count at column " << c << ")" << endl;
        return error;
    }
}

//Check if there is a serie of 4 stones for the current player (horizontally, vertically or diagonally)
bool playfield::check_win(int player) {

    //Row
    for (int i = 0; i<height-3; i++ ){
        for (int j = 0; j<width; j++){
            int count = 0;
            for(int a = i; a < i+4; a++) {
                if (stoneat(j, a) == player) {
                    count++;
                }
                if (count == 4) {
                    return true;
                }
            }               
        }
    }

    //Column
    for (int i = 0; i<width-3; i++ ){
        for (int j = 0; j<height; j++){
            int count = 0;
            for(int a = i; a < i+4; a++) {
                if (stoneat(a, j) == player) {
                    count++;
                }
                if (count == 4) {
                    return true;
                }
            }               
        }
    }

    //Diagonal up (right to left going down)
    for (int i = 3; i<width; i++ ){
        for (int j = 0; j<height-3; j++){
            int count = 0;
            for(int a = 0; a < 4; a++) {
                if (stoneat(i-a, j+a) == player) {
                    count++;
                }
                if (count == 4) {
                    return true;
                }
            }               
        }
    }

    //Diagonal down (right to left too going up)
    for (int i = 3; i<width; i++ ){
        for (int j = 3; j<height-3; j++){
            int count = 0;
            for(int a = 0; a < 4; a++) {
                if (stoneat(i-a, j-a) == player) {
                    count++;
                }
                if (count == 4) {
                    return true;
                }
            }               
        }
    }
    return false;
}

//Check if all slots are used = tie
bool playfield::check_tie() {
    int columns_full = 0;
    for(int i = 0; i < width; i++) {
        if(stones_in_column(i) == height) {
            columns_full++;
        }
    }
    // If all cols are full, then tie
    if (columns_full == width) {
        return true;
    } 

    return false;
}

//How many stones are in a column
int playfield::stones_in_column(int c) {
    int stones_count = 0;
    for(int i = 0; i < height; i++) {
        if (stoneat(c, i) != none) {
            stones_count++;
        }
    }
    return stones_count;
}


//Switch player to call for move
void playfield::switch_player() {
    current_player = (current_player == player2) ? player1 : player2;
}


//Initialize the field with all 0 (none)
void playfield::init() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            rep[j][i] = none;
        }
    }

    current_player = player1;
}
