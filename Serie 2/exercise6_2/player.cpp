#include "player.h"

//Ask the player to choose the column (human)
template<>
int player<playfield>::play(const playfield &field) {
    cout << " Select the column you want to put your stone in: (0-" << field.width-1 << ")" ;
    int column;
    cin >> column;                                                                                                                                                                                                                                       
    return column;
}