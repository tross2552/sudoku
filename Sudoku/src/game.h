#pragma once

#include "board.h"
#include <string>

namespace sudoku
{
	class Game
	{
	public:
		Game();

		void Init();

		inline Board* GetBoard() const { return m_Board; }


	private:
		Board* m_Board;
	};
}