//Aye this worked and gave me agold star. It runs in max time O(n^2) though

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream file;
  file.open("data.txt");
  int arr[200];
  int count = 0;
  int x, y, n;


  while(file >> n) {
    arr[count] = n;
    count++;
  }
  file.close();

  for (int i = 0; i < 200; i++) {
    for (int j = i+1; j < 200; j++) {
      if (arr[i] + arr[j] == 2020) {
        x = arr[i];
        y = arr[j];
        break;
      }
    }
  }

  cout << x << " + " << y << " = " << x + y << endl;
  cout << "Product: " << x * y << endl;

  return 0;
}
