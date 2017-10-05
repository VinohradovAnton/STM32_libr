1设计要求
	为了利用一块STM103V100评估板来实现CAN通讯，令bxCAN处于环回模式，也就是能接收自己
	发送的报文，并保存（如果可以通过接收过滤）在接收邮箱里。分别采用以下两种方式来发
	送接收报文，以测试CAN接口，并通过LED灯来反映CAN通讯的情况。
	使bxCAN以100Kb/s的速率发送报文，采用轮询的方式接收报文，如果接收成功，LED1灯亮，
	否则，LED3灯亮；
	使bxCAN以500Kb/s的速率发送报文，采用中断的方式接收报文，如果接收成功，LED2灯亮，
	否则，LED4灯亮。

2 硬件电路设计
 
	在评估板上，LED1、LED2、LED3、LED4分别与PC6、PC7、PC8、PC9相连，由于采用环回模式，
	因此无需连接Rx和Tx。

3 软件程序设计
	根据设计任务要求，该程序内容比较简单，主要包括：
	(1)	配置GPIO口，将PA.11和PA.12w配置为CAN的输入输出引脚，将PC.06、PC.07、PC.0和
	PC.09配置为输出。
	(2)	配置bxCAN，使bxCAN以100Kb/s的速率发送报文，采用轮询的方式接收报文，如果接收
	成功，LED1灯亮，否则，LED3灯亮；
	(3)	配置bxCAN，使其以500Kb/s的速率发送报文，采用中断的方式接收报文，如果接收成功，
	LED2灯亮，否则，LED4灯亮；
	(4)	在CAN接收中断服务子程序中接收报文。
	整个工程包含3个源文件：STM32F10x.s、stm32f10x_it.c和main.c，其中STM32F10x.s为启动
	代码，CAN接收中断服务子程序在stm32f10x_it.c中，其它函数则在main.c中。

4 运行过程
	(1)	使用Keil uVision3 通过ULINK 2仿真器连接实验板，使用STM32V100评估板附带的串口线，
	连接实验板上的UART0和PC机的串口，打开实验例程目录CAN_test子目录下的CAN.Uv2例程，编
	译链接工程；
	(2)	点击MDK 的Debug菜单，点击Start/Stop Debug Session；
	(3)	观察LED1、LED2、LED3、LED4灯的变化情况。
	(4)	为了能更好观测CAN通讯过程，可以使用软件仿真调试，选择"Run to Main"。在点击
	Start/Stop Debug Session之后再点即菜单Peripherals->CAN->Communication，然后继续仿真
	运行程序。如果程序允许正确，在CAN:Communicaiton窗口将可以看到2个报文收发过程。读者
	还可以点击菜单Peripherals->CAN下其他选项来查看CAN接口其他属性，点击菜单Peripherals->
	Gerenal Purpose I/O->GPIOA查看LED灯的状态。


