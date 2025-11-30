using namespace std;
enum eState {
SpiralAbove,
SpiralRight,
SpiralBelow,
SpiralLeft,
};
vector<int> spiralTraverse (vector<vector<int>> array) {
int n = array.size();
int m = array.back().size();
vector<int> res(n*m);
  int i = 0, j = 0;
int i_LimitLow = 0, i_LimitUp = n-1;
int j_LimitLow = 0, j_LimitUp = m-1;
eState state = SpiralAbove;
for (int& seq: res) {
seq = array[i][j];
// Check if we need to change the state and update the limit
if (state == SpiralAbove && j == j_LimitUp) {
state = SpiralRight;
i_LimitLow++;
}
if (state == SpiralRight && i == i_LimitUp) {
state = SpiralBelow;
j_LimitUp--;
}
if (state == SpiralBelow && j == j_LimitLow) {
state = SpiralLeft;
i_LimitUp--;
}
if (state == SpiralLeft && i == i_LimitLow) {
state = SpiralAbove;
j_LimitLow++;
}
// Update indices based on the current state
if (state == SpiralAbove) { j++; }
if (state == SpiralRight) { i++; }
if (state == SpiralBelow) { j--; }
if (state == SpiralLeft) { i--; }
}

  return res;
}