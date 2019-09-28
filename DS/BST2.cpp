#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2 * 1e5 + 10;
const int inf = (1953125 << 9);

struct node {
	int data;
	struct node* left;
	struct node* right;
	node() {
		data = -INT_MAX;
		left = right = NULL;
	}
};

struct node* newNode(int data) {
	struct node* ret = new node();
	ret->data = data;
	return ret;
}

struct node* insert(struct node* node, int data) {
	if (node == NULL)
		return newNode(data);
	if (node->data >= data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

int size(struct node* node) {
	if (node == NULL || node->data == -INT_MAX)
		return 0;
	return 1 + size(node->left) + size(node->right);
}

int maxDepth(struct node* node) {
	if (node == NULL || node->data == -INT_MAX)
		return 0;
	cout << "N";
	return 1 + max(maxDepth(node->left), maxDepth(node->right));
}

void printInOrder(struct node* node) {
	if (node == NULL)
		return;
	printInOrder(node->left);
	cout << node->data << " ";
	printInOrder(node->right);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	memset(vis, false, sizeof vis);
//	freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	node* root = newNode(2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 5);

	node* p1 = new node();
	node* p2 = new node();
	p1->data = 1;
	p2->data = 2;

//	swap(p1,p2);
	node*& hold = p1;
	swap(hold, p2);

	cout << p1->data << endl;
	cout << p2->data << endl;

//	cout << size(root);
//	cout << maxDepth(new node());
//	printInOrder(root);

}
