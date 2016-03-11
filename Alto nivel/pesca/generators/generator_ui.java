import java.awt.*;
import java.util.*;
import javax.swing.*;
import java.awt.event.*;

class Generator { double dh, dw;
    Vector<Integer> xs = new Vector<Integer>();
    Vector<Integer> ys = new Vector<Integer>();

    class Canvas extends JPanel
        implements MouseListener {

        public Canvas() {
            this.addMouseListener(this);
        }

        public void mousePressed(MouseEvent e) {
            Graphics g = this.getGraphics();
            int x = e.getX(), y = e.getY();
            xs.add((int) Math.floor(y / dh));
            ys.add((int) Math.floor(x / dw));
            g.fillOval(x, y, 7, 7);
            g.dispose();
        }

        public void mouseReleased(MouseEvent e) {}
        public void mouseClicked(MouseEvent e) {}
        public void mouseEntered(MouseEvent e) {}
        public void mouseExited(MouseEvent e) {}
    }

    public Generator(final int h, final int w) {
        JFrame window = new JFrame(
            "Pescador Case Generator");
        window.setDefaultCloseOperation(
            JFrame.EXIT_ON_CLOSE);

        window.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.out.printf("%d %d ", h, w);
                System.out.println(xs.size() + " 10000");
                for (int i = 0; i < xs.size(); ++i)
                    System.out.printf("%d %d\n",
                        xs.get(i), ys.get(i));
            }
        });

        Canvas canvas = new Canvas();
        canvas.addComponentListener(new ComponentAdapter() {
            public void componentResized(ComponentEvent e) {
                Component c = e.getComponent();
                double height = c.getHeight() + 1;
                double width = c.getWidth() + 1;
                dh = height / h; dw = width / w;
                xs.clear(); ys.clear();
            }
        });

        window.add(canvas);
        window.setSize(500, 500);
        window.setVisible(true);
    }

    public static void main(String[] args) {
        new Generator(Integer.parseInt(args[0]),
                      Integer.parseInt(args[1]));
    }
}
