import java.util.Scanner;

public class New {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter operation (+, -, *, /) or 'exit' to end: ");
        String operation = scanner.nextLine();

        System.out.println("Enter first number: ");
        double num1 = scanner.nextDouble();

        System.out.println("Enter second number: ");
        double num2 = scanner.nextDouble();

        double result = 0.0;

        switch (operation) {
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
            case "*":
                result = num1 * num2;
                break;
            case "/":
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    System.out.println("Error: Division by zero");
                    break;
                }
                break;
            default:
                System.out.println("Invalid operation. Please enter +, -, *, or /");
                break;
        }

        System.out.println("Result: " + result);
        scanner.close();

    }
}
