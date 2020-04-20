#include "Matrix.h"

template <class T1>
class Vector :public Matrix<T1>
{
public:
  Vector() :Matrix(){}
  Vector(int _size) :Matrix(1, _size){}
  Vector(const Vector& t) :Matrix(t){}
  ~Vector(){ }
  T1* get_vector();

  using Matrix::operator =;

  T1& operator [](const int i);

  void set_length(int _resize);

  friend Vector operator /(Vector& lhs, Vector& rhs)
  {
    if (lhs.get_length() != rhs.get_length())throw length_error("Vector's size not equal");
    Vector A(lhs);
    for (int i = 0; i < A.get_length(); i++){
      if (rhs[i] != 0){
        A.get_vector()[i] = A.get_vector()[i] / rhs[i];
      }

    }
    return A;
  }

  friend float operator *(Vector& lhs, Vector & rhs)
  {
    if (lhs.get_length() != rhs.get_length())throw length_error("Vector's size not equal");
    float s=0;
    for (int i = 0; i < rhs.get_length(); i++)s = s + lhs.get_vector()[i] * rhs.get_vector()[i];
    return s;
  }
  friend istream& operator >>(istream& in, Vector& rhs)
  {
    if (rhs.get_length() == 0)
    {
      int _size;
      in >> _size;
      rhs.set_length(_size);
    }
    for (int i = 0; i < rhs.get_length(); i++)
    {
      in >> rhs.get_vector()[i];
    }
    return in;
  }
  friend clock_t BubbleSort(Vector &A)
  {
    clock_t t1, t2;
    t1 = clock();
    T1 tmp = 0;
    int i, j = 0;
    t1 = clock();
    for (int i = 0; i <A.get_length(); i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (A.get_vector()[j] > A.get_vector()[j + 1])
        {
          tmp = A.get_vector()[j];
          A.get_vector()[j] = A.get_vector()[j + 1];
          A.get_vector()[j + 1] = tmp;
        }
      }
    }
    t2 = clock();
    return (t2 - t1);

  }
  friend void InVector(Vector &A){

    for (int i = 0; i < A.get_length(); i++){
      A[i] = rand();
    }

  }
  friend clock_t InsertionSort(Vector& a)
  {
    clock_t t1, t2;
    t1 = clock();
    T1 newElement;
    int location;

    for (int i = 1; i < a.get_length(); i++)
    {
      newElement = a.get_vector()[i];
      location = i - 1;
      while (location >= 0 && a.get_vector()[location] > newElement)
      {
        a.get_vector()[location + 1] = a.get_vector()[location];
        location = location - 1;
      }
      a.get_vector()[location + 1] = newElement;
    }
    t2 = clock();
    return t2 - t1;
  }
  friend clock_t QuickSort(Vector& p, int first, int last)
  {
    clock_t t1, t2, t3;
    t1 = clock();
    int i = first, j = last;
    T1 tmp;
    T1 x = p.get_vector()[(first + last) / 2];

    do {
      while (p.get_vector()[i] < x)
        i++;
      while (p.get_vector()[j] > x)
        j--;

      if (i <= j)
      {
        if (i < j)
        {
          tmp = p.get_vector()[i];
          p.get_vector()[i] = p.get_vector()[j];
          p.get_vector()[j] = tmp;
        }
        i++;
        j--;
      }
    } while (i <= j);

    if (i < last)
      t3 = QuickSort(p, i, last);
    if (first < j)
      t3 = QuickSort(p, first, j);
    t2 = clock();
    return (t2 - t1);
  }
};
#include "Vector_doing.h"