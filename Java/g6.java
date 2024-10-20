
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class g6 extends Frame implements MouseListener {
    Label l;

    g6() {
        addMouseListener(this);
        l = new Label();
        l.setBounds(100, 100, 100, 20);
        add(l);
        setSize(300, 300);
        setVisible(true);
        setLayout(null);
        setTitle("Guideline 6");

    }

    @Override
    public void mouseClicked(MouseEvent e) {
        l.setText("Mouse Clicked");

    }

    @Override
    public void mousePressed(MouseEvent e) {
        l.setText("Mouse pressed");

    }

    @Override
    public void mouseReleased(MouseEvent e) {
        l.setText("Mouse Released");

    }

    @Override
    public void mouseEntered(MouseEvent e) {
        l.setText("Mouse entered");

    }

    @Override
    public void mouseExited(MouseEvent e) {
        l.setText("Mouse Exited");

    }

    public static void main(String args[]) {
        new g6();
    }
}