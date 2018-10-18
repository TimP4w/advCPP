#include <iostream>
#include "connectfour.h"

using namespace std;

int main(int argc, char *argv[])  
{
    playfield field;
    player<playfield> player1;
    player<playfield> player2;

    connectfour<playfield> connect(field, &player1, &player2);
    connect.game();

    return 0;
}