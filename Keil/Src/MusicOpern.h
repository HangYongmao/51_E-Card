#include "Main.h"

// ����
uchar code T[49][2]={{0,0},
{0xF8,0x8B},{0xF8,0xF2},{0xF9,0x5B},{0xF9,0xB7},{0xFA,0x14},{0xFA,0x66},{0xFA,0xB9},{0xFB,0x03},
{0xFB,0x4A},{0xFB,0x8F},{0xFB,0xCF},{0xFC,0x0B},{0xFC,0x43},{0xFC,0x78},{0xFC,0xAB},{0xFC,0xDB},
{0xFD,0x08},{0xFD,0x33},{0xFD,0x5B},{0xFD,0x81},{0xFD,0xA5},{0xFD,0xC7},{0xFD,0xE7},{0xFE,0x05},
{0xFE,0x21},{0xFE,0x3C},{0xFE,0x55},{0xFE,0x6D},{0xFE,0x84},{0xFE,0x99},{0xFE,0xAD},{0xFE,0xC0},
{0xFE,0x02},{0xFE,0xE3},{0xFE,0xF3},{0xFF,0x02},{0xFF,0x10},{0xFF,0x1D},{0xFF,0x2A},{0xFF,0x36},
{0xFF,0x42},{0xFF,0x4C},{0xFF,0x56},{0xFF,0x60},{0xFF,0x69},{0xFF,0x71},{0xFF,0x79},{0xFF,0x81},
};

// ���� ��������
uchar code musicDJRM[][2]={
{0,4},{16,12},{23,16},{21,4},{23,4},{21,4},{19,12},{0,8},{19,4},{19,4},{19,4},{18,4},{16,8},{14,4},
{16,16},{0,16},{16,12},{28,16},{26,4},{28,4},{26,4},{23,8},{0,16},{21,4},{21,4},{21,4},{21,4},{19,8},
{16,4},{18,16},{0,12},{16,12},{23,16},{21,4},{23,4},{21,4},{19,8},{0,16},{19,4},{19,4},{19,4},{18,4},
{16,8},{14,4},{16,16},{0,12},{16,12},{28,16},{26,4},{28,4},{26,4},{23,16},{0,12},{28,4},{28,4},{28,4},
{30,4},{28,8},{26,4},{28,24},{0,12},{28,4},{28,2},{26,2},{23,4},{23,4},{28,4},{28,2},{26,2},{28,4},
{31,4},{26,6},{23,2},{26,4},{28,4},{26,16},{21,4},{21,2},{19,2},{16,4},{16,4},{21,4},{21,2},{19,2},
{21,4},{23,4},{19,6},{16,2},{19,4},{16,4},{14,16},{28,4},{28,2},{26,2},{23,4},{23,4},{28,4},{28,2},
{26,2},{28,4},{28,4},{31,4},{31,2},{28,2},{26,4},{26,4},{31,4},{31,2},{26,2},{31,4},{31,4},{0,4},
{31,4},{31,4},{31,4},{30,4},{28,8},{26,4},{28,24},{28,4},{28,2},{26,2},{23,4},{23,4},{28,4},{28,2},
{26,2},{28,4},{31,4},{26,6},{23,2},{26,4},{28,4},{26,16},{21,4},{21,2},{19,2},{16,4},{16,4},{21,4},
{21,2},{19,2},{21,4},{23,4},{19,6},{16,2},{19,4},{16,4},{14,16},{28,4},{28,2},{26,2},{23,4},{23,4},
{28,4},{28,2},{26,2},{28,4},{28,4},{31,4},{31,2},{28,2},{26,4},{26,4},{31,4},{31,2},{26,2},{31,4},
{31,4},{0,4}, {31,4},{31,4},{31,4},{30,4},{28,8},{26,4},{28,20},{0,4},{31,4},{31,4},{31,4},{30,4},
{28,8},{26,4},{28,24},{0xFF,0xFF}};

// ���� �໨��
uchar code musicQHC[][2]={
{0,4},{0,4},{24,4},{24,4},{21,4},{19,4},{21,4},{14,8},{19,4},{21,4},{24,4},{21,4},{19,16},{0,4},{24,4},
{24,4},{21,4},{19,4},{21,4},{12,8},{19,4},{21,4},{24,4},{19,4},{17,16},{0,4},{17,4},{19,4},{21,4},{24,4},
{26,4},{24,4},{22,4},{24,4},{21,4},{21,4},{19,4},{19,16},{0,4},{17,4},{19,4},{17,4},{17,4},{19,4},{17,4},
{19,4},{19,4},{21,8},{24,4},{21,4},{21,12},{0,4},{24,4},{24,4},{21,4},{19,4},{21,4},{14,8},{19,4},{21,4},
{24,4},{21,4},{19,16},{0,4},{24,4},{24,4},{21,4},{19,4},{21,4},{12,8},{19,4},{21,4},{24,4},{19,4},{17,16},
{0,4},{17,4},{19,4},{21,4},{24,4},{26,4},{24,4},{22,4},{24,4},{21,4},{21,4},{19,4},{19,12},{12,4},{21,8},
{19,4},{19,8},{17,16},{0xFF,0xFF}};

// ���� ɭ�ֿ�����
uchar code musicSLKXQ[][2]={
{0,4},{14,4},{17,4},{21,4},{24,4},{21,8},{21,4},{19,4},{21,8},{21,4},{19,4},{21,8},{14,4},{16,4},{17,4},
{21,4},{19,4},{17,4},{14,8},{12,8},{9,24},{14,4},{17,4},{21,4},{24,4},{21,8},{21,4},{19,4},{21,8},{21,4},
{19,4},{21,8},{14,4},{16,4},{17,4},{21,4},{19,4},{17,4},{14,8},{12,8},{14,24},{14,4},{16,4},{17,4},{19,4},
{21,4},{22,4},{24,8},{22,4},{21,4},{19,8},{19,4},{21,4},{19,16},{14,4},{16,4},{17,4},{19,4},{21,8},{16,4},
{14,4},{16,24},{14,4},{16,4},{17,4},{19,4},{21,4},{22,4},{24,8},{22,4},{21,4},{19,8},{19,4},{21,4},{19,8},
{14,4},{16,4},{17,4},{21,4},{19,4},{17,4},{14,8},{12,8},{14,24},{21,8},{26,16},{24,8},{21,4},{24,4},{26,16},
{24,8},{21,4},{19,4},{17,4},{14,4},{17,4},{19,4},{21,8},{21,4},{19,4},{21,24},{21,8},{26,16},{24,8},{21,4},
{24,4},{26,24},{24,8},{21,4},{19,4},{17,4},{14,4},{17,4},{19,4},{21,8},{26,4},{24,4},{26,24},{0xFF,0xFF}};

// ���� ����
uchar code musicMLH[][2]={
{0,4},{21,8},{21,4},{24,4},{26,4},{29,4},{29,4},{26,4},{24,8},{24,4},{26,4},{24,16},{21,8},{21,4},{24,4},
{26,4},{29,4},{29,4},{26,4},{24,8},{24,4},{26,4},{24,16},{24,8},{24,8},{24,8},{21,4},{24,4},{26,8},{26,8},
{24,16},{21,8},{19,4},{21,4},{24,8},{21,4},{19,4},{17,8},{17,4},{19,4},{17,16},{21,4},{19,4},{17,4},{21,4},
{19,12},{21,4},{24,8},{26,4},{29,4},{24,16},{19,8},{21,4},{24,4},{19,4},{21,4},{17,4},{14,4},{12,16},{14,8},
{17,8},{19,12},{21,4},{17,4},{19,4},{17,4},{14,4},{12,24},{0,8},{0xFF,0xFF}};