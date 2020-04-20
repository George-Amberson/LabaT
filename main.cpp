#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <time.h>
#include "Matrix.h"
#include "Vector.h"






int main(){
  try{
    Matrix<int>B;
    Matrix<int>A(2, 2);
    Matrix<int>C(A);
    cout << C.get_width() << " getter shiriny\n";
    cout << C.get_length() << " getter dliny\n";
    cout << C.get_array()[0][0] << " getter matrix\n";
   B.set_width_length(1, 1);
   A.set_width_length(1, 1);
    cout << B.get_width() << " " << B.get_length() << "setter dliny i shiriny\n";
    cin >> A >> B;
    cout << "operator >> \n";
    cout << B[0][0] << " operator [ ]\n";
    C = A + B;
    cout << C << " operator +\n";
    C = A - B;
    cout << C << "operator -\n";
    cout << A*B << " operator *\n";
    cout << (A == B) << " operator ==\n";
    Vector<float>G;
    Vector<float>H(5);
    Vector<float>I(H);
    cout << H << " operator <<\n";
    cout << H.get_vector()[0] << " getter vector\n";
    cout << H[0] << " operator [ ]\n";
    G.set_length(5);
    cin >> G;
     cin >> H;
    cout << H / G << " operator /\n";
    I = G + H;
    cout << G*H << " operator *\n";
    cout << I;
    Vector<int>K(10000);
    cout << BubbleSort(K) << endl;
    cout << InsertionSort(K) << endl;
    cout << QuickSort(K, 0, K.get_length() - 1) << endl;
    Matrix <int> P(1, 2);
    P[0][0] = 1;
    cout << P[0][0];
  }
  catch (length_error& a){
    cout << a.what() << endl;
  }
  return 0;
}