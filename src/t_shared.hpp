#ifndef T_SHARED
#define T_SHARED

#include "t_shape.hpp"

#define T_WIDTH 10
#define T_HEIGHT 24

// The board that is passed to the drawer
extern bool T_Board[T_WIDTH][T_HEIGHT];
extern unsigned T_Score;
// The next shape awaiting to be added to the game
extern Shape T_NextShape;

#endif /* T_SHARED */
