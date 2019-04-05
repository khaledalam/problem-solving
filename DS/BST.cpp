#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;

struct node
{
	int value;
	struct node * left, *right;
};

struct node *getNewNode(int value)
{
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	tmp->value = value;
	tmp->left = tmp->right = NULL;
	return tmp;
}

struct node* insert(struct node *root, int value)
{
	if (root == NULL)
		return getNewNode(value);

	if (value > root->value)
		root->right = insert(root->right, value);
	else if (value < root->value)
		root->left = insert(root->left, value);

	return root;
}

bool search(struct node *root, int value)
{
	while (root != NULL)
	{
		if (value < root->value)
		{
			root = root->left;
		} else if (value > root->value)
		{
			root = root->right;
		} else
		{
			return true;
		}
	}
	return false;
}

void print(struct node * root)
{

	if (root == NULL)
		return;
	cout << root->value << endl;

	print(root->right);
	print(root->left);

}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	struct node *root = NULL;

	root = insert(root, 9);
	insert(root, 4);
	insert(root, 1);
	insert(root, 7);

	search(root, 8) ? cout << "Yes\n" : cout << "No\n";

	print(root);

}
