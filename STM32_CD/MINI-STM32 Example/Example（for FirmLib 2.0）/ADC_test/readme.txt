1���Ҫ��
����ADC�ĵ�14ͨ���Կ������ϵ�Ȧ��λ���ĵ�ѹֵ��ADת������������ת��ģʽ��ת�����ͨ��DMAͨ
��1��ȡ��ADCת���Ľ����ÿ���1�����򴮿ڷ���һ�Ρ�

2 Ӳ����·���
����������ͨ��I/O��PC.04�뵥Ȧ��λ��RV1��������PC.04ӳ�䵽ADC��14ͨ��������ʵ������ADC_IN14
�Ե�λ��RV1��ѹ��ADת����

3����������
	�����������Ҫ�����������Ҫ������
	(1)	����GPIO�ڣ���PC.04����ΪADC�ĵ�14����ͨ����������GPIO��PA.09��PA.10������Ϊ�������������
	(2)	����ADC����ADC_IN14����Ϊ����ת��ģʽ��
	(3)	����DMAͨ��1����ADC_IN14����ת���Ľ����
	(4)	���ô��ڼ���ط��͹��ܣ�
	(5)	ÿ��1S�򴮿����ADת�������
	�������̰���2��Դ�ļ���STM32F10x.s��main.c������STM32F10x.sΪ�������룬������������main.c�С���������嵥���ο�����ע�⣬�ڹ�������Ȼ������stm32f10x_it.c�ļ���ԭ���������������ж����ж�����ʱʹ����stm32f10x_it.c�����Ķ��庯��������ϣ��ɾ��stm32f10x_it.c����������������ɾ����Ӧ���ж��������塣

4 ���й���
(1)	ʹ��Keil uVision3 ͨ��ULINK 2����������ʵ��壬ʹ��STM32V100�����帽���Ĵ����ߣ�����ʵ���
�ϵ�UART0��PC���Ĵ��ڣ���ʵ������Ŀ¼ADC_test��Ŀ¼�µ�ADC.Uv2���̣��������ӹ��̣�
(2)	��PC��������windows�Դ��ĳ����ն˴���ͨ�ų��򣨲�����115200��1λֹͣλ����У��λ����Ӳ����
���ƣ�������ʹ����������ͨ�ų���
(3)	���MDK ��Debug�˵������Start/Stop Debug Session��
(4)	��ת��λ��RV1�����Կ������������ֵ���ϱ仯��������ʾ���������ʾ��

usart1 print AD_value --------------------------
The current AD value = 0x0425
The current AD value = 0x0423
The current AD value = 0x0421
The current AD value = 0x0422
The current AD value = 0x0420
The current AD value = 0x0416
The current AD value = 0x03B6
The current AD value = 0x0841
The current AD value = 0x08C3
The current AD value = 0x08C0
The current AD value = 0x08BE
The current AD value = 0x09E9
The current AD value = 0x0A12
The current AD value = 0x0ACA
The current AD value = 0x0B0D
The current AD value = 0x0B10
The current AD value = 0x0B0E
....
....
(5)����ͨ��ITM Viewer���۲�Printf���ݣ�����Ҫ����#define DBG_ITM��������ITM���٣�
���RTX_Blinky����˵������������ֻҪȡ��#define DBG_ITMǰ��ע�ͷ��ż��ɡ�
(6)	���������壬����Ҳ����ʹ���������ģʽ����ɳ������С�
