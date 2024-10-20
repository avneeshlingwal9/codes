package AWT;
import java.awt.*;


public class g7  extends Frame{
    g7(){
        Label l = new Label("Hello World");
        l.setBounds(100,100,100,20);
        add(l);
        setSize(400,400);
        setTitle("Guideline 7");
        setLayout(null);
        setVisible(true);
        setBackground(Color.pink);

    }
    public static void main(String args[]){
    new g7();}
}
