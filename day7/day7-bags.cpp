#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main() {
  string bag, str;
  ifstream in;
  map<string, list<string>> adj;
  size_t pos = 0, pos1 = 0, pos2 = 0;

  in.open("data7.txt");

  while(getline(in, str)) {
    while(pos != string::npos) {
      pos = str.find(" bag");
      cout << str.substr(0,pos) << endl;
      pos = str.find("contain");
      pos = pos = str.find(" bag", pos);
    }
  }

  in.close();


  return 0;
}
