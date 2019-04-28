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

extern unsigned char code BriImg[];
extern unsigned char code DuanQiaoImg[];
extern unsigned char code JZhouImg[];
extern unsigned char code MoLiHuaImg[];
extern unsigned char code NewYearImg[];

// �������ֵ�һЩ����
extern uchar music_m, music_n, music_i;

// ���� ö��
enum KEYVALUE Key_Value = B_NoKey;

// ҳ�� ö��
enum ViewPage nowPage = BriPage;

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
    
    // ��ʾ��ҳ
    LCD_Write_string(2, 0, "���ܵ��Ӻؿ����");
    LCD_Write_string(3, 4, "��ʮ����");
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
                // ���տ���
                case BriPage:
                    currentMusic = musicDJRM;
                    Display_Img(BriImg);
                    break;

                // ���Ų�ѩ
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

                // ����
                case MoLiHuaPage:
                    currentMusic = musicMLH;
                    Display_Img(MoLiHuaImg);
                    DisplayDigitron(2);
                    break;
                
                // �������
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