#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <time.h>

using namespace std;
template <class Type>
class Matrix
{
public:
  Matrix() :width(0), length(0), matrix(0){}
  Matrix(int _a, int _b) : width(_a), length(_b){
    matrix = new Type*[_a];
    MemorySize(_a, _b);
    for (int i = 0; i < _a; i++)
    {
      for (int j = 0; j < _b; j++)
      {
        matrix[i][j] = 0;
      }
    }

  }

  Matrix(const Matrix& lhs) :width(lhs.width), length(lhs.length)
  {
    matrix = new Type*[lhs.width];
    MemorySize(lhs.width, lhs.length);
    for (int i = 0; i < lhs.width; i++)
    {
      for (int j = 0; j < lhs.length; j++)
      {
        matrix[i][j] = lhs.matrix[i][j];
      }
    }
  }
  virtual ~Matrix()
  {
    for (int i = 0; i < width; i++) delete matrix[i];
    delete matrix;
  }
  int get_width()const
  {
    return width;
  }
  int get_length()const
  {
    return length;
  }
  Type** get_array()
  {
    return matrix;
  }
  void set_width_length(int _width, int _length)
  {
    Type ** vr = new Type *[width];
    for (int i = 0; i < width; i++) vr[i] = new Type[length];
    for (int i = 0; i < width; i++)
    {
      for (int j = 0; j < length; j++)
      {
        vr[i][j] = matrix[i][j];
      }
    }
    if (width == 0)matrix = new Type*[_width];
    MemorySize(_width, _length);

    for (int i = 0; i < width; i++)
    {
      for (int j = 0; j < length; j++)
      {
        matrix[i][j] = vr[i][j];
      }
    }
    if ((_width > width) && (_length>length))
    {
      for (int i = width; i < _width; i++)
      {
        for (int j = length; j < _length; j++)
        {
          matrix[i][j] = 0;
        }
      }
    }
    else{
      if (_width > width)
      {
        for (int i = width; i < _width; i++)
        {
          for (int j = 0; j < length; j++)
          {
            matrix[i][j] = 0;
          }
        }
      }
      if (_length > length)
      {
        for (int i = 0; i < width; i++)
        {
          for (int j = length; j < _length; j++)
          {
            matrix[i][j] = 0;
          }
        }
      }
    }
    width = _width;
    length = _length;
  }

  Type*& operator [](const int i)
  {
    return matrix[i];

  }
  friend Matrix operator +(Matrix& lhs, Matrix& rhs)
  {
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

  Matrix& operator =(Matrix& lhs)
  {
    width = lhs.get_width();
    length = lhs.get_length();
    matrix = new Type* [width];
    MemorySize(width, length);
    for (int i = 0; i < width; i++)
    {
      for (int j = 0; j < length; j++)
      {
        matrix[i][j] = lhs[i][j];
      }
    }
    return *this;
  }

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
  friend Matrix operator *(const Matrix& lhs, const Matrix& rhs)
  {
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
  friend ostream& operator <<(ostream& out,  Matrix& rhs)
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

template <class T1>
class Vector :public Matrix<T1>
{
public:
  Vector() :Matrix(){}
  Vector(int _size) :Matrix(1, _size){}
  Vector(const Vector& t) :Matrix(t){}
  ~Vector(){ }
  T1* get_vector()
  {
    return get_array()[0];
  }

  using Matrix::operator =;

  T1& operator [](const int i)
  {
    return get_vector()[i];
  }
  void set_length(int _resize)
  {
    set_width_length(1, _resize);
  }
  friend Vector operator /(Vector& lhs, Vector& rhs)
  {
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
    float s = 0;
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
      A[i]= rand();
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
      t3 = QuickSort(p,i, last);
    if (first < j)
      t3 = QuickSort(p, first, j);
    t2 = clock();
    return (t2 - t1);
  }
};





int main(){
  Matrix<int>B;
  Matrix<int>A(2, 2);
  Matrix<int>C(A);
  cout << C.get_width() << " getter shiriny\n";
  cout << C.get_length() << " getter dliny\n";
  cout << C.get_array()[0][0] << " getter matrix\n";
  B.set_width_length(2, 2);
  cout << B.get_width() << " " << B.get_length() << "setter dliny i shiriny\n";
  cin >> A >> B;
  cout << "operator >> \n";
  cout << B[0][0] << " operator [ ]\n";
  C = A + B;
  cout <<C<< " operator +\n";
  C = A - B;
  cout << C << "operator -\n";
  cout << A*B << " operator *\n";
  cout << (A == B) << " operator ==\n";
  Vector<float>G;
  Vector<float>H(5);
  Vector<float>I(H);
  cout << H << " operator <<\n";
  cout << H.get_vector()[0]<<" getter vector\n";
  cout << H[0] << " operator [ ]\n";
  G.set_length(5);
  cin >> G;
  cin >> H;
  cout << H / G << " operator /\n";
  I = G+H;
  cout << G*H << " operator *\n";
  cout << I;
  Vector<int>K(10000);
  cout << BubbleSort(K) << endl;
  cout << InsertionSort(K) << endl;
  cout << QuickSort(K,0, K.get_length() - 1)<<endl;
  Matrix <int> P(1, 2);
  P[0][0] = 1;
  cout << P[0][0];
  return 0;
}