public class Main {
    public static void main(String[] args){
        //循环：for、while、do...while
        //for(初始化语句;条件判断语句;条件控制语句){代码体;}
        //while(条件判断语句){代码体;}
        //do{代码体;条件控制语句;}while(条件判断语句);
        int i47 = 0;
        for(int j=0;j<100;j++){
            System.out.println(j);
        }
        while(i47 < 100){
            System.out.println(i47);
            i47++;
        }
        do{
            System.out.println(i47);
            i47++;
        }while (i47 < 100);

        //continue是结束当前循环；break是结束整个循环
        for(int j=0;j<100;j++){
            if(j == 50){
                continue;
            }
            System.out.println(j);
        }
        while(i47 < 100){
            if(i47 == 10){
                break;
            }
            System.out.println(i47);
        }

        //数组的定义：数据类型[] 数组名  or   数据类型 数组名[]
        //数组初始化，静态初始化（117795200完整格式）：数据类型[] 数组名 = new 数据类型[] {元素，元素，元素，元素}
        //简写格式：数据类型[] = {元素，元素，元素，。。。。。}

        //打印数组地址
        int [] arr = {1,2,3,4,5};
        System.out.println(arr);
        //[表示这是一个数组的地址
        //I表示里面存的是int类型
        //@表示间隔符
        //后面的一串是十六进制的地址值

        //操作数组：数组名[索引]
        //数组长度：数组名.length
        //idea提供的快速遍历：数组名.fori

        //动态初始化：自己给出数组长度，初始值由系统给出
        //动态初始化：数据类型[] 数组名 = new 数据类型[数组长度]

        //数组默认初始化值：整数类型0，小数类型0.0，字符类型'/u0000' 空格，布尔类型false，引用数据类型null
        int arr1[] = new int[6];
        System.out.println(arr1[0]);

        //栈：程序主入口，main要在栈里面去运行
        //堆：new新建的都在堆里

        //方法：是程序中最小的执行单元

        //方法的定义和调用
        










    }

}
