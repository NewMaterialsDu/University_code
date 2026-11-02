
import java.util.ArrayList;
import java.util.List;

public class StudentManager {
    // 用集合保存所有学生（封装起来，外部不能直接改）
    private final List<Student> students = new ArrayList<>();

    // 添加学生，学号重复则返回 false
    public boolean add(Student s) {
        if (findById(s.getId()) != null) {
            return false;
        }
        students.add(s);
        return true;
    }

    // 按学号查找，找不到返回 null
    public Student findById(String id) {
        for (Student s : students) {
            if (s.getId().equals(id)) {
                return s;
            }
        }
        return null;
    }

    // 按学号删除
    public boolean remove(String id) {
        Student s = findById(id);
        if (s == null) {
            return false;
        }
        students.remove(s);
        return true;
    }

    // 按学号修改姓名和年龄
    public boolean update(String id, String name, int age) {
        Student s = findById(id);
        if (s == null) {
            return false;
        }
        s.setName(name);
        s.setAge(age);
        return true;
    }

    // 打印全部学生
    public void showAll() {
        if (students.isEmpty()) {
            System.out.println("暂无学生记录");
            return;
        }
        for (Student s : students) {
            System.out.println(s);
        }
    }
}