#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX 100000
#define INF 1e9

using namespace std;

struct node{
  int minv, maxv;
}

tree[4*MAX];

void buildtree(long long a[], int vertex, int left, int right){
  if (left == right)
    tree[vertex].minv = tree[vertex].maxv = a[left];
  else{
    int middle = left + (right - left) / 2;
    buildtree(a, 2 * vertex + 1, left, middle);
    buildtree(a, 2 * vertex + 2, middle + 1, right);
    tree[vertex].minv = min(tree[2 * vertex + 1].minv, tree[2 * vertex + 2].minv);
    tree[vertex].maxv = max(tree[2 * vertex + 1].maxv, tree[2 * vertex + 2].maxv);
      }

}

long long getmin(int vertex, int leftposition, int rightposition, int left, int right){
  if (left > right)
    return INF;
  if ((left == leftposition) && (right == rightposition))
    return tree[vertex].minv;
  int middle = (leftposition + rightposition) / 2;
  return min(getmin(2 * vertex + 1, leftposition, middle, left, min(right, middle)), getmin(2 * vertex + 2, middle + 1, rightposition, max(left, middle + 1), right));
}
 
long long getmax(int vertex, int leftposition, int rightposition, int left, int right){
  if (left > right)
    return -INF;
  if ((left == leftposition) && (right == rightposition))
    return tree[vertex].maxv;
  int middle = (leftposition + rightposition) / 2;
  return max(getmax(2 * vertex + 1, leftposition, middle, left, min(right, middle)), getmax(2 * vertex + 2, middle + 1, rightposition, max(left, middle+1), right));
}

void update(int vertex, int leftposition, int rightposition, int position, int newvalue){
   if (leftposition == rightposition)
    tree[vertex].minv = tree[vertex].maxv = newvalue;
  else{
    int middle = (leftposition + rightposition) / 2;
    if (position <= middle)
      update (2 * vertex + 1, leftposition, middle, position, newvalue);
    else
      update (2 * vertex + 2, middle + 1, rightposition, position, newvalue);

    tree[vertex].minv = min(tree[2 * vertex + 1].minv,tree[2 * vertex + 2].minv);
    tree[vertex].maxv = max(tree[2 * vertex + 1].maxv,tree[2 * vertex + 2].maxv);
     }
}

int main() {

freopen("rvq.in", "r", stdin);
freopen("rvq.out", "w", stdout);

long long a[MAX + 1];
int k;
int x, y;

for(int i = 0; i <= MAX; i++)
  a[i] = (i * i) % 12345 + ((i * i) % 23456 * i) % 23456;

buildtree(a,1,0,MAX-1);

cin >> k;

while(k--){
  cin >> x >> y;
  if (x > 0) 
    cout << getmax(1,0,MAX-1,x,y) - getmin(1,0,MAX-1,x,y) << '\n';
  else
    update(1,0,MAX-1,-x,y);
          }
}