#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <time.h>
#include "Matrix.h"
#include "Vector.h"
#include <vector>

int main(){
  try{
    /*Matrix<int>B;
    Matrix<int>A(2, 2);
    Matrix<int>C(2,2);
    //---------------------------------------------------------------------------
    cout << C.get_width() << " getter shiriny\n";
    cout << C.get_length() << " getter dliny\n";
    cout << C.get_array()[0][0] << " getter matrix\n";
    //---------------------------------------------------------------------------
    B.set_width_length(1, 1);
    A.set_width_length(1, 1);
    cout << B.get_width() << " " << B.get_length() << "setter dliny i shiriny\n";
    //---------------------------------------------------------------------------
    //cin >> A >> B;
    cout << "operator >> \n";
    cout << B[0][0] << " operator [ ]\n";
    //---------------------------------------------------------------------------
    C = A + B;
    cout << C << " operator +\n";
    C = A - B;
    cout << C << "operator -\n";
    cout << A*B << " operator *\n";
    cout << (A == B) << " operator ==\n";
    //---------------------------------------------------------------------------
    Vector<float>G(5);
    Vector<float>H(5);
    Vector<float>I(H);
    A.set_width_length(3, 3);
    Vector<float> L(3);
    Matrix<float>s(3, 3);
    //---------------------------------------------------------------------------
   cout << H << " operator <<\n";
    cout << H.get_vector()[0] << " getter vector\n";
    cout << H[0] << " operator [ ]\n";
    G.set_length(5);
    //---------------------------------------------------------------------------
   //cin >> G;
   //cin >> H;
   cout << H / G << " operator /\n";
   I= G + H;
   G.set_length(3);
   L = s*L;
   float p = G*H;
    cout << I;
    Vector<int>K(10000);
    In_Vector(K);
    cout << BubbleSort(K) << endl;
    cout << InsertionSort(K) << endl;
    cout << QuickSort(K, 0, K.get_length() - 1) << endl;
    Matrix <int> P(1, 2);
    P[0][0] = 1;
    cout << P[0][0];/*/

    //------------------------------------------------------------------------------
    cout << "QuickSort"<<endl;
    vector<double> A(3);
    Vector<int>Z(1000);
    Matrix<int>N(1000, 1000);
    int j = 0;
    for (int i = 100000; j< 3; i *= 2){
      Z.set_length(i);
      In_Vector(Z);
      clock_t start = clock();
      QuickSort(Z,0,Z.get_length()-1);
      clock_t end = clock();
      A[j] = (double)(end - start) / CLOCKS_PER_SEC;
      j++;
    }
    for (int i = 0; i < 3; i++){
      cout << A[i] << endl;
    }
    

  }
  catch (length_error& a){
    cout << a.what() << endl;
  }
  return 0;
}