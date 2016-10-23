#include "GS_Func_Stack.h"
#include "sample.h"

void StackSample::conversion()
{
        SqStack S;
        int N = 0;
        int e = 0;
        GSStackFunc stackFunc;
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
}//conversion
