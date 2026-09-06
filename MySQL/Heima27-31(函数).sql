
# 27.函数
# 字符串函数：
# concat（s1,s2,...,sn）将多个字符串拼接成一个
# lower（str）将字符串str全部转换为小写
# upper（str）将字符串str全部转换为大写
# lpad（str，n，pad）左填充，用字符串pad对str的左边进行填充，达到n个字符串长度
# rpad（str，n，pad）右填充
# trim（str）去掉字符串头部和尾部的空格
# substring（str，start，len）返回字符串str从start起的len个长度(字符串str从1开始)
select concat('hello','mysql');
select lower('Hello');
select upper('Hello');
select lpad('01',5,'-');
select rpad('01',5,'-');
select trim('   Hello   MySql');
select substring('Hello mysql',1,5);
# 修改员工工号为五位数，不足的前面补0
use test01;
update emp set workno = lpad(workno,5,'0');

# 28.数值函数：
# ceil（x）向上取整
# floor（x）向下取整
# mod（x,y）取x/y的模，即取余数
# rand（）0-1内的随机数
# round（x/y）求参数x的四舍五入的值，保留y位小数
select ceil(1.1);
select floor(1.9);
select mod(7,4);
select rand();
select round(3.14,2);
# 生成一个六位数的随机验证码:生成随机数，×1000000，向上取整，不够后面补0
select rpad(ceil(rand()*1000000),6,'0');

# 29.日期函数：
# curdate（） 返回当前日期
# curtime（） 返回当前时间
# now（） 返回当前日期和时间
# year（date）获取指定date的年份
# month（date）获取指定date的月份
# day（date）获取指定date的日期
# date_add（date，interval expr type）返回上一个日期/时间值加上一个时间间隔expr后的时间值
# datediff（date1，date2）返回起始时间date1，和结束时间date2之间的天数
select curdate();
select curtime();
select now();
select year(now());
select month(now());
select day(now());
# 往后推70天,往前推就写负数
select date_add(now(),interval 70 day);
select date_add(now(),interval -70 day);
# 实质是用第一个减去第二个
select datediff(now(),'2021-12-01');
# 查询所有员工的入职天数，并根据入职天数倒序排序
select name,datediff(curdate(),entrydate) as 'entrydays' from emp order by entrydays desc;

# 30.流程控制函数：
# if（value，t，f）如果value位true则返回t，否则返回f
# ifnull（value1，value2）如果value1不为空，则返回value1，否则返回value2
# case when [val1] then [res1] .... else [default] end 如果val1为true，返回res1，.... ，否则返回default默认值
# case [expr] when [val1] then [res1] .... else[default] end 如果expr的值等于val1，返回res1，.... ，否则返回default默认值
select if(true,'ok','error');
select ifnull('ok','default');
select ifnull('','default');
select ifnull(null,'default');
# 查询emp员工的姓名和工作地址（北京/上海--》一线，其他--》二线）
select name,workaddress,case workaddress when '北京' then '一线城市' when '上海' then '一线城市' else '二线城市' end from emp;
select name,workaddress,if(workaddress='北京'or'上海','一线城市','二线城市') from emp;

create table score(
    id int comment 'ID',
    name varchar(20) comment '姓名',
    math int comment '数学',
    english int comment '英语',
    chinese int comment '语文'
)comment '学员成绩表';
insert into score(id,name,math,english,chinese) values (1,'Tom',67,88,95),(2,'Rose',23,66,90),(3,'Jack',56,98,76);
# >=85优秀,>=60及格,不及格
select name,
       case when math >= 85 then '优秀' when math >= 60 then '及格' else '不及格' end,
       case when english >= 85 then '优秀' when english >= 60 then '及格' else '不及格' end,
       case when chinese >= 85 then '优秀' when chinese >= 60 then '及格' else '不及格' end
from score;
# 31.函数小结
