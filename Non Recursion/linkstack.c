#include "linkstack.h"


LinkStack * Init_LinkStack(){

    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));

    stack->head.next = NULL;

    stack->size = 0;

    return stack;
}


void Push_LinkStack(LinkStack * stack,LinkNode * data)
{
    if(stack == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    data->next = stack->head.next;
    stack->head.next = data;

    /*
        之后每次有新的入栈
        都会让data指向 stack结构体头结点已经指向的内容(即:上一个data的位置)
        然后让stack结构体的头结点指向这个新data
    */

    // size增长
    stack->size++;
}

void Pop_LinkStack(LinkStack * stack)
{
    if(stack == NULL){
        return;
    }

    if(stack->size == 0){
        return;
    }

    LinkNode * pNext  = stack->head.next;

    stack->head.next = pNext->next;

    stack->size--;
}

LinkNode * Top_LinkStack(LinkStack *stack)
{
    if(stack == NULL){
        return NULL;
    }
    if(stack->size == 0){
        return NULL;
    }

    return stack->head.next;
}

int Size_LinkStack(LinkStack * stack)
{
    if(stack == NULL){
        return -1;
    }
    
    return stack->size;
}


void Clear_LinkStack(LinkStack * stack)
{   
    if(stack == NULL){
        return;
    }

    stack->head.next = NULL;
    stack->size = 0;
}

void FreeSpace_LinkStack(LinkStack * stack)
{
    if(stack == NULL){
        return;
    }
    free(stack);
}