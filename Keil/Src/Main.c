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

// 按键 枚举
enum KEYVALUE Key_Value = B_NoKey;

// 页面 枚举
enum ViewPage nowPage = ApplePage;

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
            if (Key_Value == B_NEXT)
                nowPage = (++nowPage)%NoPage;
            
            // 每次按下,只更新一次界面显示,减少界面刷新频率.
            switch (nowPage)
            {
                case ApplePage:
                    Display_Img(Apple);
                    break;
                case RunPage:
                    Display_Img(Run);
                    break;
                case GirlPage:
                    Display_Img(Girl);
                    break;
                case BikePage:
                    Display_Img(Bike);
                    break;
                default:
                    break;
            }
        }
        
        PlayMusic(currentMusic);
    }
}