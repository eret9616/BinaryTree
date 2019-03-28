#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdlib.h>
#include <stdio.h>


typedef struct LINKNODE{
    // (企业链表
    struct LINKNODE *next;
} LinkNode;

typedef struct LINKSTACK{
    LinkNode head;
    int size;
} LinkStack;

// 初始化函数
LinkStack * Init_LinkStack();

// 入栈
void Push_LinkStack(LinkStack *stack,LinkNode * data);

// 出栈
void Pop_LinkStack(LinkStack *stack);

// 返回栈顶元素
LinkNode * Top_LinkStack(LinkStack * stack);

// 返回栈元素个数
int Size_LinkStack(LinkStack * stack);

// 清空栈
void Clear_LinkStack(LinkStack *stack);

// 销毁栈
void FreeSpace_LinkStack(LinkStack *stack);

#endif