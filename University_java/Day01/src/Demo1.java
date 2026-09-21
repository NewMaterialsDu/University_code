import java.util.Scanner;
public class Demo1 {

	static void chooseAnOtherAnimal(Animal p) {
		p.cry();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("请输入你要选择的类别：1、人类 2、狗类  ");
		Scanner sc=new Scanner(System.in);
		int i=sc.nextInt();
		if(i==1) {
			chooseAnOtherAnimal(new People());
		}
		if(i==2) {
			chooseAnOtherAnimal(new Dog());
		}
//		if(i==3) {
//			chooseAnOtherAnimal(new Cat());
//		}


		//多态  同一个对象，调用同一个方法，呈现了不同的行为
//		Animal p=new People();  //多态一定是父类对象p得到不同的子类空间
//		p.cry();
//		p=new Dog();
//		p.cry();
//
	}

}
