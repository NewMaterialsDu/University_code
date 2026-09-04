/*
DDL语句：用来定义数据库对象（数据库，表，字段）
DML语句，用来对数据库表中的数据进行增删改
DQL语句，用来查询数据库中表的记录
DCL语句，用来创建数据库用户、控制数据库的访问权限
 */
 #DDL语句：
show databases;#查询所有数据库   中括号表示可选
select database();#查询当前数据库
# create [if not exists] 数据库名 [default charset 字符集] [collate 排序规则]; #创建数据库
# drop database [if exists] 数据库名;#删除数据库
# use 数据库名; #使用数据库
use test01;
show tables;#查询当前数据库所有表
# create table 表名(
#     字段1 类型 [comment 注释],
#     字段2 类型 [comment 注释],
#     字段3 类型 [comment 注释],
#     字段4 类型 [comment 注释]
#     )[comment 表注释]; #创建表
create table tb_user(
    id int comment'编号',
    name varchar(50) comment'姓名',
    age int comment'年龄',
    gender varchar(1) comment'性别'
)comment'用户表';
# show create table 表名;#查询指定表的建表语句
# desc 表名;#查询表结构
desc tb_user;
show create table tb_user;
# 08.MySQL的数据类型：数值类型，字符串类型，时间日期类型
create table emp
(
    id        int comment '编号',
    workno    varchar(10) comment '工号',
    name      varchar(10) comment '姓名',
    grnder    char(1) comment '性别',
    age       tinyint unsigned comment '年龄',#这里加一个unsigned表示无符号，有符号范围和无符号范围不一样
    idcard    varchar(18) comment '身份证号',
    entrydate date comment '入职时间'
) comment '员工表';
desc emp;
# 09.表的修改操作
# 添加字段语句：
# alter table 表名 add 字段名 类型(长度) [comment '注释'] [约束];
alter table emp add nickname varchar(20) comment'昵称';
# 修改字段类型：alter table 表名 modify 字段名 新数据类型(长度);
# 修改字段类型和字段名：alter table 表名 change 旧字段名 新字段名 类型(长度) [comment'注释'] [约束];
alter table emp change nickname username varchar(30) comment'用户名';
# 删除字段：alter table 表名 drop 字段名;
alter table emp drop username;
# 修改表名：alter table 表名 remname to 表名;
alter table emp rename to employee;
desc employee;
# 删除表：drop table [if exists] 表名;
# 删除表，并重新创建该表(即初始化)：truncate table 表名;
drop table tb_user;
truncate table employee;
# 10.DDL小结
# 11.MySQL图形化界面

