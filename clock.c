#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
    int h,m,s;
    printf("Enter Hours,Minutes and Second\n");
    scanf("%d%d%d",&h,&m,&s);
    if(h>24 || m>60 || s>60)
    {
        printf("Error Data\n");
        exit(0);
    }
    while(1)
    {
        s++;
        if(s==60)
        {
            m++;
            s=0;
        }
        if(m==60)
        {
            h++;
            m=0;
        }
        if(h==24)
        {
            h=0;
            m=0;
            s=0;
        }
        printf("\n\t\t\t\t\tTime:%02d:%02d:%02d",h,m,s);
        sleep(1);
        system("cls");
    }
}