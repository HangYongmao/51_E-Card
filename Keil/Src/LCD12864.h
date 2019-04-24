#ifndef __LCD12864_H__
#define __LCD12864_H__

#include "Main.h"

// ��ʼ��Һ��
void LCD_Init();

// ����
void LCD_Clear_Screen();

// дָ�������
void Write_char(bit start, unsigned char ddata);

// ����һ���ֽ�
void Send_byte(unsigned char bbyte);

// ����LCD��ʾ����ʼλ�ã�XΪ�У�YΪ��
void LCD_set_xy(unsigned char x, unsigned char y);

// ��Ӣ���ַ�����ʾ����
void LCD_Write_string(unsigned char X, unsigned char Y, unsigned char *s);

// ������ʾ����
void LCD_Write_number(unsigned char s);

// ͼ�η�ʽ12864��ʾ��ģ221 ����ȡĤ
void Display_Img(unsigned char *img);

#endif
