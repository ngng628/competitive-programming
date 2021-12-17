import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        s = s.replaceAll("6", "X");
      	s = s.replaceAll("9", "6");
        s = s.replaceAll("X", "9");
        StringBuilder t = new StringBuilder();
        t.append(s);
        t.reverse();
        System.out.println(t);
    }
}