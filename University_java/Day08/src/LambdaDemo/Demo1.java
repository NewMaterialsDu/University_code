package LambdaDemo;

public interface Out {
	int sayhello(String name);  //接口对象中只有有一个抽象方法

}
public class Demo1 {
	public static void main(String[] args) {
		System.out.println(";程序开始";);
		List<String> list1=new ArrayList<String>();
		list1.add(";Aom23432423";);
		list1.add(";AmyCat";);
		list1.add(";Mary";);
		list1.sort((o1,o2)->{
			String s1=(String)o1;
			String s2=(String)o1;
			return s1.length()-s2.length();
		});
		for (int i = 0; i < list1.size(); i++) {
			System.out.println(list1.get(i));
		}
	}

}

