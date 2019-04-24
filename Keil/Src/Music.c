#include "Music.h"
#include "MusicOpern.h"

uchar m, n, i;

void delay(uchar p)
{
    uchar i,j; 
    for(;p>0;p--)
    for(i=181;i>0;i--)
    for(j=30;j>0;j--);
}

void pause()
{
    uchar i,j;
    for(i=150;i>0;i--)
    for(j=30;j>0;j--);
}

// 初始化音乐播放器
void InitMusic()
{
    TMOD=0x01;
    EA=1;
    ET0=1;
}

// 定时器0
void T0_int() interrupt 1
{
	BeePIO = !BeePIO;
	TH0 = T[m][0]; 
	TL0 = T[m][1];
}

// 播放音乐
void PlayMusic(uchar music[][2])
{
    m = music[i][0];
    n = music[i][1];
    if (m == 0x00)
    {
        TR0 = 0;
        delay(n);
        i++;
    }
    else if (m == 0xFF)
    {
        TR0 = 0;
        delay(30);
        i = 0;
    }
    else if (m == music[i + 1][0])
    {
        TR0 = 1;
        delay(n);
        TR0 = 0;
        pause();
        i++;
    }
    else
    {
        TR0 = 1;
        delay(n);
        i++;
    }
}
