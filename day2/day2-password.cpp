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
char pass, c;

//for (int i = 0; i < 5; i++) {
while(!file.eof()) {
  file >> x;
  file.ignore(1);
  file >> y;
  file >> pass;
  file.ignore(1);
  file >> str;
  file.ignore(256, '\n');
  //cout << x << " " << y << " " << pass << " " << str << endl;


  for (unsigned i = 0; i < str.length(); i++) {
    if (str.at(i) == pass) {
      charcount++;
    }
  }
  //cout << "charcount " << charcount << endl;
  if (charcount >= x && charcount <= y) {
    passcount++;
  }
  charcount = 0;
}
file.close();

cout << passcount;

return 0;
}
