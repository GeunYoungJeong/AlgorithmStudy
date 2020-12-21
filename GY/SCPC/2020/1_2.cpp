#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(void) {
   int A[200000] = {0, };
   int B[200000] = {0, };
   int n;
   cin >> n;
   
   for(int i = 0; i < n; i++) {
      cin >> A[i];
   }
   
   for(int i = 0; i < n; i++) {
      cin >> B[i];
   }
   
   sort(A, A+n);
   sort(B, B+n);
   
   int maximum = 0;
   int total = 0;
   
   for(int i = 0; i < n; i++) {
      int sub = abs(A[i] - B[i]);
      total += sub;      
      maximum = max(maximum, abs(A[i] - B[i]));
   }
   
   total -= maximum;
   
   cout << total << endl;
   
   return 0;
}