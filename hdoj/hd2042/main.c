#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a,j,s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {s=3;
        scanf("%d",&a);
        for(j=0;j<a;j++)
            s=(s-1)*2;
        printf("%d\n",s);
    }
    return 0;
}
