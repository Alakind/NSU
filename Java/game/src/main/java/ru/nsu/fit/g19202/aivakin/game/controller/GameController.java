package ru.nsu.fit.g19202.aivakin.game.controller;


import ru.nsu.fit.g19202.aivakin.game.Model;

import javax.swing.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import static java.awt.event.KeyEvent.VK_LEFT;
import static java.awt.event.KeyEvent.VK_RIGHT;
import static java.awt.event.KeyEvent.VK_DOWN;
import static java.awt.event.KeyEvent.VK_UP;

public class GameController {
    private JFrame frame = new JFrame();
    private Model model;

    private static final int SPEED = 4;

    public JFrame getFrame() {
        return frame;
    }

    public GameController(Model modelIn) {
        model = modelIn;
    }

    public void update() {
        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        frame.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
                System.out.println(e.getKeyCode());
                if (keyCode == VK_LEFT) {
                    model.getPlayer().setSpeedX(-SPEED);
                }
                if (keyCode == VK_RIGHT) {
                    model.getPlayer().setSpeedX(SPEED);
                }
                if (keyCode == VK_DOWN) {
                    model.getPlayer().setSpeedY(SPEED);
                }
                if (keyCode == VK_UP) {
                    model.getPlayer().setSpeedY(-SPEED);
                }
            }
        });
    }


}
