实验报告 week7
===

`罗剑杰  教务三班  15331229`

> 实验环境： Ubuntu 16.04lts

源程序
---
已经存在于目录里面，具体的文件结构如下:
```
.
├── include
│   ├── ArrayList.hpp
│   ├── enum.hpp
│   └── NodeList.hpp
├── Makefile
└── src
    ├── ArrayList.cpp
    ├── main.cpp
    └── NodeList.cpp

2 directories, 7 files
```
主要是调用了模板类，然后编译方面做了一点微小的处理，其他是很基础的代码的实现，


-------


运行结果
---

1. 标准输入
```
Choose 1 for specific initialization and others for no specific initialization
1
This experiment's List_entry is char
The report messages are list below
0 : fail
1 : success
2 : overflow
3 : underflow
----------------------------
End the experiment with EOF
You can use the following command to control the 2 list
0 -> help
1 -> ArrayList: insert an element
2 -> ArrayList: remove an element
3 -> ArrayList: display the current element
4 -> NodeList: insert an element
5 -> NodeList: remove an element
6 -> NodeList: display the current element
3
The current ArrayList is:
C->O->M->P->U->T->E->R
6
The current NodeList is:
C->O->M->P->U->T->E->R
1     
Input the data and the position
A 0
1
6
The current NodeList is:
C->O->M->P->U->T->E->R
3
The current ArrayList is:
A->C->O->M->P->U->T->E->R
2
Input the position you want to move from the ArrayList
0
1
3
The current ArrayList is:
C->O->M->P->U->T->E->R
4
Input the data and the position
1 5
1
6
The current NodeList is:
C->O->M->P->U->1->T->E->R
5
Input the position you want to move from the ArrayList
3
1
6
The current NodeList is:
C->O->M->U->1->T->E->R
The experiment is over

```
