package P2;

import java.util.Scanner;

public class g4 {
    public void pattern(int p) throws  NumberFormatException{
        if (p <1){
            throw new NumberFormatException() ;
        }
        else{
            for(int i = 1 ; i < p+1;i++){
                for(int j = i ; j<p; j++){
                    System.out.print(" ");
                    System.out.print(" ");
                }
                for(int k =1 ; k < i+1; k++){
                    System.out.print(k);
                    System.out.print(" ");
                }
                for(int l = i-1 ; l >0 ;l--){
                    System.out.print(l);
                    System.out.print(" ");}
                System.out.println();

            }


        }
    }


    public static void main(String args[]) {
        try{
        int  p ;

        Scanner s = new Scanner(System.in);

        System.out.println("Enter the number of lines for the pattern: ");
        p = s.nextInt();
        g4 g = new g4();
        g.pattern(p);
        }
        catch (NumberFormatException n){
            System.out.println("Please Enter a positive number");
        }







    }
}

