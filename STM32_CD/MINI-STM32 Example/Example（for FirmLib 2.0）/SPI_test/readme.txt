1 设计要求
    利用一块STM103V100评估板的两个SPI接口来实现SPI全双工通讯。
	第一阶段，SPI1为主模式，SPI2为从模式，双方交换数据；
	第二阶段，SPI1为从主模式，SPI2为主模式，双方交换数据。利用LED1和LED2来反映SPI通讯的情况。

2 硬件电路实现
	在评估板上，LED1、LED2、LED3、LED4分别与PC6、PC7、PC8、PC9相连；
	但SPI1接口和SPI2接口在开发板上没有相互连接，因此需要使用实验板将两个SPI接口连接。

3 软件程序设计
	根据设计任务要求，该程序内容比较简单，主要包括：
	(1)	配置RCC，NVIC，GPIO；
	(2)	配置SPI1为主设备、SPI2为从设备，双方交换数据；如果SPI1发送到SPI2 的数据正确则LED1亮，
	如果SPI2发送到SPI1的数据正确则LED2亮；
	(3)	修改SPI端口配置，将配置SPI2为主设备、SPI1为从设备，双方交换数据；如果SPI1发送到SPI2
	的数据正确则LED3亮，如果SPI2发送到SPI1的数据正确则LED4亮；
	整个工程包含2个源文件：STM32F10x.s和main.c，其中STM32F10x.s为启动代码，其它函数则在main.c中。

4 运行过程
	(1)	使用Keil uVision3，通过ULINK 2仿真器连接评估板，将SPI1接口与SPI2接口互连（需要用户连线
	实现）；
	(2)	打开实验例程目录SPI_TEST子目录下的SPI.Uv2例程，编译链接工程；
	(3)	点击MDK 的Debug菜单，点击Start/Stop Debug Session；
	(4)	观察LED1、LED2、LED3、LED4灯的变化情况。如果LED1亮表示SPI1主发送到SPI2从接收正确，
	如果LED2亮表示SPI2从发送到SPI1主接收成功；如果LED3亮表示SPI1从发送到SPI2主接收正确;
	如果LED4亮表示SPI2主发送到SPI1从接收成功。
