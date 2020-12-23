#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

ifstream file;
file.open("data2.txt");
stringstream ss;
string str;
int passcount = 0;
int charcount = 0;
int x,y;
unsigned i = 0, j = 0;
char pass, c;

//for (int i = 0; i < 10; i++) {
while(!file.eof()) {
  file >> i;
  file.ignore(1);
  file >> j;
  file >> pass;
  file.ignore(1);
  file >> str;
  file.ignore(256, '\n');
  cout << i << " " << j << " " << pass << " " << str << endl;
  if (i == 0) break;
  if ((str.at(i-1) == pass && str.at(j-1) != pass) || (str.at(i-1) != pass && str.at(j-1) == pass)) {
    passcount++;
  }
  i = 0;
  j = 0;
}

file.close();

cout << passcount;

return 0;
}
