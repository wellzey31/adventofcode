#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

//valid if 1920 - 2002
bool validByr(string s) {
  int num = stoi(s);
  //cout << num << endl;
  if (num >= 1920 && num <= 2002) return true;
  return false;
}

bool validIyr(string s) {
  int num = stoi(s);
  //cout << num << endl;
  if (num >= 2010 && num <= 2020) return true;
  return false;
}

bool validEyr(string s) {
  int num = stoi(s);
  //cout << num << endl;
  if (num >= 2020 && num <= 2030) return true;
  return false;
}

bool validHgt(string s) {
  //cout << s << endl;
  int num = stoi(s);
  size_t pos = 0;
  //cout << num << endl;
  pos = s.find("cm");
  if (pos != string::npos) {
    if (num <= 193 && num >= 150) return true;
  }
  pos = s.find("in");
  if (pos != string::npos) {
    if (num <= 76 && num >= 59) return true;
  }
  return false;
}

bool validHcl(string s) {
  //cout << s << endl;
  size_t pos = 0;
  pos = s.find("#");
  if (pos == string::npos) return false;
  for (size_t i = 1; i < s.size(); i++) {
    if (!(isdigit(s.at(i)) || s.at(i) == 'a' || s.at(i) == 'b' || s.at(i) == 'c' || s.at(i) == 'd'
  || s.at(i) == 'e' || s.at(i) == 'f')) {
    return false;
  }
  }
  //cout << "true" << endl;
  return true;
}

bool validEcl(string s) {
  //cout << s << endl;

  //s1 = substr(0,3);
  if (s == "amb" || s == "blu" || s == "brn" || s == "gry" || s == "grn" || s == "hzl" || s == "oth") {
    //cout << "true" << endl;
    return true;
  }
  return false;
}


bool validPid(string s) {
  cout << s << endl;
  bool flag = true;
  if (s.size() < 9) return false;
  for (int i = 0; i < 9; i++) {
     if (!(isdigit(s.at(i)))) {
       flag = false;
     }
  }
  if (s.size() > 9 && ! (s.at(9) == ' ')) return false;
  if (flag == true) cout << "true" << endl;
 return flag;
}


int main () {
  size_t pos = 0;
  int count = 0;
  fstream in;
  string str, str1;
  bool byr, iyr, eyr, hgt, hcl, ecl, pid , br = true;
  in.open("data4.txt");
  while (getline(in, str)) {
  //for (int i = 0; i < 10; i++) {
    //getline(in,str);
    br = true;
    while (br) {
      //cout << str << endl;
      pos = str.find("byr");
      if (pos != string::npos) byr = validByr(str.substr(pos+4,4));
      pos = str.find("iyr");
      if (pos != string::npos) iyr = validIyr(str.substr(pos+4,4));
      pos = str.find("eyr");
      if (pos != string::npos) eyr = validEyr(str.substr(pos+4,4));
      pos = str.find("hgt");
      if (pos != string::npos) hgt = validHgt(str.substr(pos+4,5));
      pos = str.find("hcl");
      if (pos != string::npos) hcl = validHcl(str.substr(pos+4,7));
      pos = str.find("ecl");
      if (pos != string::npos) ecl = validEcl(str.substr(pos+4,3));
      pos = str.find("pid");
      if (pos != string::npos) pid = validPid(str.substr(pos+4));
      getline(in, str);
      if (str.empty() || in.eof()) {
        if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
          count++;
          //cout << count << endl;
        }
        byr = false; iyr = false; eyr = false; hgt = false; hcl = false;
        ecl = false; pid = false; br = false;
      }
    }
    //break;
  }
  in.close();

  cout << count << endl;

return 0;
}
