#include <iostream>
#include <cstdlib>
using namespace std;

// ANSI Escape Codes for Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"
#define CLEAR   "\033[H\033[J"

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row,column; 
bool draw = false;
void clearScreen() 
{
    cout <<CLEAR;  // ANSI escape codes to clear screen
}
void display_board()
{
    clearScreen();
    cout << "\n\t\t\t" << BOLD << "      🎮 QUANTUM TIC-TAC-TOE 🎮" << RESET << endl;
    cout << "\t\t\t---------------------------------\n";
    cout << "\t\t\t     Player 1 [" << RED << "X" << RESET << "]  vs  Player 2 [" << BLUE << "O" << RESET << "]" << endl;
    cout << "\t\t\t---------------------------------\n\n";
    
    cout << "\t\t\t\t     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "\t\t\t\t  ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') cout << RED << board[i][j] << RESET;
            else if (board[i][j] == 'O') cout << BLUE << board[i][j] << RESET;
            else cout << board[i][j];

            if (j < 2) cout << "  |  ";
        }
        cout << "\n";
        if (i < 2) cout << "\t\t\t\t ____|_____|_____\n";
        else cout << "\t\t\t\t     |     |     \n";
    }
}

void player_turn()
{
    int choice;
    
    if(turn == 'X')
    {
        cout<<"\t\t\t\tPlayer1 [X] turn:";
    }
    
    if(turn == 'O')
    {
        cout<<"\t\t\t\tPlayer2 [O] turn:";
    }
    cin>>choice;
    
    switch(choice)
    {
        case 1:
        row=0; column=0;
        break;
        
        case 2:
        row=0; column=1;
        break;
        
        case 3:
        row=0; column=2;
        break;
        
        case 4:
        row=1; column=0;
        break;
        
        case 5:
        row=1; column=1;
        break;
        
        case 6:
        row=1; column=2;
        break;
        
        case 7:
        row=2; column=0;
        break;
        
        case 8:
        row=2; column=1;
        break;
        
        case 9:
        row=2; column=2;
        break;
        
        default:
        cout<<"Invalid Choice\n";
        break;
    }
    
    if(turn == 'X' && board[row][column]!='X' && board[row][column]!='O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    
    else if(turn == 'O' && board[row][column]!='X' && board[row][column]!='O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "\n\t\t\t⚠️ That spot is already taken! Try again.\n";
        player_turn();
    }
    display_board();
}
bool game_over()
{
    //check weather player 1 win or 2 win 
    for(int i=0;i<3;i++)
    {
        //row or column is filled with either X or O so one player will win 
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            return false;
        }
        
        //digonally can also one player could win the game 
        if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
        {
            return false;
        }
        
    }
    
    //continue playing if there is any box in which number is present and not showing nay winning condition
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    
    //Game Draw we have consider that there is no draw fistly but when upper both condition didn't worked then we do draw true
    draw = true;
    return false;
}
int main()
{
    while(game_over()) //if it is false then give either winning condition or over the game but when it is true then it will continue to play  
    {
        display_board();
        player_turn();
        game_over();
    }
    
    if (!draw) {
        if (turn == 'X')
            cout << "\n\t\t\t🎉 " << BLUE << "Player 2 [O] Wins! 🎉" << RESET << "\n";
        else
            cout << "\n\t\t\t🎉 " << RED << "Player 1 [X] Wins! 🎉" << RESET << "\n";
    } else {
        cout << "\n\t\t\t🤝 It's a Draw! Well Played! 🤝\n";
    }
    return 0;
}