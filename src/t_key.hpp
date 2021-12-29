#ifndef T_KEYBOARD
#define T_KEYBOARD

extern int KEY_KeysPressed[32];
extern bool KEY_WritingToKeys;

void KEY_Begin();
// Request clear the pressed array.
// Returns 0 if success.
// Returns 1 if KEY is still writing to KEY_Pressed.
// Returns 2 if just fucked up. There is no reason but still.
char KEY_Clear();
void KEY_Stop();

#endif /* T_KEYBOARD */
