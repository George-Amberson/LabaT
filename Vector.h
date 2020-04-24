#include "Matrix.h"

template <class T1>
class Vector :public Matrix<T1>
{
public:
  Vector() :Matrix(){}
  Vector(int _size) :Matrix(1, _size){}
  Vector(const Vector& t) :Matrix(t){}
  ~Vector(){}
  T1* get_vector();
  
  using Matrix:: operator =;
 
  T1& operator [](const int i);

  void set_length(int _resize);

  template<class J>
  friend Vector<J> operator /(Vector<J>& lhs, Vector<J>& rhs);

  template<class Y>
  friend Y operator *(Vector<Y>& lhs, Vector<Y>& rhs);

  template<class K>
  friend istream& operator >>(istream& in, Vector<K>& rhs);

  friend void In_Vector(Vector& lhs){
    for (int i = 0; i < lhs.get_length(); i++)
      lhs[i] = rand();
  }

  template<class P>
  friend clock_t BubbleSort(Vector<P> &A);

  template<class Q>
  friend clock_t InsertionSort(Vector<Q>& a);
 
  template<class K>
  friend clock_t QuickSort(Vector<K>& p, int first, int last);
};

#include "Vector_doing.h"
