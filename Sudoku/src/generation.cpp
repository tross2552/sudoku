#include "board.h"
#include "generation.h"

#include <random>

namespace sudoku
{
	void GenerateBoardRandom(Board& board, const unsigned int seed)
	{

		std::random_device rd;
		std::mt19937 mt(seed);
		std::uniform_real_distribution<float> dist(1.0, 10.0);

		for (int i = 0; i < board.GetSize()*board.GetSize(); i++)
			board.SetValue(i, (unsigned int)dist(mt));
	}
}