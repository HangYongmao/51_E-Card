#include "LCD12864.h"
#include "LCD12864_IMG.h"

// ��ʱ
void Delaynms(unsigned int di)
{
	unsigned int da,db;
 	for(da=0; da<di; da++)
        for(db=0; db<10; db++);
}

// ��ʼ��Һ��
void LCD_Init()
{
	LCD_PSB = 0;
	Delaynms(10);         // �����ȴ�����LCM���빤��״̬
	LCD_CS = 1;
	Write_char(0, 0x30);  // 8 λ���棬����ָ�
	Write_char(0, 0x0c);  // ��ʾ�򿪣����أ����׹�
	Write_char(0, 0x01);  // ��������DDRAM�ĵ�ַ����������  
}

// дָ�������
void Write_char(bit start, unsigned char ddata)
{
	unsigned char start_data, Hdata, Ldata;
	if (start == 0)
		start_data = 0xf8;	 // дָ��
	else
		start_data = 0xfa;   // д����

	Hdata = ddata & 0xf0;		  // ȡ����λ
	Ldata = (ddata << 4) & 0xf0;  // ȡ����λ
	Send_byte(start_data);        // ������ʼ�ź�
	Delaynms(5);
	Send_byte(Hdata);	          // ���͸���λ
	Delaynms(1);
	Send_byte(Ldata);		      // ���͵���λ
	Delaynms(1);
}

// ����һ���ֽ�
void Send_byte(unsigned char bbyte)
{
	unsigned char i;
	for (i = 0; i<8; i++)
	{
		LCD_SID = bbyte & 0x80; // ȡ�����λ
		LCD_SCLK = 1;
		LCD_SCLK = 0;
		bbyte <<= 1;            // ����
	}
}

// ��������
void LCD_Clear_Screen()
{
	Write_char(0, 0x01);
}

// ����LCD��ʾ����ʼλ�ã�XΪ�У�YΪ��
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

// ��Ӣ���ַ�����ʾ����
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

// ͼ�η�ʽ12864��ʾ��ģ221 ����ȡĤ
void Display_Img(unsigned char *img)
{
	unsigned char i, j;
	unsigned int k = 0;

	Write_char(0, 0x36); //ͼ�η�ʽ
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
