#include <stdio.h>

int main()
{
   float chocolate,childern,gift;
   scanf("%f %f %f",&chocolate,&childern,&gift);
   float x,check=0.9555,answer=0;
   x=(chocolate/childern);
   answer=(gift/x)+check;
   int final=answer;
   printf("%d is the winner",final);
    return 0;
}



