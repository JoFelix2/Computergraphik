// CG Assignment 1 Exercise 3 WS 18/19

#include "MatrixInt.hpp"

#include <algorithm>
#include <iostream>
#include <cstring>


MatrixInt::MatrixInt() : m_row_cnt(0), m_column_cnt(0), m_raw_data(nullptr) {
}

///////
// TODO
// Implement the constructor
// Make sure to check the hpp file for the desired behaviour.
MatrixInt::MatrixInt(unsigned int row_cnt, unsigned int column_cnt){
    ///////
    // TODO
    // Implement the constructor.
    
    // if row or column count is zero, set raw data storage to nullptr
    if (row_cnt == 0 || column_cnt == 0)
    {
    	m_row_cnt = 0;
    	m_column_cnt = 0;
    	m_raw_data = nullptr;
    }
    else
    {
		// take on these values
		m_row_cnt = row_cnt;
		m_column_cnt = column_cnt;
		
		// initialize raw data storage
		m_raw_data = new int[m_row_cnt * m_column_cnt];
		
		// fill with zeroes
		for (int currentRow = 0; currentRow < m_row_cnt; ++currentRow)
			for (int currentColumn = 0; currentColumn < m_column_cnt; ++currentColumn)
				m_raw_data[currentRow * m_column_cnt + currentColumn] = 0;
	}
}

MatrixInt::~MatrixInt() {
    ///////
    // TODO
    // Implement the destructor
	delete[] m_raw_data;
}

MatrixInt::MatrixInt(MatrixInt const& other)
    : m_row_cnt(other.m_row_cnt), m_column_cnt(other.m_column_cnt), m_raw_data(nullptr)
{
    if (other.m_raw_data != nullptr) {
        m_raw_data = new int[m_row_cnt*m_column_cnt];
        std::memcpy(m_raw_data, other.m_raw_data, m_row_cnt*m_column_cnt * sizeof(int));
    }
}

MatrixInt::MatrixInt(MatrixInt&& other) : MatrixInt() {
    std::swap(m_raw_data, other.m_raw_data);
    std::swap(m_row_cnt, other.m_row_cnt);
    std::swap(m_column_cnt, other.m_column_cnt);
}

MatrixInt& MatrixInt::operator=(MatrixInt const& rhs) {
    if (this != &rhs) {
        MatrixInt tmp(rhs);
        std::swap(m_raw_data, tmp.m_raw_data);
        std::swap(m_row_cnt, tmp.m_row_cnt);
        std::swap(m_column_cnt, tmp.m_column_cnt);
    }

    return *this;
}

MatrixInt& MatrixInt::operator=(MatrixInt&& rhs) {
    if (this != &rhs) {
        std::swap(m_raw_data, rhs.m_raw_data);
        std::swap(m_row_cnt, rhs.m_row_cnt);
        std::swap(m_column_cnt, rhs.m_column_cnt);
    }

    return *this;
}

MatrixInt MatrixInt::operator*(MatrixInt const& rhs)
{
    // matrix A size
    unsigned int rows1 = this->getRowCount();
    unsigned int columns1 = this->getColumnCount();

    // matrix B size
    unsigned int rows2 = rhs.getRowCount();
    unsigned int columns2 = rhs.getColumnCount();

    if (columns1 != rows2) {
        std::cerr << "Matrix multiplication size mismatch." << std::endl;
        return MatrixInt();
    }

    MatrixInt resultMatrix(rows1, columns2);

    ///////
    // TODO
    // Implement matrix multiplication (A * B).
    // Hint: Values of matrix A are accessed using the "this" pointer,
    // values of matrix B are accessed from function input parameter "rhs".
    // Hint: The matrizes are stored in row-major order. Be careful to use
    // the correct offsets when accessing values of row- and column-vectors
    // of A and B respectively.
	for (int currentRow = 0; currentRow < rows1; ++currentRow)
		for (int currentColumn = 0; currentColumn < columns2; ++currentColumn)
		{
			int result = 0;
			for (int i = 0; i < columns1; ++i) // interchangeably, rows2
				result += this->m_raw_data[currentRow * columns2 + i] * rhs.m_raw_data[i * columns2 + currentColumn];
			resultMatrix.m_raw_data[currentRow * columns2 + currentColumn] = result;
		}

    return resultMatrix;
}
