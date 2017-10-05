1设计要求
    设计一个中断优先级抢占的实例。设置三个中断：EXTI0、EXTI9和SysTick，在EXTI9的中断服务之程序
	中实现EXTI1和SysTick的优先级别的转换，使之分别出现：在EXTI1中断时可以被SysTick抢占和不可以
	被SysTick抢占这两种状态。
2 硬件电路设计
   在评估板上按键Key与PB.9相连作为EXTI9，按键Wakeup与PA.0相连作为EXTI1；LED1、LED2、LED3、LED4
   分别与PC6、PC7、PC8、PC9相连，用于显示不同的优先级抢占状态。
3 软件程序设计
   根据设计任务要求，软件程序主要内容包括：
  (1)	配置两根EXTI 外部中断线（Line0 和 Line9），在下降沿产生中断，并配置SysTick中断。其中：
    	    EXTI0: 优先级= PreemptionPriorityValue，子优先级=0；
    		EXTI9: 优先级= 0，子优先级= 1；
	        SysTick Handler:优先级= !PreemptionPriorityValue，子优先级 SubPriority = 0；
  (2)	刚开始设置PreemptionPriorityValue=0，即EXTI0优先级比SysTick优先级高；在EXTI9中断服务子
  程序中，EXTI Line0和SysTick 的优先级对换；
  (3)	在EXTI0中断服务子程序中，SysTick中断挂起位被置1，若SysTick优先级比EXTI Line0 优先级高，
  则EXTI 0中断被抢占，转而去执行SysTick中断服务子程序；否则继续执行EXTI Line0中断服务子程序。
  (4)	如果EXTI1被SysTick抢占则LED1、LED2、LED3、LED4循环闪烁，如果EXTI1抢占SysTick则LED1、
  LED2、LED3、LED4常亮。
4 运行过程
  (1)	使用Keil uVision3 通过ULINK仿真器连接实验板，打开实验例程NVIC_test子目录下的NVIC.Uv2
  例程，编译链接工程；
  (2)	点击MDK 的Debug菜单，选择Start/Stop Debug Session项或Ctrl+F5键，远程连接目标板并下载
  调试代码到目标系统的RAM中；
  (3)	程序正常启动运行后，会有以下结果： 
            当第一次发生EXTI9 中断后（按下STM32板上Key按钮），SysTick中断的优先级比EXTI0中断
			优先级高。因此当EXTI0中断发生时（按下Wakeup按钮），将先执行SysTick中断服务子程序，
			发生抢占，变量PreemptionOccured 为真，LED1-LED4开始闪烁；
            当第二次发生EXTI9中断后，SysTick中断的占优先级比EXTI0优先级低，因此当EXTI0中断发
			生时SysTick无法抢占，变量PreemptionOccured 为假，LED1-LED4停止闪烁；
            每次EXTI9发生后，SysTick和EXTI0就会发生优先级转换，出现前面2步的状态。
