# 算法分析与设计

大三上学期选修了《算法分析与设计》这门专业选修课。

这里存放着课程涉及到的、自认为比较有意思的代码实现。

## 1.递归与分治

* full_arrange

  利用分治思想解决一组数的全排列问题。

* binary_search

  经典二分搜索法的非递归实现。有时间把递归的补上。

* chessboard

  棋盘覆盖问题，很有意思，很能体现分治思想。

* merge_sort

  归并排序，时间复杂度O(NlgN)
  简单理解为归并共进行了log2^N次，复杂度O(lgN);每次的时间是N/2到N不等，取决于原始数据的排列，复杂度O(N)，乘起来就是O(NlgN)了。
  写的过程中发现coding技术确实生疏了 ~~光考虑怎么求数组长度就想了半天~~
