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
    for (int i = 0; i < width; i++) delete matrix[i];
    delete matrix;
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
   for (int i = 0; i < width; i++) delete matrix[i];
   delete matrix;
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
   if ((i > width) || (i>length))throw length_error("uncorrect index");
     return matrix[i]; 
 }


 template<class A1>
 Matrix<A1>& Matrix<A1>::operator =(Matrix& lhs){
   
     if (this == &lhs){
       return (*this);
     }
     for (int i = 0; i < width; i++) delete matrix[i];
     delete matrix;
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