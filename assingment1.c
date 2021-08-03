#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h> 
/*
   This programme creates process tree with given varibale and 
   value of variables will be generate in output 
         P
      /     \
     c1      c2
    /  \     / \
 c11  c12 c21  c22

*/
int main()
{
    int p = getpid();
    int c1,c2,c11,c12,c21,c22;
    printf("parent p %d\n", p);
    int child_id=fork();
    if(child_id==0)   // fork return 0 in child and child id in parent
    {
        c2=getpid();
        printf("c2 %d\n", c2);
        int c2_child_id=fork();
        if(c2_child_id==0)   // fork return 0 in child and child id in parent
        {
            c22=getpid();
            printf("c22 %d\n", c22);
            printf("before deleting parent id of c22 is %d\n", c22);
            kill(c2,0);
            sleep(1);
            printf("after deleting parent id of c22 is %d\n", getppid());
        }
        else
        {
            c21=getpid();
            printf("c22 %d\n", c21);
            sleep(1);
            
        }
    }
    else
    {
        c1=getpid();
        printf("c1 %d\n", c1);
        int c1_child_id=fork();
        if(c1_child_id==0)   // fork return 0 in child and child id in parent
        {
            c12=getpid();
            printf("c12 %d\n", c12);
            printf("before deleting parent id of c12 is %d\n", c12);
            kill(c1,0);
            sleep(1);
            printf("after deleting parent id of c12 is %d\n", getppid());
        }
        else
        {
            c11=getpid();
            printf("c11 %d\n", c11);
        }
    }


    return 0;
}
