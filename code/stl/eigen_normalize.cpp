#include <iostream>
#include <eigen3/Eigen/Eigen>

int main(int argc, char const *argv[])
{
  Eigen::Vector2f v{3, 4};
  // 对于向量, norm就是平方和开方
  std::cout << "v norm is " << v.norm() << std::endl;
  // normalize就是把所有元素除以v.norm()(范数)
  v.normalize();
  std::cout << "v is " << v << std::endl;
  // normalized是生成了一个新的Vector2f
  std::cout << "v normalized is " << v.normalized() << std::endl;
  return 0;
}
