#include <windows.h>
#include "game.hpp"

int _getch( void );

int *KEY_Pressed;
bool KEY_WritingToKeys;

size_t keyslen; // Length of the keys pressed array

// Get's me a character from keyboard
// Stolen from Google.
TCHAR getch() {
    DWORD mode, cc;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
    if (h == NULL) {
        return 0;
    }
    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}

void KEY_Init()
{
    KEY_WritingToKeys = false;
    keyslen = 32;
    // Allocate on heap for possible size increase
    KEY_Pressed = (int *)calloc(keyslen * sizeof (int), 1);

    DWORD tid;
    HANDLE handle = CreateThread(0,0,KEY_Begin,0,0,&tid);
}

DWORD WINAPI KEY_Begin(LPVOID lp)
{
    for (int i = 0; i < keyslen; i++)
    {
        // Sleep for 5 milliseconds and wait.
        // NOTE: This MIGHT, cause a bug, because it may overwait
        // We will see what we can do.
        if (G_ReadingPressed)
            Sleep(5);

        // Resize array
        

        // This looks very dumb but trust me.
        KEY_WritingToKeys = false;
        KEY_Pressed[i] = getch();
        KEY_WritingToKeys = true;

    }

    return 0;
}

void KEY_Stop()
{

}
