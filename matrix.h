#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <cmath>
#include <conio.h>
template <class T>
class matrix
{
private:
    T **vector = NULL;
    int size;
    int pos_col = 0;
    int pos_row = 0;
    char pressAnyKey;
protected:

void createSquareMatrix(int size)
    {
        int i, j;
        this->size = size;
        this->vector = new T *[size];
        for (i = 0; i < size; i++)
        {
            this->vector[i] = new T[size];
            for (j = 0; j < size; j++)
            {
                if (i == j)
                {
                    this->vector[i][j] = INFINITY;
                }
                else
                {
                    this->vector[i][j] = 0;
                }
            }
        }
    }
    void deleteMatrix()
    {
        int i;
        for (i = 0; i < this->size; i++)
        {
            delete[] this->vector[i];
        }
        delete[] this->vector;
        this->vector=NULL;
    }

public:
    matrix(int size = 1)
    {
        createSquareMatrix(size);
    }
    
    ~matrix()
    {
        deleteMatrix();
    }
    friend std::ostream &operator<<(std::ostream &out, const matrix &a)
    {
        int i, j;
        for (i = 0; i < a.size; i++)
        {
            for (j = 0; j < a.size; j++)
            {
                if (i == a.pos_row && j == a.pos_col)
                {
                    out << "\033[4m" << a.vector[i][j] << "\033[0m" << '\t';
                }
                else
                {
                    out << a.vector[i][j] << '\t';
                }
            }
            out << '\n';
        }
        return out;
    }
    char moveInCell()
    {
        char tmp;
        tmp = _getch();
        switch (tmp)
        {
        case 'w':
            if (this->pos_row > 0)
            {
                this->pos_row--;
            }
            break;
        case 'a':
            if (this->pos_col > 0)
            {
                this->pos_col--;
            }
            break;
        case 's':
            if (this->pos_row < this->size - 1)
            {
                this->pos_row++;
            }
            break;
        case 'd':
            if (this->pos_col < this->size - 1)
            {
                this->pos_col++;
            }
            break;
        case 13:
            if (this->vector[this->pos_row][this->pos_col] != INFINITY)
            {
                std::cout << "Type value of this cell: ";
                std::cin >> this->vector[this->pos_row][this->pos_col];
            }
            else
            {
                std::cout << "Cannot change infinity value(Press any key to contiune)";
                this->pressAnyKey = _getch();
            }
            break;
        default:
            break;
        }
        return tmp;
    }
    matrix &operator=(const matrix &a)
    {
        int i, j;
        this->deleteMatrix();
        this->size = a.size;
        this->createSquareMatrix(this->size);
        for (i = 0; i < this->size; i++)
        {
            for (j = 0; j < this->size; j++)
            {
                this->vector[i][j] = a.vector[i][j];
            }
        }
        return *this;
    }
    unsigned int findInRow(unsigned int row)
    {
        unsigned int smallest=this->vector[row][0];
        unsigned int i;
        for ( i = 1; i < this->size; i++)
        {
            if(this->vector[row][i]<smallest)
            {
                smallest=this->vector[row][i];
            }
        }
        return smallest;
    }
    unsigned int findInCol(unsigned int col)
    {
        unsigned int smallest=this->vector[0][col];
        unsigned int i;
        for ( i = 1; i < this->size; i++)
        {
            if(this->vector[i][col]<smallest)
            {
                smallest=this->vector[i][col];
            }
        }
        return smallest;
    }
};
#endif