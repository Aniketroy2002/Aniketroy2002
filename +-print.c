#include<stdio.h>
#include<conio.h>
int main()
{
    char ch;
    printf("Enter any key to start");
    scanf(" %c",&ch);
    system("cls");
    int n,row,col,space;
    printf("Enter the odd row number");
    scanf("%d",&n);
    if(n%2!=0){
    for(row=1;row<=n;row++){
        for(col=1;col<=n;col++){
            if(row==(n/2)+1 || col== (n/2)+1)
            printf(" ");
            else
            printf(" 0");
        }
        printf("\n");
    }
    }
    else 
    printf("Enter odd number like 3,5,7,9,11......\n");
    int a;
    printf("Press any key to exit");
    scanf("%d",&a);
return 0;
}