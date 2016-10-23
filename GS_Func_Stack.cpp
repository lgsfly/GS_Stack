#include "GS_Func_Stack.h"

GSStackFunc::GSStackFunc()
{
        ;
}

GSStackFunc::~GSStackFunc()
{
        ;
}

int GSStackFunc::InitStack( SqStack &S )
{
        S.base = ( SElemType *)malloc( STACK_INIT_SIZE * sizeof( SElemType ));
        if ( !S.base )
        {
                return 0;
        }
        S.top = S.base;
        S.stacksize = STACK_INIT_SIZE;
        return 1;
}

int GSStackFunc::GetTop( SqStack S, SElemType &e )
{
        if ( S.top == S.base )
        {
                return 0;
        }
        e = *( S.top -1 );
        return 1;
}

int GSStackFunc::DestroyStack( SqStack &S )
{
        ;
}

int GSStackFunc::ClearStack( SqStack &S )
{
        ;
}

int GSStackFunc::StackEmpty( SqStack S )
{
        if ( S.top == S.base )
        {
                return 1;
        }
        return 0;

}

int GSStackFunc::StackLength( SqStack S)
{
        ;
}

int GSStackFunc::Push( SqStack &S, SElemType e )
{
        if ( S.top - S.base > S.stacksize )
        {
                S.base = ( SElemType* )realloc( S.base, ( S.stacksize + STACKINCREASEMENT ) * sizeof( SElemType ));

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

int GSStackFunc::Pop( SqStack &S, SElemType &e )
{
        if ( S.base == S.top )
        {
                return 0;
        }
        e = * --S.top;
        return 1;
}

int GSStackFunc::StackTraverse( SqStack S, int( *visit )())
{
        ;
}
