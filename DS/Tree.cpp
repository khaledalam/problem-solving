#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;

//Auto inc when add new node
int nodesIdx = 0;

struct tree
{
	int value;
	int idx;
	vector<tree*> childs;
};

struct tree* getNewTree(int value)
{
	tree * tmp = new tree;
	tmp->value = value;
	tmp->idx = nodesIdx;
//	tmp->childs.clear();
	return tmp;
}

void insertChild(struct tree * &parent, struct tree * child)
{
	struct tree * tmp = getNewTree(child->value);
	parent->childs.push_back(tmp);
	nodesIdx++;
}

void insertChilds(struct tree * parent, vector<tree*> childs)
{
	for (auto it : childs)
		insertChild(parent, it);
}

struct tree* searchNodeByIndex(struct tree * root, int idx)
{
	if (idx >= nodesIdx)
		return NULL;

	if (root->idx == idx)
		return root;

	for (auto it : root->childs)
	{
		if (it->idx == idx)
			return it;
		searchNodeByIndex(it, idx);
	}
	return NULL;

}

//get first node with given value
struct tree* searchSingleNodeByValue(struct tree* root, int value)
{
	if (root == NULL)
		return NULL;

	if (root->value == value)
		return root;

	for (auto it : root->childs)
	{
		if (it->value == value)
			return it;
		searchSingleNodeByValue(it, value);
	}
	return NULL;
}

void searchMultiNodesByValue(struct tree * root, int value,
		vector<tree*>& results)
{
	if (root == NULL)
		return;
	if (root->value == value)
		results.push_back(root);

	for (auto it : root->childs)
	{
		if (it->value == value)
		{
			results.push_back(it);
			searchMultiNodesByValue(it, value, results);
		}
	}
}

void print(struct tree* root)
{
	cout << "value: " << root->value << " idx: " << root->idx << endl;
	cout << "Childrens: \n[";
	bool firstTime = false;
	int maxLineWidth = 4, width = 0;
	for (auto it : root->childs)
	{
		if (firstTime)
			cout << " , ";
		firstTime = true, width++;
		cout << "(val: " << it->value << ", idx: " << it->idx << ")";
		if (width >= maxLineWidth)
		{
			cout << endl;
			width = 0;
		}
	}
	cout << "]\n\n";
	for (auto it : root->childs)
	{
		print(it);
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	struct tree * root;
	root = getNewTree(-1);
//	cout << root->value << " " << root->idx << endl;

	insertChild(root, getNewTree(0));

	struct tree * base = root;

	vector<tree *> nodes;
	for (int i = 7; i >= 4; --i)
	{
		nodes.push_back(getNewTree(i));
	}

	insertChilds(root, nodes);
	insertChild(root->childs[(int)nodes.size()-1], getNewTree(5));

	print(base);

	(searchNodeByIndex(base, 2)) != NULL ?
			cout << "Found!\n" : cout << "NOT FOUND!\n";

	cout << endl;

	vector<tree *> res;

	searchMultiNodesByValue(base, 5, res);


}
