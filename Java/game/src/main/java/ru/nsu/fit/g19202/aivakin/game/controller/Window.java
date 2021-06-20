package ru.nsu.fit.g19202.aivakin.game.controller;

import javafx.stage.Stage;

public class Window {

    private static Window instance;

    private static class Maker {
        private static final Window win = new Window();
    }

    public static Window getInstance() {
        if(instance == null) {
            instance = Maker.win;
        }
        return instance;
    }
}
