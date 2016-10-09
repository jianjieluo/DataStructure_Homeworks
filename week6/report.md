实验报告 week6
===

`罗剑杰  教务三班  15331229`

> 实验环境： Ubuntu 16.04lts

源程序
---
已经存在于目录里面，具体的文件结构如下:
```
week6
├── compileAndRun.sh
├── main
└── 背包问题.cpp


```
**脚本complieAndRun.sh运行后直接编译出可执行文件main并且直接执行**
**其他具体实现可以看代码，已经写好了详细的注释，主要使用递归，stl中的vector容器，还有一些c++11特性简化程序的书写**

给出递归的核心代码：
```cpp
/**
 * a rescusive function to solve the package problem
 * @param ptotal the previous weight the package has taken in
 * @param T      the standard weight
 * @param index  the position that the current thing that is going to be put in
 * the package
 * @param vec    a vector stored all the things that can be put into the package
 * @param result a vector to store the things that have been put into the
 * package
 */
void put(int ptotal, const int T, unsigned int index,
         const std::vector<int>& vec, std::vector<int>& result) {
  if (index == vec.size()) {
    return;
  } else {
    result.push_back(vec[index]);
    int ctotal = ptotal + vec[index];
    if (ctotal < T) {
      put(ctotal, T, index + 1, vec, result);
    } else if (ctotal == T) {
      display(result);
    }
    result.pop_back();
    put(ptotal, T, index + 1, vec, result);
  }
}
```

-------


运行结果
---

1. 标准输入
```
longj@longj-working-bench:~/Data_Structure/week6$ ./compileAndRun.sh
10
Please end the input using EOF
1 8 4 3 5 2
The correct results can be listed below
1 4 3 2
1 4 5
8 2
3 5 2


```



2. 自由输入

```
longj@longj-working-bench:~/Data_Structure/week6$ ./compileAndRun.sh
8
Please end the input using EOF
1 3 2 5
The correct results can be listed below
1 2 5
3 5

```
