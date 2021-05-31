#include <iostream>

#include "src/game.h"

int main() {
	std::cout << "1" << std::endl;
	sudoku::Game* game = new sudoku::Game();
	sudoku::Board* board = game->GetBoard();

	std::cout << "2" << std::endl;
	std::cout << board->ToString();

	std::cout << "3" << std::endl;
	for (int i = 0; i < board->GetSize(); i++)
	{
		std::cout << board->GetRow(i).ToString();
	}

	std::cout << std::endl;

	for (int i = 0; i < board->GetSize(); i++)
	{
		std::cout << board->GetColumn(i).ToString();
	}

	std::cout << std::endl;

	for (int i = 0; i < board->GetSize(); i++)
	{
		std::cout << board->GetBlock(i).ToString();
	}
	
	std::cin.get();
	return 0;
}
