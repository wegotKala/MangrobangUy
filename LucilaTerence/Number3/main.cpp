#include <iostream>
#include <stdio.h>
#include <math.h>
int isPrime(int n){
int i;
if (n%2==0)
return 0;
for (i=3;i<n/2;i+=2)
if (n%i==0)
return 0;
return 1;
}
int main(){
double n = 600851475143.0;
int i = 1;
while (i<50000){
if (isPrime(i))
if (fmod(n,(double)i)==0)
printf("%d\n",i);
i++;
}
return 0;
}
