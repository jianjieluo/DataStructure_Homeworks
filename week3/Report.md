实验报告 week4
===

`罗剑杰  教务三班  15331229`

源程序
---
已经存在于目录里面，具体的文件结构如下:
```
.
├── bin
│   └── main
├── build
│   ├── main.o
│   ├── queue.o
│   └── stack.o
├── include
│   ├── Error_code.hpp
│   ├── Queue.hpp
│   └── Stack.hpp
├── makefile
├── Report.md
└── src
    ├── main.cpp
    ├── queue.cpp
    └── stack.cpp

```
**已经写完makefile，可以通过make来管理整个项目**
*其他具体实现可以看代码*

-------


运行结果
---

1. 标准输入
```
longj@longj-working-bench:~/Data_Structure/week4$ ./bin/main
1 for the standard input and 2 for the test
1
The display of my stack
R E T U P M O C
The display of my queue
C O M P U T E R

```



2. 自由输入

```
longj@longj-working-bench:~/Data_Structure/week4$ ./bin/main
1 for the standard input and 2 for the test
2
[3;J  // 因为调用了system("clear") 而导致的一些输出
----------------Welcome!!----------------
0 display the help menu
-----------------------------------------
1 push an element into the stack
2 pop an element from the stack
3 display the current stack
-----------------------------------------
4 push an element into the queue
5 pop an element from the queue
6 display the current stack
------------------------------------------
Here is the Error_code:
0 for fail
1 for success
2 for overflow
3 for underflow
1
Input a data:
a
The Error code is :1
1
Input a data:
b
The Error code is :1
3
Display my stack:
b a
The Error code is :1
4
Input a data:
h
The Error code is :1
4
Input a data:
a
The Error code is :1
6
Display my queue:
h a
The Error code is :1
5
Pop a data:
The Error code is :1
5
Pop a data:
The Error code is :1
5
Pop a data:
The Error code is :3
```
