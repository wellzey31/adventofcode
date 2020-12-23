//Aye this worked and gave me agold star. It runs in max time O(n^2) though

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream file;
  file.open("data.txt");
  int arr[200];
  int count = 0;
  int x, y, z, n;


  while(file >> n) {
    arr[count] = n;
    count++;
  }
  file.close();

  for (int i = 0; i < 200; i++) {
    for (int j = i+1; j < 200; j++) {
      for (int k = j+1; k < 200; k++) {
      if (arr[i] + arr[j] + arr[k] == 2020) {
        x = arr[i];
        y = arr[j];
        z = arr[k];
        break;
      }
      }
    }
  }

  cout << x << " + " << y << " + " << z << " = " << x + y + z << endl;
  cout << "Product: " << x * y * z << endl;

  return 0;
}
