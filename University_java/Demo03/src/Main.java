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

        //当+出现在字符串操作中时，+会将前后的数据进行拼接，产生一个新的字符串。连续+号出现的时候，从左到右逐个执行
        System.out.println(1 + 99 + "heima");

        //int byte char 三个相加的时候都会先提升为int类型再相加（char会转为ASCII码相加）
        char c1 = 'a';
        System.out.println(c1 + 0);
        System.out.println(c1 + 'a');

        //自增和自减运算符++--
        //放在后面是先用再加加，放在前面是先加加再用
        int a3 =1;
        int b3 = a3++;
        System.out.println(b3);

        int a4=10;
        int b4=++a4;
        System.out.println(b4);

        //赋值运算符=，+=，-=，*=，/=，%=
        //      赋值，加后赋值，减后赋值，乘后赋值，取余后赋值
        //a += b;相当于a = （a的类型）（a + b）会强转为a的类型
        int a5=10;
        int b5=20;
        System.out.println(a5);
        a5 += b5;
        System.out.println(a5);
        a5 -= b5;
        System.out.println(a5);
        a5 *= b5;
        System.out.println(a5);
        a5 %= b5;
        System.out.println(a5);
        a5 /= b5;
        System.out.println(a5);

        //(比较运算符)关系运算符==,!=,>,<,>=,<=。成立则返回true，不成立则返回flase。关系运算符的结果都是Boolean类型
        System.out.println(a5 == b5);
        System.out.println(a5 != b5);

        //逻辑运算符：
        //& 逻辑与（且）  并且，两边都为真，结果才是真
        //| 逻辑或       或者，两边都为假，结果才是假
        //^ 逻辑异或     相同为flase，不同为true
        //！ 逻辑非      取反
        System.out.println(true & false);
        System.out.println(true | false);
        System.out.println(true ^ true);
        System.out.println(!false);
        //&&短路与，||短路或。跟&和|相同，但是有短路效果
        //单个&，当一个为假是，结果已经为假，但是它还是会去判断第二个。但是&&，如果判断第一个为假，它就1直接结果为假，不判断第二个，效率较高。||同理

        //三元运算符格式：关系表达式?表达式1:表达式2;
        //关系表达式为真，则返回表达式1，为假则返回表达式2
        System.out.println(20 > 10 ? true : false);

        //优先级：（）优先于所有

        //原码，反码，补码
        //原码：十进制的二进制表现形式，最左边是符号位，0为正，1为负（但是如果是负数计算，实际运算的结果是相反的）
        //反码：为了解决原码不能原码不能计算负数的问题而出现的（计算规则：正数的反码不变，负数的反码在原码的基础上，符号位不变，数值取反，0变1，1变0）
        //补码 = 反码 + 1（为了解决当负数跨越0计算变成正数的时候，用反码计算会出问题11111111加一应该是00000000，所以补码就后退一位，11111111做-1，以此类推）
        //注意：计算机中的存储和计算都是以补码的形式进行的
        








    }
}
