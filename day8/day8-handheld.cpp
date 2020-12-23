#include <bits/stdc++.h>

using namespace std;

bool checkSwap(vector<pair<string, int>> instructions, vector<bool> visited, int x) {
  pair<string, int> mypair;
  mypair = instructions.at(x);
  if (mypair.first == "jmp") {
    mypair.first = "nop";
  } else if (mypair.first == "nop") {
    mypair.first = "jmp";
  }
  instructions[x] = mypair;
  int i = 0;
  while (true) {
    mypair = instructions.at(i);
    visited[i] = true;
    if (mypair.first == "nop") {

    } else if (mypair.first == "acc") {
      //acc = acc + mypair.second;
    } else if (mypair.first == "jmp") {
        i = i + mypair.second;
        if (visited.at(i) != false) {
          //cout << "visited[i] == true at i of: " << i << endl;
          //cout << "previous i value: " << i - mypair.second << endl;
          cout << x << ": " << "false" << endl;
          return false;
          }
    }
    if (mypair.first != "jmp") i++;
    if (i == 648 || i == 649 || i == 647 || i == 646) return true;
  }
  return true;
}

int main() {
  int acc = 0;
  fstream in;
  in.open("data8.txt");
  vector<bool> visited;
  vector<int> vseq;
  vector<pair<string, int>> instructions;
  string str1, str2;
  int num, numtoswap;
  pair<string, int> mypair;
  char c;
  bool loop = true;

  while(!in.eof()) {
    in >> str1 >> str2;
    //cout << str1 << " " << str2 << endl;
    num = stoi(str2);
    instructions.push_back(make_pair(str1, num));
    visited.push_back(false);
  }
  in.close();
  instructions.pop_back();
  visited.pop_back();
  //instructions.at(216) = make_pair("nop", 0);

  for (auto& x : instructions) {
    cout << x.first << " " << x.second << endl;
  }

  cout << "size of instructions: " << instructions.size() << endl;
  cout << "size of visited: " << visited.size() << endl;

  for (int j = 0; j < instructions.size(); j++) {
    if (checkSwap(instructions, visited, j)) {
      numtoswap = j;
      cout << "numtoswap: " << numtoswap << endl;
    }
  }

  mypair = instructions.at(numtoswap);
  if (mypair.first == "jmp") {
    mypair.first = "nop";
  } else if (mypair.first == "nop") {
    mypair.first = "jmp";
  }
  instructions[numtoswap] = mypair;


  int i = 0;
  while (i < 646) {
    vseq.push_back(i);
    mypair = instructions.at(i);
    visited[i] = true;
    if (mypair.first == "nop") {

    } else if (mypair.first == "acc") {
      acc = acc + mypair.second;
    } else if (mypair.first == "jmp") {
        i = i + mypair.second;
        if (visited.at(i) != false) {
          cout << "visited[i] == true at i of: " << i << endl;
          cout << "previous i value: " << i - mypair.second << endl;
          }
    }
    if (mypair.first != "jmp") i++;
  }

  for (auto& x : vseq) {
    cout << x << " ";
  }

  cout << "value of accumulator: " << acc;

  return 0;
}
