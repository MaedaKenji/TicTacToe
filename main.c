#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int layout[3][3]={};
int win;
int x,y;
int xx,yy;
int i,j;
int sum=0;


int checkWin()
{
    // int ret;

    // Baris
    for (i=0;i<3;i++)
    {
        sum=0;
        for (j=0;j<3;j++)   sum += layout[i][j];
        if (sum==3) return 1;
        else if (sum== -3) return 2;
    }

   // Kolom
     for (i=0;i<3;i++)
    {
        sum=0;
        for (j=0;j<3;j++)   sum += layout[j][i];
        if (sum==3) return 1;
        else if (sum== -3) return 2;
    }

    // Diagonal kanan
    if (layout[0][0]+layout[1][1]+layout[2][2] == 3) return 1;
    else if (layout[0][0]+layout[1][1]+layout[2][2] == -3) return 2;

    //Diagonal Kiri
    if (layout[2][0]+layout[1][1]+layout[0][2] == 3) return 1;
    else if (layout[2][0]+layout[1][1]+layout[0][2] == -3) return 2;
return 0;
}

int checkDraw()
{
    int count=0;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if (layout[i][j] != 0) count++;
        }
    }
    if (count==9) return 1;
    else return 0;
}


void printD()
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (layout[i][j]==0) printf(".");
            else if (layout[i][j]==1) printf("x");
            else if (layout[i][j]==-1) printf("o");
        }
        printf("\n");
    }

    int CW= checkWin();
    if (CW==1) {  printf("Player 1 Win !!\n");}
    else if (CW==2) {  printf("Player 2 Win !!\n");}

}


void input()
{
    int cek=0;

    printf("Player 1 your move: "); scanf("%d %d",&x,&y);
    if (layout[x-1][y-1]==0) {layout[x-1][y-1]=1;}
    else
        while (cek!=1)
    {
        printf("Tidak bisa !!\n");
        printf("Player 1 your move: \n");
        scanf("%d %d",&x,&y);
        if (layout[x-1][y-1]==0) {  layout[x-1][y-1]=1; cek=1;}
    }

    int CW= checkWin();
    if (CW==1 || CW ==2 ) return;
    int CD= checkDraw();
    if (CD==1) {    printf("Draw\n"); return;}
}


void computer()
{   if (layout[1][1]==0) {  layout[1][1]=-1;    return;}






    for (int i=0;i<3;i++)
        {   for (int j=0;j<3;j++)
            {   if (layout[i][j]==0)
                    {   layout[i][j]=-1;
                        return;
                    }

            }

        }

}


int main()
{
    int CD;

    printf("Hello Player!\n");
    printD();
    printf("\n");
    while (win!=1 || win != 2)
    {
        input();
        win=checkWin();
        CD=checkDraw();
        printD();
        if (win==1 || win == 2) break;
        if (CD==1) break;
        printf("\nComputer Move\n");

        computer();
        win=checkWin();
        CD=checkDraw();
        printD();
        if (win==1 || win== 2) break;
        if (CD==1) break;
        printf("\n\n");

    }
return 0;
}
