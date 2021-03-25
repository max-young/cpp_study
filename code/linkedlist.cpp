template <class T>
class Node {
  private:
    Node<T> *next; // 指向后继节点的指针
  public:
    T data; // 数据域
    Node(const T& item, Node<T>* next = 0); // 构造函数
    void insertAfter(Node<T> *p); // 在本节点之后插入一个同类节点p
    Node<T> *deleteAfter(); // 删除本节点的后继节点, 并返回此后继节点的地址
    Node<T> *nextNode() const; // 返回后继节点的地址
}

// 构造函数
template <class T>
Node<T>::Node(const T& data, Node<T>* next = 0): data(data), next(next) {}

// 返回后继节点的指针
template <class T>
Node<t>* Node<T>::nextNode() {
  return next;
}

// 返回后继节点的指针
template <class T>
const Node<t>* Node<T>::nextNode() const {
  return next;
}

template <class T>
void Node<T>::insertAfter(Node<T> *p) {
  p->next = next;
  next = p; // 当前节点的指针域指向p
}

template <class T>
Node<T> *Node<T>::deleteAfter(void) {
  Node<T> *tempPtr = next;
  if (next == 0)
    return 0;
  next = tempPtr->next;
  return tempPtr;
}