package ru.nsu.fit.g19202.aivakin.game.views;

import ru.nsu.fit.g19202.aivakin.game.actors.Actor;
import ru.nsu.fit.g19202.aivakin.game.actors.Player;
import ru.nsu.fit.g19202.aivakin.game.views.GameView;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class CanvasView implements GameView {
    private Canvas canvas;

    public Canvas getCanvas() {
        return canvas;
    }

    public CanvasView(ArrayList<Actor> actors, Player player) {
        canvas = new Canvas(actors);
        canvas.getActors().add(player);
    }

    @Override
    final public void gameViewInit(JFrame frame, int width, int height) {
        canvas.setBackground(Color.white);

        frame = new JFrame("Invasion!");
        frame.setSize(width, height);
        frame.getContentPane().add(BorderLayout.CENTER, canvas);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    final public void drawView() {
        canvas.repaint();
    }

    @Override
    final public void updateView() {
        canvas.repaint();
    }
}
