#include <stdio.h>
#include <iostream>

using namespace std;

void output(int input[], int len)
{
    for(int i=0; i<len; i++){
    cout << input[i] << ";";
  }
}

void insertionSort(int input[], int len){

  int i, key, j;
  for(i=1; i<len; i++){
    key = input[i];
    j = i-1;

    while(j >= 0 && input[j] > key){
      input[j+1] = input[j];
      j = j-1;
    }
    input[j+1] = key;

    output(input, i+1);
    cout << endl;
  }
}


int main (int argc, char *argv[])
{
  int len = 0;
  cin >> len;

  int input[len];

  for(int i = 0; i<len; i++){
    cin >> input[i];
  }

  insertionSort(input, len);
}
