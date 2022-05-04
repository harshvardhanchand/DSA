#include <iostream>
using namespace std;
// convert sparse_matrix.c to c++
class Element
{
public:
    int row;
    int col;
    int value;
};

class sparse_matrix
{
private:
    int rows;
    int cols;
    int size;
    Element *elements;
    /* data */
public:
    sparse_matrix(int rows, int cols, int size)
    {
        this->rows = rows;
        this->cols = cols;
        this->size = size;
        elements = new Element[size];
    }

    sparse_matrix::~sparse_matrix()
    {
        delete[] elements;
    }
    sparse_matrix operator+(sparse_matrix &other)
    {
        int i, j, k;
        i = j = k = 0;
        if (this->rows != other.rows || this->cols != other.cols)
        {
            cout << "Error: Matrixs are not of same size" << endl;
            return sparse_matrix(0, 0, 0);
        }
        sparse_matrix *sum = new sparse_matrix(this->rows, this->cols, this->size + other.size);
        while (i < this->size && j < other.size)
        {
            if (this->elements[i].row < other.elements[j].row)
            {
                sum->elements[k++] = this->elements[i++];
            }
            else if (this->elements[i].row > other.elements[j].row)
            {
                sum->elements[k++] = other.elements[j++];
            }
            else
            {
                if (this->elements[i].col < other.elements[j].col)
                {
                    sum->elements[k++] = this->elements[i++];
                }
                else if (this->elements[i].col > other.elements[j].col)
                {
                    sum->elements[k++] = other.elements[j++];
                }
                else
                {
                    sum->elements[k++] = this->elements[i++];
                    sum->elements[k++].value = +other.elements[j++].value;
                }
            }
            for (; i < this->size; i++)
            {
                sum->elements[k++] = this->elements[i];
            }
            for (; j < other.size; j++)
            {
                sum->elements[k++] = other.elements[j];
            }
            sum->size = k;
            return *sum;
        }
    }
    friend ostream &operator<<(ostream &os, sparse_matrix &other)
    {
        int i;
        for (i = 0; i < other.size; i++)
        {
            os << other.elements[i].row << " " << other.elements[i].col << " " << other.elements[i].value << endl;
        }
        return os;
    }
    friend istream &operator>>(istream &is, sparse_matrix &other)
    {
        int i, j, k;
        i = j = k = 0;
        while (i < other.size)
        {
            is >> other.elements[i].row >> other.elements[i].col >> other.elements[i].value;
            i++;
        }
        return is;
    }
};
