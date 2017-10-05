1设计要求
利用ADC的第14通道对开发板上单圈电位器的电压值作AD转换，采用连续转换模式，转换结果通过DMA通
道1读取。ADC转换的结果，每间隔1秒钟向串口发送一次。

2 硬件电路设计
在评估板上通用I/O口PC.04与单圈电位器RV1相连，将PC.04映射到ADC第14通道，即可实现利用ADC_IN14
对电位器RV1电压作AD转换。

3软件程序设计
	根据设计任务要求，软件程序主要包括：
	(1)	配置GPIO口，将PC.04配置为ADC的第14采用通道；将配置GPIO中PA.09和PA.10根引脚为串口输入输出。
	(2)	设置ADC，将ADC_IN14设置为连续转换模式；
	(3)	配置DMA通道1用于ADC_IN14传输转换的结果；
	(4)	配置串口及相关发送功能；
	(5)	每隔1S向串口输出AD转换结果。
	整个工程包含2个源文件：STM32F10x.s和main.c，其中STM32F10x.s为启动代码，其它函数则在main.c中。具体程序清单见参考程序。注意，在工程中仍然包含了stm32f10x_it.c文件，原因是在启动代码中定义中断向量时使用了stm32f10x_it.c函数的定义函数名，如希望删除stm32f10x_it.c则需在启动代码中删除相应的中断向量定义。

4 运行过程
(1)	使用Keil uVision3 通过ULINK 2仿真器连接实验板，使用STM32V100评估板附带的串口线，连接实验板
上的UART0和PC机的串口，打开实验例程目录ADC_test子目录下的ADC.Uv2例程，编译链接工程；
(2)	在PC机上运行windows自带的超级终端串口通信程序（波特率115200、1位停止位、无校验位、无硬件流
控制）；或者使用其它串口通信程序；
(3)	点击MDK 的Debug菜单，点击Start/Stop Debug Session；
(4)	旋转电位器RV1，可以看到串口输出数值不断变化，正常显示结果如下所示。

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
(5)若想通过ITM Viewer来观测Printf数据，则需要加入#define DBG_ITM，并允许ITM跟踪，
详见RTX_Blinky例的说明。本例程中只要取消#define DBG_ITM前的注释符号即可。
(6)	若无评估板，读者也可以使用软件仿真模式来完成程序运行。
