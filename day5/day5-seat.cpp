#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getRow(string s) {
  int row = 0;
  if (s.at(6) == 'B') row = row+1;
  if (s.at(5) == 'B') row = row+2;
  if (s.at(4) == 'B') row = row+4;
  if (s.at(3) == 'B') row = row+8;
  if (s.at(2) == 'B') row = row+16;
  if (s.at(1) == 'B') row = row+32;
  if (s.at(0) == 'B') row = row+64;
  return row;
}

int getCol(string s) {
  int col = 0;
  if (s.at(9) == 'R') col = col+1;
  if (s.at(8) == 'R') col = col+2;
  if (s.at(7) == 'R') col = col+4;
  return col;
}

int main() {
  int seats[1016];
  for (auto& x : seats) {
    x = 0;
  }
  int id = 0, maxid = 0;
  fstream in;
  in.open("data5.txt");
  string str;

  while(getline(in, str)) {
    id = getRow(str) * 8 + getCol(str);
    seats[id] = 1;
    if (id >= maxid) maxid = id;
  }
  in.close();

  cout << "maxid: " << maxid << endl;
  for (int i = 0; i < 1016; i++) {
    if (seats[i] == 0 && seats[i-1] == 1 && seats[i+1] == 1) {
      cout << "seat id: " << i << endl;
    }
  }

  return 0;
}
