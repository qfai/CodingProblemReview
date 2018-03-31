# A TO DO LIST for geting a job of machine learning in 6 months

(3 months to get a intern)

## need to do in 3 months

- [ ] A project
- [ ] A competition
- [ ] Implementation of all basic stuff of ONE technic 

## 基本学习思想

- 尽量往图形学方面靠，计算机视觉
- 尽量往deep learning 方向靠

## 目录
- [SVM](#svm)
- [KNN](#knn-k-means-k-medoids)
- [Logistic regression](#lr)
- [贝叶斯](#贝叶斯)
- [梯度下降法](#梯度下降法)
- [KDD](#KDD)
- [python](#python)
- [SVD PCA](#svd pca)
- [基本问题](#基本问题)
- [深度学习](#深度学习)
- [Tensorflow](#tensorflow)
- [计算机视觉](#计算机视觉)
- [生成对抗网络](#生成对抗网络)
- [集成学习](#集成学习)
- [随机森林](#随机森林)
- [XGBoost](#xgboost)
- [Adaboost](#adaboost)
- [判别式模型](#判别式模型)
- [生成模型](#生成模型)
- [面试前](#面试前)


---
- [ ] [理论知识](https://www.zhihu.com/question/62482926)
- ![](http://img.blog.csdn.net/20171214121258504?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2luYXRfMzU1MTIyNDU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
- [ ] 李飞飞课程作业（一个月之内）
- [ ] 借本西瓜书

- [ ] python 3的基本技巧(tomorrow)
- [ ] tensor flow 环境搭好(tomorrow)

### SVM
- [ ] 基本了解
	- [ ] [支持向量机通俗导论（理解SVM的三层境界）](https://www.cnblogs.com/v-July-v/archive/2012/06/01/2539022.html)
	- [ ] 西瓜书
	- [ ] stanford course
	- [ ] [机器学习之深入理解SVM](http://blog.csdn.net/sinat_35512245/article/details/54984251)
- [ ] python 实现
- [ ] 带核的SVM为什么能分类非线性问题？

### KNN, K-MEANS, K-MEDOIDS
- [ ] python 实现
- [ ] [机器学习之深入理解K-means、与KNN算法区别及其代码实现](https://blog.csdn.net/sinat_35512245/article/details/55051306)
- [ ] 优化Kmeans。(KD-TREE, BALL TREE) 用库实现
- [ ] KMeans初始类簇中心点的选取。
- [ ] 在k-means或kNN，我们是用欧氏距离来计算最近的邻居之间的距离。为什么不用曼哈顿距离
	-  曼哈顿距离只计算水平或垂直距离，有维度的限制。另一方面，欧氏距离可用于任何空间的距离计算问题。因为，数据点可以存在于任何空间，欧氏距离是更可行的选择
### LR
- [ ] 西瓜书
- [ ] [机器学习之Logistic回归(逻辑蒂斯回归](http://blog.csdn.net/sinat_35512245/article/details/54881672)
- [ ]把LR从头到脚都给讲一遍。建模，现场数学推导，每种解法的原理，正则化，LR和maxent模型啥关系，LR为啥比线性回归好
- [ ] python实现
- [ ] 读一个开源的实现
- [ ] 工程，并行化怎么做，有几种并行化方式
- [ ] LR和SVM的联系与区别？

联系：
	1. LR和SVM都可以处理分类问题，且一般都用于处理线性二分类问题（在改进的情况下可以处理多分类问题） 
	2. 两个方法都可以增加不同的正则化项，如L1. L2等等。所以在很多实验中，两种算法的结果是很接近的。 

区别： 
	1. LR是参数模型，SVM是非参数模型。 
	2. 从目标函数来看，区别在于逻辑回归采用的是Logistical Loss，SVM采用的是hinge loss.这两个损失函数的目的都是增加对分类影响较大的数据点的权重，减少与分类关系较小的数据点的权重。 
	3. SVM的处理方法是只考虑Support Vectors，也就是和分类最相关的少数点，去学习分类器。而逻辑回归通过非线性映射，大大减小了离分类平面较远的点的权重，相对提升了与分类最相关的数据点的权重。 
	4. 逻辑回归相对来说模型更简单，好理解，特别是大规模线性分类时比较方便。而SVM的理解和优化相对来说复杂一些，SVM转化为对偶问题后,分类只需要计算与少数几个支持向量的距离,这个在进行复杂核函数计算时优势很明显,能够大大简化模型和计算。 
	5. Logic 能做的 SVM能做，但可能在准确率上有问题，SVM能做的Logic有的做不了。

- [ ] LR发展历史？
- ![LR推导](http://img.blog.csdn.net/20171213201050525?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2luYXRfMzU1MTIyNDU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

（1）公式推导一定要会 
（2）逻辑回归的基本概念 
　　这个最好从广义线性模型的角度分析，逻辑回归是假设y服从Bernoulli分布。 
（3）L1-norm和L2-norm 
　　其实稀疏的根本还是在于L0-norm也就是直接统计参数不为0的个数作为规则项，但实际上却不好执行于是引入了L1-norm；而L1norm本质上是假设参数先验是服从Laplace分布的，而L2-norm是假设参数先验为Gaussian分布，我们在网上看到的通常用图像来解答这个问题的原理就在这。 
　　但是L1-norm的求解比较困难，可以用坐标轴下降法或是最小角回归法求解。 
（4）LR和SVM对比 
　　首先，LR和SVM最大的区别在于损失函数的选择，LR的损失函数为Log损失（或者说是逻辑损失都可以）、而SVM的损失函数为hinge loss 
minw,b∑iN[1−yi(w∗xi+b)]+λ||w||2

其次，两者都是线性模型。 
　　最后，SVM只考虑支持向量（也就是和分类相关的少数点） 
（5）LR和随机森林区别 
　　随机森林等树算法都是非线性的，而LR是线性的。LR更侧重全局优化，而树模型主要是局部的优化。 
（6）常用的优化方法 
　　逻辑回归本身是可以用公式求解的，但是因为需要求逆的复杂度太高，所以才引入了梯度下降算法。 
　　一阶方法：梯度下降、随机梯度下降、mini 随机梯度下降降法。随机梯度下降不但速度上比原始梯度下降要快，局部最优化问题时可以一定程度上抑制局部最优解的发生。 
　　二阶方法：牛顿法、拟牛顿法： 
　　这里详细说一下牛顿法的基本原理和牛顿法的应用方式。牛顿法其实就是通过切线与x轴的交点不断更新切线的位置，直到达到曲线与x轴的交点得到方程解。在实际应用中我们因为常常要求解凸优化问题，也就是要求解函数一阶导数为0的位置，而牛顿法恰好可以给这种问题提供解决方法。实际应用中牛顿法首先选择一个点作为起始点，并进行一次二阶泰勒展开得到导数为0的点进行一个更新，直到达到要求，这时牛顿法也就成了二阶求解问题，比一阶方法更快。我们常常看到的x通常为一个多维向量，这也就引出了Hessian矩阵的概念（就是x的二阶导数矩阵）。缺点：牛顿法是定长迭代，没有步长因子，所以不能保证函数值稳定的下降，严重时甚至会失败。还有就是牛顿法要求函数一定是二阶可导的。而且计算Hessian矩阵的逆复杂度很大。 
拟牛顿法： 不用二阶偏导而是构造出Hessian矩阵的近似正定对称矩阵的方法称为拟牛顿法。拟牛顿法的思路就是用一个特别的表达形式来模拟Hessian矩阵或者是他的逆使得表达式满足拟牛顿条件。主要有DFP法（逼近Hession的逆）、BFGS（直接逼近Hession矩阵）、 L-BFGS（可以减少BFGS所需的存储空间）。

### 贝叶斯
- [ ] 西瓜书
- [ ] 简单说说贝叶斯定理。

### 梯度下降法
- [ ] python 实现
- [ ] [一文清晰讲解机器学习中梯度下降算法（包括其变式算法）](http://blog.csdn.net/wemedia/details.html?id=45460)
- [ ] [牛顿法等机器学习常见的最优化算法](https://blog.csdn.net/wtq1993/article/details/51607040)
- [ ] 随机梯度下降法的问题和挑战
- [ ] 说说共轭梯度法？
- [ ] 对所有优化问题来说, 有没有可能找到比現在已知算法更好的算法?
- [ ] 什么最小二乘法？
- [ ] 优化算法及其优缺点？
- [ ] 采用 EM 算法求解的模型有哪些，为什么不用牛顿法或梯度下降法？
### KDD 
- [ ] 基本知识
- [ ] 解释对偶的概念。
- [ ] 如何进行特征选择？
- [ ] 数据预处理。
- [ ] 知道哪些数据处理和特征工程的处理？
### python 
- [ ] 请写出一段Python代码实现删除一个list里面的重复元素。
- [ ] 编程用sort进行排序，然后从最后一个元素开始判断。
- [ ] [Python是如何进行内存管理的？](http://www.cnblogs.com/tom-gao/p/6645859.html)
- [ ] Python里面如何生成随机数？
- [ ] [Python到底是什么样的语言？你可以比较其他技术或者语言来回答你的问题。](http://nooverfit.com/wp/15%E4%B8%AA%E9%87%8D%E8%A6%81python%E9%9D%A2%E8%AF%95%E9%A2%98-%E6%B5%8B%E6%B5%8B%E4%BD%A0%E9%80%82%E4%B8%8D%E9%80%82%E5%90%88%E5%81%9Apython%EF%BC%9F/)

### SVD PCA
- [ ] python 实现
- 
### 基本问题
- [ ] 简单说下有监督学习和无监督学习的区别？
- [ ] 协方差和相关性有什么区别？
- [ ] 线性分类器与非线性分类器的区别以及优劣。
- [ ]数据的逻辑存储结构（如数组，队列，树等）对于软件开发具有十分重要的影响，试对你所了解的各种存储结构从运行速度、存储效率和适用场合等方面进行简要地分析。
- ![](http://img.blog.csdn.net/20171213195006009?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2luYXRfMzU1MTIyNDU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
- [ ] 什么是分布式数据库？
- [ ]哪些机器学习算法不需要做归一化处理？
- [ ] 标准化与归一化的区别?
- [ ][怎么理解决策树、xgboost能处理缺失值？而有的模型(svm)对缺失值比较敏感？](https://www.zhihu.com/question/58230411)
- [ ] 衡量分类器的好坏。
- [ ] [机器学习和统计里面的auc的物理意义是什么？](https://www.zhihu.com/question/39840928)
- [ ] EM算法、HMM、CRF。
- 
### 深度学习
- [ ] overfitting怎么解决？
- [ ] 简单说下sigmoid激活函数
- [ ] 什么是卷积?
- [ ] dropout、regularization、batch normalizatin实现
- [ ] 如何解决梯度消失和梯度膨胀？
- [ ] 什么是CNN的池化pool层?
- [ ] 说说常见的损失函数
- [ ] [Imbalanced Classification Problems](https://www.analyticsvidhya.com/blog/2017/03/imbalanced-classification-problem/)
- [ ] [你有哪些Deep Learning（RNN，CNN）调参的经验？](https://www.zhihu.com/question/41631631)
- [ ] [RNN原理](http://blog.csdn.net/heyongluoyao8/article/details/48636251)
- [ ] [深度学习（CNN RNN Attention）解决大规模文本分类问题](https://zhuanlan.zhihu.com/p/25928551)
- [ ] [如何解决RNN梯度爆炸和弥散的问题的？](http://blog.csdn.net/han_xiaoyang/article/details/51932536)
- [ ] [性能瓶颈](https://blog.csdn.net/han_xiaoyang/article/details/53453145),[如何提高](http://blog.csdn.net/han_xiaoyang/article/details/52654879)
- [ ]做过什么样的机器学习项目？比如如何从零构建一个推荐系统？推荐系统的公开课http://www.julyedu.com/video/play/18/148，另，再推荐一个课程：机器学习项目班 [10次纯项目讲解，100%纯实战]（https://www.julyedu.com/course/getDetail/48）。
- [ ] 为什么引入非线性激励函数？
- [ ] Sigmoid、Tanh、ReLu这三个激活函数有什么缺点或不足，有没改进的激活函数？
- [ ] 请问人工神经网络中为什么ReLu要好过于Tanh和Sigmoid function?
- [ ] 什么造成梯度消失问题? 推导一下。 
- [ ] 什么是梯度消失和梯度爆炸？如何解决
- [ ] [推导下反向传播Backpropagation。](http://blog.csdn.net/woaidapaopao/article/details/77806273)
- [ ] 深度学习常用方法。
- [ ]  [从网上下载或自己编程实现一个卷积神经网络，并在手写字符识别数据MNIST上进行试验测试](http://blog.csdn.net/snoopy_yuan/article/details/71703019)
- [ ] 神经网络中激活函数的真正意义？一个激活函数需要具有哪些必要的属性？还有哪些属是好的属性但不必要的？
- [ ] [梯度下降法的神经网络容易收敛到局部最优，为什么应用广泛？](https://www.zhihu.com/question/68109802/answer/262143638)
- [ ] CNN常用的几个模型。
- [ ] [用贝叶斯机率说明Dropout的原理。](https://zhuanlan.zhihu.com/p/25005808)
- [ ] 为什么很多做人脸的Paper会最后加入一个Local Connected Conv？
- [ ] 什么事共线性, 跟过拟合有什么关联?
- [ ] [为什么网络够深(Neurons 足够多)的时候，总是可以避开较差Local Optima？](https://arxiv.org/pdf/1412.0233.pdf)
- [ ] 梯度爆炸会引发什么问题？如何修复梯度爆炸问题？

### Tensorflow

- [ ] [bilibili 视频](https://www.bilibili.com/video/av9156347/index_2.html#page=2)
- [ ] 计算图的了解
- [ ]

### 计算机视觉
- [ ]看你是搞视觉的，熟悉哪些CV框架，[顺带聊聊CV最近五年的发展史如何？](https://mp.weixin.qq.com/s?__biz=MzI3MTA0MTk1MA==&mid=2651986617&idx=1&sn=fddebd0f2968d66b7f424d6a435c84af&scene=0#wechat_redirect)
- [ ] [深度学习在计算机视觉领域的前沿进展](https://zhuanlan.zhihu.com/p/24699780)

### 生成对抗网络
- [ ] 定义
- [ ] 


### 集成学习
- [ ]西瓜书
- [ ] GBDT和XGBoost的区别
- 
### 随机森林
- [ ] Boosting和Bagging。
- [ ] RF与GBDT之间的区别与联系？
- [ ] python 实现
- [ ] 什么是OOB？随机森林中OOB是如何计算的，它有什么优缺点？
### XGBoost
- [ ] 为什么XGBoost要用泰勒展开，优势在哪里？
- [ ] XGBoost如何寻找最优特征？是又放回还是无放回的呢？
- [ ] 观察增益gain, alpha和gamma越大，增益越小？
- [ ] XGBoost怎么给特征评分？

### Adaboost

### 判别式模型

### 生成模型

### 面试前

- [ ] BAT机器学习面试1000题系列 选择题做一遍
- 

![实际工程](http://img.blog.csdn.net/20171213200909645?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2luYXRfMzU1MTIyNDU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


## Reference

- [BAT机器学习面试1000题系列](https://blog.csdn.net/sinat_35512245/article/details/78796328](https://blog.csdn.net/sinat_35512245/article/details/78796328)
- [百度2015校招机器学习笔试题](http://www.itmian4.com/thread-7042-1-1.html)
- [ 机器学习面试问题集（2018-3-13更新）](https://blog.csdn.net/u011239443/article/details/76360294)
- [ awesome deep version](https://github.com/kjw0612/awesome-deep-vision)
- [ awesome computer vision](https://github.com/jbhuang0604/awesome-computer-vision)
- [awesome c++](https://github.com/fffaraz/awesome-cpp)