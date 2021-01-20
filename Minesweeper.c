#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
char fillbombs(char game1[][100],int count,int n)
{
    int i,j;
    srand(time(0));
    while(count>0)
    {
        i=rand()%n;
        j=rand()%n;
        game1[i][j]='*';
        count--;
    }

}
int validboundary(int i,int j,int n) 
{
    return(i>=0) && (i<n) && (j>=0) && (j<n);
} 
char filladjacent(char game1[][100],int n)
{
    int i,j,count=0,k,l;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(game1[i][j]=='-')
            {
                if((validboundary(i-1,j,n)==1)&&(game1[i-1][j]=='*'))
                {
                    count++; 
                }
                if((validboundary(i,j+1,n)==1)&&(game1[i][j+1]=='*'))
                {
                    count++;
                }
                if((validboundary(i+1,j,n)==1)&&(game1[i+1][j]=='*'))
                {
                    count++;
                }
                if((validboundary(i,j-1,n)==1)&&(game1[i][j-1]=='*'))
                {
                    count++;
                }
                if((validboundary(i-1,j-1,n)==1)&&(game1[i-1][j-1]=='*'))
                {
                    count++;
                }
                if((validboundary(i-1,j+1,n)==1)&&(game1[i-1][j+1]=='*'))
                {
                    count++;
                }
                if((validboundary(i+1,j-1,n)==1)&&(game1[i+1][j-1]=='*'))
                {
                    count++;
                }
                if((validboundary(i+1,j+1,n)==1)&&(game1[i+1][j+1]=='*'))
                {
                    count++;
                }
                if(count>0)
                {
                    game1[i][j]=count+'0';
                }
                else
                {
                    game1[i][j]=' ';
                }
                
            }
            count=0;
        }
    }
    return 0;
}
char playgame(char game[][100],char game1[][100],int n)
{
    int i,j,inp1,inp2,flag=1;
    char replay;
    while(flag!=0)
    {
    printf("Enter your moves:");
    scanf("%d %d",&inp1,&inp2);
    if(game1[inp1][inp2]=='*')
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(game1[i][j]=='*')
                {
                    game[i][j]='*';
                }
            }
        }
        flag=0;
        printf("You Lost!\n");
        return -1;
    }
    else if(game1[inp1][inp2]==' ')
    {
        game[inp1][inp2]=game1[inp1][inp2];
        if(validboundary(inp1-1,inp2,n)==1)
        {
            game[inp1-1][inp2]=game1[inp1-1][inp2];
        }
        if(validboundary(inp1,inp2+1,n)==1)
        {
            game[inp1][inp2+1]=game1[inp1][inp2+1];
        }
        if(validboundary(inp1+1,inp2,n)==1)
        {
            game[inp1+1][inp2]=game1[inp1+1][inp2];
        }
        if(validboundary(inp1,inp2-1,n)==1)
        {
            game[inp1][inp2-1]=game1[inp1][inp2-1];
        }
        if(validboundary(inp1-1,inp2-1,n)==1)
        {
            game[inp1-1][inp2-1]=game1[inp1-1][inp2-1];
        }
        if(validboundary(inp1-1,inp2+1,n)==1)
        {
            game[inp1-1][inp2+1]=game1[inp1-1][inp2+1];
        }
        if(validboundary(inp1+1,inp2-1,n)==1)
        {
            game[inp1+1][inp2-1]=game1[inp1+1][inp2-1];
        }
        if(validboundary(inp1+1,inp2+1,n)==1)
        {
            game[inp1+1][inp2+1]=game1[inp1+1][inp2+1];
        }
    }
    else
    {
        game[inp1][inp2]=game1[inp1][inp2];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c ",game[i][j]);
        }
        printf("\n");
    }
    }
    return 0;
}
int main()
{
    char game[100][100],game1[100][100];int i,j,k,difficulty,count,n,res,replay;
    printf("\t\t\t");
    for(i=0;i<35;i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\t\t\t\tWELCOME TO MINESWEEPER\n");
    printf("\t\t\t");
    for(i=0;i<35;i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\t\t\t\tLET'S START\n");
    printf("\t\t\t");
    for(i=0;i<35;i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\t\t\t");
    for(i=0;i<35;i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\t\t\t\tSelect the level\n");
    printf("\t\t\t");
    for(i=0;i<35;i++)
    {
        printf("*");
    }
    printf("\n");
    label:
    printf("\t\t\t\t1.Easy(9x9)\n\t\t\t\t2.Medium(16X16)\n\t\t\t\t3.Advanced(24*24)\n\t\t\t\tYour Choice:");
    scanf("%d",&difficulty);
    switch (difficulty)
    {
        case 1: count=10;n=9;break;
        case 2: count=40;n=16;break;
        case 3: count=99;n=24;break;
        default:printf("Enter your valid choice\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            game[i][j]=game1[i][j]='-';
        }
        printf("\n");
    }
    fillbombs(game1,count,n);
    filladjacent(game1,n);
    res=playgame(game,game1,n);
    if(res==-1)
    {
        printf("Press 1 to replay:\n");
        scanf("%d",&replay);
        if(replay==1)
        {
            goto label;
        }
    }
    printf("\n");
    return 0;
}
