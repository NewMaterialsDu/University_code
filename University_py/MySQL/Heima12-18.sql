# 12.DML语句：增删改
use test01;
# 给指定字段添加数据
# insert into 表名 (字段名1，字段名2，...) values(值1，值2，...);
# 给全部字段添加数据
# insert into 表名 values(值1，值2，...);
# 批量添加数据
# insert into 表名 (字段名1，字段名2，...) values(值1，值2，...),(值1，值2，...),(值1，值2，...);
# insert into 表名 values(值1，值2，...),(值1，值2，...),(值1，值2，...);
insert into employee(id, workno, name, grnder, age, idcard, entrydate) values(1,'1','张三','男','18','123456789012345678','2020-01-01');
# 查看表数据：
select * from employee;
insert into employee values(2,'2','李四','男','18','123456789012345670','2025-01-01');

insert into employee values(3,'4','王五','男','28','123456789012345671','2005-01-01'),(3,'3','七八','男','14','123456789012345672','2021-01-01');
# 13.修改数据
# update 表名 set 字段名1=值1，字段名2=值2，...[where 条件];
update employee set name='itheima' where id=1;
update  employee set name='小赵',grnder = '女' where id=1;
update employee set entrydate='2008-01-01';
# DML删除表的数据
# delete from 表名 [where 条件];
delete from employee where grnder='女';
delete from employee;
# 14.DML小结
# DQL语句：

drop table employee;
create table emp(
    id int comment'编号',
    workno varchar(10) comment'工号',
    name varchar(10) comment'姓名',
    gender char(1) comment'性别',
    age tinyint unsigned comment'年龄',
    idcard char(18) comment'身份证号',
    workaddress varchar(50) comment'工作地址',
    entrydate date comment'入职时间'
    )comment '员工表';

insert into emp(id, workno, name, gender, age, idcard, workaddress, entrydate)
values (1,'1','刘岩','女',20,'12345678912345678','北京','2000-01-01'),
(2,'2','张无忌','男',18,'123456789012345670','北京','2005-09-01'),
(3,'3','韦一笑','男',38,'123456789712345670','上海','2005-08-01'),
(4,'4','赵敏','女',18,'123456757123845670','北京','2009-12-01'),
(5,'5','小昭','女',16,'123456769012345678','上海','2007-07-01'),
(6,'6','杨逍','男',28,'12345678931234567X','北京','2006-01-01'),
(7,'7','范瑶','男',40,'123456789212345670','北京','2005-05-01'),
(8,'8','黛绮丝','女',38,'123456157123645670','天津','2015-05-01'),
(9,'9','范凉凉','女',45,'123156789012345678','北京','2010-04-01'),
(10,'10','陈友谅','男',53,'123456789012345670','上海','2011-01-01'),
(11,'11','张士诚','男',55,'123567897123465670','江苏','2015-05-01'),
(12,'12','常遇春','男',32,'123446757152345670','北京','2004-02-01'),
(13,'13','张三丰','男',88,'123656789012345678','江苏','2020-11-01'),
(14,'14','灭绝','女',65,'123456719012345670','西安','2019-05-01'),
(15,'15','胡青牛','男',70,'12345674971234567X','西安','2018-04-01'),
(16,'16','周芷若','女',18,null,'北京','2012-06-01');
# 1.查询返回多个字段
# select 字段1，字段2，字段3...from 表名;
# select * from 表名;
# 2.设置别名
# select 字段1[as 别名],字段2[as 别名]...from 表名;
# 3.去除重复记录
# select distinct 字段列表 表名;
select name,workno,age from emp;
select * from emp;
# 实际开发中尽量不要用通配*，不直观
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp;
select workaddress as '工作地址' from emp;
# 其中as可以省略
select workaddress '工作地址' from emp;
# 查询不重复的工作地址
select distinct workaddress from emp;
# 16.条件查询
# select 字段列表 from 表名 where 条件列表;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age=88;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age<=20;
# 身份证为空的和有身份证的
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where idcard is NULL;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where idcard is not null;
# 不等于88岁的
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age!=88;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age<>88;
# age在15到20之间（两边都包含）
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age>=15&&age<=20;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age>=15 and age<=20;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age between 15 and 20;
# 性别为女，而且age少于25
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where gender='女' and age<25;
# age是18或20或40
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age=18 or age=20 or age=40;
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where age in (18,20,40);
# 姓名为两个字的,用占位符，_占一个字符
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where name like '__';
# 身份证最后一位为X的,不管前面多少位
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp where idcard like '%X';
select  id, workno, name, gender, age, idcard, workaddress, entrydate from emp where idcard like '_________________X';
# 17.聚合函数:将一列数据作为一个整体，进行纵向计算,语法：select 聚合函数（字段列表） from 表名；
# 常见：count统计数量，max最大值，min最小值，avg平均值，sum求和
# 统计数量
select count(id) from emp;
select count(*) from emp;
# 统计平均年龄
select avg(age) from emp;
# 最大年龄
select max(age) from emp;
# 最小年龄
select min(age) from emp;
# 西安地区年龄之和
select sum(age) from emp where workaddress='西安';
# 18.分组查询语法：select 字段列表 from 表名 [where 条件] group by 分组字段名 [having 分组后过滤条件]
# where和having区别：
# where是分组前过滤，不满足条件不参与分组，having是分组后对结果进行过滤
# where不能对聚合函数进行判断，而having可以
# 根据性别分组，统计数量
select gender,count(*) from emp group by gender;
# 根据性别分组，统计平均年龄
select gender,avg(age) from emp group by gender;
# 查询age小于45，根据工作地址分组，获取员工数量大于3的工作地址
select workaddress,count(*) workaddress_count from emp where age<45 group by workaddress having count(*)>=3;
# 可以起个别名，在聚合函数和from之间