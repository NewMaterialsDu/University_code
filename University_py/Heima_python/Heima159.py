# 159.pythonweb应用

# 160.面向对象-封装
# 封装就是把数据（属性）和操作数据的函数（方法）捆绑在一起，形成一个独立的单元（类），并隐藏内部的实现细节，只对外暴露必要的功能（方法）
# 在方法或者属性前加__就是私有（python中是没有真正的私有，这只是一个君子约定，别人想要还是可以拿到）
class Car(object):
    def __init__(self,c_brand,c_model,c_color,c_owen):
        self.color = c_color
        self.brand = c_brand
        self.model = c_model
        self.__owen = c_owen

    def start(self):
        print(f"{self.brand} {self.model} 正在启动。。。")

    def stop(self):
        print(f"{self.brand} {self.model} 停止行驶。。。")

    def run(self):
        print(f"{self.brand} {self.model} 正在行驶。。。")

    def __print_owen(self):
        print(f"整台车属于{self.__owen}")

    def charge(self):
        print(f'{self.brand} {self.model} 正在补充燃料。。。')

if __name__ == "__main__":
    car = Car('Audi','A6','黑色','我的')
    print(car.brand,car.model,car.color)
    # print(car.__owen)
    car.start()
    car.stop()
    car.run()
    # car.__print_owen()

# 161.继承
class FuelCar(Car):
    pass
# 继承的只能是非私有的属性和方法
# 所有类都有一个父类（object）
c1 = FuelCar('BMW','X5','黑色','zs')
print(c1.brand,c1.model,c1.color)
c1.start()
c1.stop()
c1.run()

# 162.继承-重写方法
# 子类继承父类之后的方法不满足需求，可以在子类中重新定义父类中已有的方法（方法名相同）
# 如果子类在重写父类的方法时需要调用父类的方法，可以通过：父类名.方法名(self) / super().方法名()
class FuelCar01(Car):
    def charge(self):
        super().charge()
        Car.charge(self)
        print(f'{self.brand} {self.model} 正在加油。。。')
c1 = FuelCar01('BMW','X5','黑色','zs')
c1.charge()

# 163.多继承
class HuaweiAiDriving:
    def __init__(self,version='v1.0'):
        self.version = version
    def run(self):
        print(f'使用华为AI智能驾驶系统{self.version}正在行驶。。。')

class WenjieCar(Car,HuaweiAiDriving):
    pass

# 当一个类继承了多个父类时
c2 = WenjieCar("")