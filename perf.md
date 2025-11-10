perf使用 (linux 内核的 perf_events 子系统; CPU 性能监控单元 PMU)

1. 用perf 生成程序运行时的统计文件.data(默认是perf.data)

   perf record -g -o ./xx.data  ./xx
  
2. 查看.data
   perf report -g -i xx.data

   注: linux GUI 查看，用 上下箭头 来上下移动， 选到某行 ‘+’ 上点击键盘上的 ‘+’ 可以展开。
  
3. 内存查看
   perf mem record -o xx_mem.dat ./xx ; perf mem report -i xx_mem.dat 
   
4. IO 查看 (需要 /sys/kernel/tracing/ 755 权限)
   perf trace -e block:block_rq_issue,block:block_rq_complete -o io_xx.dat ./xx
   
5. 一些参数选项
   --stdio 将报告输出到标准输出，即以文本形式输出到终端   
 
6. 生成火焰图
	perf script -i xx.data > xx.unfold
	stackcollapse-perf.pl xx.unfold > xx.folded
	flamegraph.pl xx.folded > xx.svg
  
6. 生成火焰图
   1) 安装 
     wget https://github.com/brendangregg/FlameGraph/archive/master.zip
	 unzip master.zip
	 mv FlameGraph-master/ /opt/FlameGrap
	 export PATH=$PATH:/opt/FlameGraph

===========================
gprof 使用

1. 编译时增加 -pg选项

2. 运行程序，会生成xx.out （gmon.out）

3. 生成分析统计文件
   gprof xx  gmon.out > xx.gprof

3.  转为图表
   gprof2dot < xx.gprof | dot -Tsvg -o xx.svg 
