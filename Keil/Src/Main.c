/*
*  ���ڵ�Ƭ�������ܵ��Ӻؿ����
*  CPU:STC89C52RC
*  ����:11.0592MHZ
*
*  ����:
*  // LCD12864
*    
*/

#include "Main.h"
#include "LCD12864.h"
#include "Music.h"
#include "Key.h"

// ���� ��������
extern uchar code musicDJRM[][2];
// ���� �໨��
extern uchar code musicQHC[][2];
// ���� ɭ�ֿ�����
extern uchar code musicSLKXQ[][2];
// ���� ����
extern uchar code musicMLH[][2];

// ��ǰ���ڲ��ŵ�����
uchar **currentMusic=musicDJRM;

extern unsigned char code Apple[];
extern unsigned char code Run[];
extern unsigned char code Girl[];
extern unsigned char code Bike[];

// ���� ö��
enum KEYVALUE Key_Value = B_NoKey;

// ҳ�� ö��
enum ViewPage nowPage = ApplePage;

// ��ʱ z ms
void delay_ms(uint z)
{
	uint x, y;
	for (x = z; x>0; x--)
        for (y = 114; y>0; y--);
}

int main(void)
{
    // ��ʼ�����ֵĶ�ʱ��
    InitMusic();
    
    // ��ʼ��Һ��
    LCD_Init();

    // ����
    LCD_Clear_Screen();
    
    // ��ӭʹ��
    Display_Img(Apple);
    delay_ms(1000);
    while(1)
    {
        Key_Value = keyScan();
        if (Key_Value != B_NoKey)
        {
            if (Key_Value == B_NEXT)
                nowPage = (++nowPage)%NoPage;
            
            // ÿ�ΰ���,ֻ����һ�ν�����ʾ,���ٽ���ˢ��Ƶ��.
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