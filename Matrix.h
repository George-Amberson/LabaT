#pragma once
#include <iostream>
using namespace std;
template <class Type>
class Matrix
{
public:
  Matrix() :width(0), length(0), matrix(0){}
  Matrix(int _a, int _b);

  Matrix(const Matrix& lhs);
  virtual ~Matrix();

  int get_width()const;

  int get_length()const;

  Type** get_array();

  void set_width_length(int _width, int _length);


  Type*& operator [](const int i);

  friend Matrix operator +(Matrix& lhs, Matrix& rhs)
  {
    if ((lhs.get_width() != rhs.get_width()) || (lhs.get_length() != rhs.get_length()))throw length_error("matrix size not equal");
    Matrix A(lhs.get_width(), rhs.get_length());
    for (int i = 0; i < rhs.get_width(); i++)
    {
      for (int j = 0; j < rhs.get_length(); j++)
      {
        A[i][j] = lhs[i][j] + rhs[i][j];
      }
    }
    return A;
  }

  friend Matrix operator -(Matrix& lhs, Matrix& rhs)
  {
    if ((lhs.get_width()!=rhs.get_width()) || (lhs.get_length()!=rhs.get_length()))throw length_error("matrix size not equal");
    Matrix A(lhs);
    for (int i = 0; i < rhs.get_width(); i++)
    {
      for (int j = 0; j < rhs.get_length(); j++)
      {
        A[i][j] = A[i][j] - rhs[i][j];
      }
    }
    return A;
  }

  Matrix& operator =(Matrix& lhs);

  friend bool operator ==(Matrix& lhs, Matrix& rhs)
  {
    if ((lhs.get_width() != rhs.get_width()) || (lhs.get_length() != rhs.get_length()))
    {
      return false;
    }
    else{
      for (int i = 0; i < lhs.get_width(); i++)
      {
        for (int j = 0; j < lhs.get_length(); j++)
        {
          if (lhs[i][j] != rhs[i][j]) return false;
        }
      }
    }
    return true;
  }
  friend Matrix operator *( Matrix& lhs,  Matrix& rhs)
  {
    if (lhs.get_length() != rhs.get_width())throw length_error("matrix size uncorrect");
    Matrix C(lhs.get_width(), rhs.get_length());
    Type S;
    for (int i = 0; i < lhs.get_width(); i++)
    {
      for (int j = 0; j < rhs.get_length(); j++)
      {
        S = 0;
        for (int k = 0; k < rhs.get_width(); k++)
        {
          S = S + lhs.get_array()[i][k] * rhs.get_array()[k][j];
        }
        C[i][j] = S;
      }
    }
    return C;
  }
  friend ostream& operator <<(ostream& out, Matrix& rhs)
  {
    for (int i = 0; i < rhs.get_width(); i++)
    {
      for (int j = 0; j < rhs.get_length(); j++)
      {
        out << rhs.get_array()[i][j] << " ";
      }
      out << endl;
    }
    return out;
  }
  friend istream& operator >>(istream& in, Matrix& rhs)
  {
    if ((rhs.get_length() == 0) || (rhs.get_width() == 0))
    {
      cout << "Vvedite width&Length" << endl;
      int a, b;
      in >> a >> b;
      rhs.set_width_length(a, b);
    }
    for (int i = 0; i < rhs.get_width(); i++)
    {
      for (int j = 0; j < rhs.get_length(); j++)
      {
        in >> rhs[i][j];
      }
    }
    return in;
  }
private:
  void MemorySize(int _width, int _length)
  {
    for (int i = 0; i < _width; i++) matrix[i] = new Type[_length];
  }
  Type** matrix;
  int width;
  int length;
};

#include "Matrix_doing.h";