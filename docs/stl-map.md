map的key是有序的, 所以我们可以利用这个特性去做排序.

下面是OpenGL的一段示例代码,  
定义了一个map, 然后往里面添加元素, 再根据key的大小逆序绘制:  

```C++
#include <map>

std::map<float, glm::vec3> sorted;
for (unsigned int i = 0; i < windows.size(); i++)
{
  float distance = glm::length(camera.Position - windows[i]);
  sorted[distance] = windows[i];
}
for (std::map<float, glm::vec3>::reverse_iterator it=sorted.rbegin(); it != sorted.rend(); ++it)  // 注意这里的loop
{
  model = glm::mat4(1.0f);
  model = glm::translate(model, it->second);  // 注意这里取值用的是->second
  shader.setMat4("model", model);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}
```

示例代码:  
<a href="code/stl/stl_map.cpp">map.cpp</a>  
<a href="code/stl/stl_map1.cpp">map1.cpp</a>