#ifndef __MAIN_H__
#define __MAIN_H__

#include <REG52.H>

#define uchar unsigned char
#define uint  unsigned int

// ���� ö��
enum KEYVALUE {
    B_NEXT, // 0-��һ��
    B_LAST, // 1-��һ��
    B_PAUSE,// 2-����/��ͣ
    B_NoKey,// 3-û�а���
};

enum ViewPage {
    ApplePage,  // 0-��ʾƻ��
    RunPage,    // 1-
    GirlPage,   // 2-��ʾŮ��
    BikePage,   // 3-��ʾ���г�
    NoPage,     // 4-����ʾ
};

// LCD12864�ӿ�
sbit LCD_CS    =  P0 ^ 7;	// Ƭѡ RS �ߵ�ƽ��Ч
sbit LCD_SID   =  P0 ^ 6;	// ���� RW
sbit LCD_SCLK  =  P0 ^ 5;	// ʱ�� EN
sbit LCD_PSB   =  P0 ^ 4;	// PSB  PSB

// ����
sbit Key_Last  = P3 ^ 2;    // ��һ��
sbit Key_Next  = P3 ^ 3;    // ��һ��
sbit Key_Pause = P3 ^ 4;    // ����/��ͣ

// ������
sbit BeePIO    = P3 ^ 6;

// �����
sbit SEGSelect = P3 ^ 7;    // λѡ
sfr  SEGPort   = 0xA0;      // ����ܶ˿� P2

// ��ʱ z ms
void delay_ms(uint z);

#endif
