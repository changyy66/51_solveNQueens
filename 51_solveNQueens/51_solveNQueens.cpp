// 51_solveNQueens.cpp : 定义控制台应用程序的入口点。
//
/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
[".Q..",  // 解法 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // 解法 2
"Q...",
"...Q",
".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int NUM = 0;
bool can(vector<int>&cols, vector<int>&z, vector<int>&f,int i,int j,int n)
{
	if (cols[j]||z[i-j+n]||f[i+j])
	{
		return false;
	}
	return true;
}

// bool NQueens(vector<vector<string>>&res, vector<string >&v,vector<int>&cols,vector<int>&z,vector<int>&f, int row,int n)
// {
// 	if (row == n)
// 	{
// 		res.push_back(v);
// 		return true;
// 	}
// 	for (int i=0;i<n;i++)
// 	{
// 		if (can(cols,z,f,row,i,n))
// 		{
// 			cols[i] = row + 1;
// 			z[row - i + n] = row + 1;
// 			f[row + i] = row + 1;
// 			string s(n,'.');
// 			s[i] = 'Q';
// 			v.push_back(s);
// 			NQueens(res, v, cols,z,f, row + 1, n);
// 			v.pop_back();
// 			cols[i] = 0;
// 			z[row - i + n] = 0;
// 			f[row + i] = 0;
// 		}
// 	}
// 	return true;
// }

// vector<vector<string>> solveNQueens(int n) {
// 	vector<vector<string>> res;
// 	if (n==1)
// 	{
// 		res.push_back({ "Q" });
// 		return res;
// 	}
// 	if (n < 4)return res;
// 	
// 	vector<string> v;
// 	vector<int> cols(n, 0);
// 	vector<int> z(n * 2, 0);
// 	vector<int> f(n * 2, 0);
// 	NQueens(res, v, cols,z,f, 0, n);
// 	return res;
// }

bool NQueens(vector<int>&cols, vector<int>&z, vector<int>&f, int row, int n)
{
	if (row == n)
	{
		NUM++;
		return true;
	}
	for (int i = 0; i < n; i++)
	{
		if (can(cols, z, f, row, i, n))
		{
			cols[i] = row + 1;
			z[row - i + n] = row + 1;
			f[row + i] = row + 1;
			string s(n, '.');
			s[i] = 'Q';
			NQueens(cols, z, f, row + 1, n);
			cols[i] = 0;
			z[row - i + n] = 0;
			f[row + i] = 0;
		}
	}
	return true;
}

void solveNQueens(int n) {
	
	if (n == 1)
	{
		NUM++;
		return ;
	}
	if (n < 4)return;

	vector<int> cols(n, 0);
	vector<int> z(n * 2, 0);
	vector<int> f(n * 2, 0);
	NQueens(cols, z, f, 0, n);
	return;
}
//51and 52
int main()
{
	for (int i=4;i<20;i++)
	{
		vector<vector<string>> res = solveNQueens(i);
		cout << res.size()<<endl;
	}
	
// 	for (auto item:res)
// 	{
// 		for (auto it:item)
// 		{
// 			cout << it << endl;
// 		}
// 		cout << "----------------" << endl;
// 	}
    return 0;
}

