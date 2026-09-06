
# 32.约束：
# 非空约束，not null，限制该字段不能为空
# 唯一约束，unique，保证该字段所有数据都是唯一的、不重复的
# 主键约束，primary key，主键是一行数据的唯一标识，要求非空且唯一
# 默认约束，default，保存数据时，如果未指定该字段的值，则采用默认值
# 检查约束，check，保证字段值满足一个条件
# 外键约束，foreign key，用来让两张表的数据之间建立连接，保证数据的一致性和完整性
use test01;

# 33.约束演示
# 建表(也可以通过图形化界面建表)：auto_increment为自动增长
create table user(
    id int primary key auto_increment comment 'ID',
    name varchar(10) not null unique comment '姓名',
    age int check ( age>=0 and age<=120 ) comment'年龄',
    status char(1) default '1' comment '状态',
    gender char(1) comment'性别'
)comment'用户表';
# 插入数据验证
insert into user(name,age,status,gender) values ('Tom',19,'1','男'),('Tom2',25,'0','男');
insert into user(name,age,status,gender) values ('Tom3',19,'1','男');

# name不允许为空,重复也不行
insert into user(name, age, status, gender) values (null,19,'1','男');
insert into user(name,age,status,gender) values ('Tom3',19,'1','男');

# 这里的id为5是因为上一句虽然没有执行成功，但是已经申请了4
insert into user(name,age,status,gender) values ('Tom4',80,'1','男');
# check生效是要MySQL8.0.16以上的版本才支持，而这里用的是tidb
insert into user(name,age,status,gender) values ('Tom5',-1,'1','男');
insert into user(name,age,status,gender) values ('Tom5',121,'1','男');
insert into user(name,age,gender) values ('Tom6',120,'男');
insert into user(name,age,status,gender) values ('Tom7',-1,'1','男');

-- 1. 直接查看表结构，看 CHECK 是否真的存在
SHOW CREATE TABLE user;
-- 2. 尝试插入极度离谱的值
INSERT INTO user(name, age, gender) VALUES ('Test4', 1000, '男');
-- 3. 查看 TiDB 版本
SELECT VERSION();

# 34.外键约束：用来连接两张表
# 准备数据：部门表和员工表
create table dept(
    id int auto_increment comment 'ID' primary key ,
    name varchar(50) not null comment '部门名称'
)comment '部门表';
insert into dept(id,name) values (1,'研发部'),(2,'市场部'),(3,'财务部'),(4,'销售部'),(5,'总经办');

create table emp(
    id int auto_increment comment 'ID' primary key ,
    name varchar(50) not null comment '姓名',
    age int comment '年龄',
    job varchar(20) comment '职位',
    salary int comment '薪资',
    entrydaate date comment '入职时间',
    managerid int comment '直属领导ID',
    dept_id int comment '部门ID'
)comment '员工表';
insert into emp (id, name, age, job, salary, entrydaate, managerid, dept_id) VALUES
    (1,'金庸',66,'总裁',20000,'2000-01-01',null,5),
    (2,'张无忌',20,'项目经理',12500,'2005-12-05',1,1),
    (3,'杨逍',33,'开发',8400,'2000-11-03',2,1),
    (4,'韦一笑',48,'开发',11000,'2002-02-05',2,1),
    (5,'常遇春',43,'开发',10500,'2004-09-07',3,1),
    (6,'小昭',19,'程序员鼓励师',6600,'2004-10-12',2,1);

# 建立外键关联语法：
# create table 表名(
# 字段名 数据类型，
# ....
# [constraint] [外键名称] foreign key(外键字段名) references 主表（主表列名）
# );

# alter table 表名 add constrsint 外键名称 foreign key(外键字段名) references 主表(主表列名);

alter table emp add constraint fk_emp_dept_id foreign key (dept_id) references dept(id);

# 删除外键：
# alter table 表名 drop foreign key 外键名称;
alter table emp drop foreign key fk_emp_dept_id;

# 35.外键删除/更新行为
# no action 或 restrict 当在父表中删除/更新对应记录时，首先检查该记录是否有对应外键，如果有则不允许删除/更新（这两个是默认行为）
# cascade 当在父表中删除/更新对应记录时，首先检查该记录是否有对应外键，如果有，则也删除/更新外键在子表中的记录
# set NULL 当在父表中删除/更新对应记录时，首先检查该记录是否有对应外键，如果有，则设置子表中该外键值为NULL（这就要求外键允许取NULL）
# set default 父表有变更时，子表将外键设置成一个默认的值（Innodb不支持）
# 语法：
# alter table 表名 add constraint 外键名称 foreign key （外键字段） references主表名（主表字段） on update cascade on delete cascade
alter table emp add constraint fk_emp_dept_id foreign key (dept_id) references dept(id) on update cascade on delete cascade;

alter table emp add constraint fk_emp_dept_id foreign key (dept_id) references dept(id) on update set null on delete set null ;

# 36.约束小结

# 37.多表查询
#  一对多或多对一在一的一方建立外键  多对多建立第三张表  一对一可以拆为两张表
# 准备数据：
create table student(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    no varchar(10) comment '学号'
)comment '学生表';
insert into student values(null,'黛丽丝','2000100101'),(null,'谢逊','2000100102'),
                          (null,'殷天正','2000100103'),(null,'韦一笑','2000100104');

create table course(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '课程名称'
)comment '课程表';
insert into course values (null,'Java'),(null,'PHP'),(null,'MySql'),(null,'Hadoop');
# 创建中间表并添加外键
create table student_course(
    id int auto_increment comment'主键' primary key ,
    studentid int not null comment '学生ID',
    courseid int not null comment '课程ID',
    constraint fk_courseid foreign key (courseid) references course(id),
    constraint fk_studentid foreign key (courseid) references student(id)
)comment '学生课程中间表';

insert into student_course values (null,1,1),(null,1,2),
                                  (null,1,3),(null,1,4);

# 一对一
create table tb_user(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    age int comment '年龄',
    gender char(1) comment '1:男,2:女',
    phone char(11) comment '手机号'
)comment '用户基本信息表';

create table tb_user_edu(
    id int auto_increment primary key comment '主键ID',
    degree varchar(20) comment '学历',
    major varchar(50) comment '专业',
    primaryschool varchar(50) comment '小学',
    middleschool varchar(50)  comment '中学',
    university varchar(50) comment '大学',
    userid int unique comment '用户ID',
    constraint fk_userid foreign key (userid) references tb_user(id)
)comment '用户教育信息表';

insert into tb_user(id, name, age, gender, phone) VALUES
                                                      (null,'黄渤',45,'1','18800001111'),
                                                      (null,'冰冰',35,'2','18800002222'),
                                                      (null,'码云',55,'1','18800008888'),
                                                        (null,'李彦宏',50,'1','18800009999');

insert into tb_user_edu(id, degree, major, primaryschool, middleschool, university, userid) VALUES
            (null,'本科','舞蹈','静安区第一小学','静安区第一中学','北京舞蹈学院',1),
            (null,'硕士','表演','朝阳区第一小学','朝阳区第一中学','北京电影学院',2),
            (null,'本科','英语','杭州市第一小学','杭州市第一中学','杭州师范大学',3),
            (null,'本科','应用数学','阳泉第一小学','阳泉市第一中学','清华大学',4);

# 38.多表查询
# 笛卡尔积：两个集合中所有的组合情况（在多表查询时，需要消除无效的笛卡尔积）
select * from dept,emp;
select * from emp02,dept where emp02.dept_id=dept.id;

create table emp02(
    id int primary key unique comment '员工ID',
    name varchar(10) comment '姓名',
    age int comment '年龄',
    job varchar(10) comment '职位',
    salary int comment '薪资',
    entrydate date comment'入职时间',
    managerid int comment '工号',
    dept_id int comment'部门'
)comment'员工表02';

alter table emp02 add constraint fk_emp02_dept_id foreign key (dept_id) references dept(id);

INSERT INTO emp02 (id, name, age, job, salary, entrydate, managerid, dept_id) VALUES
(1, '金庸', 66, '总经理', 20000, '2000-01-01', NULL, 5),
(2, '张无忌', 20, '项目经理', 12500, '2005-12-05', 1, 1),
(3, '杨逍', 33, '开发', 8400, '2000-11-03', 2, 1),
(4, '韦一笑', 48, '开发', 11000, '2002-02-05', 2, 1),
(5, '常遇春', 43, '开发', 10500, '2004-09-07', 3, 1),
(6, '小昭', 19, '程序员鼓励师', 6600, '2004-10-12', 2, 1),
(7, '灭绝', 60, '财务总监', 8500, '2002-09-12', 1, 3),
(8, '周芷若', 19, '会计', 48000, '2006-06-02', 7, 3),
(9, '丁敏君', 23, '出纳', 5250, '2009-05-13', 7, 3),
(10, '赵敏', 20, '市场部总监', 12500, '2004-10-12', 1, 2),
(11, '鹿杖客', 56, '职员', 3750, '2006-10-03', 10, 2),
(12, '鹤笔翁', 19, '职员', 3750, '2007-05-09', 10, 2),
(13, '方东白', 19, '职员', 5500, '2009-02-12', 10, 2),
(14, '张三丰', 88, '销售总监', 14000, '2004-10-12', 1, 4),
(15, '俞莲舟', 38, '销售', 4600, '2004-10-12', 14, 4),
(16, '宋远桥', 40, '销售', 4600, '2004-10-12', 14, 4);

INSERT INTO emp02 (id, name, age, job, salary, entrydate, managerid, dept_id) VALUES
                  (17,'陈友谅',42,null,2000,'2011-10-12',1,null);
# 39.多表查询之内连接(查询两张表交集部分)
# 隐式内连接
# select 字段列表 from 表1，表2 where 条件；
# 显式内连接
# select 字段列表 from 表1 [inner] join 表2 on 连接条件；
select * from dept,emp where emp.dept_id=dept.id;
select * from dept join emp on emp.dept_id=dept.id;

# 40.外连接
# 左外连接：相当于查询左表（表1）的所有数据，包含表1和表2的交集部分
# select 字段列表 from 表1 left [outer] join 表2 on 条件;
select e.*,d.name from emp e left outer join dept d on e.dept_id = d.id;
# 右外连接：相当于查询右表（表2）的所有数据，包含表1和表2的交集部分
# select 字段列表 from 表1 right [outer] join 表2 on 条件;
select d.*,e.* from emp e right outer join dept d on e.dept_id = d.id;

# 41.自连接可以是内连接，也可以是外连接(看成两张表)
# select 字段列表 from 表A 别名A join 表A 别名B on 条件;
select a.name '员工',b.name '直属领导' from emp a,emp b where a.managerid=b.id;
# 员工没有领导也要查询出来（用外连接）
select a.name '员工',b.name '直属领导' from emp a left join emp b on a.managerid=b.id;

# 42.联合查询：把多次查询的结果合并起来，形成一个新的查询结果集(并集)  语法：（多张表的字段列表必须一致）
# select 字段列表 from 表A...
# union [all]    all表示全部，没有则表示去重
# select 字段列表 from 表B...;
# 查询薪资低于5000和年龄大于50的员工
select * from emp02 where salary < 5000
union all
select * from emp02 where age > 50;

# 43-47.子查询（嵌套查询）
# 语法：select * from t1 where column1=（select colum1 from t2）；
# 子查询外部的查询语句可以是：insert/update/delete/select 的任何一个
# 标量子查询、列子查询、行子查询、表子查询
# 常用：any/some：子查询列表中，有任意一个满足即可
# all：所有条件都满足
# in：在指定集合范围内
# not in：不在指定集合范围内
