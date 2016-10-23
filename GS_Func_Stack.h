#ifndef _GS_FUNC_STACK_H
#define _GS_FUNC_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREASEMENT 10

typedef int SElemType;

typedef struct {
        SElemType* base;
        SElemType* top;
        int stacksize;
}SqStack;



class GSStackFunc
{
public:
        GSStackFunc();
        ~GSStackFunc();
        int InitStack( SqStack &S );
        int GetTop( SqStack S, SElemType &e );
        int DestroyStack( SqStack &S );
        int ClearStack( SqStack &S );
        int StackEmpty( SqStack S );
        int StackLength( SqStack S);
        int Push( SqStack &S, SElemType e );
        int Pop( SqStack &S, SElemType &e );
        int StackTraverse( SqStack S, int( *visit )());
};

#endif //_GS_FUNC_STACK_H
