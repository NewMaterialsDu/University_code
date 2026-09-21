public class Main {
    public static void main(String[] args) {
        //算术运算符:+-*/%
        System.out.println(3+2);
        System.out.println(3-2);
        System.out.println(3*2);
        System.out.println(3/2);
        System.out.println(3%2);

        //，如果有小数参与运算，结果有可能是不精确的
        System.out.println(1.1 + 1.01);
        System.out.println(1.1 - 1.01);
        System.out.println(1.1 * 1.01);
        System.out.println(1.1 / 1.01);
        System.out.println(1.1 % 1.01);

        //隐式转换和强制转换
        //数字如果类型不一样是不能运算，要转换才能运算
        //取值范围小的数值转换为取值范围大的数值
        int a = 1;
        double b = a;
        System.out.println(b);
        //byte,short,char三种类型的数据在运算的时候，都会直接先提升为int，然后再进行运算
        byte c = 10;
        byte d = 10;
        System.out.println();
        //如果把一个取值范围大的数值，赋值给取值范围小的变量，是不允许的，如果一定要这么做就要加入强制转换
        double a1 =12.3;
        int a2 = (int)a1;
        //注意：如果本来就超出范围就会溢出或者报错
        byte b1 = 100;
        byte b2 = 50;
//        byte result = byte(b1 + b2);
//        System.out.println(result);

        //当+出现在字符串操作中时，+会将前后的数据进行拼接，产生一个新的字符串
        

    }
}
