#ifndef __MAIN_H__
#define __MAIN_H__

#include <REG52.H>

#define uchar unsigned char
#define uint  unsigned int

// 按键 枚举
enum KEYVALUE {
    B_NEXT, // 0-上一曲
    B_LAST, // 1-下一曲
    B_PAUSE,// 2-播放/暂停
    B_NoKey,// 3-没有按下
};

enum ViewPage {
    ApplePage,  // 0-显示苹果
    RunPage,    // 1-
    GirlPage,   // 2-显示女孩
    BikePage,   // 3-显示自行车
    NoPage,     // 4-无显示
};

// LCD12864接口
sbit LCD_CS    =  P0 ^ 7;	// 片选 RS 高电平有效
sbit LCD_SID   =  P0 ^ 6;	// 数据 RW
sbit LCD_SCLK  =  P0 ^ 5;	// 时钟 EN
sbit LCD_PSB   =  P0 ^ 4;	// PSB  PSB

// 按键
sbit Key_Last  = P3 ^ 2;    // 上一曲
sbit Key_Next  = P3 ^ 3;    // 下一曲
sbit Key_Pause = P3 ^ 4;    // 播放/暂停

// 蜂鸣器
sbit BeePIO    = P3 ^ 6;

// 数码管
sbit SEGSelect = P3 ^ 7;    // 位选
sfr  SEGPort   = 0xA0;      // 数码管端口 P2

// 延时 z ms
void delay_ms(uint z);

#endif
