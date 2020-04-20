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
