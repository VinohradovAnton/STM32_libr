1设计要求
要求系统按如下方式进入和退出睡眠模式：
在系统启动2秒后，将RTC在3秒钟之后配置为产生一个报警事件，接着通过WFI指令使系统进入停机模式。如果要唤醒系统到正常模式，可通过按Key按钮；否则，在3秒钟后，会产生RTC报警中断自动将系统唤醒。一旦退出停机模式，系统时钟被配置成先前的状态（在停机模式下，外部高速振荡器HSE和PLL是不可用的）。经过一段延时之后，系统将再次进入停机状态，并可按上述操作无限重复。
2 硬件电路设计
硬件电路采用与7.1小节应用实例一样硬件电路，可见图7-10。其中Key按钮用于通过PB9产生一个外部中断，LED1、LED2、LED3、LED4则用于显示处理器所处的模式和中断触发情况。
3 软件程序设计
根据任务要求，程序内容主要包括：
(1)	配置GPIOB口，配置RTC，配置外部中断；   
(2)	配置PB口第9个引脚作为外部中断，下降延触发；配置RTC报警中断，上升沿触发； 
(3)	两个中断服务子程序的内容分别是：切换LED2和LED3灯的状态；
整个工程包含3个源文件：STM32F10x.s、stm32f10x_it.c和main.c，其中STM32F10x.s为启动代码，所有中断服务子程序均在stm32f10x_it.c中，其它函数则在main.c中。下面分别介绍相关的函数，具体程序清单见参考程序。
函数SYSCLKConfig_STOP用于当处理器从停机模式唤醒之后，配置系统时钟、使能HSE和PLL，并以PLL作为系统时钟源。当处理器处理停机模式的时候，HSE、PLL是不可用的。
函数GPIO_Configuration用于配置GPIO的PC6、PC7、PC8、PC9和PB9。
函数EXTI_Configuration用于配置外部中断线9（PB9）和17(RTC报警)。
函数NVIC_Configuration配置NVIC及中断向量表，这里主要是配置外部中断线9和17。
函数EXTI9_5_IRQHandler处理按钮Key(PB9)所触发的中断，其主要作用是将LED2灯的状态翻转一次。
函数RTCAlarm_IRQHandler处理RTC报警所触发的中断，其主要作用事将LED3 灯的状态翻转一次，如果设置了唤醒标志则清除之。

运行过程：

(1)	使用Keil uVision3 通过ULINK 2仿真器连接实验板，打开实验例程目录PWR_TEST子目录下的PWR.Uv2
例程，编译链接工程；
(2)	选择软件调试模式，点击MDK 的Debug菜单，选择Start/Stop Debug Session项或Ctrl+F5键，在逻
辑分析仪中添加GPIOC_ODR.6、GPIOC_ODR.7、GPIOC_ODR.8、GPIOC_ODR.9，点击Run按钮即可在逻辑分析
仪中看到如图7-14，还可用Peripherals-General Port-GPIOB来模拟KEY按钮的动作；

(3)	选择硬件调试模式，选择Start/Stop Debug Session项或Ctrl+F5键，下载程序并运行，观察LED灯
的变化情况。注意，当目标系统进入停机模式之后，将无法使用仿真器进行调试了；
(4)	退出Debug模式，打开Flash菜单>Download，将程序下载到开发板的Flash中，按RESET键复位，观察
LED灯的情况，正常情况应为：系统处于运行模式时LED1亮、LED4灭；系统处于停机状态时LED1灭、LED4亮；
当按下KEY按钮时LED2灯状态发生反转；当发生RTC报警时LED3状态发生反转。
