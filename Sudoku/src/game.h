#pragma once

#include "board.h"
#include <string>

namespace sudoku
{
	class Game
	{
	public:

		int rank;

		Game() :
			Game(7) {}

		Game(const unsigned int seed);

		void Init(const int rank, const unsigned int seed);

		inline Board* GetBoard() const { return m_Board; }


	private:
		Board* m_Board;
	};
}