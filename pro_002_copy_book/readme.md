问题描述
===
3162 抄书问题

现在要把M本有顺序的书分给K个人复制（抄写），每一个人的抄写速度都一样，一本书不允许给两个（或以上）的人抄写，
分给每一个人的书，必须是连续的，
比如不能把第一、第三、第四本数给同一个人抄写。
现在请你设计一种方案，使得复制时间最短。
复制时间为抄写页数最多的人用去的时间。

输入描述 Input Description
第一行两个整数M、K；（K<=M<=100）
第二行M个整数，第i个整数表示第i本书的页数。
输出描述 Output Description

共K行，每行两个正整数，第i行表示第i个人抄写的书的起始编号和终止编号。K行的起始编号应该从小到大排列，如果有多解，则尽可能让前面的人少抄写。

  样例输入 Sample Input
  
  9 3
  
  1 2 3 4 5 6 7 8 9
  

  样例输出 Sample Output
  
  1 5
  
  6 7
  
  8 9

原题：
[codevs - 3162 抄书问题](http://codevs.cn/problem/3162/)
