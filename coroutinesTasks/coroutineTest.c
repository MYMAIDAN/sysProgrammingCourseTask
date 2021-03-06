#include <stdio.h>
#include <setjmp.h>

jmp_buf bufferA;
jmp_buf bufferB;

void routineB();

void routineA()
{
  int status = 0;
  printf("(A1)\n");

  status = setjmp( bufferA );
  if( !status )
    routineB();

  printf("(A2)\n");

  status = setjmp( bufferA );
  if( !status )
    longjmp( bufferB, 1 );

  printf("(A3)\n");

  status = setjmp( bufferA );
  if( !status )
    longjmp( bufferB, 1 );

  printf("(A4)\n");
}

void routineB()
{
  int status = 0;

  printf("(B1)\n");

  status = setjmp( bufferB );
  if( !status )
    longjmp( bufferA, 1 );

  printf("(B2)\n");

  status = setjmp( bufferB );
  if( !status )
    longjmp( bufferA, 1 );

  printf("(B3)\n");

  status = setjmp( bufferB ); 
  if( !status )
    longjmp( bufferA, 1 );
}

int main()
{
  routineA();
  return 0;
}
