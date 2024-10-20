package AWT;
import java.awt.*;
import java.awt.event.*;

public class ex3 extends Frame implements ActionListener {
    TextField t ;
    ex3(){
        t = new TextField();
        Button b = new Button("Click me");
        t.setBounds(20,80,70,20);
        b.setBounds(40,100,50,20);
        setSize(400,400);
        setTitle("Action event example");
        setLayout(null);
        setVisible(true);
        b.addActionListener(this);

        add(b);
        add(t);

    }
    public static void main(String args[]){
        ex3 e = new ex3();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        t.setText("Welcome");

    }
}
