#include <stdio.h>
int main(){
int i,j,y,sum1,sum2;
int sum=0;
for (i=1;i<101;i++)
sum1+=i*i;
y=0;
for (j=1;j<101;j++){
y=y+j;
}
sum2=y*y;

printf("Answer: %d\n",sum2-sum);
return 0;
}
