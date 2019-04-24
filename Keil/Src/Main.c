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
#include "Digitron.h"

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

// �������ֵ�һЩ����
extern uchar music_m, music_n, music_i;

// ���� ö��
enum KEYVALUE Key_Value = B_NoKey;

// ҳ�� ö��
enum ViewPage nowPage = ApplePage;

// ��ʾ 1-����/0-��ͣ
uchar MusicStatus=1;

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
            TR0 = 0;    // ���°�����ֹͣ����
            if (Key_Value == B_NEXT)
                nowPage = (++nowPage)%NoPage;
            else if (Key_Value == B_LAST)
                nowPage = (nowPage+NoPage-1)%NoPage;    // ������ת��Ϊ�ӷ�,��ֹ�������.
            else if (Key_Value == B_PAUSE)
            {
                MusicStatus = !MusicStatus; // ״̬��ת
                continue;   // ������µ�����ͣ��,��ˢ�½�����ʾ
            }
            
            // ���·���ͣ�� ��յ�ǰ�Ĳ��Ž���
            music_m=0;music_n=0;music_i=0;
            
            // ÿ�ΰ���,ֻ����һ�ν�����ʾ,���ٽ���ˢ��Ƶ��.
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