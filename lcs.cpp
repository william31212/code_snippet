#include <bits/stdc++.h>

using namespace std;

const int n1 = 10, n2 = 10;
int s1[10+1] = {0, 3, 1, 2, 4, 9, 5, 10, 6, 8, 7};
int s2[10+1] = {0, 4, 7 ,2 ,3 ,10 ,6 ,9 ,1 ,5 ,8};
int length[10+1][10+1];
int preve[10+1][10+1]; // 記錄每一格的的結果是從哪一格而來
int lcs[10];


void print_LCS(int i, int j)
{
    // 第一個或第二個序列為空集合就停止
    if (i == 0 || j == 0) return;
 
    if (preve[i][j] == 0)        // 左上方
    {
        print_LCS(i-1, j-1);
        cout << s1[i];  // 印出LCS的元素
    }
    else if (preve[i][j] == 1)   // 左方
        print_LCS(i, j-1);
    else if (preve[i][j] == 2)   // 上方
        print_LCS(i-1, j);
}
 
void LCS()
{

    for (int i = 0; i <= n1; i++) 
    	length[i][0] = 0;
    for (int j = 0; j <= n2; j++) 
    	length[0][j] = 0;
 
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
            if (s1[i] == s2[j])
            {
                length[i][j] = length[i-1][j-1] + 1;
                preve[i][j] = 0; // 左上方
            }
            else
            {
                if (length[i-1][j] < length[i][j-1])
                {
                    length[i][j] = length[i][j-1];
                    preve[i][j] = 1; // 左方
                }
                else
                {
                    length[i][j] = length[i-1][j];
                    preve[i][j] = 2; // 上方
                }
            }
 
    cout << "LCS的長度是" << length[n1][n2] << '\n';
    cout << "LCS是";
    print_LCS(n1, n2);
    //從right down開始
}




int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	LCS();
	



	return 0;

}