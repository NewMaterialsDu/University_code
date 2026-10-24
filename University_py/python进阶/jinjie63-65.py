# 63.多个装饰器装饰一个函数

def check_login(fn_name):
    def fn_inner():
        print("校验登录。。。")
        fn_name()
    return fn_inner

def check_code(fn_name):
    def fn_inner():
        print("校验验证码。。。。")
        fn_name()
    return fn_inner

# 语法糖写法：从上往下执行（结果是先校验登录再校验验证码）
@check_login
@check_code
def comment():
    print("发表评论")
comment()

# 传统写法：结果是先校验登录在校验验证码
# comment = check_code(comment)
# comment = check_login(comment)
# comment()

# 传统写法由内到外装饰

# 64.带参数的装饰器
# 65.一个装饰器装饰多个函数
# 装饰器只能有一个参数，如果需要装饰多个函数，可以在外面再嵌套一层装饰器

def logging(my_flag):
    def my_decorator(func):
        def my_inner(a,b):
            if my_flag == '+':
                print("正在努力加法计算中")
            elif my_flag == '-':
                print("正在努力做减法中。。。")
            return func(a,b)
        return my_inner
    return my_decorator

@logging('+')
def get_sum(a,b):
    return a+b

@logging('-')
def get_sub(a,b):
    return a-b

get_sum(2,3)
get_sub(2,3)

