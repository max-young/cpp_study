# include <eigen3/Eigen/Eigen>
# include <iostream>

int main() {
  // 单位矩阵
   Eigen::Matrix4f model = Eigen::Matrix4f::Identity();
   std::cout << "model is:" << std::endl << model << std::endl;

   Eigen::Matrix4f model1 {
     {1, 0, 0, 0},
     {1, 1.0/3.0, 0, 0},
     {1, 2.0/3.0, 1.0/3.0, 0},
     {1, 1, 1, 1}
   };

   std::cout << "model1 is:" << std::endl << model1 << std::endl;
   // 矩阵的逆
   std::cout << "model1 inverse is:" << std::endl << model1.inverse() << std::endl;
   std::cout << "model1 product inverse is:" << std::endl << model1 * model1.inverse() << std::endl;
   // 矩阵的转置
   std::cout << "model1 transpose is:" << std::endl << model1.transpose() << std::endl;

   Eigen::Vector3f v{1, 2, 3};
   std::cout << "v is:" << std::endl << v << std::endl;
   Eigen::Vector3f v1{3, 4, 5};
   std::cout << "v * 2 is:" << std::endl << v * 2 << std::endl;
   std::cout << "v + v1 is:" << std::endl << v + v1 << std::endl;
   std::cout << "v * v1 is:" << std::endl << v.cwiseProduct(v1) << std::endl;

   Eigen::Vector3f color[] = {
    {0.580392182, 0.474509805, 0.360784322},
    {0.580392182, 0.474509805, 0.360784322},
    {0.580392182, 0.474509805, 0.360784322}
   };
   float alpha = 0.904124438, beta = 0.0731089413, gamma = 0.0227930527;
   Eigen::Vector3f tc = alpha * color[0] + beta * color[1] + gamma * color[2];
   std::cout << "tc is:" << std::endl << tc << std::endl;
   return 0;
}