#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000005];

void pre_next(int *next,char *str,int m)
{
    int k=-1;
    next[0]=-1;
    for(int i=1; i<m; i++)
    {
        while(k>-1&&str[k+1]!=str[i])
            k=next[k];
        if(str[k+1]==str[i])
            k++;
        next[i]=k;
    }
}
int main()
{

    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {


            if(str[0]=='#')
                break;
            int m=0;
            char str1[100005]= {0};
            scanf("%s %s",str1,str);
            m=strlen(str1);
            int next[100005]= {0},j,k=-1,count=0;
            pre_next(next,str1,m);
            for(j=0; j<strlen(str); j++)
            {
                while(k>-1&&str1[k+1]!=str[j])
                    k=next[k];
                if(str1[k+1]==str[j])
                    k++;
                if(k==m-1)
                {
                    j=j-m+1;
                    count++;
                    k=-1;
                }
            }
            printf("%d\n",count);
            memset(str,0,sizeof(str));
        }
    }
    return 0;
}
