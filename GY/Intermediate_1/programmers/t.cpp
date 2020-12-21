#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> arr;

void small(vector<int> a, bool check, int k){
   if(k != -1)
      a.erase(a.begin()+k);
   int size = a.size();
   
   if(size == 1) {
      int m = a[0];
      arr.push_back(m);
      return;
   }
   for(int i = 0; i < size-1; i++) {
      if(a[i] > a[i+1]){
         if(check){
            k = i+1;
//            a.erase(a.begin()+i+1);
            check = false;
            small(a, check, k);
            check = true;
//            a.assign(vec.begin(), vec.end());
         }
         k = i;
//         a.erase(a.begin()+i);
         small(a, check, k);
//         a.assign(vec.begin(), vec.end());
      }
      
      else {
         if(check){
            k = i;
//            a.erase(a.begin()+i);
            check = false;
            small(a, check, k);
//            a.assign(vec.begin(), vec.end());
            check = true;
            
         }
         k = i +1;
//         a.erase(a.begin()+i+1);
         small(a, check, k);
//         a.assign(vec.begin(), vec.end());
      }
   }
   return;
}


int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    
//    for(int i = 0; i < size-1; i++) {
//       int start, end;
//       
//   }
    
    small(a, true, -1);
    
    sort(arr.begin(), arr.end());
   arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    answer = arr.size();
    
    for(int i = 0; i < answer; i++) {
       cout << arr[i] << endl;
   }
    
    return answer;
}

int main(void) {
   int N, a;
   cin >> N;
   vector<int> arr;
   
   for(int i = 0; i < N; i++) {
      cin >> a;
      arr.push_back(a);
   }   
   
   solution(arr);
   
   
   return 0;
}