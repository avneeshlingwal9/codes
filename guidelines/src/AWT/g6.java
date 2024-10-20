package AWT;
import java.awt.*;
import java.awt.event.*;

public class g6 extends Frame implements MouseListener {
    Label l;
    private int height ;
    private int width ;

    g6() {
        height = 300 ;
        width = 300 ;

        addMouseListener(this);


        setSize(width, height);
        setLayout(null);
        setVisible(true);
        setTitle("Guideline 6");
    }

    public void mouseClicked(MouseEvent e) {
        setSize(width,height);
    }

    public void mouseEntered(MouseEvent e) {
        setSize(3*width, 3*height);
    }

    public void mouseExited(MouseEvent e){
        dispose();

    }

    public void mousePressed(MouseEvent e) {

    }

    public void mouseReleased(MouseEvent e){
    }

    public static void main(String[] args) {
        new g6();
    }
}