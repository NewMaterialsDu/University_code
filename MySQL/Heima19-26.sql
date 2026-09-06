
use test01;

# 19.排序字段列表
# 语法：
# select 字段列表 from 表名 order by 字段1 排序方式1，字段2 排序方式2;
# 排序方式：asc:升序（默认值）  desc:降序
# 多字段排序，当第一个字段相同时才会根据第二个字段进行排序
# 根据员工年龄升序,asc不写也可以，因为默认是升序
select age,id, workno, name, gender, idcard, workaddress, entrydate from emp order by age asc;
select age,id, workno, name, gender, idcard, workaddress, entrydate from emp order by age;
# 根据入职时间降序
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp order by entrydate desc;
# 根据年龄升序，年龄相同再根据入职时间降序
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp order by age asc,entrydate desc;

# 20.分页查询
# select 字段列表 from 表名 limit 起始索引,查询记录数;
# 起始索引从零开始，起始索引 = （查询页码 - 1） * 每页显示记录数;
# 分页查询是数据库的方言，MySQL是limit，不同数据库有不同实现
# 如果查询的是第一页数据，起始索引可以省略，直接简写为limit 10
# 查询第一页员工数据，每页展示10条记录
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp limit 0,10;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp limit 10;
# 查询第二页员工数据，每页展示10条记录;第一个10代表从第10个开始，第二个10代表展示10条
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp limit 10,10;

# 21.DQL案例
# 查询年龄为20，21，22，23岁的女性员工
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='女' and age in (20,21,22,23);
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='女' and age>=20 and age<=23;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='女' and age>=20 && age<=23;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='女' and age between 20 and 23;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='女' and  age=20 or age=21 or age=22 or age=23;
# 查询性别为男，并且年龄在20-40岁（含）以内的姓名为三个字的员工
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='男' and age between 20 and 40 and name like '___';
# 统计表中，年龄小于60的，男员工和女员工的人数
select gender,count(*) from emp where age<60 group by gender;
# 查询所有年龄小于等于35岁的员工的姓名和年龄，并对查询结果按年龄升序，年龄相同则按入职时间降序
select name,gender,age,entrydate from emp where age<=35 order by age asc,entrydate desc;
# 查询性别为男，且年龄在20-40（含）以内的前5个员工信息，对查询的结果按年龄升序，年龄相同则按入职时间降序
select gender,name,age,entrydate from emp where gender='男' and age between 20 and 40 order by age asc,entrydate desc limit 0,5;

# 22.DQL语句的执行顺序
# 编写顺序：delect 字段列表 from 表名列表 where 条件列表 grounp by 分组字段列表 having 分组后字段列表 order by 排序字段列表 limit 分页参数;
# 执行顺序：from 表名列表 where 条件列表 grounp by 分组字段列表 having 分组后字段列表 delect 字段列表 order by 排序字段列表 limit 分页参数;
# 查询年龄大于15的，姓名，年龄，根据年龄升序
# 先执行了from，所以有了别名e，select后执行，所以也能用e
select e.name,e.age from emp as e where e.age>15 order by age asc;
# 因为select在where执行后再执行，所以在select起的别名，where那里用不了，会说没找到
select e.name ename,e.age eage from emp as e where eage>15 order by age asc;
# select是在order by之前，所以order by可以使用select的别名
select e.name,e.age eage from emp as e where e.age>15 order by eage asc;

# 23.DQL小结

# 24.SQL-DCL-用户管理
# 1.查询用户：use mysql; select * from user;
# 2.创建用户：create user '用户名'@'主机名' identified by '密码';
# 3.修改用户密码：alter user '用户名'@'主机名' identified with mysql_native_password by '新密码';
# 4.删除用户：drop user '用户名'@'主机名';
use mysql;
select * from user;
# 因为我用的是tidb，所以要加上一个前缀
# 创建用户itcast，只能在当前主机localhost访问，密码123456；但是这个用户是没有权限的，可以用命令行访问以此验证（本地MySQL可以，tidb也可以但是很复杂），用户表中也可以看到全是N即no
create user 'PXkufcKH6hBQ5AF.itcast'@'localhost' identified by '123456';
# 创建用户heima，可以在任意主机访问数据库，密码123456;用%代替主机名，表示可以访问任意用户
create user 'PXkufcKH6hBQ5AF.heima'@'%' identified by '123456';
# 修改用户heima的访问密码为1234
alter user 'PXkufcKH6hBQ5AF.heima'@'%' identified with mysql_native_password by '1234';
# 删除itcast@localhost用户
drop user 'PXkufcKH6hBQ5AF.itcast'@'localhost';

# 25.DCL权限控制
# MySQL中定义了很多权限，但是常用的也就几种：
# all,all privileges;所有权限
# select;查询数据
# insert;插入数据
# update;修改数据
# delete;删除数据
# alter;修改表
# drop;删除数据库/表/视图
# create;创建数据库/表
# 其他的权限描述及含义，可以参考官方文档
#1.查询权限：show grants for '用户名'@'主机名';
show grants for 'PXkufcKH6hBQ5AF.heima'@'%';
# 2.授予权限：grant 权限列表 on 数据库名.表名 to '用户名'@'主机名';全部库和表用通配*;因为用的是tidb，云端数据库是不能授予all的，因为有一些系统级的权限
grant select, insert, update, delete, create, drop, alter, index on *.* to 'PXkufcKH6hBQ5AF.heima'@'%';
# 3.撤销权限：revoke 权限列表 on 数据库名.表名 from '用户名'@'主机名';
revoke select, insert, update, delete, create, drop, alter, index on *.* from 'PXkufcKH6hBQ5AF.heima'@'%';

# 26.DCL小结
