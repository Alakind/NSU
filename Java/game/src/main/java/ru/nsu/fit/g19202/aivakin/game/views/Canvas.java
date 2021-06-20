package ru.nsu.fit.g19202.aivakin.game.views;

import ru.nsu.fit.g19202.aivakin.game.Text;
import ru.nsu.fit.g19202.aivakin.game.actors.Actor;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Canvas extends JPanel {
    ArrayList<Actor> actors;
    Text text = null;

    public void setText(Text text) {
        this.text = text;
    }

    public Canvas(ArrayList<Actor> actors) {
        this.actors = actors;
    }

    public ArrayList<Actor> getActors() {
        return actors;
    }

    @Override
    public void paint(Graphics q) {
        super.paint(q);
        for (Actor actor : actors) {
            actor.paint(q);
        }
        if (text != null) {
            text.paint(q);
        }
    }

}
