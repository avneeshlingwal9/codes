import java.util.Scanner;

public class Pattern {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n;
        n = s.nextInt();
        if (n % 2 == 0) {
            System.out.print("Invalid line number ");

        } else {
            int k = (n + 1) / 2;

            for (int i = 1; i <= k; i++) {
                for (int space = 0; space < k - i; space++) {
                    System.out.print(" ");

                }
                for (int j = 0; j < i; j++) {
                    System.out.print("* ");
                }

                System.out.println();

            }

            for (int i = k - 1; i > 0; i--) {
                for (int space = 0; space < k - i; space++) {
                    System.out.print(" ");
                }
                for (int j = 0; j < i; j++) {
                    System.out.print("*");
                    if (j != i - 1) {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }

        }

    }
}
