#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}

	TreeNode * reConstructBinaryTree(vector<int> pre, int pBegin, int pEnd, vector<int> vin, int vBegin, int vEnd) {
		if (pBegin > pEnd || vBegin > vEnd)
			return NULL;
		if (pBegin == pEnd) {
			TreeNode *tmp;
			tmp = new TreeNode(pre[pBegin]);
			return tmp;
		}
		TreeNode * root;
		root = new TreeNode(pre[pBegin]);
		int right = 0;
		for (int i = vBegin; i <= vEnd;i++) {
			if (vin[i] == root->val) {
				right = i;
				break;
			}
		}
		root->left = reConstructBinaryTree(pre,pBegin+1,pBegin+right-vBegin, vin,vBegin,right-1);
		root->right = reConstructBinaryTree(pre, pBegin + right - vBegin + 1, pEnd, vin, right + 1, vEnd);
		return root;
	}
};

int main()
{
	int a[] = { 1,2,4,7,3,5,6,8 };
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> pre(a,a+8), vin(b,b+8);
	Solution s;
	TreeNode *head = s.reConstructBinaryTree(pre, vin);
	return 0;
}