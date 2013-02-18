#include <iostream>
#include <stdio.h>
#include <math.h>
int isPrime(num){
int i;
if (num==2)
return 1;
for (i=2;i<sqrt(num)+1;i++){
if (num%i==0)
return 0;
}
return 1;
}
int main(){
int i;
double soma=0;
for (i=2;i<2000000;i++){
if (isPrime(i)==1)
soma=soma+i;
}
printf("%lf\n",soma);
return 0;
}
