#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
int main_count;
    int smalli;
    int smallj;
    int small1=8;
    char cfo[10];
    int tsmalli;
    int tsmallj;
    int n;
    int moves[20][20]={};//declaration of the move matrix
    int puzz[20][20]={};//declaration of puzzle moves in a matrix
    int n_square;

void taking_side(void)
{cout<<"\n *************WELCOME TO THE KNIGHT PUZZLE**********\n";
cout<<"\n ENTER THE VALUE OF SIDE OF THE SQUARE TO PLAY THE KNIGHT PUZZLE\n";
cin>>n;
};
void graphical_grid(void)
{initwindow(1000,1000, "KNIGHT PUZZLE");
    
    rectangle(100,100,100+n*50,100+n*50);
    for (int i=0;i<n;i++)
    {line(100+i*50,100,100+i*50,100+n*50);
    line(100,100+i*50,100+n*50,100+i*50);
        }
        };
void starting_coordinates(void)
{cout<<"Enter the cordinates of the starting position 0<=x<n :\n";
    cin>>smalli;
    cout<<"and 0<=y<n :\n";
    cin>>smallj;
    };
void calc_avail_moves(void)
{for(int i=0; i<n;i++)
    for(int j=0;j<n;j++)
    {if((i-2)>=0&&(j-1)>=0)
    moves[i][j]++;
    else;
    if((i-2)>=0&&(j+1)<n)
    moves[i][j]++;
    else;
    if((i+2)<n&&(j-1)>=0)
    moves[i][j]++;
    else;
    if((i+2)<n&&(j+1)<n)
    moves[i][j]++;
    else;
    if((i-1)>=0&&(j-2)>=0)
    moves[i][j]++;
    else;
    if((i+1)<n&&(j-2)>=0)
    moves[i][j]++;
    else;
    if((i-1)>=0&&(j+2)<n)
    moves[i][j]++;
    else;
    if((i+1)<n&&(j+2)<n)
    moves[i][j]++;
    else;
    }    
    };
void printing_move_matrix(void)
    {for(int i=0; i<n;i++)
{for(int j=0;j<n;j++)
cout<<moves[i][j]<<" ";
cout<<"\n";
}
};
void choose_lowest_moves(int a,int b)
{if(a>=0&&b>=0&&a<n&&b<n&&moves[a][b]!=0)
{if(small1>moves[a][b]&&moves[a][b]>0)
{small1=moves[a][b];
tsmalli=a;
tsmallj=b;
}
else;
}
else;
}


void add_num(void)
{for(main_count=0;main_count<n_square-1;main_count++)
{

cout<<"\nthe lowest aquired position i="<<smalli<<" j="<<smallj<<"\n";
puzz[smalli][smallj]=(main_count+1);
//aquiring a position and updating possible moves
moves[smalli][smallj]=0;

if((smalli-2)>=0&&(smallj-1)>=0&&moves[smalli-2][smallj-1]!=0)
moves[smalli-2][smallj-1]--;
else;
if((smalli+2)<n&&(smallj-1)>=0&&moves[smalli+2][smallj-1]!=0)
moves[smalli+2][smallj-1]--;
else;
if((smalli+2)<n&&(smallj+1)<n&&moves[smalli+2][smallj+1]!=0)
moves[smalli+2][smallj+1]--;
else;
if((smalli-2)>=0&&(smallj+1)<n&&moves[smalli-2][smallj+1]!=0)
moves[smalli-2][smallj+1]--;
else;
if((smalli-1)>=0&&(smallj-2)>=0&&moves[smalli-1][smallj-2]!=0)
moves[smalli-1][smallj-2]--;
else;
if((smalli+1)<n&&(smallj-2)>=0&&moves[smalli+1][smallj-2]!=0)
moves[smalli+1][smallj-2]--;
else;
if((smalli+1)<n&&(smallj+2)<n&&moves[smalli+1][smallj+2]!=0)
moves[smalli+1][smallj+2]--;
else;
if((smalli-1)>=0&&(smallj+2)<n&&moves[smalli-1][smallj+2]!=0)
moves[smalli-1][smallj+2]--;
else;

cout<<"\n the "<<main_count+1<<" matrix after the operation is \n";
for(int i=0; i<n;i++)
{for(int j=0;j<n;j++)
cout<<moves[i][j]<<" ";
cout<<"\n";
}
cout<<"\n the puzzle matrix is :\n";
for(int i=0; i<n;i++)
{for(int j=0;j<n;j++)
if(puzz[i][j]==0)
cout<<"_\t";
else
{cout<<puzz[i][j]<<"\t";
itoa (puzz[i][j],cfo,10);
outtextxy(120+i*50,120+j*50,cfo);
}
cout<<"\n\n\n";
}
//choosing the lowest moves possible place/block amoung the possible positions

small1=8;
choose_lowest_moves(smalli-2,smallj-1);
choose_lowest_moves(smalli+2,smallj-1);
choose_lowest_moves(smalli+2,smallj+1);
choose_lowest_moves(smalli-2,smallj+1);
choose_lowest_moves(smalli-1,smallj-2);
choose_lowest_moves(smalli+1,smallj-2);
choose_lowest_moves(smalli+1,smallj+2);
choose_lowest_moves(smalli-1,smallj+2);
smalli=tsmalli;
smallj=tsmallj;
//playing the knight
getch();
system("CLS");
}
};
int main()
{
taking_side();
graphical_grid();
starting_coordinates();
//calculation of available or possible moves.
calc_avail_moves();
printing_move_matrix();
n_square=n*n;
// for adding the numbers to the puzzle matrix
add_num();
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{if(puzz[i][j]==0)
puzz[i][j]=main_count+1;
}

cout<<"\n the puzzle matrix is :\n";
for(int i=0; i<n;i++)
{for(int j=0;j<n;j++)
if(puzz[i][j]==0)
cout<<"_\t";
else
{cout<<puzz[i][j]<<"\t";
itoa (puzz[i][j],cfo,10);
outtextxy(120+i*50,120+j*50,cfo);
}
cout<<"\n\n\n";
}



getch();
return 0;
}
