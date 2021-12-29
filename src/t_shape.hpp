// t_shape.hpp : Code for shapes.

#ifndef T_SHAPE
#define T_SHAPE

typedef enum
{
    DIR_0,
    DIR_90,
    DIR_180,
    DIR_270,
} dir_t;

#define SHAPE_L 0
#define SHAPE_Z 1
#define SHAPE_I 2
#define SHAPE_T 3
#define SHAPE_S 4
#define SHAPE_J 5
#define SHAPE_O 6

class Shape
{
    public:
    Shape(char type);

    void Rotate();

    void MoveR();
    void MoveL();
    bool Fall();

    char type;
    bool data[4][4];
    unsigned char x, y; // (0,0)=First

    
    private:
    bool Inside();
};

#endif /* T_SHAPE */
