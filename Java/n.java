import java.awt.*;
import java.awt.event.*;

public class n extends Frame implements MouseListener {
    Label l;

    n() {
        addMouseListener(this);

        l = new Label();
        l.setBounds(20, 50, 100, 20);
        add(l);
        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        l.setText("Mouse Clicked");
        setSize(300, 300);
    }

    public void mouseEntered(MouseEvent e) {
        l.setText("Mouse Entered");
        setSize(900, 900);
    }

    public void mouseExited(MouseEvent e) {
        l.setText("Mouse Exited");

    }

    public void mousePressed(MouseEvent e) {
        l.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        l.setText("Mouse Released");
    }

    public static void main(String[] args) {
        new n();
    }
}