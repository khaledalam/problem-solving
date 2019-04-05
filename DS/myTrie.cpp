#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;

const int ALPH_SIZE = 26;

struct trieNode
{
	struct trieNode * children[ALPH_SIZE];
	bool endOfWord;
};

struct trieNode *getNewNode()
{
	struct trieNode *newNode = new trieNode;
	newNode->endOfWord = false;

	for (int i = 0; i < ALPH_SIZE; ++i)
		newNode->children[i] = NULL;

	return newNode;
}

void insert(struct trieNode* root, string word)
{
	struct trieNode *tmp = root;
	for (int i = 0; i < (int) word.size(); ++i)
	{
		int childIdx = word[i] - 'a';

		if (!tmp->children[childIdx])
			tmp->children[childIdx] = getNewNode();

		tmp = tmp->children[childIdx];
	}
	tmp->endOfWord = true;
}

bool search(struct trieNode* root, string searchText)
{
	struct trieNode *tmp = root;

	for (int i = 0; i < (int) searchText.size(); ++i)
	{
		int childIdx = searchText[i] - 'a';

		if (!tmp->children[childIdx])
			return false;

		tmp = tmp->children[childIdx];
	}
	return (tmp->endOfWord && tmp != NULL);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	struct trieNode *myTrie = getNewNode();

	insert(myTrie, "khaled");
	insert(myTrie, "alam");

	search(myTrie, "khaled") ? cout << "y\n" : cout << "n\n";

	search(myTrie, "text") ? cout << "y\n" : cout << "n\n";

}
