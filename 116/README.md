#Populating Next Right Pointers in Each Node 二叉树填充next指针指向右侧结点
##原题地址
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
##题目描述
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
填充二叉树，使得每个结点的next指针指向其右侧的结点。如果没有右侧结点，next指针指向NULL。

Initially, all next pointers are set to NULL.
初始情况下，所有的next指针都指向NULL。

Note:
注意：

You may only use constant extra space.
只能使用常数级的额外空间。

You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
假设二叉树是完全二叉树（所有的叶子结点都在同一层上，每一个父结点都右两个孩子结点）。

For example,
例如，

Given the following perfect binary tree,
给出如下完全二叉树，

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:
在调用方法之后，二叉树应该看起来像下面这样：

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

##解题思路
http://blog.csdn.net/smile_watermelon/article/details/46710205


##运行结果
    Lauguage  Status  Time
    c         Accept  4ms
    cpp       Accept  28ms

---
2015/6/27
