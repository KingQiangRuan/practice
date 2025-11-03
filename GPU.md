# GPU

SM : Stream Multiprocessor, 执行任务的核心单元。
Tensor Core： 硬件单元，能在一个时钟周期内完成小的矩阵乘加运算，（4x4 矩阵）。

1. regiser file
2. share memory
3. L1 Data Cache, Instruction Cache.
4. Warp Scheduler
5. PICE 负责CPU和GPU通信，DMA模式

6. 全局显存 ：高带宽内存（HBM），

7. 速度有快到慢， L1 Cahe -> L2 Cache -> HBM -> DRAM
8. 编程模型， 软件/硬件对应关系

   1) Grid -> Block -> Threads （软件层面）
   2) GPU(device) -> SM(Share Multiprocess) -> Core （硬件层面）
  
9. 调度

   1) Thread Block 是最小的资源调度与分配的 最小单位
   2) Warp 是硬件调度最小单位
   3) Thread Block 被分配给硬件的SM， SM将 Thread Block 按照32 个Thread 一组组成Warp. 分配给Warp Scheduler 执行

10. 一个SM 能执行的Warp 主要由以下3点：
  1） register， SM的寄存器， 存储局部变量。
  2） Shared Memory， 分给一个SM的共享内存。
  3） 线程快/线程数限制， 一个SM可以同时调度多少个Tread Block




