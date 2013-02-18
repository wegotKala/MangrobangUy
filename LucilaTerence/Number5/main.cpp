#include <iostream>
#include <stdio.h>
int main(){
int i,j,counter;
for (i=10;i<1000000000;i++){
counter=0;
for (j=11;j<21;j++){
if (i%j==0)
counter++;
}
if (counter==10){
printf("%d\n",i);
break;
}
}
return 0;
}
