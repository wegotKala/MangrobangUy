#include <iostream>
#include <stdio.h>
int fib(int n){
int i;
int f1=1;
int f2=1;
if (n==0 || n==1)
return f1;
else{
for (i=1;i<n;i++){
f1=f1+f2;
f2=f1-f2;
}
return f1;
}
}
int main(){
int i,x;
int sum=0;
for (i=1;i<1000;i++){
x=fib(i);
if (x>4000000)
break;
if (x%2==0)
sum+=x;
}
printf("%d\n",sum);
return 0;
}
