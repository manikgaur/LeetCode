#include "DesignSnakeGame.h"

DesignSnakeGame::DesignSnakeGame()
{
	file.open("DesignSnakeGame.txt");
}

class SnakeGame {
	int w;
	int h;
	vector<vector<int>> foodArray;
	vector<vector<bool>> grid;
	list < pair<int, int>> snakeBody;
	int posR;
	int posC;
	int cfpos;
	int score;
public:
	/** Initialize your data structure here.
		@param width - screen width
		@param height - screen height
		@param food - A list of food positions
		E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
	SnakeGame(int width, int height, vector<vector<int>>& food) {
		w = width;
		h = height;
		grid = vector<vector<bool>>(h, vector<bool>(w, false));
		grid[0][0] = true;
		snakeBody.push_back(pair<int, int>({ 0,0 }));
		for (int i = 0; i < food.size(); i++) {
			foodArray.push_back(vector<int>({ food[i][0],food[i][1] }));
		}
		posC = posR = 0;
		cfpos = 0;
		score = 0;
	}

	/** Moves the snake.
		@param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
		@return The game's score after the move. Return -1 if game over.
		Game over when snake crosses the screen boundary or bites its body. */
	int move(string direction) {
		if (direction.size() == 0)
			return 0;
		char c = direction[0];
		makeMove(c);
		if (cfpos < foodArray.size() && isFood()) {
			cfpos++;
			score++;
		}
		else {
			pair<int, int> tail = snakeBody.front();
			grid[tail.first][tail.second] = false;
			snakeBody.pop_front();
		}
		if (hasHitWalls() || hasHitSnake())
			return -1;

		grid[posR][posC] = true;
		snakeBody.push_back(pair<int, int>({ posR, posC }));
		return score;
	}
	bool isFood()
	{
		if (posR == foodArray[cfpos][0] && posC == foodArray[cfpos][1])
		{
			return true;
		}
		return false;
	}

	bool hasHitSnake()
	{
		if (grid[posR][posC])
			return true;
		return false;
	}

	bool hasHitWalls()
	{
		if (posC < 0 || posC >= w || posR < 0 || posR >= h)
			return true;
		return false;
	}
	void makeMove(char c)
	{
		switch (c)
		{
		case 'R':
			posC++;
			break;
		case 'L':
			posC--;
			break;
		case 'U':
			posR--;
			break;
		case 'D':
			posR++;
			break;
		default:
			break;
		}
	}
};
void DesignSnakeGame::solve()
{
	fillInput();
	SnakeGame obj(grid[0], grid[1], food);
	for (int i = 1; i < queries.size(); i++)
	{
		if (queries[i] == "move") {
			cout << obj.move(qData[i - 1]) << endl;
		}
	}
	return;
}

void DesignSnakeGame::fillInput()
{
	getStrings(queries);
	getIntArray(grid);
	get2Darray(food);
	getStrings(qData);
}
