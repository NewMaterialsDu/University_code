import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class CollectionDemo01 {
    public static void main(String[] args) {
        List<String> l1 = new ArrayList<String>();
        l1.add("H");
        l1.add("e");
        l1.add("l");
        l1.add("l");
        l1.add("o");

        Iterator<String> it = l1.iterator();

        while(it.hasNext()) {
            String s = it.next();
            System.out.println(s);
        }
        System.out.println(l1.isEmpty());












    }
}
