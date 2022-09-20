#include<stdio.h>
#include<conio.h>
int main()
{
    char ch;
    printf("Enter any key to start");
    scanf(" %c",&ch);
    system("cls");
    int n,row,col,space;
    printf("Enter the row number");
    scanf("%d",&n);
    for(row=1;row<=n;row++){
        for(col=1;col<=n;col++){
            if(row==1||col==1||row==n||col==n||row==col||(row+col)==(n+1)){
                printf("*");
            }
            else
            printf(" ");
        }
        printf("\n");
    }
    int a;
    printf("Press any key to exit");
    scanf("%d",&a);
return 0;
}