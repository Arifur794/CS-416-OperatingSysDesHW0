#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

static inline long long unsigned time_ns(struct timespec* const ts) {
  if (clock_gettime(CLOCK_REALTIME, ts)) {
    exit(1);
  }
  return ((long long unsigned) ts->tv_sec) * 1000000000LLU
    + (long long unsigned) ts->tv_nsec;
}

int main(void) {
  const int iterations = 10000000;
  struct timespec ts;
  const long long unsigned start_ns = time_ns(&ts);
  for (int i = 0; i < iterations; i++) {
    if (syscall(SYS_gettid) <= 1) {
      exit(2);
    }
  }
  const long long unsigned delta = time_ns(&ts) - start_ns;
  printf("%i system calls in %lluns (%.1fns/syscall)\n",
         iterations, delta, (delta / (float) iterations));
  return 0;
}




#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

static int count;

void handle_signal(int signum)
{
         if (count <10000)
         {
            count++;
            printf(1, "count = %d", count);
            __asm__("mov  0x4(%ebp), %eax");
            __asm__("mov  %eax, 0x8(%ebp)");
            __asm__("mov  0x0(%ebp), %eax");
            //__asm__("mov  %eax, 0x4(%ebp)");
            __asm__("addl $0x4, %ebp");

         }
         else
         {
             __asm__("addl $0x8, 0x4(%ebp)");
         }
}

int main(int argc, char *argv[])
{

        int x = 5;
        int y = 0;
        uint tick1 = 0;
        uint tick2 = 0;
        uint tickr = 0;
        uint rtime = 0;

        //tick1 = uptime();

	signal(SIGFPE, handle_signal);
 
        tick1 = uptime();

        x= x/y;	

        tick2 = uptime();

        tickr = (tick2 - tick1);
       
        rtime = ((tick2 - tick1)*10000)/count;                
    
	printf(1, "Traps Performed = %d\n", count);
	printf(1, "Total Elapsed Time: %d\n", tickr*10000);
	printf(1, "Average Time Per Trap: %d us\n", rtime);

	exit();
}