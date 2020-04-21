#include <iostream>
#include <string>

struct BoardSquare 
{
	enum E 
	{
		X,
		O,
		Empty
	};
};
struct Winner
{
	enum E
	{
		X,
		O,
		Stalemate,
		None
	};
};
class Board
{
	int _width;
	BoardSquare::E* _squares;
public:
	Board(int width) : _width(width)
	{
		_squares = new BoardSquare::E[width * width];
		for (auto i = 0; i < GetTotalSquares(); i++)
			_squares[i] = BoardSquare::Empty;
	}
	~Board()
	{
		delete[] _squares;
	}

	int GetWidth() 
	{
		return _width;
	}
	int GetTotalSquares() 
	{
		return _width * _width;
	}
	BoardSquare::E GetSquare(int index) 
	{
		return _squares[index];
	}
	void SetSquare(int index, BoardSquare::E square) 
	{
		_squares[index] = square;
	}
};
class IRuleEngine //Interface
{
public:
	virtual Winner::E GetWinningPlayer(Board& board/*Reference.*/) = 0; //ABSTRACT (=0 points that) //It has no implementation.
};
class Game
{
	Board& _board;
	IRuleEngine& _ruleEngine;

public:
	Game(Board& board, IRuleEngine& engine) : _board(board), _ruleEngine(engine) //Init list.
	{

	}
	Winner::E Run() 
	{
		Winner::E winningPlayer, currentPlayer = Winner::X;
		while ((winningPlayer= _ruleEngine.GetWinningPlayer(_board))== Winner::None)
		{
			Render();
			std::cout << std::endl;
			int input;
			std::cout << "Move for " << (currentPlayer == Winner::X ? 'X': 'O') << ": ";
			std::cin >> input;
			std::cin.ignore();
			input -= 1;
			if (input <0 || input > _board.GetTotalSquares() || _board.GetSquare(input) != BoardSquare::Empty)
			{
				std::cout << "Invalid move!\n";
				continue;
			}
			_board.SetSquare(input, currentPlayer== BoardSquare::X? BoardSquare::X: BoardSquare::O);
			currentPlayer = currentPlayer == Winner::X ? Winner::O : Winner::X;
		}
		return winningPlayer;
	}
private:
	void Render()
	{
		for (auto i = 1; i <= _board.GetTotalSquares(); i++)
		{
			std::cout << GetSquareChar(i, _board.GetSquare(i - 1)) << " ";
			if ((i % _board.GetWidth()) == 0)
			{
				std::cout << std::endl;
			}
		}
	}
	char GetSquareChar(int index, BoardSquare::E square)
	{
		switch (square)
		{
		case BoardSquare::X:
			return 'X';
			break;
		case BoardSquare::O:
			return 'O';
			break;
		}
		return index + '0';
	}
};
class NullRuleEngine : public IRuleEngine //public class
{
public:
	virtual Winner::E GetWinningPlayer(Board& board/*Reference.*/)
	{
		return Winner::None;
	}
};
int main()
{
	Board board(3); //Constructor on stack.

	NullRuleEngine nullruleEngine;

	Game game(board, nullruleEngine);
	game.Run();

	//Homework 7:
	//Create the engine that allows a player to win the game.
	//right now it's impossible to win the game.

	return 0;
}