#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits>
#define MAX 100000 + 1

using namespace std;

struct node{
  long long minv, maxv;
}

tree[4*MAX];

void buildtree(int vertex, int left, int right){
  if (left == right) {
    long long i = left + 1;
    tree[vertex].minv = tree[vertex].maxv = (i * i) % 12345 + (i * i * i) % 23456;}
  else{
    int middle = (left + right) / 2;
    buildtree(2 * vertex, left, middle);
    buildtree(2 * vertex + 1, middle + 1, right);
    tree[vertex].minv = min(tree[2 * vertex].minv, tree[2 * vertex + 1].minv);
    tree[vertex].maxv = max(tree[2 * vertex].maxv, tree[2 * vertex + 1].maxv);
      }

}

long long getmin(int vertex, int leftposition, int rightposition, int left, int right){
  if (left > right)
    return std::numeric_limits<long long>::max();
  if ((left == leftposition) && (right == rightposition))
    return tree[vertex].minv;
  int middle = (leftposition + rightposition) / 2;
  return min(getmin(2 * vertex, leftposition, middle, left, min(right, middle)), getmin(2 * vertex + 1, middle + 1, rightposition, max(left, middle + 1), right));
}
 
long long getmax(int vertex, int leftposition, int rightposition, int left, int right){
  if (left > right)
    return -std::numeric_limits<long long>::max();
  if ((left == leftposition) && (right == rightposition))
    return tree[vertex].maxv;
  int middle = (leftposition + rightposition) / 2;
  return max(getmax(2 * vertex, leftposition, middle, left, min(right, middle)), getmax(2 * vertex + 1, middle + 1, rightposition, max(left, middle + 1), right));
}

void update(int vertex, int leftposition, int rightposition, int position, int newvalue){
   if (leftposition == rightposition)
    tree[vertex].minv = tree[vertex].maxv = newvalue;
  else{
    int middle = (leftposition + rightposition) / 2;
    if (position <= middle)
      update (2 * vertex, leftposition, middle, position, newvalue);
    else
      update (2 * vertex + 1, middle + 1, rightposition, position, newvalue);

    tree[vertex].minv = min(tree[2 * vertex].minv,tree[2 * vertex + 1].minv);
    tree[vertex].maxv = max(tree[2 * vertex].maxv,tree[2 * vertex + 1].maxv);
     }
}

int main() {

freopen("rvq.in", "r", stdin);
freopen("rvq.out", "w", stdout);

int k;
int x, y;

buildtree(1, 0, MAX - 1);

cin >> k;

while(k--){
  cin >> x >> y;
  if (x > 0) 
    cout << getmax(1, 0, MAX - 1, x - 1, y - 1) - getmin(1, 0, MAX - 1, x - 1, y - 1) << '\n';
  else
    update(1, 0, MAX - 1, -x - 1, y);
          }
}
