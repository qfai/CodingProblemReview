# Linux

### [从 inode 了解 Linux 文件系统](https://www.ibm.com/developerworks/cn/linux/l-cn-hardandsymb-links/index.html)

inode 是 UNIX 操作系统中的一种数据结构，它包含了与文件系统中各个文件相关的一些重要信息。在 UNIX 中创建文件系统时，同时将会创建大量的 inode 。通常，文件系统磁盘空间中大约百分之一空间分配给了 inode 表。

有时，人们使用了一些不同的术语，如 inode 和索引编号 (inumber)。这两个术语非常相似，并且相互关联，但它们所指的并不是同样的概念。 inode 指的是数据结构；而索引编号实际上是 inode 的标识编号，因此也称其为 inode 编号 或者索引编号。索引编号只是文件相关信息中一项重要的内容。下一个部分将介绍 inode 中的其他一些属性。

inode 表包含一份清单，其中列出了对应文件系统的所有 inode 编号。当用户搜索或者访问一个文件时，UNIX 系统通过 inode 表查找正确的 inode 编号。在找到 inode 编号之后，相关的命令才可以访问该 inode ，并对其进行适当的更改。

例如，使用 vi 来编辑一个文件。当您键入 vi <filename> 时，在 inode 表中找到 inode 编号之后，才允许您打开该 inode 。在 vi 的编辑会话期间，更改了该 inode 中的某些属性，当您完成操作并键入 :wq 时，将关闭并释放该 inode 。通过这种方式，如果两个用户试图对同一个文件进行编辑， inode 已经在第一个编辑会话期间分配给了另一个用户 ID (UID)，因此第二个编辑任务就必须等待，直到该 inode 释放为止。


我们知道文件都有文件名与数据，这在 Linux 上被分成两个部分：用户数据 (user data) 与元数据 (metadata)。用户数据，即文件数据块 (data block)，数据块是记录文件真实内容的地方；而元数据则是文件的附加属性，如文件大小、创建时间、所有者等信息。在 Linux 中，元数据中的 inode 号（inode 是文件元数据的一部分但其并不包含文件名，inode 号即索引节点号）才是文件的唯一标识而非文件名。文件名仅是为了方便人们的记忆和使用，系统或程序通过 inode 号寻找正确的文件数据块。图 1.展示了程序通过文件名获取文件内容的过程。

为解决文件的共享使用，Linux 系统引入了两种链接：硬链接 (hard link) 与软链接（又称符号链接，即 soft link 或 symbolic link）。链接为 Linux 系统解决了文件的共享使用，还带来了隐藏文件路径、增加权限安全及节省存储等好处。若一个 inode 号对应多个文件名，则称这些文件为硬链接。换言之，硬链接就是同一个文件使用了多个别名（见 图 2.hard link 就是 file 的一个别名，他们有共同的 inode）。硬链接可由命令 link 或 ln 创建。如下是对文件 oldfile 创建硬链接。

    link oldfile newfile 
	ln oldfile newfile
#### 硬链接特性
- 文件有相同的 inode 及 data block；
- 只能对已存在的文件进行创建；
- 不能交叉文件系统进行硬链接的创建；
- 不能对目录进行创建，只可对文件创建；
- 删除一个硬链接文件并不影响其他有相同 inode 号的文件。

硬链接不能对目录创建是受限于文件系统的设计（见 清单 4.对目录创建硬链接将失败）。现 Linux 文件系统中的目录均隐藏了两个个特殊的目录：当前目录（.）与父目录（..）。查看这两个特殊目录的 inode 号可知其实这两目录就是两个硬链接（注意目录 /mnt/lost+found/ 的 inode 号）。若系统允许对目录创建硬链接，则会产生目录环。、


软链接与硬链接不同，若文件用户数据块中存放的内容是另一文件的路径名的指向，则该文件就是软连接。软链接就是一个普通文件，只是数据块内容有点特殊。软链接有着自己的 inode 号以及用户数据块（见 图 2.）。因此软链接的创建与使用没有类似硬链接的诸多限制：


- 软链接有自己的文件属性及权限等；
- 可对不存在的文件或目录创建软链接；
- 软链接可交叉文件系统；
- 软链接可对文件或目录创建；
- 创建软链接时，链接计数 i_nlink 不会增加；
- 删除软链接并不影响被指向的文件，但若被指向的原文件被删除，则相关软连接被称为死链接（即 dangling link，若被指向路径文件被重新创建，死链接可恢复为正常的软链接）。

![](https://www.ibm.com/developerworks/cn/linux/l-cn-hardandsymb-links/image002.jpg)

Linux VFS 存在四个基本对象：超级块对象 (superblock object)、索引节点对象 (inode object)、目录项对象 (dentry object) 及文件对象 (file object)。超级块对象代表一个已安装的文件系统；索引节点对象代表一个文件；目录项对象代表一个目录项.文件对象代表由进程打开的文件.


```
struct inode { 
   ... 
   const struct inode_operations   *i_op; // 索引节点操作
   unsigned long           i_ino;      // 索引节点号
   atomic_t                i_count;    // 引用计数器
   unsigned int            i_nlink;    // 硬链接数目
   ... 
} 
 
struct inode_operations { 
   ... 
   int (*create) (struct inode *,struct dentry *,int, struct nameidata *); 
   int (*link) (struct dentry *,struct inode *,struct dentry *); 
   int (*unlink) (struct inode *,struct dentry *); 
   int (*symlink) (struct inode *,struct dentry *,const char *); 
   int (*mkdir) (struct inode *,struct dentry *,int); 
   int (*rmdir) (struct inode *,struct dentry *); 
   ... 
}
```

每个文件存在两个计数器：i_count 与 i_nlink，即引用计数与硬链接计数。结构体 inode 中的 i_count 用于跟踪文件被访问的数量，而 i_nlink 则是上述使用 ls -l 等命令查看到的文件硬链接数。或者说 i_count 跟踪文件在内存中的情况，而 i_nlink 则是磁盘计数器。当文件被删除时，则 i_nlink 先被设置成 0。文件的这两个计数器使得 Linux 系统升级或程序更新变的容易。系统或程序可在不关闭的情况下（即文件 i_count 不为 0），将新文件以同样的文件名进行替换，新文件有自己的 inode 及 data block，旧文件会在相关进程关闭后被完整的删除。