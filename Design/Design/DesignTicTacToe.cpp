#include "DesignTicTacToe.h"

DesignTicTacToe::DesignTicTacToe()
{
	file.open("DesignTicTacToe.txt");
}
class TicTacToe {
	int size;
	vector<vector<int>> board;
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		size = n+1;
		board = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
	}

	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		row++; col++;
		int val = player == 1 ? 1 : -1;
		if (player == 1) {
			board[row][col] = 1;
		}
		else {
			board[row][col] = -1;
		}

		board[row][size] += val;
		board[size][col] += val;
		if (row == col)
			board[size][size] += val;
		if(row + col == size)
			board[0][size] += val;
		return whoWins(row, col);
	}

	int whoWins(int row, int col)
	{
		int val = 0;
		if (board[row][size] && board[row][size] % (size-1) == 0)
			val = board[row][size];
		else if (board[size][col] && board[size][col] % (size - 1) == 0)
			val = board[size][col];
		else if (board[size][size] && board[size][size] % (size - 1) == 0)
			val = board[size][size];
		else if (board[0][size] && board[0][size] % (size - 1) == 0)
			val = board[0][size];
		
		if (val < 0) return 2;
		if (val > 0) return 1;
		return val;
	}
};

void DesignTicTacToe::solve()
{
	fillInput();
	TicTacToe obj(size);
	int j = 1;
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "move") {
			cout << obj.move(qData[i-1][0],qData[i-1][1],qData[i-1][2]);
		}
	}
	return;
}

void DesignTicTacToe::fillInput()
{
	getStrings(queries);
	size = getInt();
	get2Darray(qData);
}
