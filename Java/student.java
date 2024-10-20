import java.util.Scanner ; 
public class student {
    String  name, sub1,sub2,sub3,sub4 ; 
    int num_1 , num_2 , num_3 , num_4 ; 
    Scanner n = new Scanner(System.in);
    public student(){
        System.out.print("Enter your name : - " );
        this.name = n.nextLine();
        System.out.print("Enter the name of your subjects : - ");
        this.sub1 = n.nextLine();
        this.sub2 = n.nextLine();
        this.sub3 = n.nextLine();
        this.sub4 = n.nextLine();
        System.out.print("Enter your marks in " + sub1 + " :- ");
        this.num_1 = n.nextInt();
        System.out.print("Enter your marks in "  + sub2 + " :- ");
        this.num_2 = n.nextInt();
        System.out.print("Enter your marks in " + sub3 + ":- ");
        this.num_3 = n.nextInt();
        System.out.print("Enter marks in " + sub4 + " : - ");
        this.num_4 = n.nextInt();
    }
    public  int  sum(){
        return num_1+num_2 +num_3 + num_4 ;
    }
    public float prct(){
        return (sum()/4);
    }
   public String grd(float mrk ){
    if ( mrk > 95 ) {
        return "A+";
    }
    else if( mrk <=95 && mrk > 90 ){
        return "A";
    }
    else if( mrk <= 90 && mrk > 85){
        return "B+";
    }
    else if( mrk <=85 && mrk > 80 ){
        return "B";
    }
    else if (mrk <= 80 && mrk > 75){
        return "C+";
    }
    else if( mrk <= 75 && mrk > 70){
        return "C";
    }
    else if ( mrk <= 70 && mrk > 65){
        return "D+";
    }
    else if( mrk <=65 && mrk > 60  ){
        return "D";
    }
    else if ( mrk <=60 && mrk > 55){
        return "E+";
    }
    else if ( mrk <=55 && mrk > 50){
        return "E";
    }
    else {
        return "F";
    }   
    }
    public String subgrade(String subjec){
        if ( subjec == sub1 ){
            return grd(num_1);
        }
        else if ( subjec == sub2){
            return grd(num_2);
        }
        else if (subjec == sub3 ){
            return grd(num_3);
        }
        else if( subjec == sub4){
            return grd(num_4);
        }
        else {
            return ("Please enter a correct subject . ");
        }
    }
    public String total_grd(){
        return grd(prct());
    }

}


