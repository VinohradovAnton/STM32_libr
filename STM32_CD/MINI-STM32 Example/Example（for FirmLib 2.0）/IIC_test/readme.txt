1 设计要求
	利用一块STM103V100评估板的两个IIC接口来实现IIC通讯，IIC1为主发送模式，
	IIC2为从接收模式，并通过LED灯来反映IIC通讯的情况。

2 硬件电路实现
	在评估板上，LED1、LED2分别与PC6、PC7相连；IIC1接口和IIC2接口在开发板上
	没有相互连接，因此需要使用实验板将两个IIC接口连接，并提供上拉电阻。

3 软件程序设计
	根据设计任务要求，该程序内容比较简单，主要包括：
	(1)	配置RCC，NVIC，GPIO；
	(2)	配置IIC1为主发送、IIC2为从接收方式；
	(3)	IIC1先发出开始信号，随后发出一个数组；
	(4)	IIC2接口以中断方式接收外部发过来的数据，接收到数据如果与发送出的数
	据不同则点亮LED1，相同则点亮LED2。
	整个工程包含3个源文件：STM32F10x.s、stm32f10x_it.c和main.c，其中STM32F10x.s
	为启动代码，IIC1和IIC2 中断服务子程序在stm32f10x_it.c中，其它函数则在main.c中。
	

4 运行过程
	(1)	使用Keil uVision3，通过ULINK 2仿真器连接评估板，将IIC1接口与IIC2接口互连
	（需要用户自制实验板实现）；
	(2)	打开实验例程目录IIC_TEST子目录下的IIC.Uv2例程，编译链接工程；
	(3)	点击MDK 的Debug菜单，点击Start/Stop Debug Session；
	(4)	观察LED1、LED2灯的变化情况，如果LED1亮表示传输失败，如果LED2亮表示传输成功。

