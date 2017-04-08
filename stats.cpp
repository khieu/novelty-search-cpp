#include "stats.h"
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

float average(vector<float> data) {
  float avg = 0;
  for (int i = 0; i < data.size(); i++) {
    avg += data[i];
  }

  avg = avg/data.size();
  return avg;
}


float range(vector<float> data) {
  // find max in array
  float max = data[0];
  for (int i = 0; i < data.size(); i++) {
    if (data[i] > max) {
      max = data[i];
    } 
  }
  // find min in array
  float min = data[0];
  for (int i = 0; i < data.size(); i++) {
    if (data[i] < min) {
      min = data[i];
    } 
  }
  // return max - min
  return (float) (max - min);
}

float innerQuartileRange(vector<float> data) {
  float q1,q3;
  //sort data
  std::sort(data.begin(), data.end());
  // find median
  int halfSize = (int) data.size()/2;
  // find q1, q3
  if (halfSize % 2 == 1) {
    q1 = data[(int) halfSize/2];
    q3 = data[data.size() - ((int) halfSize/2)-1];
  } else {
    q1 = (data[(int) halfSize/2] + data[(int) halfSize/2 - 1] )/ 2 ;
    q3 = (data[data.size() - (int) halfSize/2] + data[data.size() - 1 - (int) halfSize/2])/2;
  }
  // return
  return q3 - q1;
}

float meanAbsoluteDeviation(vector<float> data) {
  float avg = average(data), mad = 0;

  for (int i = 0; i < data.size(); i++) {
    mad += abs(data[i] - avg);
  }
  mad = mad/data.size();

  return mad;
}

float variance(vector<float> data) {
  float avg = average(data), variance = 0;

  for (int i = 0; i < data.size(); i++) {
    variance += pow((data[i] - avg), 2);
  }
  variance = (float) variance / data.size();
  return variance;
}

float standardDeviation(vector<float> data) {
  float vrnc = variance(data);
  float stdDeviation = sqrt(vrnc);
  return stdDeviation;
}

float entropy(vector<float> data) {
  // calculate # of appearance of each point in the data vector
  map<float, float> count;
  for (int i = 0; i < data.size(); i++) {
    if (count.find(data[i]) == count.end()) {
      count.insert(pair<float, float>(data[i],1));
    } else {
      map<float,float>::iterator it = count.find(data[i]);
      it->second = it->second + 1;
    }
  }
  int size = data.size();
  // calculate probability
  for (auto& it : count) {
    it.second = it.second/size;
  }
  // calculate info entropy
  float sum = 0;
  for (auto& it : count) {
    float pi = it.second;
    sum += pi*log2(pi);
  }
  sum = -sum;

  return sum;
}

vector<float> normalize(vector<float> data) {
  // calculating the sum of all elems in data vector
  float sum = 0;
  for (auto& val : data) {
    sum += val;
  }

  // normalize by dividing each element by the sum
  vector<float> norm;
  for (auto& val : data) {
    norm.push_back(val/sum);
  }
  return norm;
}

// int main( int argc, const char* argv[] )
// {
//   printf( "\nHello World\n\n" );
//   vector<float> data = {1,2,25,3,5,6,3,4, 12, 18};
//   float x = innerQuartileRange(data);
//   cout << x << endl;
//   vector<float> x1 = {2,2,4,4};
//   vector<float> x2 = {1,1,6,4};
//   cout << meanAbsoluteDeviation(x1) << endl;
//   cout << meanAbsoluteDeviation(x2) << endl;
//   vector<float> x3 = {2,4,4,4,5,5,7,9};
//   float vrnc = variance(x3);
//   float stdDeviation = standardDeviation(x3);
//   cout << vrnc << endl;
//   cout << stdDeviation << endl;
//   vector<float> x4 = {1,1,2,3};
//   cout << entropy(x4) << endl;
//   vector<float> x5 = {1,2,3,4};
//   x5 = normalize(x5);
//   for (auto& val : x5) {
//     cout << val << endl;
//   }

// }