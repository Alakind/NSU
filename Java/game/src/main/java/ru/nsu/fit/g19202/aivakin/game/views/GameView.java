package ru.nsu.fit.g19202.aivakin.game.views;

import javax.swing.*;

public interface GameView {

    public void gameViewInit(JFrame frame, int width, int height);

    public void drawView();

    public void updateView();
}
