# include <eigen3/Eigen/Eigen>
# include <iostream>

int main() {
  // 单位矩阵
   Eigen::Matrix4f model = Eigen::Matrix4f::Identity();
   std::cout << "model is:" << std::endl << model << std::endl;

   Eigen::Matrix4f model1 {
     {1, 0, 0, 0},
     {0, 2, 0, 0},
     {0, 0, 3, 0},
     {0, 0, 0, 1}
   };

   std::cout << "model1 is:" << std::endl << model1 << std::endl;
   // 矩阵的逆
   std::cout << "model1 inverse is:" << std::endl << model1.inverse() << std::endl;
   std::cout << "model1 product inverse is:" << std::endl << model1 * model1.inverse() << std::endl;
   // 矩阵的转置
   std::cout << "model1 inverse transpose is:" << std::endl << model1.inverse().transpose() << std::endl;

   Eigen::Vector3f v{1, 2, 3};
   std::cout << "v is:" << std::endl << v << std::endl;
   return 0;
}