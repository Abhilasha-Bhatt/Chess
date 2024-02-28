#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define size 8

char board[size][size];

void initialize()
{

    board[0][0]=board[0][7]='r';
    board[0][1]=board[0][6]='n';
    board[0][2]=board[0][5]='b';
    board[0][3]='q';
    board[0][4]='k';
    for(int i=0;i<size;board[1][i++]='p');

    board[7][0]=board[7][7]='R';
    board[7][1]=board[7][6]='N';
    board[7][2]=board[7][5]='B';
    board[7][3]='Q';
    board[7][4]='K';
    for(int i=0;i<size;board[6][i++]='P');

    for(int i=2;i<6;i++)
    for(int j=0;j<size;board[i][j++]=' ');

}

void display()
{
    printf("    a    b   c   d   e   f   g   h\n");
    printf(" +---------------------------------+\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d |", 8 - i);
        for (int j = 0; j < size;j++) 
        printf(" %c |", board[i][j]);
        printf("\n +---------------------------------+\n");
    }
}

int validMove(char* move,int* col,int* row)
{
    if(move[0]>='a'&&move[0]<='h'&&move[1]>='1'&&move[1]<='8')
    {
        *col= move[0]-'a';
        *row=8-(move[1] - '0');
        return 1;
    }
    return 0;
}
/**bool parse_move(char* move, int* row, int* col) {
    if (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8') {
        *row = 8 - (move[1] - '0');
        *col = move[0] - 'a';
        return true;
    }
    return false;
}*/

int moveCheck(int fromR,int fromC,int toC,int toR,char player)
{
    if((board[fromR][fromC]==' ')||(player=='w'&&islower(board[fromR][fromC]))||(player=='b'&&isupper(board[fromR][fromC])))
    return 0;
/**bool is_valid_move(int from_row, int from_col, int to_row, int to_col, char player) {
    // Check if the starting position contains the player's piece
    if (board[from_row][from_col] == ' ') {
        return false;
    }
    if ((player == 'w' && islower(board[from_row][from_col])) || (player == 'b' && isupper(board[from_row][from_col]))) {
        return false;
    }
    // TODO: Implement rules for valid moves (for simplicity, allow any move for now)
    return true;
}
*/
    if(board[fromR][fromC]=='r'||board[fromR][fromC]=='R')//rook
    {
        if((fromR==toR||fromC==toC))
        return 1;
    }

    if(board[fromR][fromC]=='n'||board[fromR][fromC]=='N')//knight
    {
        if((abs(fromR-toR)==1||abs(fromR-toR)==2)&&(abs(fromC-toC)==1||abs(fromC-toC)==2))
        return 1;
    }

    if(board[fromR][fromC]=='b'||board[fromR][fromC]=='B')//bishop
    {
        if(fromR!=toR&&fromC!=toC&&((abs)(fromR-toR)==(abs)(fromC-toC))) 
        return 1;
    }

    if(board[fromR][fromC]=='p'||board[fromR][fromC]=='P')//pawn
    {
        if((abs(fromR-toR)==1||abs(fromR-toR)==2)||(abs(fromR-toR)==1||abs(fromR-toR)==2))
        return 1;
    }

    if(board[fromR][fromC]=='k'||board[fromR][fromC]=='K')//king
    {
        if((abs)(fromR-toR)==1||(abs(fromC-toC)==1))
        return 1;
    }

    if(board[fromR][fromC]=='q'||board[fromR][fromC]=='Q')//queen
    {
        if(((fromR==toR||fromC==toC))||((abs(fromR-toR)==1||abs(fromR-toR)==2)&&(abs(fromC-toC)==1||abs(fromC-toC)==2))||(fromR!=toR&&fromC!=toC&&((abs)(fromR-toR)==(abs)(fromC-toC)))||((abs(fromR-toR)==1||abs(fromR-toR)==2)||(abs(fromR-toR)==1||abs(fromR-toR)==2))||((abs)(fromR-toR)==1||(abs(fromC-toC)==1)))
        return 1;
    }
    return 0;
}
void makemove(int fromR,int toR,int fromC,int toC)
{
    board[toR][toC]=board[fromR][fromC];
    board[fromR][fromC]=' ';
}
int main()
{

    initialize();
    char player='w';
    while(1)
    {
        display();
        printf("Player %c 's turn",player);
        printf("Enter Your Move (eg: a2a5)");
        char move[4];
        scanf("%s",move);

        int fromR,fromC,toR,toC;
        if(!validMove(move,&fromC,&fromR)||!validMove(move+2,&toC,&toR))
        {
            printf("\nINVALID FORMAT\n");
            continue;
        }

        if(!moveCheck(fromR,fromC,toC,toR,player))
        {
            printf("\nINVALID MOVE!\n");
            continue;
        }

        makemove(fromR,toR,fromC,toC);
        player = (player == 'w') ? 'b' : 'w';

    }
    return 0;
}