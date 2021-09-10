# include <eigen3/Eigen/Eigen>
# include <iostream>

int main() {
  // 单位矩阵
   Eigen::Matrix4f model = Eigen::Matrix4f::Identity();
   std::cout << model << std::endl;
   return 0;
}