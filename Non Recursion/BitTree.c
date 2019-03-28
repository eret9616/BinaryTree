#include <stdio.h>
#include <stdlib.h>

#include "linkstack.h"

#define MY_FALSE 0
#define MY_TRUE 1



typedef struct BINARYTREE
{
    char ch;
    struct BINARYTREE *lchild;
    struct BINARYTREE *rchild;
} BinaryTree;


typedef struct BITREESTACKNODE{
    LinkNode node;
    BinaryTree * root;
    int flag;
} BiTreeStackNode;

// 二叉树的非递归深度优先遍历
// 前序遍历 中序遍历 后序遍历
/*
   算法思路:
   
   使用栈
  
   对二叉树进行包装，增加一个flag位  初始化root的flag为false
   
   第一次将root结点压入栈
   
   当栈不为空的时候:
   {

    弹出栈顶元素

    如果栈顶元素值为NULL就跳过本次循环
    
    如果栈顶元素flag为true就输出

    否则:{

      将弹出的栈顶元素将结点flag设置为true(目的是进行标记之后将访问这个结点)
  
      分别取到包装好的该结点的左节点右结点

      将三个结点压栈 (根据不同压栈顺序实现先序中序后序遍历  DLR LDR LRD  压入顺序是相反的 比如DLR应先压入右再压入左再压入中)
      }

   }

*/

BiTreeStackNode * CreateBiTreeStackNode(BinaryTree * node,int flag){

    BiTreeStackNode * newnode = (BiTreeStackNode *)malloc(sizeof(BiTreeStackNode));

    newnode->root = node;

    newnode->flag = flag;

    return newnode;
};


void NonRecursion(BinaryTree * root)
{
    LinkStack *stack = Init_LinkStack();

    Push_LinkStack(stack,(LinkNode *)CreateBiTreeStackNode(root,MY_FALSE));

    while(Size_LinkStack(stack) > 0){

        BiTreeStackNode * node = (BiTreeStackNode *)Top_LinkStack(stack);

        Pop_LinkStack(stack);

        if(node->root == NULL){
            continue;
        }

        if(node->flag == MY_TRUE)
        {
            printf("%c",node->root->ch);
        }else
        {
            node->flag = MY_TRUE;

            Push_LinkStack(stack,(LinkNode *)CreateBiTreeStackNode(node->root->rchild,MY_FALSE));
            Push_LinkStack(stack,(LinkNode *)CreateBiTreeStackNode(node->root->lchild,MY_FALSE));
            Push_LinkStack(stack,(LinkNode *)node);
        }
    }
}


void createBinaryTree()
{
    // 初始化二叉树
    BinaryTree node1 = {'A', NULL, NULL};
    BinaryTree node2 = {'B', NULL, NULL};
    BinaryTree node3 = {'C', NULL, NULL};
    BinaryTree node4 = {'D', NULL, NULL};
    BinaryTree node5 = {'E', NULL, NULL};
    BinaryTree node6 = {'F', NULL, NULL};
    BinaryTree node7 = {'G', NULL, NULL};
    BinaryTree node8 = {'H', NULL, NULL};

    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;

    NonRecursion(&node1);

}

int main(void)
{
    createBinaryTree();
    printf("\n");
    system("pause");
    return 0;
}