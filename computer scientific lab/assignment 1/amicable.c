#include <stdio.h>
int main() {
    int num1,num2;
    int i,sum1=0,sum2=0;
    printf("first number: ");
    scanf("%d", &num1);
    printf("\nsecond number: ");
    scanf("%d", &num2);
    
    
    printf("Factors of %d are: ",num1);
    for (i = 1; i < num1; ++i) {
        if (num1 % i == 0) {
            printf(" %d,",i);
            sum1+=i;
        }  
    }
    

    printf("\nFactors of %d are: ",num2);
    for (i = 1; i < num2; ++i) {
        if (num2 % i == 0) {
            printf(" %d,",i);
            sum2+=i;
        }  
    }
    
    printf("\nSum of factors of %d is %d\n",num1,sum1);
    printf("Sum of factors of %d is %d\n",num2,sum2);

    if (sum1==num2 && sum2==num1)
    {
        printf("Numbers are amicable numbers.");
    }
    else{
        printf("Numbers are not amicable numbers.");
    }
    
    return 0;
}
