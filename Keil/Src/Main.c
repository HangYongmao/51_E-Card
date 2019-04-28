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

extern unsigned char code BriImg[];
extern unsigned char code DuanQiaoImg[];
extern unsigned char code JZhouImg[];
extern unsigned char code MoLiHuaImg[];
extern unsigned char code NewYearImg[];

// 控制音乐的一些变量
extern uchar music_m, music_n, music_i;

// 按键 枚举
enum KEYVALUE Key_Value = B_NoKey;

// 页面 枚举
enum ViewPage nowPage = BriPage;

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
    
    // 显示主页
    LCD_Write_string(2, 0, "智能电子贺卡设计");
    LCD_Write_string(3, 4, "第十八组");
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
                // 生日快乐
                case BriPage:
                    currentMusic = musicDJRM;
                    Display_Img(BriImg);
                    break;

                // 断桥残雪
                case DuanQiaoPage:
                    currentMusic = musicQHC;
                    Display_Img(DuanQiaoImg);
                    DisplayDigitron(2);
                    break;

                // 
                case JZhouPage:
                    currentMusic = musicSLKXQ;
                    Display_Img(JZhouImg);
                    DisplayDigitron(2);
                    break;

                // 茉莉花
                case MoLiHuaPage:
                    currentMusic = musicMLH;
                    Display_Img(MoLiHuaImg);
                    DisplayDigitron(2);
                    break;
                
                // 新年快乐
                case NewYearPage:
                    Display_Img(NewYearImg);
                    break;
                
                default:
                    break;
            }
        }
        if (MusicStatus == 1)
            PlayMusic(currentMusic);
    }
}