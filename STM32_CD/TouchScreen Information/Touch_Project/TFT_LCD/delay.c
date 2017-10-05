#include <stm32f4xx.h>

#include "delay.h"

void delay_init ( uint8_t a)
{
	// for 168 MHz TIM6
	// ���� d=1 �� ����� �������� � �������������
	// ���� d=10 �� ����� �������� � �������������*10
	// ���� d=100 �� ����� �������� � �������������*100
	// ����� �������� ������ 3 �������� 1,10,100

	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->PSC = (84*a)-1;
	TIM6->CR1 = TIM_CR1_OPM;
}

void delay ( uint16_t a )
{
	TIM6->ARR=a; 				// �� ������� ������ �������
	TIM6->CNT=0; 				// �������� ������� �������� ��������
	TIM6->CR1 |= TIM_CR1_CEN;	// �������� �������

	while((TIM6->SR & TIM_SR_UIF)==0);	//�������� ������������ ��������
	TIM6->SR &= ~TIM_SR_UIF; 			//����� ���� ������������ ��������
	TIM6->CR1 &= ~TIM_CR1_CEN;			//��������� �������
}

