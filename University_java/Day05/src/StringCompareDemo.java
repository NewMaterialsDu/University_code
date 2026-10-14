
import java.util.Scanner;

public class StringCompareDemo {
    public static void main(String[] args) {
        String s1 = "hello";
        String s2 = "hello";
        String s3 = new String("helllo");
        String s4 = new String("helllo");

        //==:比较两个引用是否指向同一个对象（内存地址），判断是否为同一对象
        System.out.println(s1 == s2);
        System.out.println(s1 == s3);
        System.out.println(s4 == s3);

        //equals:比较的是内容是否相同，判断内容是否相等
        System.out.println(s1.equals(s3));
        System.out.println(s3.equals(s4));

        //equalsIgnoreCase:比较内容，忽略大小写，验证码、用户等场景
        String s5 = "Hello";
        System.out.println(s1.equalsIgnoreCase(s5));

        System.out.println("请输入你的名字：");
        Scanner sc = new Scanner(System.in);
        String name = sc.next();



    }

}