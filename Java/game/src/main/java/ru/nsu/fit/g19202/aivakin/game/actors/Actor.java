package ru.nsu.fit.g19202.aivakin.game.actors;

import java.awt.*;

public class Actor {
    int x;
    int y;

    int radius;

    int speedX;
    int speedY;

    public Actor(int x, int y, int radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setSpeedX(int speedX) {
        this.speedX = speedX;
    }

    public void setSpeedY(int speedY) {
        this.speedY = speedY;
    }

    public int getSpeedX() {
        return speedX;
    }

    public int getSpeedY() {
        return speedY;
    }

    public void die() {};

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getRadius() {
        return radius;
    }

    public void updatePosition() {
    };

    public void paint(Graphics gr) {
        gr.setColor(Color.BLUE);
        gr.fillOval(x, y, radius * 2, radius * 2);
    }

    public Actor shoot() {
        Actor bullet = new Actor(x + radius, y + radius*2, 5);
        bullet.setSpeedY(2);

        return bullet;
    }

}
