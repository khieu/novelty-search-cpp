#ifndef _STATS_H_
#define _STATS_H_

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

float average(vector<float> data);

float range(vector<float> data);

float innerQuartileRange(vector<float> data);

float meanAbsoluteDeviation(vector<float> data);

float variance(vector<float> data);

float standardDeviation(vector<float> data);

float entropy(vector<float> data);

vector<float> normalize(vector<float> data);

#endif

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