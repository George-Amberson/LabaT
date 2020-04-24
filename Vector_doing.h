template <class T1>
T1* Vector<T1>::get_vector()
{
    return get_array()[0];
}



template<class T2>
T2& Vector<T2>::operator [](const int i)
{
  return get_vector()[i];
}

template <class T1>
void Vector<T1>::set_length(int _resize)
{
  set_width_length(1, _resize);
}

template<class F>
Vector<F> operator /(Vector<F>& lhs, Vector<F>& rhs)
{
  
    if (lhs.get_length() != rhs.get_length())throw length_error("Vector's size not equal");
    Vector<F> A(lhs);
    for (int i = 0; i < A.get_length(); i++)
    {
      if (rhs[i] != 0)
      {
        A.get_vector()[i] = A.get_vector()[i] / rhs[i];
      }

    }
    return A;
  
}

template <class Y>
Y operator *(Vector<Y>& lhs, Vector<Y>& rhs)
{
    if (lhs.get_length() != rhs.get_length())throw length_error("Vector's size not equal");
    Y s = 0;
    for (int i = 0; i < rhs.get_length(); i++)s = s + lhs.get_vector()[i] * rhs.get_vector()[i];
    return s;
}
template<class U>
 istream& operator >>(istream& in, Vector<U>& rhs)
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

 template<class P>
 clock_t BubbleSort(Vector<P>& A)
 {
     clock_t t1, t2;
     t1 = clock();
     P tmp = 0;
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

 template<class Q>
 clock_t InsertionSort(Vector<Q>& a)
 {
   
     clock_t t1, t2;
     t1 = clock();
     Q newElement;
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

 template<class K>
 clock_t QuickSort(Vector<K>& p, int first, int last)
 {
   clock_t t1, t2, t3;
   t1 = clock();
   int i = first, j = last;
   K tmp;
   K x = p.get_vector()[(first + last) / 2];

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

