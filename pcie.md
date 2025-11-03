# PCIE
一种点对点，高速串行的计算机扩展总线。

1. PCIE 主要由RC (Root Complex)，Switch，EP（End Point）等设备组成
   1.1 RC
    1) 将存储域地址空间转换为PCIE域地址空间
    2) 将CPU的请求转换为PCIE的4种请求，（configuration, Memory, I/O, Message）.
    3) 转换CPU和PCIE设置的通信消息
   1.2 Switch
    1) PCI 连接桥梁
  
2. PCIE 分三层
   2.1 事务层（Transaction Layer）
      1) 处理TLP
      2) Credit-Based 流控机制，防止接收缓冲区溢出
         
   2.2 数据链路层（Link Data Layer）
      1） DLLP 生成
      2）链路管理，错误检测，纠正
   
   2.3 物理层（physical Layer）
    1）链路训练，状态机
    2）链路初始化, 速度协商，链路带宽协商

   3. 数据传输方式
      3.1 PIO（Programed IO）
        1) CPU 控制数据在设备和内存之间的传输
        2) 控制简单，CPU占用率高
      3.2 DMA
        1) 设备通过DMA 直接与内存进行数据传输
        2) 传输速度快，占用CPU资源少
      3.3 P2P
       1）PCIE 设备通过PCIE Switch 直接传输数据
       2）降低延迟和CPU开销，速率极高
