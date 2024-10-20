import java.util.Scanner;

public class Calc {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: -");
        String input = sc.nextLine();
        if (input.contains("p")) {
            String[] inp = input.split("p");
            char op = gui_map('p');
            String a = inp[0], b = inp[1];
            double inp1 = 0, inp2 = 0;
            char[] c = a.toCharArray();
            char[] d = b.toCharArray();
            if (d[d.length - 1] == 'c') {
                for (int i = 0; i < c.length; i++) {
                    c[i] = gui_map(c[i]);
                }
                for (int j = 0; j < d.length; j++) {
                    d[j] = gui_map(d[j]);
                }
                a = String.valueOf(c);
                b = String.valueOf(d);
                b = b.substring(0, b.length() - 2);
                inp1 = Double.parseDouble(a);
                inp2 = Double.parseDouble(b);
                System.out.print(inp1 / inp2);

            }

        } else if (input.contains("d")) {
            String[] inp = input.split("d");
            char op = gui_map('d');
            String a = inp[0], b = inp[1];
            double inp1 = 0, inp2 = 0;
            char[] c = a.toCharArray();
            char[] d = b.toCharArray();
            if (d[d.length - 1] == 'c') {
                for (int i = 0; i < c.length; i++) {
                    c[i] = gui_map(c[i]);
                }
                for (int j = 0; j < d.length; j++) {
                    d[j] = gui_map(d[j]);
                }
                a = String.valueOf(c);
                b = String.valueOf(d);
                b = b.substring(0, b.length() - 2);
                inp1 = Double.parseDouble(a);
                inp2 = Double.parseDouble(b);
                System.out.print(inp1 + inp2);

            }

        } else if (input.contains("h")) {
            String[] inp = input.split("h");
            char op = gui_map('h');
            String a = inp[0], b = inp[1];
            double inp1 = 0, inp2 = 0;
            char[] c = a.toCharArray();
            char[] d = b.toCharArray();
            if (d[d.length - 1] == 'c') {
                for (int i = 0; i < c.length; i++) {
                    c[i] = gui_map(c[i]);
                }
                for (int j = 0; j < d.length; j++) {
                    d[j] = gui_map(d[j]);
                }
                a = String.valueOf(c);
                b = String.valueOf(d);
                b = b.substring(0, b.length() - 2);
                inp1 = Double.parseDouble(a);
                inp2 = Double.parseDouble(b);
                System.out.print(inp1 - inp2);

            }
        } else if (input.contains("l")) {
            String[] inp = input.split("l");
            char op = gui_map('l');
            String a = inp[0], b = inp[1];
            double inp1 = 0, inp2 = 0;
            char[] c = a.toCharArray();
            char[] d = b.toCharArray();
            if (d[d.length - 1] == 'c') {
                for (int i = 0; i < c.length; i++) {
                    c[i] = gui_map(c[i]);
                }
                for (int j = 0; j < d.length; j++) {
                    d[j] = gui_map(d[j]);
                }
                a = String.valueOf(c);
                b = String.valueOf(d);
                b = b.substring(0, b.length() - 1);
                inp1 = Double.parseDouble(a);
                inp2 = Double.parseDouble(b);
                System.out.print(inp1 * inp2);

            }
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