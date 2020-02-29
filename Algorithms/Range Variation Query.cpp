#include <iostream>
#include <limits>
#include <cmath>
#include <cstdio>
#define MAX 100000
using namespace std;

long long tree [4 * MAX];


void build (long long a[], int vertex, int tleft, int tright) {
    if (tleft == tright)
        tree[vertex] = 
    else {
        int tmiddle = (tleft + tright) / 2;
        build (a, vertex * 2, tleft, tmiddle);
        build (a, vertex * 2 + 1, tmiddle + 1, tright);
        tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
    }
}

void update (int vertex, int tleft, int tright, int position, int newvalue) {
	if (tleft == tright)
		tree[vertex] = newvalue;
	else {
		int tmiddle = (tleft + tright) / 2;
		if (position <= tmiddle)
			update (vertex * 2, tleft, tmiddle, position, newvalue);
		else
			update (vertex * 2 + 1, tmiddle + 1, tright, position, newvalue);
		tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
	}
}

long long GetMin(int vertex, int tleft, int tright, int left, int right) {
    if (left > right)
        return std::numeric_limits<int>::max();
    if (left == tleft && right == tright)
        return tree[vertex];
    int tmiddle = (tleft + tright) / 2;

    return min(GetMin(vertex * 2, tleft, tmiddle, left, min(tmiddle, right)), GetMin(vertex * 2 + 1, tmiddle + 1, right, max(tmiddle + 1, left), right));
}

long long GetMax(int vertex, int tleft, int tright, int left, int right){
    if (left > right)
        return -std::numeric_limits<int>::max();
    if (left == tleft && right == tright)
        return tree[vertex];
    int tmiddle = (tleft + tright) / 2;

    return max(GetMax(vertex * 2, tleft, tmiddle, left, min(tmiddle, right)), GetMax(vertex * 2 + 1, tmiddle + 1, right, max(tmiddle + 1, left), right));
}

int main() {

long long a[MAX];
int k;
int x, y;

freopen("rvq.in", "r", stdin);
freopen("rvq.out", "w", stdout);

for (int i = 0; i <= MAX; i++)
    a[i] = (i * i) % 12345 + ((i * i) % 23456 * i) % 23456;


build(a, 1, 0, MAX);
cin >> k;

//for (int i = 0; i < k; i++) {
while (k--)
{
    cin >> x >> y;
    if (x > 0)
        cout << GetMax(1, 0, MAX, x, y) - GetMin(1, 0, MAX, x, y) << '\n';
    else 
        update(1, 0, MAX, -x, y);
}
}