#pragma once
#include <string>

namespace sudoku
{
	class Board
	{
	public:

		struct Cell
		{
			Cell() :
				Cell(0) {}

			Cell(unsigned int value) :
				value(value) {}

			unsigned int value;

		};

		struct Group
		{
			Cell** members;
			unsigned int size;

			std::string ToString() const;
		};

	private: 

		Cell*  m_Board;
		int    m_Size;

		Group* m_Rows;
		Group* m_Columns;
		Group* m_Blocks;

	public:

		Board() : Board(3) {}
			
		Board(const unsigned int rank);

		inline void SetValue(const unsigned int index, unsigned int value) { m_Board[index] = value; }
		void SetValue(const unsigned int row, const unsigned int column, unsigned int value);

		inline Board::Cell* GetCell(const unsigned int index) const { return &m_Board[index]; }
		Board::Cell* GetCell(const unsigned int row, const unsigned int column) const;

		Board::Group& GetRow(const unsigned int row) const;
		Board::Group& GetColumn(const unsigned int column) const;
		Board::Group& GetBlock(const unsigned int block) const;

		inline int GetSize() const { return m_Size; }

		

		std::string ToString() const;
		
	};
}