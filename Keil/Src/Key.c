#include "Key.h"

// ∞¥º¸…®√Ë
enum KEYVALUE keyScan()
{
    if (Key_Last == 0)
    {
        delay_ms(5);
        if (Key_Last == 0)
        {
            while(!Key_Last);   // À… ÷ºÏ≤‚
            return B_LAST;
        }
    }
    if (Key_Next == 0)
    {
        delay_ms(5);
        if (Key_Next == 0)
        {
            while(!Key_Next);   // À… ÷ºÏ≤‚
            return B_NEXT;
        }
    }
    if (Key_Pause == 0)
    {
        delay_ms(5);
        if (Key_Pause == 0)
        {
            while(!Key_Pause);   // À… ÷ºÏ≤‚
            return B_PAUSE;
        }
    }
    return B_NoKey;
}