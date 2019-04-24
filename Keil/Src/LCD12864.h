#ifndef __LCD12864_H__
#define __LCD12864_H__

#include "Main.h"

// 初始化液晶
void LCD_Init();

// 清屏
void LCD_Clear_Screen();

// 写指令或数据
void Write_char(bit start, unsigned char ddata);

// 发送一个字节
void Send_byte(unsigned char bbyte);

// 设置LCD显示的起始位置，X为行，Y为列
void LCD_set_xy(unsigned char x, unsigned char y);

// 中英文字符串显示函数
void LCD_Write_string(unsigned char X, unsigned char Y, unsigned char *s);

// 数字显示函数
void LCD_Write_number(unsigned char s);

// 图形方式12864显示字模221 横向取膜
void Display_Img(unsigned char *img);

#endif
