//------pattern matching-------//

#include <stdio.h>

void main()
{
    char s[100],p[100],r[100],ans[100];
    printf("\nEnter the MAIN string: \n");
    gets(s);
    printf("\nEnter a PATTERN string: \n");
    gets(p);
    printf("\nEnter a REPLACE string: \n");
    gets(r);
    
    int i,j,k,l,c,f=0;
    i=j=l=c=0;
    
    while(s[c]!='\0')
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
            if(p[j]=='\0')
            {
                for(k=0;r[k]!='\0';k++,l++)
                {
                    ans[l]=r[k];
                    f=1;
                }
                c=i;
                j=0;
            }
        }
        else
        {
            ans[l]=s[c];
            c++;
            l++;
            i=c;
            j=0;
        }
    }
    if(f==0)
        printf("\npattern not found...!!!");
    else
    {
       ans[l]='\0';
       printf("\npattern founded...!!\n");
       printf("\nNEW pattern:\n\t%s",ans);
    }
}