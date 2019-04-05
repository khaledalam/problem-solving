#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;

struct node
{
	int value;
	struct node * next;
};

struct node * getNewNode(int value)
{
	struct node * newNode = new node;
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void walk(struct node * root)
{
	while (root != NULL)
	{
		cout << root->value;
		if (root->next != NULL)cout << " -> ";
		root = root->next;
	}
}

bool search(struct node* root, int value)
{
	if (root == NULL)return false;
	while (root != NULL)
	{
		if (root->value == value)return true;;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	struct node * root = NULL;

	root = getNewNode(0);
	struct node * base = root;
	for (auto it : vector<int> { 1, 2, 3, 4, 5, 6 })
	{
		root->next = getNewNode(it);
		root = root->next;
	}

	walk(base);
}
