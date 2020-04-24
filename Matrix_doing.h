template<class A1>
Matrix<A1>::Matrix(int _a, int _b)
{
  if ((_a < 0) || (_b < 0))
  {
    if (_a < 0) throw length_error("uncorrect width");
    if (_b<0) throw length_error("uncorrect length");
  }
    matrix = new A1*[_a];
    MemorySize(_a, _b);
    for (int i = 0; i < _a; i++)
    {
      for (int j = 0; j < _b; j++)
      {
        matrix[i][j] = 0;
      }
    }
    width = _a;
    length = _b;
}

template <class A2>
Matrix<A2>::Matrix(const Matrix& lhs)
{
    matrix = new A2*[lhs.width];
    MemorySize(lhs.width, lhs.length);
    for (int i = 0; i < lhs.width; i++)
    {
      for (int j = 0; j < lhs.length; j++)
      {
        matrix[i][j] = lhs.matrix[i][j];
      }
    }
    width = lhs.width;
    length = lhs.length;
}

template <class A3>
Matrix<A3>::~Matrix()
{
    for (int i = 0; i < width; i++) delete [] matrix[i];
    delete[] matrix;
}

template<class A1>
int  Matrix<A1>::get_width() const 
{ 
    return width;
}

template <class A2>
 int Matrix<A2>::get_length() const 
{
    return length;
}

 template <class A3>
 A3** Matrix<A3>::get_array()
 {
     return matrix;
 }

 template<class A1>
 void Matrix<A1>::set_width_length(int _width, int _length){
   if ((_width < 0) || (_length < 0))
   {
     if (_width < 0) throw length_error("uncorrect width");
     if (_length <0) throw length_error("uncorrect length");
   }
   Matrix<A1>D(width, length);
   for (int i = 0; i < width; i++){
     for (int j = 0; j < length; j++){
       D.get_array()[i][j] = (*this).get_array()[i][j];
     }
   }
   for (int i = 0; i < width; i++) delete [] matrix[i];
   delete []  matrix;
   width = _width;
   length = _length;
   matrix = new A1*[width];
   for (int i = 0; i < width; i++) matrix[i] = new A1[length];
   for (int i = 0; i < width; i++){
     for (int j = 0; j < length; j++){
       matrix[i][j] = 0;
     }
   }
   int wb = (D.get_width() < width) ? D.get_width() : width;
   int lb = (D.get_length() < length) ? D.get_length() : length;
   for (int i = 0; i < wb; i++){
     for (int j = 0; j < lb; j++){
       matrix[i][j] = D.get_array()[i][j];
     }
   }
 }
 template <class A3>
 A3*& Matrix<A3>::operator[](const int i)
 {
   if ((i > width) || (i>length)||(i<0))throw length_error("uncorrect index");
     return matrix[i]; 
 }


 template<class A1>
 Matrix<A1>& Matrix<A1>::operator =(Matrix& lhs){
   
     if (this == &lhs){
       return (*this);
     }
     for (int i = 0; i < width; i++) delete[] matrix[i];
     delete[] matrix;
     width = lhs.get_width();
     length = lhs.get_length();
     matrix = new A1*[width];
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

 template <class Type>
 Matrix<Type> operator +(Matrix<Type> &lhs, Matrix<Type>&rhs){

   if ((lhs.get_width() != rhs.get_width()) || (lhs.get_length() != rhs.get_length()))throw length_error("matrix size not equal");
   Matrix<Type> A(lhs.get_width(), rhs.get_length());
   for (int i = 0; i < rhs.get_width(); i++)
   {
     for (int j = 0; j < rhs.get_length(); j++)
     {
       A[i][j] = lhs[i][j] + rhs[i][j];
     }
   }
   return A;

 }


 template <class Type>
 Matrix<Type> operator -(Matrix<Type>& lhs, Matrix<Type>& rhs){
   
     if ((lhs.get_width() != rhs.get_width()) || (lhs.get_length() != rhs.get_length()))throw length_error("matrix size not equal");
     Matrix<Type> A(lhs);
     for (int i = 0; i < rhs.get_width(); i++)
     {
       for (int j = 0; j < rhs.get_length(); j++)
       {
         A[i][j] = A[i][j] - rhs[i][j];
       }
     }
     return A;

 }

 template <class E>
 bool operator ==(Matrix<E>&lhs, Matrix<E>& rhs)
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

 template <class F>
 Matrix<F> operator *(Matrix<F>& lhs, Matrix<F>& rhs){
   
     if (lhs.get_length() != rhs.get_width())throw length_error("matrix size uncorrect");
     Matrix<F> C(lhs.get_width(), rhs.get_length());
     F S;
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

 template <class R>
  ostream& operator <<(ostream& out, Matrix<R>& rhs)
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

  template <class K>
   istream& operator >>(istream& in, Matrix<K>& rhs)
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
 