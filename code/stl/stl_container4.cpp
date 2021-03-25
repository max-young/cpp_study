# include <queue>
# include <iostream>
# include <stdlib.h>
# include <time.h>

using namespace std;

const int SPLIT_TIME_MIN = 500; // 细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000; // 细胞分裂最长时间

class Cell;
priority_queue<Cell> cellQueue;

// 细胞类
class Cell {
  private:
    static int count; // 细胞总数
    int id; // 当前细胞编号
    int time; // 细胞分裂时间
  public:
    Cell(int birth): id(count++) { //birth为细胞诞生时间
      // 初始化, 确定细胞分裂时间
      time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
    }
    int getId() const {return id;} // 得到细胞编号
    int getSplitTime() const {return time;} // 得到细胞分裂时间
    bool operator < (const Cell& s) const { // 定义“<”
      return time > s.time;
    }
    void split() const { // 细胞分裂
      Cell child1(time), child2(time); // 定义两个子细胞
      cout << time << "s: Cell #" << id << " split to #"
        << child1.getId() << " and #" << child2.getId() << endl;
      cellQueue.push(child1); // 将第一个子细胞压入优先级队列
      cellQueue.push(child2); // 将第二个子细胞压入优先级队列
    }
};

int Cell::count = 0;

int main() {
  srand(static_cast<unsigned>(time(0)));
  int t; // 模拟时间长度
  cout << "Simulation time: ";
  cin >> t;
  cellQueue.push(Cell(0)); // 将第一个细胞压入优先级队列
  while(cellQueue.top().getSplitTime() <= t) {
    cellQueue.top().split(); // 模拟下一个细胞的分裂
    cellQueue.pop(); // 将刚刚分裂的细胞弹出
  }
  queue<int> q;
  q.push(10);
  cout << q.front() << endl;
  cout << q.back() << endl;
  q.emplace(20);
  cout << q.front() << endl;
  cout << q.back() << endl;
  return 0;
}