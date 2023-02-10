import javax.swing.BorderFactory;

import javax.swing.*;
import javax.swing.WindowConstants;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;
public class frame implements ActionListener {
    final private Font mainFont = new Font("Segoe print", Font.BOLD, 18);
    JFrame frame = new JFrame();
    JButton b;
    public void init(){
        JLabel lbLoginForm = new JLabel("Login Form", SwingConstants.CENTER);
        lbLoginForm.setFont(mainFont);
        
        b = new JButton();
        b.setBounds(200, 200, 150, 50);
        b.addActionListener(this);
        b.setText("Tab For Login");
        b.setFocusable(false);
        b.setBorder(BorderFactory.createEtchedBorder());
        frame.setTitle("Pharmacy Management");
        frame.setLayout(null);
        frame.setSize(550,500);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
        frame.add(b);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==b){
            frame.dispose();
            LoginForm ob1 = new LoginForm();
            ob1.initialize();
            
        }
        
    }
}