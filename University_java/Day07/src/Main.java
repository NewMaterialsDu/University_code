
import java.util.Scanner;

public class Main {
    private static final Scanner sc = new Scanner(System.in);
    private static final StudentManager manager = new StudentManager();

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n===== 学生管理系统 =====");
            System.out.println("1. 添加学生");
            System.out.println("2. 删除学生");
            System.out.println("3. 修改学生");
            System.out.println("4. 查看全部");
            System.out.println("5. 按学号查找");
            System.out.println("0. 退出");
            System.out.print("请选择：");

            String choice = sc.nextLine().trim();
            switch (choice) {
                case "1":
                    addStudent();
                    break;
                case "2":
                    removeStudent();
                    break;
                case "3":
                    updateStudent();
                    break;
                case "4":
                    manager.showAll();
                    break;
                case "5":
                    findStudent();
                    break;
                case "0":
                    System.out.println("已退出，再见！");
                    return;
                default:
                    System.out.println("输入有误，请重新选择");
            }
        }
    }

    private static void addStudent() {
        System.out.print("请输入学号：");
        String id = sc.nextLine().trim();
        System.out.print("请输入姓名：");
        String name = sc.nextLine().trim();
        int age = readInt("请输入年龄：");

        if (manager.add(new Student(id, name, age))) {
            System.out.println("添加成功！");
        } else {
            System.out.println("学号已存在，添加失败！");
        }
    }

    private static void removeStudent() {
        System.out.print("请输入要删除的学号：");
        String id = sc.nextLine().trim();
        System.out.println(manager.remove(id) ? "删除成功！" : "未找到该学生！");
    }

    private static void updateStudent() {
        System.out.print("请输入要修改的学号：");
        String id = sc.nextLine().trim();
        if (manager.findById(id) == null) {
            System.out.println("未找到该学生！");
            return;
        }
        System.out.print("请输入新姓名：");
        String name = sc.nextLine().trim();
        int age = readInt("请输入新年龄：");
        manager.update(id, name, age);
        System.out.println("修改成功！");
    }

    private static void findStudent() {
        System.out.print("请输入要查找的学号：");
        String id = sc.nextLine().trim();
        Student s = manager.findById(id);
        System.out.println(s == null ? "未找到该学生！" : s);
    }

    // 读取一个整数，输入非法时提示重输
    private static int readInt(String tip) {
        while (true) {
            System.out.print(tip);
            try {
                return Integer.parseInt(sc.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("请输入数字！");
            }
        }
    }
}