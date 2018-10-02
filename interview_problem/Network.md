# Network

1. [滑动窗口机制，流量控制](https://www.cnblogs.com/woaiyy/p/3554182.html)TCP必需要解决的可靠传输以及包乱序（reordering）的问题
2. 拥塞控制
	1. 慢开始，拥塞避免
	2. 快重传，快恢复

Q：聊聊计算机网络的内容吧，TCP三次握手是怎样的？
A：这部分大家参考相关课本。
Q：为什么两次不可以？
A：服务器端未收到客户端的连接确认，因此必须三次。
Q：四次呢？
A：连接确认后第三次的握手已经包含了客户端数据，不需要四次。
3. [TCP协议](https://coolshell.cn/articles/11564.html)，TCP状态机，数据重传，RTT算法
### TCP/UDP区别
TCP与UDP基本区别
  1.基于连接与无连接
  2.TCP要求系统资源较多，UDP较少； 
  3.UDP程序结构较简单 
  4.流模式（TCP）与数据报模式(UDP); 
  5.TCP保证数据正确性，UDP可能丢包 
  6.TCP保证数据顺序，UDP不保证 
　　
UDP应用场景：
  1.面向数据报方式
  2.网络数据大多为短消息 
  3.拥有大量Client
  4.对数据安全性无特殊要求
  5.网络负担非常重，但对响应速度要求高
 
具体编程时的区别
   1.socket()的参数不同 
　　 2.UDP Server不需要调用listen和accept 
　　 3.UDP收发数据用sendto/recvfrom函数 
　　 4.TCP：地址信息在connect/accept时确定 
　　 5.UDP：在sendto/recvfrom函数中每次均 需指定地址信息 
　　 6.UDP：shutdown函数无效
 
编程区别
   通常我们在说到网络编程时默认是指TCP编程，即用前面提到的socket函数创建一个socket用于TCP通讯，函数参数我们通常填为SOCK_STREAM。即socket(PF_INET, SOCK_STREAM, 0)，这表示建立一个socket用于流式网络通讯。 
　  SOCK_STREAM这种的特点是面向连接的，即每次收发数据之前必须通过connect建立连接，也是双向的，即任何一方都可以收发数据，协议本身提供了一些保障机制保证它是可靠的、有序的，即每个包按照发送的顺序到达接收方。 

　　而SOCK_DGRAM这种是User Datagram Protocol协议的网络通讯，它是无连接的，不可靠的，因为通讯双方发送数据后不知道对方是否已经收到数据，是否正常收到数据。任何一方建立一个socket以后就可以用sendto发送数据，也可以用recvfrom接收数据。根本不关心对方是否存在，是否发送了数据。它的特点是通讯速度比较快。大家都知道TCP是要经过三次握手的，而UDP没有。 

基于上述不同，UDP和TCP编程步骤也有些不同，如下：

TCP: 
TCP编程的服务器端一般步骤是： 
　　1、创建一个socket，用函数socket()； 
　　2、设置socket属性，用函数setsockopt(); * 可选 
　　3、绑定IP地址、端口等信息到socket上，用函数bind(); 
　　4、开启监听，用函数listen()； 
　　5、接收客户端上来的连接，用函数accept()； 
　　6、收发数据，用函数send()和recv()，或者read()和write(); 
　　7、关闭网络连接； 
　　8、关闭监听； 

TCP编程的客户端一般步骤是： 
　　1、创建一个socket，用函数socket()； 
　　2、设置socket属性，用函数setsockopt();* 可选 
　　3、绑定IP地址、端口等信息到socket上，用函数bind();* 可选 
　　4、设置要连接的对方的IP地址和端口等属性； 
　　5、连接服务器，用函数connect()； 
　　6、收发数据，用函数send()和recv()，或者read()和write(); 
　　7、关闭网络连接；

UDP:
与之对应的UDP编程步骤要简单许多，分别如下： 
　　UDP编程的服务器端一般步骤是： 
　　1、创建一个socket，用函数socket()； 
　　2、设置socket属性，用函数setsockopt();* 可选 
　　3、绑定IP地址、端口等信息到socket上，用函数bind(); 
　　4、循环接收数据，用函数recvfrom(); 
　　5、关闭网络连接； 

UDP编程的客户端一般步骤是： 
　　1、创建一个socket，用函数socket()； 
　　2、设置socket属性，用函数setsockopt();* 可选 
　　3、绑定IP地址、端口等信息到socket上，用函数bind();* 可选 
　　4、设置对方的IP地址和端口等属性; 
　　5、发送数据，用函数sendto(); 
　　6、关闭网络连接；

TCP和UDP是OSI模型中的运输层中的协议。TCP提供可靠的通信传输，而UDP则常被用于让广播和细节控制交给应用的通信传输。

UDP补充：
   UDP不提供复杂的控制机制，利用IP提供面向无连接的通信服务。并且它是将应用程序发来的数据在收到的那一刻，立刻按照原样发送到网络上的一种机制。即使是出现网络拥堵的情况下，UDP也无法进行流量控制等避免网络拥塞的行为。此外，传输途中如果出现了丢包，UDO也不负责重发。甚至当出现包的到达顺序乱掉时也没有纠正的功能。如果需要这些细节控制，那么不得不交给由采用UDO的应用程序去处理。换句话说，UDP将部分控制转移到应用程序去处理，自己却只提供作为传输层协议的最基本功能。UDP有点类似于用户说什么听什么的机制，但是需要用户充分考虑好上层协议类型并制作相应的应用程序。

TCP补充：
  TCP充分实现了数据传输时各种控制功能，可以进行丢包的重发控制，还可以对次序乱掉的分包进行顺序控制。而这些在UDP中都没有。此外，TCP作为一种面向有连接的协议，只有在确认通信对端存在时才会发送数据，从而可以控制通信流量的浪费。TCP通过检验和、序列号、确认应答、重发控制、连接管理以及窗口控制等机制实现可靠性传输。


TCP与UDP区别总结：
1、TCP面向连接（如打电话要先拨号建立连接）;UDP是无连接的，即发送数据之前不需要建立连接
2、TCP提供可靠的服务。也就是说，通过TCP连接传送的数据，无差错，不丢失，不重复，且按序到达;UDP尽最大努力交付，即不保   证可靠交付
3、TCP面向字节流，实际上是TCP把数据看成一连串无结构的字节流;UDP是面向报文的
  UDP没有拥塞控制，因此网络出现拥塞不会使源主机的发送速率降低（对实时应用很有用，如IP电话，实时视频会议等）
4、每一条TCP连接只能是点到点的;UDP支持一对一，一对多，多对一和多对多的交互通信
5、TCP首部开销20字节;UDP的首部开销小，只有8个字节
6、TCP的逻辑通信信道是全双工的可靠信道，UDP则是不可靠信道


### 网络编程模型

#### 阻塞型的网络编程接口：  listen()、send()、recv() 等接口开始的。使用这些接口可以很方便的构建服务器 / 客户机的模型。
大部分的 socket 接口都是阻塞型的。所谓阻塞型接口是指系统调用（一般是 IO 接口）不返回调用结果并让当前线程一直阻塞，只有当该系统调用获得结果或者超时出错时才返回。
![](https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image001.jpg)
#### 多线程的服务器程序：
主线程持续等待客户端的连接请求，如果有连接，则创建新线程，并在新线程中提供为前例同样的问答服务。

很多初学者可能不明白为何一个 socket 可以 accept 多次。实际上，socket 的设计者可能特意为多客户机的情况留下了伏笔，让 accept() 能够返回一个新的 socket。

int accept(int s, struct sockaddr *addr, socklen_t *addrlen);

输入参数 s 是从 socket()，bind() 和 listen() 中沿用下来的 socket 句柄值。执行完 bind() 和 listen() 后，操作系统已经开始在指定的端口处监听所有的连接请求，如果有请求，则将该连接请求加入请求队列。调用 accept() 接口正是从 socket s 的请求队列抽取第一个连接信息，创建一个与 s 同类的新的 socket 返回句柄。新的 socket 句柄即是后续 read() 和 recv() 的输入参数。如果请求队列当前没有请求，则 accept() 将进入阻塞状态直到有请求进入队列。

很多程序员可能会考虑使用“**线程池**”或“**连接池**”。“线程池”旨在减少创建和销毁线程的频率，其维持一定合理数量的线程，并让空闲的线程重新承担新的执行任务。“连接池”维持连接的缓存池，尽量重用已有的连接、减少创建和关闭连接的频率。
![https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image002.jpg](https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image002.jpg)

#### 非阻塞的服务器程序

非阻塞的接口相比于阻塞型接口的显著差异在于，在被调用之后立即返回。
使用如下的函数可以将某句柄 fd 设为非阻塞状态。

fcntl( fd, F_SETFL, O_NONBLOCK );

在非阻塞状态下，recv() 接口在被调用后立即返回，返回值代表了不同的含义。如在本例中，

- recv() 返回值大于 0，表示接受数据完毕，返回值即是接受到的字节数；
- recv() 返回 0，表示连接已经正常断开；
- recv() 返回 -1，且 errno 等于 EAGAIN，表示 recv 操作还没执行完成；
- recv() 返回 -1，且 errno 不等于 EAGAIN，表示 recv 操作遇到系统错误 errno。
- 
可以看到服务器线程可以通过**循环调用 recv() 接口**，可以在单个线程内实现对所有连接的数据接收工作。不推荐

![https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image003.jpg](https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image003.jpg)

#### 使用 select() 接口的基于事件驱动的服务器模型

上述模型中，最关键的地方是如何动态维护 select() 的三个参数 readfds、writefds 和 exceptfds。作为输入参数，readfds 应该标记所有的需要探测的“可读事件”的句柄，其中永远包括那个探测 connect() 的那个“母”句柄；同时，writefds 和 exceptfds 应该标记所有需要探测的“可写事件”和“错误事件”的句柄 ( 使用 FD_SET() 标记 )。

首先，select() 接口并不是实现“事件驱动”的最好选择。因为当需要探测的句柄值较大时，select() 接口本身需要消耗大量时间去轮询各个句柄。很多操作系统提供了更为高效的接口，如 linux 提供了 epoll，

其次，该模型将事件探测和事件响应夹杂在一起，一旦事件响应的执行体庞大，则对整个模型是灾难性的。如下例，庞大的执行体 1 的将直接导致响应事件 2 的执行体迟迟得不到执行，并在很大程度上降低了事件探测的及时性。
![https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image004.jpg](https://www.ibm.com/developerworks/cn/linux/l-cn-edntwk/image004.jpg)