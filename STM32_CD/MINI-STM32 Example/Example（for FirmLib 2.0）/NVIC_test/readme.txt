1���Ҫ��
    ���һ���ж����ȼ���ռ��ʵ�������������жϣ�EXTI0��EXTI9��SysTick����EXTI9���жϷ���֮����
	��ʵ��EXTI1��SysTick�����ȼ����ת����ʹ֮�ֱ���֣���EXTI1�ж�ʱ���Ա�SysTick��ռ�Ͳ�����
	��SysTick��ռ������״̬��
2 Ӳ����·���
   ���������ϰ���Key��PB.9������ΪEXTI9������Wakeup��PA.0������ΪEXTI1��LED1��LED2��LED3��LED4
   �ֱ���PC6��PC7��PC8��PC9������������ʾ��ͬ�����ȼ���ռ״̬��
3 ����������
   �����������Ҫ�����������Ҫ���ݰ�����
  (1)	��������EXTI �ⲿ�ж��ߣ�Line0 �� Line9�������½��ز����жϣ�������SysTick�жϡ����У�
    	    EXTI0: ���ȼ�= PreemptionPriorityValue�������ȼ�=0��
    		EXTI9: ���ȼ�= 0�������ȼ�= 1��
	        SysTick Handler:���ȼ�= !PreemptionPriorityValue�������ȼ� SubPriority = 0��
  (2)	�տ�ʼ����PreemptionPriorityValue=0����EXTI0���ȼ���SysTick���ȼ��ߣ���EXTI9�жϷ�����
  �����У�EXTI Line0��SysTick �����ȼ��Ի���
  (3)	��EXTI0�жϷ����ӳ����У�SysTick�жϹ���λ����1����SysTick���ȼ���EXTI Line0 ���ȼ��ߣ�
  ��EXTI 0�жϱ���ռ��ת��ȥִ��SysTick�жϷ����ӳ��򣻷������ִ��EXTI Line0�жϷ����ӳ���
  (4)	���EXTI1��SysTick��ռ��LED1��LED2��LED3��LED4ѭ����˸�����EXTI1��ռSysTick��LED1��
  LED2��LED3��LED4������
4 ���й���
  (1)	ʹ��Keil uVision3 ͨ��ULINK����������ʵ��壬��ʵ������NVIC_test��Ŀ¼�µ�NVIC.Uv2
  ���̣��������ӹ��̣�
  (2)	���MDK ��Debug�˵���ѡ��Start/Stop Debug Session���Ctrl+F5����Զ������Ŀ��岢����
  ���Դ��뵽Ŀ��ϵͳ��RAM�У�
  (3)	���������������к󣬻������½���� 
            ����һ�η���EXTI9 �жϺ󣨰���STM32����Key��ť����SysTick�жϵ����ȼ���EXTI0�ж�
			���ȼ��ߡ���˵�EXTI0�жϷ���ʱ������Wakeup��ť��������ִ��SysTick�жϷ����ӳ���
			������ռ������PreemptionOccured Ϊ�棬LED1-LED4��ʼ��˸��
            ���ڶ��η���EXTI9�жϺ�SysTick�жϵ�ռ���ȼ���EXTI0���ȼ��ͣ���˵�EXTI0�жϷ�
			��ʱSysTick�޷���ռ������PreemptionOccured Ϊ�٣�LED1-LED4ֹͣ��˸��
            ÿ��EXTI9������SysTick��EXTI0�ͻᷢ�����ȼ�ת��������ǰ��2����״̬��
