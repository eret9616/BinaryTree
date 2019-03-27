#include <stdio.h>
#include <stdlib.h>

typedef struct BINARYTREE
{
    char ch;
    struct BINARYTREE *lchild;
    struct BINARYTREE *rchild;
} BinaryTree;


// 二叉树的几种递归操作

// 1 递归遍历二叉树

// 2 递归求叶子结点数目

// 3 递归求二叉树高度

// 4 递归拷贝二叉树

// 5 递归释放二叉树内存


// 1
void Recursion( BinaryTree * node){
    if(node == NULL)
    {
        return;
    }

    // DLR 前序遍历
    printf("%c",node->ch);
    Recursion(node->lchild);
    Recursion(node->rchild);
}


// 2  叶子结点: 度( 结点分叉数目)为0的结点.
int num;
void RecursionLeafNum(BinaryTree * node)
{
    if(node == NULL)
    {
        return;
    }

    // 如果左子树右子树都没有 那就是叶子节点
    if(node->lchild == NULL && node->rchild == NULL)
    {
        num++;
        return; // 这个return可以不写
    }

    RecursionLeafNum(node->lchild);
    RecursionLeafNum(node->rchild);
}

// 3 递归求二叉树高度
int RecursionCalculateHeight(BinaryTree * node){
    
    int height;
    int Lheight = 0;
    int Rheight = 0;

    // 设置递归退出条件
    if(node == NULL)
    {
        return 0;
    }

    Lheight =  RecursionCalculateHeight(node->lchild);
    Rheight =  RecursionCalculateHeight(node->rchild);

    height = (Lheight>Rheight? Lheight:Rheight) +1;
    return height;
}

int RecursionCalculateHeight2(BinaryTree *node){

    int height;
    int Lheight = 0;
    int Rheight = 0;

    // 如果存在左子树
    if(node->lchild != NULL)
    {
        Lheight = RecursionCalculateHeight2(node->lchild);
    }

    // 如果存在右子树
    if(node->rchild  != NULL)
    {
        Rheight = RecursionCalculateHeight2(node->rchild);
    }

    height = (Lheight > Rheight ? Lheight: Rheight) + 1;
    return height;
}


// 4 递归拷贝二叉树
BinaryTree * RecursivelyCopyBinaryTree(BinaryTree * Node)
{
    // 设置递归退出条件
    if(Node == NULL)
    {
        return NULL;
    }

    // 在堆空间开辟临时结点
     BinaryTree * Tmpnode  = (BinaryTree *)malloc(sizeof(BinaryTree));

     Tmpnode->ch = Node->ch;
     Tmpnode->lchild = RecursivelyCreateBinaryTree(Node->lchild);
     Tmpnode->rchild = RecursivelyCreateBinaryTree(Node->rchild);

     return Tmpnode;
}


// 5 递归释放二叉树内存
void RecursivelyFreeBinaryTree(BinaryTree *Node)
{   
    // 设置递归退出条件
    if(Node == NULL)
    {
        return;
    }    

    RecursivelyFreeBinaryTree(Node->lchild);
    RecursivelyFreeBinaryTree(Node->lchild);
    free(Node);
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

    // 1
    // Recursion(&node1);

    // 2
    // RecursionLeafNum(&node1);
    // printf("%d",num);

    // 3
    // printf("%d",RecursionCalculateHeight(&node1));
    // printf("%d",RecursionCalculateHeight2(&node1));

    // 4
    // BinaryTree* Copy =  RecursivelyCreateBinaryTree(&node1);
    // Recursion(Copy);
    // RecursivelyFreeBinaryTree(Copy);

}


int main(void)
{
    createBinaryTree();

    return 0;
}

