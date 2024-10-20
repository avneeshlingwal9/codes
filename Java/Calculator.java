import java.util.*;

public class Calculator {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the input: - ");
        String input = in.nextLine();
        if (input.contains("c")) {
            StringBuilder k = new StringBuilder();
            for (char f : input.toCharArray()) {
                k.append(gui_map(f));

            }
            String d = k.toString();

            String[] parts = d.split("[+/X-]");
            char operator = d.charAt(parts[0].length());
            Double op1 = Double.parseDouble(parts[0]);
            Double op2 = Double.parseDouble(parts[1].substring(0, parts[1].length() - 1));
            switch (operator) {
                case '+':
                    System.out.println(op1 + op2);
                    break;
                case '-':
                    System.out.println(op1 - op2);
                    break;
                case 'X':
                    System.out.println(op1 * op2);
                case '/':
                    System.out.println(op1 / op2);

            }

        } else {
            System.out.print("Invalid input");
        }

    }

    static char gui_map(char in) {
        char out = 'N';// N = Null/Empty
        char gm[][] = { { 'a', '.' }, { 'b', '0' }, { 'c', '=' }, { 'd', '+' }, { 'e', '1' }, { 'f', '2' },
                { 'g', '3' }, { 'h', '-' }, { 'i', '4' }, { 'j', '5' }, { 'k', '6' }, { 'l', 'X' }, { 'm', '7' },
                { 'n', '8' }, { 'o', '9' }, { 'p', '/' } };

        // Checking for maps
        for (int i = 0; i < gm.length; i++) {
            if (gm[i][0] == in) {
                out = gm[i][1];
                break;
            }
        }
        return out;
    }
}
