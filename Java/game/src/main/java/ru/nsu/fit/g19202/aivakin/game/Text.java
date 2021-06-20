package ru.nsu.fit.g19202.aivakin.game;

import java.awt.*;

public class Text {

    String text;

    public Text(String text) {
        this.text = text;
    }

    public void paint(Graphics gr) {
        gr.setColor(Color.red);
        gr.setFont(new Font("Arial", Font.BOLD, 25));
        FontMetrics fm = gr.getFontMetrics();
        gr.drawString(text, 0, 500);
    }

}
