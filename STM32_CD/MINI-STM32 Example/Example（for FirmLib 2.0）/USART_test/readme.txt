1设计要求
利用PC机的串口与开发板的COM0口进行输入输出通信。通过PC机键盘往开发板的COM0口送字符，
开发板上的COM0将收到的字符再传回给PC，在PC超级终端上显示其串口接收到的字符。
2 电路设计
由于串口已连好，该实验不需要额外电路设计，只需将用一根RS232串行通讯线将开发板的COM0口
（CN11连接器）与PC机的串口相连即可。  
3 软件程序设计
根据任务要求，程序内容主要包括：
(1)	初始化串口；
(2)	检测串口接收器，如果有数据则放入串口USART_DR寄存器中；
(3)	将收到的字符发送给PC，然后回到（2）。
整个工程包含2个源文件：STM32F10x.s和main.c，其中STM32F10x.s为启动代码，其它函数则在
main.c中。其中，USART_Configuration函数用于配置USART控制器，fputc函数用于将printf函
数重定向到USART，循环接收和发送字符则在main函数中进行。


4 运行过程
(1)	使用Keil uVision3 通过ULINK 2仿真器连接实验板，打开实验例程目录USART_TEST子目录下
的USART.Uv2例程，编译链接工程；
(2)	使用STM32开发板附带的串口线，连接开发板上的COM0和PC机的串口；
(3)	在PC机上运行windows自带的超级终端串口通信程序（波特率115200、1位停止位、无校验位、
无硬件流控制）；或者使用其它串口通信程序；
(4)	选择硬件调试模式，点击MDK 的Debug菜单，选择Start/Stop Debug Session项或Ctrl+F5键，
远程连接目标板并下载调试代码到目标系统中；
(5)	例程正常运行之后会在超级终端显示以下信息：
Welcome to Wuhan R&D Center, Embest  
 Please Input Character from Keyboard 
在PC机的键盘上输入的字符，将在超级终端上显示。
(6)	也可选择软件调试模式，点击MDK 的Debug菜单，打开串行窗口，选择Start/Stop Debug Session
项或Ctrl+F5键，在串行窗口中也可看到与第（5）步超级终端中所显示的相同内容。
