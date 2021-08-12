#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
struct timeval tv1, tv2;

struct matPowInput
{
	long mat[2][2];
	int n;	
	int number;
};

void multiply(long mat1[][2], long mat2[][2])
{
   long mat3[2][2];
   mat3[0][1]=(mat1[0][0]*mat2[0][1])+(mat1[0][1]*mat2[1][1]);
   mat3[0][0]=(mat1[0][0]*mat2[0][0])+(mat1[0][1]*mat2[1][0]);
   mat3[1][0]=(mat1[1][0]*mat2[0][0])+(mat1[1][1]*mat2[1][0]);
   mat3[1][1]=(mat1[1][0]*mat2[0][1])+(mat1[1][1]*mat2[1][1]);
   mat1[0][0]=mat3[0][0];
   mat1[0][1]=mat3[0][1];
   mat1[1][0]=mat3[1][0];
   mat1[1][1]=mat3[1][1];
}

void *matPow(void *ptr)
{
	struct matPowInput *input=(struct matPowInput*)ptr;
	long mat2[2][2]={1,1,1,0};
	int result[2][2];
	for (int i = 0; i <input->n; ++i)
	{
		usleep(1e5);
		printf("%d thread number\n ",input->number);
		multiply(input->mat,mat2);
	}
}
int main()
{
    int n;  // terms
    scanf("%d",&n);
    if (n==1)
    {
    	printf("%d",1);
    		return 1;
    }
    int thread_count;
    scanf("%d",&thread_count);
    gettimeofday(&tv1, NULL);
    if (thread_count>n)
    {
    	printf("threads should be < fibonaci terms \n");
    	return 0;
    }
    n-=(thread_count-1);
    struct matPowInput inputs[thread_count];
    pthread_t threads[thread_count];
    int calc_per_thread=n/thread_count;
    for (int i = 0; i < thread_count; ++i)
    {
    inputs[i].n=calc_per_thread;
    if (i==thread_count-1)
    {
    	inputs[i].n+=(n%thread_count);
    }
    inputs[i].number=i;
    inputs[i].mat[0][0]=1;
    inputs[i].mat[0][1]=1;
    inputs[i].mat[1][0]=1;
    inputs[i].mat[1][1]=0;
    pthread_create( &threads[i], NULL, matPow, &inputs[i]);
    }
    
    for (int i = 0; i < thread_count; ++i)
    {
    pthread_join( threads[i], NULL);
    }

    for (int i = 1; i < thread_count; ++i)
    {
    	multiply(inputs[0].mat,inputs[i].mat);
    }
    gettimeofday(&tv2, NULL);
    printf("\n\n %fsec\n\n", (double)(tv2.tv_usec - tv1.tv_usec)/1e6 + (double) (tv2.tv_sec - tv1.tv_sec) );

    printf("%ld\n",inputs[0].mat[1][1]);
	return 0;
}