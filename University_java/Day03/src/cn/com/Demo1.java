package cn.com;

public class Demo1 {
	static void change(Animal a) {
		if(a instanceof Monkey) {
			Monkey m=(Monkey)a;  //强制往下转型
			m.jump();   //可以使用子类新增加的方法和属性
		}
		if(a instanceof SnowWhitePrincess) {
			SnowWhitePrincess s=(SnowWhitePrincess)a;  //强制往下转型
			s.eatApple();  //可以使用子类新增加的方法和属性
		}
	}
	public static void main(String[] args) {
		Animal a=new SnowWhitePrincess();
		a.type="动物";
		a=new Monkey();
		change(a);
		double b=20.5;
		int a1=(int)b;
		System.out.println(a1);


	}

}
