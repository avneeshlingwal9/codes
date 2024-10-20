package AWT;
import java.awt.*;

public class ex2 {
    public static void main(String args[]){
    Frame f = new Frame();

    Button b = new Button("Enter");
    TextField t = new TextField();
    Label l = new Label("Employee");
    t.setBounds(20,100,100,20);
    b.setBounds(100,100,40,20);
    l.setBounds(20,80,90,10);
    f.add(b);
    f.add(t);
    f.add(l);
    f.setTitle("Information");
    f.setLayout(null);
    f.setVisible(true);
    f.setSize(500,500);

    }





}
