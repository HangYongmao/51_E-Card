#include "LCD12864.h"
#include "LCD12864_IMG.h"

// 延时
void Delaynms(unsigned int di)
{
	unsigned int da,db;
 	for(da=0; da<di; da++)
        for(db=0; db<10; db++);
}

// 初始化液晶
void LCD_Init()
{
	LCD_PSB = 0;
	Delaynms(10);         // 启动等待，等LCM讲入工作状态
	LCD_CS = 1;
	Write_char(0, 0x30);  // 8 位介面，基本指令集
	Write_char(0, 0x0c);  // 显示打开，光标关，反白关
	Write_char(0, 0x01);  // 清屏，将DDRAM的地址计数器归零  
}

// 写指令或数据
void Write_char(bit start, unsigned char ddata)
{
	unsigned char start_data, Hdata, Ldata;
	if (start == 0)
		start_data = 0xf8;	 // 写指令
	else
		start_data = 0xfa;   // 写数据

	Hdata = ddata & 0xf0;		  // 取高四位
	Ldata = (ddata << 4) & 0xf0;  // 取低四位
	Send_byte(start_data);        // 发送起始信号
	Delaynms(5);
	Send_byte(Hdata);	          // 发送高四位
	Delaynms(1);
	Send_byte(Ldata);		      // 发送低四位
	Delaynms(1);
}

// 发送一个字节
void Send_byte(unsigned char bbyte)
{
	unsigned char i;
	for (i = 0; i<8; i++)
	{
		LCD_SID = bbyte & 0x80; // 取出最高位
		LCD_SCLK = 1;
		LCD_SCLK = 0;
		bbyte <<= 1;            // 左移
	}
}

// 清屏函数
void LCD_Clear_Screen()
{
	Write_char(0, 0x01);
}

// 设置LCD显示的起始位置，X为行，Y为列
void LCD_set_xy(unsigned char x, unsigned char y)
{
	unsigned char address;
	switch (x)
	{
	case 0: address = 0x80 + y; break;
	case 1: address = 0x80 + y; break;
	case 2: address = 0x90 + y; break;
	case 3: address = 0x88 + y; break;
	case 4: address = 0x98 + y; break;
	default:address = 0x80 + y; break;
	}
	Write_char(0, address);
}

// 中英文字符串显示函数
void LCD_Write_string(unsigned char X, unsigned char Y, unsigned char *s)
{
	LCD_set_xy(X, Y);

	while (*s)
	{
		Write_char(1, *s);
		s++;
		Delaynms(1);
	}
}

// 图形方式12864显示字模221 横向取膜
void Display_Img(unsigned char *img)
{
	unsigned char i, j;
	unsigned int k = 0;

	Write_char(0, 0x36); //图形方式
	for (i = 0; i<32; i++)
	{
		Write_char(0, 0x80+i);
		Write_char(0, 0x80);
		for (j = 0; j<16; j++)
		{
			Write_char(1, img[k++]);
		}
	}

	for (i = 0; i<32; i++)
	{
		Write_char(0, 0x80+i);
		Write_char(0, 0x88);
		for (j = 0; j<16; j++)
		{
			Write_char(1, img[k++]);
		}
	}
}
