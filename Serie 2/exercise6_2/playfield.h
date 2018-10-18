#include <iostream>
#include <string>

using namespace std;


class playfield {
    public:
    // the size of the field
    const static int width=7;
    const static int height=6;
    // these elements are used to indicate whether a given position
    // in the playing field is taken by a given player
    const static int none=0;
    const static int player1=1;
    const static int player2=2;

    const static int invalid=-1;
    const static int ok=0;
    const static int tie=1;
    const static int win=2;
    const static int error=-2;

    int current_player;

    protected:
    // the internal representation of the field
    char rep[playfield::width][playfield::height];

    private:
    char player_to_symbol(int p);

    void print_field();
    

    void switch_player();
    void init();

    bool check_win(int player);
    bool check_tie();

    int stones_in_column(int c);
    public:
    // return the stone (none/player1/player2) at the position(x,y)
    // 0 <= x <= width
    // 0 <= y <= height
    // stoneat(0,0) ................ top left
    // stoneat(width-1,height-1) ... bottom right
    // if we insert a stone in a new game in column i,
    // it lands at (i,height-1)
    // implementation may be changed, interface not
    int stoneat(int x, int y) const { 
        return rep[x][y]; 
    }

    playfield() {
        init();
    }
    
    int insert_stone(int c);
    
    int get_current_player() {
        return current_player;
    }

};