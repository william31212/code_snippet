#include <iostream>
#include <cstdio>

using namespace std;

void Perm(char list[], int i, int n){ //list[i] ~ list[n]permutation
    int j;
    if(i == n){
      for (j = 1; j <= n; j++){
        printf("%c ", list[j]);
      }
      printf("\n");
    }
    else{ //i < n
        for(j = i; j <= n; j++){
          swap(list[i], list[j]); //list[j] as head
          printf("first%d %d\n", i, j);

          Perm(list, i+1, n); //list[i+1] ~ list[n] permutation
          printf("second%d %d\n", i, j);
          
          swap(list[i], list[j]); //return to the original list
          printf("third%d %d\n", i, j);
        }
    }
}

int main(int argc, char const *argv[])
{
    char list[4]={' ','a','b','c'};
    Perm(list,1,3);
    return 0;
}
