#include "t_shape.hpp"
#include "t_shared.hpp"

const bool idata[4][4] =
{
    1,0,0,0,
    1,0,0,0,
    1,0,0,0,
    1,0,0,0,
};
const bool idata[4][4] =
{
    1,0,0,0,
    1,0,0,0,
    1,1,0,0,
    0,0,0,0,
};
const bool zdata[4][4];

Shape::Shape(char type)
{
    
}

// Check if shape is inside of another
bool Shape::Inside()
{
	bool isinside=false;
	for (int i = 0; i < sizeof (data) / sizeof (int); i++)
	{
		for (int j = 0; i < 4; i++)
		{
            // This is cute.
			if(data[i][j]==1){
				if(T_Board[i+x][j+y]==1){
					//stop, the shape reached cant move
					isinside=true;
				}
			}
		}
		
	}
	return isinside;
}
// The falling 
bool Shape::Fall()
{
    bool isinside;
    y++;
    isinside=Inside();
    if(isinside)
    {
        y--;
        return true;
    }
	return false;
}
// Right
void Shape::MoveR()
{
	bool isinside;
	x++;
	isinside=Inside();
	if(isinside)
	{
		x--;
	}
}
// Left
void Shape::MoveL()
{
	bool isinside;
	x--;
	isinside=Inside();
	if(isinside)
	{
		x++;
	}

}
