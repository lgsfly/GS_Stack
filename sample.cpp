#include "GS_Func_Stack.h"
#include "sample.h"

void StackSample::Conversion()
{
        GSStackFunc<int> stackFunc;
        GSStackFunc<int>::SqStack S;
        int N = 0;
        int e = 0;
        stackFunc.InitStack(S);
        printf( "Please Enter A NUM: " );
        scanf( "%d", &N);//Attention: %d without /n
        while( N )
        {
                if( ! stackFunc.Push( S, N%8 ))
                {
                        printf( "Push Wrong!" );
                }
                N = N/8;
        }
        printf( "10 to 8 result: ");
        while( !stackFunc.StackEmpty( S ))
        {
                if( ! stackFunc.Pop( S, e ))
                {
                        printf( "Pop Wrong!" );
                }
                printf( "%d", e );
        }
        printf( "\n" );
        stackFunc.DestroyStack( S );
}//conversion

void StackSample::LineEdit()
{
        GSStackFunc<char> stackFunc;
        GSStackFunc<char>::SqStack S;
        char c;
        stackFunc.InitStack( S );
        char ch = getchar();
        while ( ch != EOF )
        {
                while ( ch != EOF && ch != '\n' )
                {
                        switch( ch )
                        {
                        case '#':
                                stackFunc.Pop( S, c );
                                break;
                        case '@':
                                stackFunc.ClearStack( S );
                                break;
                        default:
                                stackFunc.Push( S, ch );
                                break;
                        }
                        ch = getchar();
                }

                while ( stackFunc.Pop( S, c ))
                {
                      printf( "%c", c);
                }

                //printf( "%s", S.base );
                stackFunc.ClearStack( S );
                if ( ch != EOF )
                {
                       ch = getchar();
                }
        }
        stackFunc.DestroyStack( S );
}
