#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main () {
  fstream in;
  in.open("data6.txt");
  string str;
  int total = 0, groupsum = 0;
  bool loop = true;
  map<char,bool> cmap;
  map<char,bool>::iterator it;
  size_t pos = 0;
  int op = 0;

  string alpha = "abcdefghijklmnopqrstuvwxyz";

  while(getline(in,str)) {
    loop = true;
    while (loop) {
      if(op == 0) {
        for (size_t i = 0; i < str.size(); i++) {
          cmap[str.at(i)] = true;
          op++;
        }
      } else {
        for (auto& x : cmap) {
          pos = str.find(x.first);
          if (pos == string::npos && x.second == true) {
            x.second = false;
          }
        }
      }
      for (auto& x : cmap) {
        cout << x.first;
      }
      cout << endl << endl;
      getline(in, str);
      if (str.empty() || in.eof()) {
        for (auto& x : cmap) {
          if (x.second == true) groupsum++;
        }
        cmap.clear();
        loop = false;
        total = total + groupsum;
        groupsum = 0;
        pos = 0;
        op = 0;
    }
  }
}

  cout << total << endl;

  return 0;
}
