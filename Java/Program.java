public class Program {

    public static void main(String args[]) {
        int X = 10;
        int Y = 5;
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = i; j < 5; j++) {
                sum = sum + j;
            }
        }
        System.out.print(sum);

    }

}
