package AWT;
import P2.Fraction;

import java.awt.* ;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.event.WindowStateListener;

import static java.lang.System.exit;

public class ex6 extends Frame  {

    ex6(){
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        setTitle("Example for drawing a circle");
        setSize(400,400);
        setVisible(true);
        setLayout(null);
        setBackground(Color.cyan);
        setForeground(Color.green);

    }
    public void paint(Graphics g){
        g.drawOval(100,100,120,120);
        g.fillOval(100,100,120,120);

    }
    public static void main(String[] args){
        new ex6();
    }




}
