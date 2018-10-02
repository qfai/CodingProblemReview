# CheckList


### TCP 与 UDP区别

TCP 是面向连接的，提供可靠，有序，带有拥塞控制的服务，但是TCP慢，效率低，确认机制，拥塞机制会消耗大量时间，建立连接也会占用CPU等硬件资源。面向字节流的。

UDP 是个无状态协议，速度快，overhead 少，程序结构简单。但是不稳定不可靠。面向数据报的，可以一对多。

TCP应用场景： 当对网络通讯质量有要求的时候。比如HTTP、HTTPS、FTP等传输文件的协议

UDP应用场景： 当对网络通讯质量要求不高的时候，要求网络通讯速度能尽量的快。 比如，日常生活中， QQ语音 QQ视频 TFTP

编程上的差别

UDP Server不需要调用listen和accept。UDP收发数据用sendto/recvfrom函数。 