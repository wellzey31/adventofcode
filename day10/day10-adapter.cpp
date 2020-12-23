#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int* findAdapters(vector<int> v, int &dif1, int &dif3) {
  int size = v.size()+1;
  int* arr = new int[size+1];
  arr[0] = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) == arr[i] +1) {
      arr[i+1] = v.at(i);
      dif1++;
    } else if (v.at(i) == arr[i]+3) {
      arr[i+1] = v.at(i);
      dif3++;
    }
  }

  return arr;
}

int main() {
  fstream in;
  in.open("data10.txt");

  int nextnum, dif1 = 0, dif3 = 0;
  vector<int> v;

  while(in >> nextnum) {
    v.push_back(nextnum);
  }

  sort(v.begin(),v.end());

  for (auto x : v) {
    cout << x << " ";
  }

  cout << endl;

  int* result = findAdapters(v, dif1, dif3);

  cout << "dif1: " << dif1 << endl;
  cout << "dif3: " << dif3 << endl;
  cout << "dif1 * dif3 = " << dif1 * dif3 << endl;

  for (int i = 0; i < v.size()+1; i++) {
    cout << result[i] << " ";
  }

  return 0;
}
