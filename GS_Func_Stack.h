#ifndef _GS_FUNC_STACK_H
#define _GS_FUNC_STACK_H

#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREASEMENT 10


//typedef char SElemType;

template <class T>
class GSStackFunc
{
public:
        GSStackFunc()
                {
                        ;
                }
        ~GSStackFunc()
                {
                        ;
                }

        typedef struct{
                T* base;
                T* top;
                int stacksize;
        }SqStack;

        int InitStack( SqStack &S )
                {
                        S.base = ( T *)malloc( STACK_INIT_SIZE * sizeof( T ));
                        if ( !S.base )
                        {
                                return 0;
                        }
                        S.top = S.base;
                        S.stacksize = STACK_INIT_SIZE;
                        return 1;
                }

        int GetTop( SqStack S, T &e )
                {
                        if ( S.top == S.base )
                        {
                                return 0;
                        }
                        e = *( S.top -1 );
                        return 1;
                }

        int DestroyStack( SqStack &S )
                {
                        if ( !S.base )
                        {
                                free( S.base );
                                return 1;
                        }
                        return 0;
                }

        int ClearStack( SqStack &S )
                {
                        if ( !S.base )
                        {
                                S.top = S.base;
                                return 1;
                        }
                        return 0;
                }

        int StackEmpty( SqStack S )
                {
                        if ( S.top == S.base )
                        {
                                return 1;
                        }
                        return 0;
                }

        int StackLength( SqStack S)
                {
                        ;
                }

        int Push( SqStack &S, T e )
                {
                        if ( S.top - S.base > S.stacksize )
                        {
                                S.base = ( T* )realloc( S.base, ( S.stacksize + STACKINCREASEMENT ) * sizeof( T ));

                                if ( !S.base )
                                {
                                        return 0;
                                }
                                S.top = S.base + S.stacksize;
                                S.stacksize += STACKINCREASEMENT;
                        }
                        *S.top++ = e;
                        return 1;
                }

        int Pop( SqStack &S, T &e )
                {
                        if ( S.base == S.top )
                        {
                                return 0;
                        }
                        e = * --S.top;
                        return 1;
                }

        int StackTraverse( SqStack S, int( *visit )())
                {
                        ;
                }
};

#endif //_GS_FUNC_STACK_H
