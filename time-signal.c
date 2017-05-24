#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

static sig_atomic_t caught = 33;
static sigjmp_buf env;

void action( int unused )
{
    caught = 42;
    siglongjmp( env, 1 );
}

int main( void )
{
    if ( signal( SIGFPE, action ) == SIG_ERR ) {
        perror( "signal failed" );
        return 1;
    }

    int x = 1;
    int y = 0;
    int z;
    if ( sigsetjmp( env, 1 ) == 0 )
        z = x / y;

    printf( "%d\n", caught );
}




   
   
   
   jmp_buf jumper;

   int SomeFunction(int a, int b)
   {
      if (b == 0) // can't divide by 0
         longjmp(jumper, -3);
      return a / b;
   }

   void main(void)
   {
      if (setjmp(jumper) == 0)
      {
         int Result = SomeFunction(7, 0);
         // continue working with Result
      }
      else
         printf("an error occured\n");
   }
