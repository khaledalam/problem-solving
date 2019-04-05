/*
 * Google Hash Code 2019
 * Authors:
 * - Khaled Alam
 * - Sharaf
 */

#include<bits/stdc++.h>
#include <unordered_set>

using namespace std;
const long long maxn = 5 * 1e1 + 55;
bool vis[maxn];

typedef long long ll;
typedef unsigned long long ul;

template<typename T>
inline T max(const T &x, const T &y) {
	if (x > y)
		return x;
	else
		return y;
}

template<typename T>
inline T min(const T &x, const T &y) {
	if (x < y)
		return x;
	else
		return y;
}

template<typename T>
inline void print_vec(const std::vector<T> &a) {
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}

enum Type {
	H, V
};

//==================================
struct photo {
	int len;
	Type type;
	unordered_set<string> tags;

	// h photo [idx, -1]
	// v photo [idx pic1, idx pic2]
	int idLeft, idRight;

	void setType(char ch) {
		type = ( ch == 'H' ? Type::H : Type::V );
	}
};
//==================================

template<typename T>
void print_photo(T p) {
	for (auto i : p) {
		cout << "type: " << ( i.type == Type::H ? 'H' : 'V' ) << ", n: "
		        << i.len << ", tags: ";
		for (auto j : i.tags)
			cout << j << " ";
		cout << ", photo(s) id(s) : " << i.idLeft << " , " << i.idRight << endl;
	}
}

deque<photo> allPhotos, vPhotos;
deque<photo> allPhotosWithConvertedV; // convert each 2 v pair photos to 1 h photo

inline bool photoCmpLessSize(photo &a, photo & b) {
	return a.len <= b.len;
}
bool photoCmpMoreSize(photo & a, photo & b) {
	return a.len > b.len;
}

photo doCombine(photo &a, photo &b) {
	for (auto &it : b.tags)
		a.tags.insert(it);
	a.len = a.tags.size();
	a.idRight = b.idLeft;
	if (a.idLeft > a.idRight)
		swap(a.idLeft, a.idRight);
	a.type = Type::H;
	return a;

}
vector<photo> combine() {
	vector<photo> ret;

	int soz = vPhotos.size();
	for (int i = 0; i < soz / 2; ++i) {
		ret.push_back(doCombine(vPhotos[i], vPhotos[soz - 1 - i]));
	}
	return ret;

}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	memset(vis, false, sizeof vis);
//	freopen("in/a_example.txt", "r", stdin); freopen("out/a.txt", "w", stdout);
//	freopen("in/b_lovely_landscapes.txt", "r", stdin);	freopen("out/b.txt", "w", stdout);
//	freopen("in/c_memorable_moments.txt", "r", stdin);	freopen("out/c.txt", "w", stdout);
//	freopen("in/d_pet_pictures.txt", "r", stdin); freopen("out/d.txt", "w", stdout);
//	freopen("in/e_shiny_selfies.txt", "r", stdin); freopen("out/e.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		char ch;
		int num_tags;
		photo photo;

		cin >> ch >> num_tags;

		photo.len = num_tags;

		photo.setType(ch);

		char tag[10];
		while (num_tags--) {
			cin >> tag;
			photo.tags.insert(tag);
		}

		photo.idLeft = i, photo.idRight = -1;

		allPhotos.push_back(photo);

		if (photo.type == Type::V)
			vPhotos.push_back(photo);
		else
			allPhotosWithConvertedV.push_back(photo);
	}

//	cout<<"test X"<<endl;

//	sort(vPhotos.begin(), vPhotos.end(), photoCmpLessSize);

//	cout<<"test Y"<<endl;

	vector<photo> combinedVPhotos = combine();

	allPhotosWithConvertedV.insert(allPhotosWithConvertedV.begin(),
	        combinedVPhotos.begin(), combinedVPhotos.end());

	// photos in (allPhotosWithConvertedV) are original H photos + converted V photos
//	print_photo(allPhotosWithConvertedV);

	sort(allPhotosWithConvertedV.begin(), allPhotosWithConvertedV.end(),photoCmpLessSize);



	//output:
	int slidesLen = allPhotosWithConvertedV.size();
	cout << slidesLen << endl;
	for (auto it : allPhotosWithConvertedV) {
		if (it.idRight == -1)
			cout << it.idLeft << endl;
		else
			cout << it.idLeft << " " << it.idRight << endl;
	}

}

