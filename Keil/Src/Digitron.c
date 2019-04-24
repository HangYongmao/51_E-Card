#include "Digitron.h"

uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

// 在数码管显示一个数字 共阳数码管
void DisplayDigitron(uchar num)
{
    SEGSelect = 1;
    SEGPort   = table[num%9];
}
