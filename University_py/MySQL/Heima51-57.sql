
use test01;
# 51.事务简介
# 事务是一组操作的集合，是不可分割的工作单位，事务会把所有的操作作为一个整体一起向系统提交或撤销操作请求，即这些操作要么同时成功，要么同时失败

# 52.事务操作
# 数据准备：
create table account(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    money int comment '余额'
)comment '账户表';
insert into account(id, name, money) VALUES (null,'张三',2000),(null,'李四',2000);

# 恢复数据
update account set money = 2000 where name = '张三' or name = '李四';

# 转账操作（张三给李四转账1000）
# 1.查询张三余额
select * from account where name='张三';
# 2.张三余额-1000
update account set money = money - 1000 where name='张三';
# 3.李四余额+1000
update account set money = money + 1000 where name='李四';

# 查看/设置事务提交方式
select @@autocommit;
# =就是设置为手动提交，=1则是设置为自动提交
set @@autocommit=0;
# 提交事务
commit;
# 回滚事务
rollback;
# 开启事务
# start transaction 或 begin
start transaction ;
# 转账操作（张三给李四转账1000）
# 1.查询张三余额
select * from account where name='张三';
# 2.张三余额-1000
update account set money = money - 1000 where name='张三';
# 3.李四余额+1000
update account set money = money + 1000 where name='李四';
# 成功则提交
commit ;
# 失败则回滚
rollback ;

# 53.事务的四大特性
# 原子性、一致性、隔离性、持久性

# 54.并发事务的常见问题
# 脏读  不可重复读  幻读

# 55.并发事务的演示及隔离级别
# 事务隔离级别                         脏读        不可重复读             幻读
# read uncommitted（tidb不存在这种）    可以        可以                 可以
# read committed                     不可以      可以                  可以
# repeatable read（MySQL默认）        不可以       不可以                不可以
# serializable                       不可以       不可以                不可以
# 事务隔离级别越高，数据越安全，但是性能越低

# 查看事务隔离级别
# MySQL8.0+版本：select @@transction_isolation;        5.7版本：
select @@tx_isolation;

# 设置事务隔离级别
# set [session（会话级别，当前窗口有效）|global（所有客户端的窗口有效）] transaction isolation level {read uncommitted|read committed|repeatable read|serializable};
#tidb底层不允许设置 read uncommitted，即使强制设置了，实际上还是默认的repeatable read
set session transaction isolation level repeatable read ;

# 56.事务小结

# 57.基础篇小结
