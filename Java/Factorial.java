import java.util.Scanner;

public class Factorial {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int n = scanner.nextInt();
        Factorial f = new Factorial();
        if (n > 0) {
            System.out.println("Factorial of the number is: " + f.calculateFactorial(n));
        } else {
            System.out.println("Wrong number");
        }

        scanner.close();
    }

    public int calculateFactorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * calculateFactorial(n - 1);
        }
    }
}
