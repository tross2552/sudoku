#include "game.h"
#include "generation.h"

namespace sudoku
{

	Game::Game(const unsigned int seed)
	{
		rank = 3;
		Init(rank, seed);
	}

	void Game::Init(const int rank, const unsigned int seed)
	{
		m_Board = new Board(rank);
		GenerateBoardRandom(*m_Board, seed);
	}
}