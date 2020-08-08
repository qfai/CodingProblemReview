# 转组之前想清楚这几个问题

1. 现在的组/项目为什么让你不满意， 你有没可能让它改变， 然后让你满意？
2. 现在的manager 对你的 career 发展有没和你一起做规划， 让你进步？
3. 现在的组员 对你的长成有帮助吗？ 团队氛围是你喜欢的吗？
4. 未来数月是想换公司吗？ 这样你知道自己想去一个忙还是闲的组。

# 筛选你感兴趣的组， 以下内容帮大家了解一些组的数据，以做决策。 转组不能因为聊得开心就去了，楼主觉得找自己感兴趣的组和项目比较重要。
1. [筛选岗位] 在内网的 j**finder 搜感兴趣的岗位， 按关键字搜索， filter location， manager等等 （如果有人推荐你， 那这一步可以省掉）
2. 搜一下 hiring manager的 sev2， ticket queue （你会知道这个组的oncall是怎样的， 用数据说话。 内网有一个网站专门记录这些的。 有时候manager不会对你说实话的，明明oncall 重的很，就说 you know, it's an aws service!）
3. 搜一下 那个组的code base （很重要！ 很重要！ 很重要！） 重要的事情说三次！ 你可以知道这个组的code base。 code的质量如何，用的什么technology， 有没有让你意外的发现。
4. 在code base 看一下 manager下面的engineer commit code 的活跃度， 这样确定一下这个组是不是很忙/闲
5. 从[3] 中你发现有哪些key service， 看一下那些 service 的pipelines， 看deploy和更新 是不是频繁的， 有没有经常fail
6. 从[3] 中选一些最近的commit， 看一下 code review， 你可能感受到这个组对code 质量的要求. check 1point3acres for more.
7. 从[3] 中你会知道 key service是谁主要commit的， 看一下那些人还在不在组里。
8. 看一下这个manager底下的近一年的 错误报告的root cause 和 lesson learn （亚麻的大家懂这个是什么， 有内网工具查）
9. 看一下这个组的人的wiki （如果wiki有内容的话）

# 面试新组
1. 选好了感兴趣的组， 发邮件给hiring manager， 说自己感兴趣。 在邮件贴上以下的内容能帮你获得好感（有就尽量提供）
1.1 你做过的项目的code commit （选你觉得比较好的code commit， 用来说明你的code quality还可以。 -- deliver result）
1.2 你的design doc （你的design清晰， 有良好的document习惯， 一直跟进进度 -- leadership）
1.3 你处理过的比较好的 ticket （有root cause，有 solution， 有良好的document。 -- operation excellence）
1.4 你mentor 过的intern， new hire， teammate （提供一些wiki， 说明你 check 进度，很好mentor他们 -- making the team and others better）

2. 面试
2.1. 和manager聊， 一般都会让你很舒服，让你觉得是个好组，画大饼，氛围很好。 （再说一次，这只是聊天， 你已经调查过了， 所以你会知道他说话实在不实在）
2.2. 和组里的engineer聊， 有可能会被问leetcode的， 一般不会很难。 有的组不问刷题。问一下 design， 问一下做过的项目，为什么想换组之类。 （good luck)

# 转组
1. hiring manager 给了 apply link （注意，口头offer不算数，一定要给apply link， 才做接下来的事情。 不然小心和现在的组闹翻）
2. 和现在组的manager schedule 1-on-1， 说明情况，要转组， 已经有offer了， 新组的东西很感兴趣。  记得温和一点，说是想try new things， 少说现在这个组不好。
3. [2] 聊完了，马上点 apply link。 如果已经确定要走了，就不要等！ 我看到过有人吃亏过的！
4. 现在组的manager最多keep 你30天， 期间你就尽量做好document， 让这个组以后的engineer 有更好的reference， 这样的好处是可以让现在的组更好， 同时以后不会经常有之前组的人来找你问问题！！！


# 其他
1, 有人问，要不要去 XXX 组？ 记得做上面 *筛选你感兴趣的组* 的内容，你就有答案了， 不需要依靠别人的意见，用数据说话！


2. 要不要去 AWS？ 看组的， 有的组忙的很， oncall 很重。 有的组不忙。 关键还是看你想要什么。在有些AWS组是很锻炼人的，能学到很多东西。 不过说白了，大部分AWS的service 其实就是给 外面的企业做 ops的， 记住这一点就好了。不过从aws出来的engineer，很多都很抗压，很能熬。


3. 要不要去 retail， Alexa， xxx， yyy？也是看组的， 组太多了。有的组可能还可以的。 大家记得提前做功课。


ref: https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=634680&highlight=transfer