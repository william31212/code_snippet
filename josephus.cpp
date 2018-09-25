#include <bits/stdc++.h>
#define LEN 41
#define STEP 3

void josephus(int*, int, int);
int next(int*, int, int, int);
int winner(int, int);

int main(void) { 
    int man[LEN] = {0}; 
    josephus(man, LEN, STEP);

    printf("約琴夫排列："); 
    int i;
    for(i = 0; i < LEN; i++) {
        printf("%d ", man[i]); 
    }
    printf("\nWinner: %d", winner(LEN, STEP));

    return 0; 
} 

void josephus(int* man, int len, int k) {
    int i, n;
    for(i = 1, n = -1; i <= len; i++) {
        n = next(man, len, k, n);
        man[n] = i;
    }
}

int next(int* man, int len, int k, int n) {
    int count = 0;
    while(count < k) {
        n = (n + 1) % len;
        if(man[n] == 0) { count++; }
    }    
    return n;
}

int winner(int len, int k) {
    int g, n;
    for(g = 0, n = 1; n <= len; n++) {
        g = (g + k) % n;
    }
    return g + 1;
}