/*
*  基于单片机的智能电子贺卡设计
*  CPU:STC89C52RC
*  晶振:11.0592MHZ
*
*  接线:
*  // LCD12864
*    
*/

#include "Main.h"
#include "LCD12864.h"
#include "Music.h"
#include "Key.h"
#include "Digitron.h"

// 音乐 刀剑如梦
extern uchar code musicDJRM[][2];
// 音乐 青花瓷
extern uchar code musicQHC[][2];
// 音乐 森林狂想曲
extern uchar code musicSLKXQ[][2];
// 音乐 茉莉花
extern uchar code musicMLH[][2];

// 当前正在播放的音乐
uchar **currentMusic=musicDJRM;

extern unsigned char code Apple[];
extern unsigned char code Run[];
extern unsigned char code Girl[];
extern unsigned char code Bike[];

// 控制音乐的一些变量
extern uchar music_m, music_n, music_i;

// 按键 枚举
enum KEYVALUE Key_Value = B_NoKey;

// 页面 枚举
enum ViewPage nowPage = ApplePage;

// 表示 1-播放/0-暂停
uchar MusicStatus=1;

// 延时 z ms
void delay_ms(uint z)
{
	uint x, y;
	for (x = z; x>0; x--)
        for (y = 114; y>0; y--);
}

int main(void)
{
    // 初始化音乐的定时器
    InitMusic();
    
    // 初始化液晶
    LCD_Init();

    // 清屏
    LCD_Clear_Screen();
    
    // 欢迎使用
    Display_Img(Apple);
    delay_ms(1000);
    while(1)
    {
        Key_Value = keyScan();
        if (Key_Value != B_NoKey)
        {
            TR0 = 0;    // 按下按键后停止音乐
            if (Key_Value == B_NEXT)
                nowPage = (++nowPage)%NoPage;
            else if (Key_Value == B_LAST)
                nowPage = (nowPage+NoPage-1)%NoPage;    // 将减法转化为加法,防止数据溢出.
            else if (Key_Value == B_PAUSE)
            {
                MusicStatus = !MusicStatus; // 状态翻转
                continue;   // 如果按下的是暂停键,不刷新界面显示
            }
            
            // 按下非暂停键 清空当前的播放进度
            music_m=0;music_n=0;music_i=0;
            
            // 每次按下,只更新一次界面显示,减少界面刷新频率.
            switch (nowPage)
            {
                case ApplePage:
                    currentMusic = musicDJRM;
                    Display_Img(Apple);
                    break;

                case RunPage:
                    currentMusic = musicQHC;
                    Display_Img(Run);
                    DisplayDigitron(2);
                    break;

                case GirlPage:
                    currentMusic = musicSLKXQ;
                    Display_Img(Girl);
                    DisplayDigitron(2);
                    break;

                case BikePage:
                    currentMusic = musicMLH;
                    Display_Img(Bike);
                    DisplayDigitron(2);
                    break;

                default:
                    break;
            }
        }
        if (MusicStatus == 1)
            PlayMusic(currentMusic);
    }
}