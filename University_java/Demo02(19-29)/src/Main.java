import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
       //19.
        //定义变量：
        //数据类型 变量名 = 数据值;
        int a = 10;
        System.out.println(a);

        //20.
        //变量参与计算
        int b = 10, c = 20;
        System.out.println(b + c);

        //21.变量的练习

        //22.jdk7以上规定，二进制0b开头，十进制默认，八进制0开头，十六进制0x开头（大小写都可以）
        System.out.println(17);
        System.out.println(017);
//      System.out.println(0b123);//报错
        System.out.println(0x123);

        //23.数据类型
        //基本数据类型：整数：byte,short,int,long;浮点数：float,double;字符：char;布尔：boolean
        byte q = 10;
        short s = 20;
        int i = 30;
        //要定义long时，需在数据值后面加一个L大小写都可以
        long n = 999999999L;
        System.out.println(q);
        System.out.println(s);
        System.out.println(i);
        System.out.println(n);
        //定义float时也要加一个F作为后缀(大小写都可以)
        float f = 10.5F;
        System.out.println(f);
        double d = 10.5;
        System.out.println(d);
        char ch = 'a';
        System.out.println(ch);
        boolean bool = true;
        System.out.println(bool);

        //命名规则：由数字、字母、下划线和美元符号$组成，不能以数字开头，不能是关键字，要区分大小写

        //键盘录入：1.导包，导入Scanner，要写在类的定义上
        //2.创建对象，表示我现在准备要用Scanner这个类
        Scanner sc = new Scanner(System.in);
        //3.接受数据
        System.out.println("请输入整数：");
        int ok =sc.nextInt();
        System.out.println(ok);






    }



}


