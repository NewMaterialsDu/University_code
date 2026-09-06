use test01;

# 48-49.多表查询练习：
# 数据准备：
create table salgrade(
    grade int,
    losal int,
    hisal int
)comment '薪资等级表';

insert into salgrade values (1,0,3000);
insert into salgrade values (2,3001,5000);
insert into salgrade values (3,5001,8000);
insert into salgrade values (4,8001,10000);
insert into salgrade values (5,10001,15000);
insert into salgrade values (6,15001,20000);
insert into salgrade values (7,25001,25000);
insert into salgrade values (8,30001,30000);
# 1.查询员工姓名、年龄、职位、部门信息（隐式链接）：
    select emp02.name,age,job,d.name from emp02, test01.dept d where d.id = emp02.dept_id;
# 2.查询年龄小于30岁的员工姓名、年龄、职位、部门信息（显式链接）
    select emp02.name,age,job,d.name from emp02 join dept d on d.id = emp02.dept_id and age<30;
# 3.查询拥有员工部门ID、部门名称
    select distinct dept.id,dept.name from dept;
# 4.查询所有年龄大于40岁的员工，及其归属的部门名称；如果员工没有分配部门，也要显示出来
    select e.*,d.name from emp02 e left join dept d on e.dept_id = d.id where e.age>40;
# 5.查询所有员工的工资等级
    select  e.*,s.grade,s.losal,s.hisal from emp e,salgrade s where e.salary >= s.losal and e.salary<=s.hisal;
# 6.查询研发部所有员工信息及工资等级
select distinct e.*, s.grade, d.name
from emp02 e,
     salgrade s,
     dept d
where e.dept_id = d.id
  and d.name = '研发部'
  and e.salary between s.losal and s.hisal;
# 7.查询研发部员工的平均工资
 select avg(e.salary) from emp02 e where dept_id=1  ;
# 8.查询比灭绝工资高的员工
select * from emp02 e where e.salary > (select e.salary from emp02 e where e.name='灭绝') ;
# 9.查询比平均工资高的员工信息
select * from emp02 e where e.salary > (select avg(e.salary) from emp02 e);
# 10.查询低于本部门平均工资的员工信息
select *, (select avg(e1.salary) from emp02 e1 where e1.dept_id = e2.dept_id) '平均薪资'
from emp02 e2
where e2.salary < (select avg(e1.salary) from emp02 e1 where e1.dept_id = e2.dept_id);
# 11.查询所有员工部门信息，并统计该部门的员工人数
select d.id,d.name,(select count(*) from emp02 e where e.dept_id=d.id) '人数' from dept d;
# 12.查询所有学生的选课情况，展示出学生的名称，学号，课程名称
select s.name,s.no,c.name from student s,student_course sc,course c where s.id=sc.studentid and sc.courseid=c.id;

# 50.小结




