package day04;

import java.util.Random;

public class RandomTest {
    public static void main(String[] args){
        Random random = new Random();
        int result=random.nextInt(10,20);
        System.out.println("随机数是：" + result);
        System.out.println("好了好了");



    }

}