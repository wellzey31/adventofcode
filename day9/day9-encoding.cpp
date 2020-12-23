#include <bits/stdc++.h>

using namespace std;

bool findPair(int arr[], int arr_size, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr_size; i++)
    {
        int temp = sum - arr[i];

        if (s.find(temp) != s.end())
            return true;

        s.insert(arr[i]);
    }
    return false;
}

vector<int> findContig(int arr[], int count, int goal) {
  vector<int> result;
  int currentsum = 0;
  for (int i = 0; i < count; i++) {
    for (int j = i; j < count; j++) {
      result.push_back(arr[j]);
      currentsum = currentsum + arr[j];
      if (currentsum == goal) {
        cout << "found contiguous subarray" << endl;
        return result;
      } else if (currentsum > goal) {
        result.clear();
        currentsum = 0;
        break;
      }
    }
  }
  cout << "contiguous subarray not found";
  return result;
}

int getPt2(vector<int> result) {
  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 0; i < result.size(); i++) {
    if (result.at(i) <= min) {
      min = result.at(i);
    }
    if (result.at(i) >= max) {
      max = result.at(i);
    }
  }
  return max + min;
}

int main() {

  //create file stream variable and open file
  fstream in;
  in.open("data9.txt");

  //more variables
  int nums[25];
  int contig[1000];
  int count = 0;
  int nextsum, x;
  bool loop = true;

  while (loop) {
    for (int i = 0; i < 25; i++) {
      in >> nextsum;
      nums[i] = nextsum;
      contig[i] = nextsum;
      count++;
    }
    while(loop) {
      in >> nextsum;
      loop = findPair(nums, 25, nextsum);
      //update array contents
      for (int i = 0; i < 24; i++) {
        nums[i] = nums[i+1];
      }
      nums[24] = nextsum;
      contig[count] = nextsum;
      count++;
    }

  }

  in.close();

  cout << "the first sum that is false: " << nextsum << endl;

  vector<int> answer = findContig(contig, count, nextsum);

  cout << "sum of max and min is: " << getPt2(answer) << endl;

  return 0;
}
