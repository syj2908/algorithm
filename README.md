# 算法分析与设计

大三上学期选修了《算法分析与设计》这门专业选修课。

这里存放着课程涉及到的、自认为比较有意思的代码实现。

## 1.递归与分治

* **full_arrange**

  利用分治思想解决一组数的全排列问题。

* **binary_search**

  经典二分搜索法的非递归实现。有时间把递归的补上。

* **chessboard**

  棋盘覆盖问题，很有意思，很能体现分治思想。

* **merge_sort**

  归并排序，时间复杂度O(NlgN)
  简单理解为归并共进行了log2^N次，复杂度O(lgN);每次的时间是N/2到N不等，取决于原始数据的排列，复杂度O(N)，乘起来就是O(NlgN)了。
  写的过程中发现coding技术确实生疏了 ~~光考虑怎么求数组长度就想了半天~~

* **quick_sort**

  快排，时间复杂度为O(NlgN)，当存在许多相同的元素时性能会急剧下降，最差O(N^2).

  和归并排序相比较，归并排序是先化简规模再求解问题，而快排是先求解出一个问题的解（先求出一个枢轴量）再化简规模（根据枢轴量将数组一分为二）。

  快排实现起来比较容易，需要注意指针的范围问题。

* **liner_time_selection**

  线性时间选择，实现起来涉及多个函数的组合，同时在设置分组循环次数的时候容易出差错。

* **big_number_multiplication**

  智障作业题要求实现的代码……随便写的，乱七八糟，当作交个差就完事了。

## 2. 动态规划

* **longest_increment_subsquence**

  最长单调递增子序列问题。

  $O(n^2)$算法：将原序列设为A，将由低到高排序后的原序列设为B，则求最长单调递增子序列的问题就转化为了求AB的最长公共子序列，按照教材的算法得知其时间复杂度为$O(n^2)$。

  $O(nlogn)$算法：建立一个长度为n的数组tail，$tail[i]$用来存放长度为i+1的最长单调递增子序列的最小末位数，通过维护这个数组来求得最长单调递增子序列及其对应的长度。初始情况下该数组为空，当插入一个数时，如果它大于tail中所有的数，那么直接将他放到所有数字的后面，LIS的长度+1；如果它小于等于所有的数，那么就查找tail中比它大的最小的那个数（或者找到了和它相等的数），并用这个待插入的数替换，LIS长度不变。查找可用二分查找，时间复杂度为$O(logn)$，最坏情况下n个数每个数都要查找一遍，因此整个算法的时间复杂度为$O(nlogn)$。

  这里使用后者实现的。

* **beautiful_print**

  漂亮打印问题。

  k个英文单词最漂亮=$\begin{cases}(k-1)个单词最漂亮+空格+第k个单词\\(k-1)个单词最漂亮+换行+第k个单词\end{cases}$

  将问题按行考虑，有$c[j]=min\{c[i-1]+lc[i,j]\}$

  即以第j个单词为结尾的漂亮打印等于以第i-1个单词为结尾的漂亮打印加上第i个单词到第j个单词放在一行产生的空格数。

  根据上面的推导式，我们发现这个问题具有最优子结构，并且有重叠子问题。

  因此我们自底向上，从第一个单词开始逐个插入单词，保证每行剩余空格数最少，直到将n个单词全部插入进去，所得的方案即为所求。

* **ackerman**

  空间复杂度为O(m)的动规方法求解阿克曼函数。

  $A(i,ind[i])=val[i]$

  通过Ackerman函数的定义我们可以发现：

  * $A(0,n)=n+1$是所有迭代的基础；
  * 当$A(m,1)=val$时，有$A(m+1,0)=val$；
  * 当$A(m,val_2)=val_1$时，有$A(m+1,n+1)=val_1$。这也说明了$A(m+1,n+1)$的值已经包含了$A(m+1,n)$的部分，因此我们可以通过不断更新$ind[i]$和$val[i]$的值来减少使用空间。

  因此，我们可以从$A(0,n)=n+1$入手，令$i$从1遍历到$n$，每次更新$ind$和$val$的值，直到$ind[i]=n$，这时$A(i,n)$的值已经求出，$val[m]$的值就是$A(m,n)$的值。

## 3. 贪心算法



## 4.回溯法

* TSP&TSP_2

	旅行商问题，都是课本上的课后习题，两份代码的区别主要是限界函数不同



## Extra：实验题目

《算法设计与分析》的实验题目

## 1.递归与分治：带权中位数

> 编写一个算法，能够在最坏情况下用O(n)时间找出n个元素的带权中位数。

对应代码：`mid_number_with_value.cpp`

## 2. 动态规划：钢条切割

> 设有一个长度为L的钢条，在钢条上标有n个位置点(p1,p2....n)。现在需要按钢条上标注的位置将钢条切割为n+1段，假定每次切割所需要的代价与所切割的钢条长度成正比。请编写一个算法，能够确定一个切割方案，使切割的总代价最小。

对应代码：`cut_rod.cpp`、`cut_rod_fil_ver.cpp`

对应输入数据：`exp2_in.txt`

对应输出数据：`exp2_out.txt`

## 3.贪心算法：作业调度

> 有n个作业和m台相同设备，每个作业i可选择一台设备进行加工，加工时间为ti。每台机器一次只能加工一个作业。编写算法，实现对作业的调度，使得n个作业的等待时间和最小。

对应代码：`job_scheduling_fil_ver.cpp`

对应输入数据：`exp3_in.txt`

### 4. 回溯法：互斥集合问题

> 给定1个1000行×20列的O-1矩阵，对于该矩阵的任意1列，其中值为1的元素的数量不超过10%。设有两个非空集合A和B，每个集合由矩阵的若干列组成。集合A和B互斥是指对于矩阵的任意一行，同时满足下列2个条件:1）若A中有一个或多个元素在这一行上的值是1，则B中的元素在这一行全部是0﹔2）若B中有一个或多个元素在这一行上的值是1，则A中的元素在这一行全部是0。请你设计一个算法，找出一对互斥集合A和B，使得A和B包含的列的总数最大。

对应代码：`backtrace.cpp`

对应输入数据：`exp6_in.txt`

## 5. 回溯法：互斥集合问题（三个集合）

> 给定1个1000行×20列的0-1矩阵，对于该矩阵的任意1列，其中值为1的元素的数量不超过10%。设有两个非空集合A和B，每个集合由矩阵的若干列组成。集合A和B互斥是指对于矩阵的任意一行，同时满足下列2个条件∶1）若A中有一个或多个元素在这一行上的值是1，则B中的元素在这一行全部是0﹔2)若B中有一个或多个元素在这一行上的值是1，则A中的元素在这一行全部是0。请你设计一个算法，找出集合A、B和C，满足∶1）A、B、C两两互斥，且2）A、B和C包含的列的总数最大。

对应代码：`backtrace_three.cpp`

对应输入数据：`exp7_in.txt`