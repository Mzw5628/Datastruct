# 📚 数据结构学习

## ✧ 顺序表
- **基础顺序表**：ArrayList实现

## ✧ 链表
- **基础链表**：List 实现
- **扩展类型**：
  - 双向链表（doublyList 实现）
  - 循环链表（circleList 实现）

## ✧ 栈
- **实现方式**：基于数组的 Stack 实现

## ✧ 队列
- **实现方式**：基于数组的 Queue 实现

## ✧ 树结构
- **表示方法**：双亲表示法
- **遍历**：先中后遍历,手动维护栈
            完成DFS和BFS,其中DFS为用stack的先序遍历，BFS把栈换成了queue
---

## 🚀 编译与运行

### 分步执行：
```bash
▸ cmake -S . -B build
▸ cmake --build build
▸ ./build/main_exec
```

### 或合并执行：
```bash
▸ cmake -S . -B build && cmake --build build && ./build/main_exec
```