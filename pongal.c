#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>
int main()
{ 
    //To print vertically
    char str[]="HAPPY PONGAL";
    int i,len,j;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        printf("%c",str[i]);
        usleep(1000000);
    }
    printf("\n");
    // To print horizontally
    for(i=0;i<len;i++)
    {
        int clrscr();
        for(j=0;j<=i+1;j++)
        {
            printf("%c\n",str[j]);
            usleep(1000000);
        }
    }
    return 0;
}
