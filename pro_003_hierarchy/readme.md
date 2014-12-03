九章算法面试题7 分层遍历二叉树
===

问题详情 

初阶：给一棵二叉树，按照层次进行输出，第一行输出第一层的节点，第二行输出第二层，如此类推。
进阶：如果只给你O(h)的额外空间该怎么办？（h为树的高度） 

解答 

答：

初阶：
    采用宽度（广度）优先搜索算法BFS。用一个队列存储一层的节点，通过一层节点扩展出下一层节点。
    实现的时候有两种方式：一种方式是队列中同时存储层数，发现层数不同了，就换行输出；另一种方式是记录每一层的头尾，
    多套一层循环输出每一层。时间复杂度O(n)，空间复杂度O(n)

进阶：
    采用迭代搜索。迭代搜索的意思是，设定一个层数限制x，利用深度优先搜索的方式往下搜索，
    每次搜到x这一层就不再往下继续递归了。通过逐渐放宽x来实现每一层的搜索，
    也就是x从1到h进行枚举（h为树的高度）。时间复杂度O(nh)，空间复杂度O(h)。
    迭代搜索是常用的在空间不足的情况下替代宽度优先搜索的方法。是一种用时间换取空间的方法。

面试官角度：

    考察对于搜索的基础知识熟练程度。
    深度优先搜索，宽度优先搜索，迭代搜索，是最常见的三种搜索方式。
    其中初阶问题，还会考察对宽度优先搜索实现的掌握，这是诸多IT公司面试都会考察的内容.

[九章算法原题-落单的数](http://www.ninechapter.com/problem/7/)