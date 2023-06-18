#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int player = 1;
int cpu = 2;


void displayBoard(){

    cout << "+---+---+---+\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " " << " | " << board[0][2] << endl;
    cout << "------------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " " << " | " << board[1][2] << endl;
    cout << "------------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " " << " | " << board[2][2] << endl;
    cout << "+---+---+---+";

}

void clear_board (){

    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){

            board[i][j] = ' ';
        }
    }

}

bool playerMarker (int entry, char marker)
{

    int row = entry / 3;
    int col;

    if (entry % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }

    else
    {
        col = (entry % 3) - 1;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O'){

        board[row][col] = marker;
        return true;
    }

    else{

        return false;
    }
}

char checkWin()
{
    for (int i = 0; i < 3; i++){

        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                if(board[i][0] == 'X'){

                    return player;
                }

                if(board[i][0] == 'O'){

                    return cpu;
                }
            }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){

                if(board[0][i] == 'X'){

                    return player;
                }

                if(board[0][i] == 'O'){

                    return cpu;
                }
            }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){

        if(board[0][0] == 'X'){

            return player;
        }

        if(board[0][0] == 'O'){

            return cpu;
        }
    }

        if (board[0][2] == board[1][1] && board[0][2] == board[2][1]){

            if(board[0][2] == 'X'){

                return player;
            }

            if(board[0][2] == 'O'){

                return cpu;
            }
        }

    return 0;

}

void gameSettings(){

    cout << "\t\t Welcome to Tic-Tac-Toe!" << endl;
    cout << "\n\t\t You are X and will go first" << endl;
    cout << "\n\t\tMake a play by typing which square you want to enter your X" << endl;

    displayBoard();

    int winner = 0;
    int totalgames = 1;

    cout << "\nHow many games would you like to play? Type an integer 1-10 and hit [Enter] " << endl;
    cin >> totalgames;

    for (int i = 0; i < totalgames; i++){

        for (int i = 0; i < 9; i++){

            int place;

            cout << "\nPlayer's turn. Enter marker place: ";
            cin >> place;

            if (place < 1 || place > 9){

                cout << "Place invalid , try again" << endl;
                i--;
                continue;
            }

            if (!playerMarker(place, 'X')){

                cout << "Place occupied , try again" << endl;
                i--;
                continue;
            }

            displayBoard();

            winner = checkWin();

            if (winner == 1){

                cout << "Player won" << endl;
                clear_board();
                break;
            }

            if (winner == 2){

                cout << "CPU won" << endl;
                clear_board();
                break;
            }

            cout << "\nCPU's turn. CPU: \n";

            int cpuTurn = (rand() % 9) + 1;

            while(!playerMarker(cpuTurn, 'O')){

                cpuTurn = (rand() % 9) + 1;
            }

            displayBoard();

            winner = checkWin();

            if (winner == 1){

                cout << "Player won" << endl;
                clear_board();
                break;
            }

            if (winner == 2){

                cout << "CPU won" << endl;

                clear_board();
                break;
            }

        }

        if (winner == 0){

            cout << "DRAW" << endl;

            clear_board();
            break;
        }

    }

}

int main()
{
    gameSettings();
}
