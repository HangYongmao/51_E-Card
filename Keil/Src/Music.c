#include "Music.h"
#include "MusicOpern.h"

uchar music_m, music_n, music_i;

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
	TH0 = T[music_m][0]; 
	TL0 = T[music_m][1];
}

// 播放音乐
void PlayMusic(uchar music[][2])
{
    music_m = music[music_i][0];
    music_n = music[music_i][1];
    if (music_m == 0x00)
    {
        TR0 = 0;
        delay(music_n);
        music_i++;
    }
    else if (music_m == 0xFF)
    {
        TR0 = 0;
        delay(30);
        music_i = 0;
    }
    else if (music_m == music[music_i + 1][0])
    {
        TR0 = 1;
        delay(music_n);
        TR0 = 0;
        pause();
        music_i++;
    }
    else
    {
        TR0 = 1;
        delay(music_n);
        music_i++;
    }
}
