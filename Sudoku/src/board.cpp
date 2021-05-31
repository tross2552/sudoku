#include "board.h"

#include <array>
#include <sstream>

namespace sudoku
{

	std::string Board::Group::ToString() const
	{
		std::stringstream ostream;

		for (int i = 0; i < size; i++)
		{
			ostream << members[i]->value;
		}

		ostream << std::endl;

		return ostream.str();
	}

	//builds default square grid layout
	Board::Board(const unsigned int rank)
	{
		m_Size = rank * rank;
		m_Board = new Cell[m_Size * m_Size];

		m_Rows = new Group[m_Size];
		m_Columns = new Group[m_Size];
		m_Blocks = new Group[m_Size];

		Cell** rMembers;
		Cell** cMembers;
		Cell** bMembers;

		for (int i = 0; i < m_Size; i++)
		{
			rMembers = new Cell * [m_Size];
			cMembers = new Cell * [m_Size];
			bMembers = new Cell * [m_Size];

			for (int j = 0; j < m_Size; j++)
			{
				rMembers[j] = &m_Board[m_Size * i + j];
				cMembers[j] = &m_Board[m_Size * j + i];

				int row = rank * (i % rank) + j % rank;
				int column = rank * (int)(i / rank) + j / rank;
				bMembers[j] = &m_Board[m_Size * row + column];

			}

			m_Rows[i].members = rMembers;
			m_Rows[i].size = m_Size;
			m_Columns[i].members = cMembers;
			m_Columns[i].size = m_Size;
			m_Blocks[i].members = bMembers;
			m_Blocks[i].size = m_Size;

		}
	}

	void Board::SetValue(const unsigned int row, const unsigned int column, unsigned int value)
	{
		m_Board[m_Size * row + column] = value;
	}

	Board::Cell* Board::GetCell(const unsigned int row, const unsigned int column) const
	{
		return &m_Board[m_Size * row + column];
	}

	Board::Group& Board::GetRow(const unsigned int row) const
	{
		return m_Rows[row];
	}

	Board::Group& Board::GetColumn(const unsigned int column) const
	{
		return m_Columns[column];
	}

	Board::Group& Board::GetBlock(const unsigned int block) const
	{
		return m_Blocks[block];
	}

	std::string Board::ToString() const
	{
		std::stringstream ostream;

		for (int i = 0; i < m_Size; i++)
		{
			for (int j = 0; j < m_Size; j++) ostream << m_Board[i*m_Size+j].value;
			ostream << std::endl;
		}

		return ostream.str();
	}

}