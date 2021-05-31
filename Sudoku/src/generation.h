#pragma once

#include <random>

#include "board.h"

namespace sudoku
{
	void GenerateBoardRandom(Board& board, const unsigned int seed);
}

