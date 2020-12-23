#include <iostream>
#include <fstream>

using namespace std;

int main () {

  ifstream in;
  in.open("data3.txt");
  string str = "";
  int i1 = 0;
  int i2 = 0;
  int i3 = 0;
  int i4 = 0;
  int i5 = 0;
  char t1;
  char t2;
  char t3;
  char t4;
  char t5;
  int treecount1 = 0;
  int treecount2 = 0;
  int treecount3 = 0;
  int treecount4 = 0;
  int treecount5 = 0;
  int s5 = 0;
  long int product = 0;

  while(getline(in, str)) {
  //for (int i = 0; i < 15; i++) {
    //getline(in, str);
    //cout << str << endl;
    t1 = str.at(i1);
    t2 = str.at(i2);
    t3 = str.at(i3);
    t4 = str.at(i4);
    if(s5 % 2 == 0) t5 = str.at(i5);
    //cout << t << endl;
    i1 = (i1 + 1) % str.size();
    i2 = (i2 + 3) % str.size();
    i3 = (i3 + 5) % str.size();
    i4 = (i4 + 7) % str.size();
    if (s5 % 2 == 0) {
      i5 = (i5 + 1) % str.size();
    }
    //cout << index << endl;
    if (t1 == '#') treecount1++;
    if (t2 == '#') treecount2++;
    if (t3 == '#') treecount3++;
    if (t4 == '#') treecount4++;
    if (s5 % 2 == 0)  {
      if (t5 == '#') treecount5++;
    }
    s5++;
    cout << "str.size(): " << str.size() << endl;
    str = "";
  }

  cout << "Treecount1: " << treecount1 << endl;
  cout << "Treecount2: " << treecount2 << endl;
  cout << "Treecount3: " << treecount3 << endl;
  cout << "Treecount4: " << treecount4 << endl;
  cout << "Treecount5: " << treecount5 << endl;

  product = treecount1 * treecount2 * treecount3 * treecount4 * treecount5;

  cout << "Product: " << product << endl;


  return 0;
}
