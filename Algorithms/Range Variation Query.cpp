#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX 100000
#define INF 1e9

using namespace std;

struct node{
  int minv, maxv;
}

SegmentedTree[4*MAX];

void BuildTree(long long a[], int Vertex, int Left, int Right){
  if (Left == Right)
    SegmentedTree[Vertex].minv = SegmentedTree[Vertex].maxv = a[Left];
  else{
    int Middle = Left + (Right - Left) / 2;
    BuildTree(a, 2*Vertex + 1, Left, Middle);
    BuildTree(a, 2*Vertex + 2, Middle+1, Right);
    SegmentedTree[Vertex].minv = min(SegmentedTree[2*Vertex + 1].minv,SegmentedTree[2*Vertex+2].minv);
    SegmentedTree[Vertex].maxv = max(SegmentedTree[2*Vertex + 1].maxv,SegmentedTree[2*Vertex+2].maxv);
      }

}

long long GetMin(int Vertex, int LeftPosition, int RightPosition, int Left, int Right){
  if (Left > Right)
    return INF;
  if ((Left == LeftPosition) && (Right == RightPosition))
    return SegmentedTree[Vertex].minv;
  int Middle = (LeftPosition + RightPosition) / 2;
  return min(GetMin(2*Vertex + 1, LeftPosition, Middle, Left, min(Right,Middle)), GetMin(2*Vertex+2, Middle+1, RightPosition, max(Left,Middle+1),Right));
}
 
long long GetMax(int Vertex, int LeftPosition, int RightPosition, int Left, int Right){
  if (Left > Right)
    return -INF;
  if ((Left == LeftPosition) && (Right == RightPosition))
    return SegmentedTree[Vertex].maxv;
  int Middle = (LeftPosition + RightPosition) / 2;
  return max(GetMax(2*Vertex + 1, LeftPosition, Middle, Left, min(Right,Middle)), GetMax(2*Vertex+2, Middle+1, RightPosition, max(Left,Middle+1),Right));
}

void Update(int Vertex, int LeftPos, int RightPos, int Position, int NewValue){
   if (LeftPos == RightPos)
    SegmentedTree[Vertex].minv = SegmentedTree[Vertex].maxv = NewValue;
  else{
    int Middle = (LeftPos + RightPos) / 2;
    if (Position <= Middle)
      Update (2*Vertex + 1, LeftPos, Middle, Position, NewValue);
    else
      Update (2*Vertex+2, Middle+1, RightPos, Position, NewValue);

    SegmentedTree[Vertex].minv = min(SegmentedTree[2*Vertex + 1].minv,SegmentedTree[2*Vertex+2].minv);
    SegmentedTree[Vertex].maxv = max(SegmentedTree[2*Vertex + 1].maxv,SegmentedTree[2*Vertex+2].maxv);
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

BuildTree(a,1,0,MAX-1);

cin >> k;

while(k--){
  cin >> x >> y;
  if (x > 0) 
    cout << GetMax(1,0,MAX-1,x,y) - GetMin(1,0,MAX-1,x,y) << '\n';
  else
    Update(1,0,MAX-1,-x,y);
          }
}