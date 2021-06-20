package ru.nsu.fit.g19202.aivakin.game;

//import javafx.application.Application;
//import javafx.fxml.FXMLLoader;
//import javafx.scene.Scene;
//import javafx.scene.layout.AnchorPane;
//import javafx.stage.Stage;

import ru.nsu.fit.g19202.aivakin.game.controller.GameController;
import ru.nsu.fit.g19202.aivakin.game.views.CanvasView;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

public class Game {
    private final static int HEIGHT = 1000;
    private final static int WIDTH = 800;
    private final static int RADIUS = 50;

    private static boolean gameOn;

    public static void main(String[] args){
        play();
    }

    public static void play(){
        int record = getRecord();

        Model model = new Model();
        GameController controller = new GameController(model);
        CanvasView view = new CanvasView(model.getActors(), model.getPlayer());

        model.getActors().add(model.getPlayer());

        model.spawnEnemies();

        controller.update();

        view.gameViewInit(controller.getFrame(), WIDTH, HEIGHT);

        controller.getFrame().requestFocus();
        controller.getFrame().setVisible(true);

        int points = -1;
        while (points == -1) {
            points = model.update();

            view.getCanvas().repaint();

            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        if (points > record) {
            setRecord(points);
        }

        Text text = new Text("Your score: " + points + " Best score: " + record);
        view.getCanvas().setText(text);

        view.getCanvas().repaint();

        controller.getFrame().setVisible(false);
        return;
    }

    private static int getRecord() {
        int record = -1;

        URL path = Game.class.getClassLoader().getResource("record.txt");
        File file = new File(path.getPath());

        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        record = scanner.nextInt();

        return record;
    }

    private static void setRecord(int record) {
        URL path = Game.class.getClassLoader().getResource("record.txt");
        File file = new File(path.getPath());

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(file));
            writer.write(String.valueOf(record));
            writer.newLine();
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
