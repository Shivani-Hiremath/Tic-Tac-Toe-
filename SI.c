#include <stdio.h>

// Function to print the Tic-Tac-Toe board
void print_board(char board[3][3])
{
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Function to check if a player has won
int check_win(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Row win

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Column win
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Diagonal win
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Diagonal win
    return 0; // No win
}

// Function to check if the board is full (draw)
int is_board_full(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0; // Board is not full
        }
    }
    return 1; // Board is full (draw)
}

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    char current_player = 'X';

    printf("Tic-Tac-Toe Game\n");
    printf("Player X starts the game!\n");

    do
    {
        // Display the current board
        print_board(board);

        // Get player move
        printf("Player %c, enter your move (row and column): ", current_player);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = current_player;

        // Check for a win
        if (check_win(board, current_player))
        {
            print_board(board);
            printf("Player %c wins!\n", current_player);
            break;
        }

        // Check for a draw
        if (is_board_full(board))
        {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch to the other player
        current_player = (current_player == 'X') ? 'O' : 'X';

    } while (1); // Infinite loop, the game ends with a break statement

    return 0;
}
