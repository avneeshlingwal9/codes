package P1;
interface A{
    void run();
}
class E extends Exception{
    E (String str){
        super(str);
    }
}
class C implements A{
    C(){
        System.out.println("METHOD C");
    }
    public void run(){

    System.out.println("This is class C ");}
    public void val(int n) throws E {
        if(n<18){
            throw new E ("Your age is invalid");
        }
        else {
            System.out.println("You are valid to vote ");
        }

    }
}
public class time {
    public static void main(String args[]){
        try{
        A a ;
        a = new C();
        a.run();
        C c = new C();
        c.val(17);}
        catch(E e){
            System.out.println("Exception caught");
        }
        finally {
            System.out.println("Thank you");
        }


    }
}
