#include <iostream>
#include <algorithm>

using namespace std;


class SegmentTree {
public:
	long* tree;
	int s;

	void display() {
		for (int i = 0; i < s * 2; i++)
			cout << tree[i] <<" ";
	}

	SegmentTree(int n) {
		for (s = 1; s < n; s *= 2) {}

		tree = new long[s * 2];
		for (int i = 1; i < s * 2; i++)
			tree[i] = numeric_limits<long>::max();

	};

	void insert(long* d) {
		int d_size = _msize(d) / sizeof(d);
		for (int i = s; i < s + d_size; i++)
			tree[i] = d[i - s];
		for (int i = s - 1; i >= 1; i--)
			tree[i] = min(tree[i * 2], tree[i * 2 + 1]);//여기 수정하면 최소값, 합, 최대값 트리로 변경 가능
	};


	long getMin(int Left, int Right) {
		int l = Left + s - 1, r = Right + s - 1;
		long rval = numeric_limits<long>::max();
		while (l <= r) {
			if (l % 2 == 0) l /= 2;
			else {
				rval = min(rval, tree[l]);
				l = (l / 2) + 1;
			}
			if (r % 2 == 1) r /= 2;
			else {
				rval = min(rval, tree[r]);
				r = (r / 2) - 1;
			}
		}
		return rval;
	};

	long getSum(int Left, int Right) {
		int l = Left + s - 1, r = Right + s - 1;
		long rval = 0;
		while (l <= r) {
			if (l % 2 == 0) l /= 2;
			else {
				rval += tree[l];
				l = (l / 2) + 1;
			}
			if (r % 2 == 1) r /= 2;
			else {
				rval += tree[r];
				r = (r / 2) - 1;
			}
		}
		return rval;
	};

};
int main() {
	int n,m;
	cin >> n;
	SegmentTree T(n);
	long* v = new long[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	T.insert(v);
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << T.getMin(a, b) << endl;
	}
}