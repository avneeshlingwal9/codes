import java.util.Scanner;

public class Q1 {
    static int sm(int... a) {
        int k = 0;
        for (int i : a) {
            k += i;
        }
        return k;

    }

    public static void main(String args[]) {
        int l = sm(1, 2, 3);
        System.out.println(l);

    }

};
