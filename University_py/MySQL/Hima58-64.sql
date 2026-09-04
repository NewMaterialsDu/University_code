# 58.进阶介绍

# 59.存储引擎-MySQL体系结构

# 60.存储引擎层简介
# 存储引擎是存储数据、建立索引、更新/查询数据的实现方式。引擎是基于表的，而不是库，所以存储引擎也可称为表类型

use test01;
#查询建表语句 --默认存储引擎：ENGINE=InnoDB
# show create table emp;

# 建表时设置存储引擎：
# create table 表名（
# ...
#     )engine=innodb [commit 表注释];

# 查询当前数据库支持的存储引擎
# 实际上tidb用的存储引擎是TiKV
show engines;

# 创建my_myisam，并指定myisam存储引擎
# 所以这里在tidb指定存储引擎完全没用
create table my_myisam(
    id int ,
    name varchar(10)
)engine=myisam;

# 创建my_memoy，指定memory引擎
create table my_memory(
    id int,
    name varchar(10)
)engine=memory;

# 61.存储引擎的特点
# innodb是一种高可靠性和高性能的通用存储引擎，在MySQL5.5之后，这个是MySQL默认的存储引擎
# 特点：mdl（增删改语句）操作遵循acid（事务的四大特性：原子性、隔离性、一致性、持久性）模型，支持事务；  行级锁，提高并发访问性能；  支持外键foreign key约束，保证数据的完整性和正确性；
# 表名.idb：innodb引擎的每一张表都会有一个这样的对应表空间文件，存储表的结构（frm（8.0之后全部为sdi）、sdi）、数据和索引  参数：innodb_file_per_table（打开这个参数就代表每一张表对应一个表空间文件，因为也存在多张表对应一个表空间文件）
show variables like 'innodb_file_per_table';
# 表空间（tablespace）--段（segment）--区（extent（1mb））--页（page（16k））--行

# 62.myisam和memory介绍
# myisam是MySQL早期的默认存储引擎
# myisam：
# 特点：不支持事物、外键；  支持表锁；   访问速度快；
# 文件：myd（数据）、myi（索引）、sdi（表结构）
# memory：
# 特点：在内存中存储，会受到硬件问题和断电影响，只能作为临时表或者缓存使用；  支持hash索引（默认）；
# 文件：sdi文件

# 63.存储引擎选择

# 64.存储引擎小结