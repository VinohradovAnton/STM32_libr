#include "stm32f10x.h"

#if !defined GUI_DRV_H
#define GUI_DRV_H

// ��� ������ ������
#define  LCD_DATA    			    ((uint32_t)0x60020000)
// ��� ������ ������
#define  LCD_REG   		  	    ((uint32_t)0x60000000)

#define DISP_WIDTH  240
#define DISP_HEIGHT 320

typedef enum
{
	Orientation_Portrait,
	Orientation_Album		// Landscape
} TOrientation;

void LCD_PutPixel ( uint16_t x, uint16_t y, uint16_t color );						//��������� ������� �� �����������, ����
void LCD_SetOrient ( TOrientation orientation );									//���������� ������
uint16_t LCD_GetMaxX ( void );
uint16_t LCD_GetMaxY ( void );
uint8_t LCD_DrawChar(uint16_t x, uint16_t y, uint8_t c, uint16_t textColor,
		uint16_t backColor, uint8_t isTransparent);	//����� ������ (���������� ������, ������, ���� ������, ���� ����, ������������ ����)
uint8_t LCD_GetCharHight(void);
void LCD_DrawString(char* s, uint16_t x, uint16_t y, uint16_t color,
		uint16_t backColor, uint8_t isTransparent); //����� ������ (������, ���������� ������, ���� ������, ���� ����, ������������ ����)
void LCD_SetCursor ( uint16_t Xpos, uint16_t Ypos ); //��������� �������
void LCD_drawLine ( int x1, int y1, int x2, int y2, uint16_t color); //������ ����� (���������� ������, ���������� �����, ����). �������� ����������
void LCD_DrawRect ( int x1, int y1, int x2, int y2, uint16_t color,uint8_t filled ); //������ �������������(���������� �������� ������ ����, ���������� ������� ������� ����, ����, �������)
void LCD_FillScr(uint16_t color); //������� ������
void LCD_DrawEllipse(uint16_t X1,uint16_t Y1,uint16_t R, uint16_t color); //������ ���������� (���������� ������, ������,����)


#endif
