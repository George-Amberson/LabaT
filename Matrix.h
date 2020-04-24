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

  template<class V>
  friend Matrix<V> operator +(Matrix<V>& lhs, Matrix<V>& rhs);
 
  template <class A>
  friend Matrix<A> operator -(Matrix<A>& lhs, Matrix<A>& rhs);

  Matrix& operator =(Matrix& lhs);

  template <class C>
  friend bool operator ==(Matrix<C>& lhs, Matrix<C>& rhs);
  
  template <class D>
  friend Matrix<D> operator *(Matrix<D>& lhs, Matrix<D>& rhs);

  template <class E>
  friend ostream& operator <<(ostream& out, Matrix<E>& rhs);
  
  template<class W>
  friend istream& operator >>(istream& in, Matrix<W>& rhs);

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
