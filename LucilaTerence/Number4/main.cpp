#include <stdio.h>
#include <math.h>
int isPali(n)n{
int copy = n;
int complement = 0;
while (copy>0){
complement = complement * 10 + copy % 10;
copy/=10;
}
if (complement==n)
return 1;
return 0;
}
int main(){
int i,j,ans,x;
ans=0;
for (i=1;i<1000;i++){
for (j=1;j<1000;j++){
x=i*j;
if (isPali(x)&&x>ans)
ans=x;
}
}
printf("%d\n",ans);
return 0;
}
