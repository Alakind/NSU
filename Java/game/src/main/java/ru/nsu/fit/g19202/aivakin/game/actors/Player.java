package ru.nsu.fit.g19202.aivakin.game.actors;

import java.awt.geom.Point2D;

public class Player extends Actor {

    public Player(int x, int y, int radius) {
        super(x, y, radius);
    }

    @Override
    public Actor shoot() {
        Actor bullet = new Actor(x + radius, y - radius*2, 5);
        bullet.setSpeedY(-3);

        return bullet;
    }

    @Override
    public void die() {

    }
}
