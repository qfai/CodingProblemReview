[[_TOC_]]
# CodingProblemReview
This a personal leetcode,hiho, kikstart problem solving and paper work repository

After work like a year, I am thinking my objective is cloud computing, focusing on storage, buildout, deployment.

It is a little bit difference from compus hire, so tring to record here

## First thing is resume
1. the google book resume [pdf](https://www.uop.edu.jo/download/research/members/495_1887_llll.pdf)
2. refer to [this](https://www.1point3acres.com/bbs/thread-187005-1-1.html)
3. use [fiverr](https://www.fiverr.com/categories/writing-translation/resume-writing) find someone whose background is HR and revisit your resume(needs pay)


Search in google about picture of "resume-software engineer" to get a idea what a social hire resume should be like

and some links [here](https://tanchao.github.io/2016/08/10/how-to-seek-job.html)

## Second thing is Interview problems
0. course
    1. https://www.coursera.org/specializations/algorithms#courses
1. Book
    1. Cracking the Coding Interview
    2. Programming Interview Exposed
2. Leetcode(参考：6个月的时间，一共刷了800道题，大部分常考题大概平均每道题刷了5遍左右。)
    1. 第一遍按照Leetcode的tag分类，然后按照频率排序，优先做高频题，不管难度，如果是近两年都没有出现过或者近两年面过的公司不是FANNG则直接跳过。第一遍刷题，如果十分钟以内想不出来，那么直接看答案或者网上别人的解法，同时在Leetcode上用笔记记录思路，然后理解答案的想法，记住要背容易记忆和理解的最优解法。第一遍不会做不用灰心，因为这一遍的目的是背答案，答案背多了自然能从题中找到规律。最后用一个list记录这一轮第一次没有做出来的题。

    2. 第二轮重复第一遍的过程，还是按照tag分类和频率排序，并且还是只考虑十分钟，如果第一轮看答案才做出来的题目，这一轮没有看答案就做出来了，说明你已经背下了答案，把它从第一轮的list挪到一个新的list。我们的目的是如果连续两轮完全没有看任何提示就做出来了，那么表示这道题你就掌握了。

    3. 第三轮重复第二轮，再按照tag分类和频率排序，这一轮我们考虑二十分钟，依旧秉承一个原则：连续两轮完全没有看任何提示做出来的题目，代表你已经掌握了，哪怕是已经把答案背下来了。到第三轮的时候，你应该会有2个list，一个list是做了三遍还是没有任何思路的题（也就是对于自己而言比较难理解的题），还有一个list是第一次没做出来但第二次没有看任何提示做出来的题（也就是对自己而言还没有完全掌握的题）。

    4. 第四轮，根据自己创建的list，只给自己五分钟的考虑时间，过一遍前三轮创建的两个list，清空那些连续两轮都做出来的题，然后把那些之前没思路的题但这一轮做出来的题移动到另一个list。如果你坚持下来，那么到这个时候，你应该已经刷了5-600道题了，然后实际完全掌握的肯定有50%以上，大概300道题。
    5. 第五轮，根据自己面试的公司，刷近一年该公司面过的题，按照频率排序。如果时间允许，把所有出现的题都做一遍，保证看到原题立马想到最优解。
3. System design 
    1. [grokking the system interview](https://www.educative.io/courses/grokking-the-system-design-interview?affiliate_id=5749180081373184/)当零散时间的反复温习(needs pay)
    2. 主攻design data intensive application[DDIA]， 反复认真读了3遍，
    3. 然后去youtubu自己看cmu 15721，高级数据库的课程
    4. other resources
        1. http://www.1point3acres.com/bbs/thread-208829-1-1.html
        2. http://www.1point3acres.com/bbs/thread-169343-1-1.html
        2. http://www.1point3acres.com/bbs/thread-171320-1-1.html
        2. http://www.1point3acres.com/bbs/thread-210083-1-1.html
        2. http://www.1point3acres.com/bbs/thread-184542-1-1.html
    5. maybe mit 6.824

## Third thing about experiences
1. make a story of your experiences. 
    1. what is the project
    2. why this project exist
    3. what you have done in this project, what's the contribution and how you did this.
    4. what you learn from this project
2. what technoledge you have used
    1. what is this tech and why you use it
    2. are there any competors and why you choose this one, pro and cons.
3. project of open source

## Others
1. salary [negotiation](https://candor.co/guides/salary-negotiation)
2. complete linkln
3. glassdoor for infos

## Not so sure about general compus hire problem like what const mean in c++. will skip this for now.

ref: https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=303319&extra=page%3D1%26filter%3Dsortid%26sortid%3D192%26sortid%3D192

### New TODO [here](https://github.com/qfai/CodingProblemReview/blob/master/interview_problem/todo.md)

-----------------------------------Below are compus hire records ------------------------------------------------

[TO LISTS](https://github.com/qfai/CodingProblemReview/blob/master/interview_problem/mytodo.md)

## paper_work

| catagory      | comment or blog| src  |
| ------------- |:-------------:| -----:|
| 最长公共子序列    | DP | [click](https://github.com/qfai/CodingProblemReview/blob/master/src/LCS.cpp)|
| 快速幂| bits |[click](https://github.com/qfai/CodingProblemReview/blob/master/src/quick_pow.cpp)|
|浮点数幂,开方实现| [扩展](https://www.zhihu.com/question/20930598)|待写 |
|判断括号合法性| 如果我们从前到后遍历，左括号可以暂时多于右括号，但不可以少于，每次成功闭合一对括号把数量 - 1 ，得到负数说明不平衡|待写|
|背包问题| 背包问题九讲和记录不同的背包问题|待写|

## Interview_problem
| catagory      | comment or blog| src  |
| ------------- |:-------------:| -----:|
| Network     |  | [click](https://github.com/qfai/CodingProblemReview/blob/master/interview_problem/Network.md)|
| Operating System     | | [click](https://github.com/qfai/CodingProblemReview/blob/master/interview_problem/os.md)|
| C++    |  | [click](https://github.com/qfai/CodingProblemReview/blob/master/interview_problem/cpp.md)|
| Graphics    |  | [click](https://github.com/qfai/CodingProblemReview/blob/master/interview_problem/graphics.md)|

## Design Pattern

| peoblems      | comment or blog| src  |
| ------------- |:-------------:| -----:|
| singleton     | [C-plus-plus-In-Theory-The-Singleton-Pattern](https://www.devarticles.com/c/a/Cplusplus/C-plus-plus-In-Theory-The-Singleton-Pattern-Part-I/) | [click](https://github.com/qfai/CodingProblemReview/blob/master/src/singleton_template.cpp)|
| 最长公共子序列,hiho一下1     | [写的很棒，图很好，Manacher 算法](https://segmentfault.com/a/1190000003914228) | [click](https://github.com/qfai/CodingProblemReview/blob/master/src/Longest_Palindromic_Substring.cpp)|
| kmp,hiho一下3  |  | [click](https://github.com/qfai/CodingProblemReview/blob/master/src/kmp.cpp)|
| Trie图，AC自动机,hiho一下4  |  | [click](https://github.com/qfai/CodingProblemReview/blob/master/src/trie_map.cpp)|
## 面经
| Company      | comment or blog| link  |
| ------------- |:-------------:| -----:|
| Google_intern     |   | [click](https://github.com/qfai/CodingProblemReview/blob/master/Real_problem/google_intern.md)|
| Tencent_intern      |   | [click](https://github.com/qfai/CodingProblemReview/blob/master/Real_problem/tencent_intern.md)|
| TouTiao_intern      |   | [click](https://github.com/qfai/CodingProblemReview/blob/master/Real_problem/toutiao.md)|
|大摩| | [click](https://github.com/qfai/CodingProblemReview/blob/master/Real_problem/morgen_intern.md)|
|阿里| | [click](https://github.com/qfai/CodingProblemReview/blob/master/Real_problem/ali_intern.md)|

---
ps: [github markdown grammar](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#tables)
