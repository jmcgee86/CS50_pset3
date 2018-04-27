// PRC-MATT - Style50 and check50 both pass, (except for a couple of style edits that are from the distrubution code, not yours)
// One suggestion i would make is since we deal with a lot of iterating over the board using double for loops, instead of using
// i and j for your variable names, it may help if you use something more descriptive, like row and column. I think it would
// make it easier to follow along.
// Comments in each of the functions would really help too, especially in move where the code gets pretty long and is harder to
// follow along


/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int tile = (d * d) - 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = tile;
            tile--;
        }
    }
    if (d % 2 == 0)
    {
        board[ d - 1][ d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf("   -  ");
            }
            else
            {
                printf("  %2i  ", board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{

    int blank_row;
    int blank_col;
    int tile_row;
    int tile_col;

    if (tile < 0 || tile > (d * d - 1))
    {
        return false;
    }

    if (board[d - 1][d - 1] == 0)
    {
        blank_row = d - 1;
        blank_col = d - 1;
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] == 0)
                {
                    blank_row = i;
                    blank_col = j;
                    break;
                }

            }
        }
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (tile == board[i][j])
            {
                tile_row = i;
                tile_col = j;
                break;
            }

        }
    }
    if (tile_row == blank_row && (tile_col == (blank_col - 1) || tile_col == (blank_col + 1)))
    {
        board[tile_row][tile_col] = 0;
        board[blank_row][blank_col] = tile;
        blank_row = tile_row;
        blank_col = tile_col;
        return true;
    }
    else if (tile_col == blank_col && (tile_row == (blank_row - 1) || (tile_row == (blank_row + 1))))
    {
        board[tile_row][tile_col] = 0;
        board[blank_row][blank_col] = tile;
        blank_row = tile_row;
        blank_col = tile_col;
        return true;
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // TODO
    int check = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (check == board[i][j])
            {
                if (check < (d * d) - 1)
                {
                    check++;
                }
                else
                {
                    check = 0;
                }
            }
            else
            {
                return false;
            }

        }
    }
    return true;
}
