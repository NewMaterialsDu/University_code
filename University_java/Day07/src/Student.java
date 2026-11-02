
public class Student {
    private String id;     // 学号
    private String name;   // 姓名
    private int age;       // 年龄

    public Student(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public String getId()   { return id; }
    public String getName() { return name; }
    public int getAge()     { return age; }

    public void setName(String name) { this.name = name; }
    public void setAge(int age)      { this.age = age; }

    @Override
    public String toString() {
        return "学号:" + id + "  姓名:" + name + "  年龄:" + age;
    }
}