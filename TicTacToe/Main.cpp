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
		//Validity check.
		//if the board is less than 3 squares width
		if (_board.GetWidth() < 3)
		{
			std::cout << "Invalid quantity of board, use 3*3 or higher!\n";
			return Winner::None;
		}

		Winner::E winningPlayer, currentPlayer = Winner::X;
		while ((winningPlayer= _ruleEngine.GetWinningPlayer(_board)) == Winner::None)
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
		std::cout << GetWinnerText(winningPlayer);
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
	std::string GetWinnerText(Winner::E name)
	{
		switch (name)
		{
		case Winner::X:
			return "X wins\n";
			break;
		case Winner::O:
			return "O wins\n";
			break;
		case Winner::Stalemate:
			return "It's a tie (Stalemate)\n";
			break;
		case Winner::None:
			return "Nobody wins?? How did you do that\n";
			break;
		default:
			return "???\n";
			break;
		}
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

//Homework 7:
//Create the engine that allows a player to win the game!
//Works flawlessly! ;)
class ClassicRuleEngine : public IRuleEngine
{
	
public:
	virtual Winner::E GetWinningPlayer(Board& board)
	{
		bool linematches = false; //Identify if there's 3 in a row.
		int samePlayerCount = 1; //Keep a count of the current matches of a player in the board.
		Winner::E winner;
		if (linematches == false)
		{
			samePlayerCount = 1;
			//std::cout << "Checking Horizontally\n";
			for (auto i = 0; i < board.GetTotalSquares(); i++)
			{
				if (board.GetSquare(i) == BoardSquare::Empty)
				continue; //move to the next item.

				   //Horizontal check.
				if (i == 0) continue; //greater than or equals because the next line will make a check with the next item.
				if ((i + 1) % board.GetWidth() == 0) //The only one that equals 0 is 0 and the Width of the board,
						//this way we know we are int the last item horizontally if this is true.
					{
						for (int reverseindex = i; reverseindex > (i - 2); reverseindex--) //now lets read from the last to the first horizontally.
						{
							if ((reverseindex - 1) < 0) continue;

							if (board.GetSquare(reverseindex) == board.GetSquare(reverseindex - 1))
							{
								samePlayerCount = samePlayerCount + 1;
							}
							else
							{
								samePlayerCount = 1;
							}
							if (samePlayerCount == board.GetWidth())
							{
								linematches = true;
								winner = (board.GetSquare(reverseindex) == BoardSquare::X) ? Winner::X : Winner::O;
								break;
							}
						}
					}
				
				if (linematches) break; //Exit of the main loop because I already found a Winner!
			}
		}
		if (linematches == false)
			{
				//Still no match? check vertically.
				samePlayerCount = 1; //reset.
				//std::cout << "Checking Vertically\n";
				for (auto i = 0; i < board.GetTotalSquares(); i++)
				{
					if (board.GetSquare(i) == BoardSquare::Empty) continue; //move to the next item.
					if (board.GetSquare(i) == board.GetSquare(i + board.GetWidth()))
					{
						samePlayerCount = samePlayerCount + 1;
						i += board.GetWidth() - 1;
					}
					else
					{
						samePlayerCount = 1;
					}
					if (samePlayerCount == board.GetWidth())
					{
						linematches = true;
						winner = (board.GetSquare(i + 1) == BoardSquare::X) ? Winner::X : Winner::O;
						break;

					}
				}
			}
		if (linematches == false)
			{
				//If still does not matchhhhhh then let's prove now in diagonal fashion
				//there are two diagonals
				samePlayerCount = 1; //reset again.
				//std::cout << "Checking Top Left\n";
				//from Top Left:
				for (auto i = 0; i < board.GetTotalSquares(); i++)
				{
					if (board.GetSquare(0) == BoardSquare::Empty) break; //if the top left is empty then don't check for anything.
					//first diagonal (starting from top left)
					if (board.GetSquare(i) == board.GetSquare(i + board.GetWidth() + 1))
					{
						samePlayerCount = samePlayerCount + 1;
						i += board.GetWidth();
					}
					else
					{
						samePlayerCount = 1;
					}
					if (samePlayerCount == board.GetWidth())
					{
						linematches = true;
						winner = (board.GetSquare(i + 1) == BoardSquare::X) ? Winner::X : Winner::O;
						break;
					}
				}
				samePlayerCount = 1; //reset again.
				//from Top Right:
				//std::cout << "Checking Top Right\n";
				for (auto i = (board.GetWidth()-1); i < board.GetTotalSquares(); i++)
				{
					if (board.GetSquare(i) == BoardSquare::Empty) break; //if the top right is empty then don't check for anything.
					if (board.GetSquare(i) == board.GetSquare(i + board.GetWidth() - 1))
					{
						samePlayerCount = samePlayerCount + 1;
						i += board.GetWidth() - 2;
					}
					else
					{
						samePlayerCount = 1;
					}
					if (samePlayerCount == board.GetWidth())
					{
						linematches = true;
						winner = (board.GetSquare(i-1) == BoardSquare::X) ? Winner::X : Winner::O;
						break;
					}
				}
			}

		if (linematches)
		{
			return winner;
		}
		else
		{
			//Check for a Stalemate.
			bool atLeastOneSquareEmpty = false;
			for (auto i = 0; i < board.GetTotalSquares(); i++)
			{
				if (board.GetSquare(i) == BoardSquare::Empty)
				{
					atLeastOneSquareEmpty = true;
					break;
				}
				else
				{
					atLeastOneSquareEmpty = false;
				}
				
			}
			if (atLeastOneSquareEmpty == true)
			{
				return Winner::None;
			}
			else
			{
				return Winner::Stalemate;
			}
		}
		
	}
};
int main()
{

	Board board(3); //Constructor on stack.

	ClassicRuleEngine classicRuleEngine;

	Game game(board, classicRuleEngine);
	game.Run();

	

	return 0;
}