//getpid()

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void mylistfiles();

int main(){
    pid_t mypid;
    pid_t myotherpid;
    char mycommand[100];
   
    int i = 10;
    mypid = getpid();
   
   
    fork();
    printf("\nMy pid is %i", mypid);
    
    myotherpid = getpid();
     printf("\nMy new pid is %i", myotherpid);
    printf("\n Hit enter to exit from parent");
    scanf("%s", mycommand);
    return 0;   
    //pid_t myforkresult = fork();
    //if(myforkresult = 0){  //testing who you are
        //printf("\nmy CHILD says fork results is is %i", myforkresult);
       // printf("\nmy CHILD knows the parent's pid is %i", mypid);
        //mypid = getpid();
        //printf("\nmy CHILD asked for his own pid and %i", mypid);

    }

void mylistfiles(){
    printf("\nYou asked to list files");;
    fprintf(stderr, "I am a child");
    execlp("/bin/ls","ls","-cl", NULL);
}