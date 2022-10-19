#include<bits/stdc++.h>
using namespace std;
#define max 100000
int nextv1[max];
int nextVal[max];

// Firstly, We should know how to find the longest prefix and the longest suffix which are equal to each other

// We need to use two pointers to check the prefix and the suffix of a string

// If the prefix and the suffix are equal, then we go forward until the first element that makes the prefix and the suffix are not equal appears.

// We call the first pointer 'j' to check the suffix and the second pointer 'k' to check the prefix.

// And we need an array to record the position 'k' should return to when the prefix and the suffix are not equal to each other.
// One tip is that the position of 'k' is firstly recorded as '-1' because if the 'j' suffix is not equal to the 'k' prefix, 'k' will return to the beginning

// What's more, if the length of the string is one, there will be no prefix and suffix, thus we return '-1' to tell you it's wrong.

int CalcLCT(char pattern[])
{
  if(strlen(pattern) == 1) return -1;
  int j = 0;
  nextv1[0] = -1;
  int k = nextv1[0];
  
  while(j < strlen(pattern)){
    if(k == -1 || pattern[j] == pattern[k]){
      j++; k++;
      nextv1[j] = k;
    }else{
      k = nextv1[k];
    }
  }
  return nextv1[strlen(pattern)];
}

// Better the algrothim of nextv1 array to return a whole new array called nextVal
void CalcNextVal(char pattern[], int nxtVal[])
{
    int i = 0, j = -1;
    nxtVal[i] = j;
    int length = strlen(pattern);

    while(i < length){

        if(j == -1 || pattern[i] == pattern[j]){
            i++; j++;

            if(pattern[i] == pattern[j])
                nxtVal[i] = nxtVal[j];
            else
                nxtVal[i] = j;
            
        }else{
            j = nxtVal[j];
        }
        
    }

}

// The true usage of the kmp algrothim
int Find_Pos_With_KMP(char ori[], char pattern[], int nextval[])
{
    int k = 0, j = 0;
    int lo = strlen(ori), lp = strlen(pattern);
    while(k < lo && j < lp){
        if(ori[k] == pattern[j] || j == -1){
            k++; j++;
        }else{
            j = nextval[j];
        }
    }
    if(j > lp){
        return k - lp;
    }else 
        return -1;
}
