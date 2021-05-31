#include "game.h"
#include "generation.h"

namespace sudoku
{
	Game::Game()
	{
		Init();
	}

	void Game::Init()
	{
		m_Board = new Board(3);
		GenerateBoardRandom(*m_Board, 7);

	}
}