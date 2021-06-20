package ru.nsu.fit.g19202.aivakin.game;

import ru.nsu.fit.g19202.aivakin.game.actors.Actor;
import ru.nsu.fit.g19202.aivakin.game.actors.Player;

import java.util.*;

public class Model {
    private final static int HEIGHT = 1000;
    private final static int WIDTH = 800;
    private final static int RADIUS = 25;

    private static int framesShoot = 0;
    private static int framesPlayerShoot = 0;
    private static int framesTurn = 0;
    private static int framesSpawn = 0;
    private static int framesShootSpeed = 300;



    public static int points = 0;

    ArrayList<Actor> actors = new ArrayList<Actor>();
    Player player = new Player(WIDTH / 2 - RADIUS, HEIGHT - RADIUS * 4, RADIUS);


    public int getPoints() {
        return points;
    }

    public int update() {
        framesShoot++;
        Set<Actor> bullets = new HashSet<>();
        if (framesShoot >= framesShootSpeed) {
            points += 5;
            framesShoot = 0;
            for (Actor actor : actors) {
                if (actor.getSpeedX() != 0) {
                    bullets.add(actor.shoot());
                }
            }
        }
        framesPlayerShoot++;
        if (framesPlayerShoot >= 200) {
            points += 5;
            bullets.add(player.shoot());
            framesPlayerShoot = 0;
        }
        bullets.forEach(bullet -> actors.add(bullet));

        framesTurn++;
        if (framesTurn >= 500) {
            framesShootSpeed *= 0.9;
            for (Actor actor : actors) {
                if (actor != player) {
                    actor.setSpeedX(actor.getSpeedX() * (-1));
                }
            }
            framesTurn = 0;
        }

        framesSpawn++;
        if (framesSpawn >= 2000) {
            points += 50;
            spawnEnemies();
            framesSpawn = 0;
        }

        if (player.getX() < 0) {
            player.setSpeedX(1);
        }
        if (player.getX() > WIDTH - RADIUS - 10) {
            player.setSpeedX(-1);
        }
        if (player.getY() < 0) {
            player.setSpeedY(0);
        }
        if (player.getY() + RADIUS > HEIGHT) {
            player.setSpeedY(-1);
        }

        Set<Actor> toDelete = new HashSet<>();
        for (Actor actor : actors) {
            for (Actor actor1 : actors) {
                if ((actor != actor1) && (actor1.getX() + 2*actor1.getRadius() > actor.getX())
                        && (actor1.getX() < actor.getX() + 2*actor.getRadius())
                        && (actor1.getY() < actor.getY() + 2*actor.getRadius())
                        && (actor1.getY() + 2*actor1.getRadius() > actor.getY())) {

                    toDelete.add(actor);

                    if (actor == player) {
                        return points;
                    }
                }
            }

            actor.setX(actor.getX() + actor.getSpeedX());
            actor.setY(actor.getY() + actor.getSpeedY());
            player.setX(player.getX() + player.getSpeedX());
            player.setY(player.getY() + player.getSpeedY());

            player.setSpeedX(0);
            player.setSpeedY(0);
        }
        toDelete.forEach(actor -> actors.remove(actor));

        return -1;
    }

    public void spawnEnemy(int x, int y) {
        Actor enemy = new Actor(x, y, RADIUS);
        enemy.setSpeedX(1);
        actors.add(enemy);
    }

    public void spawnEnemies() {
        for (int i = 0; i < WIDTH - RADIUS; i += RADIUS * 6) {
            spawnEnemy(i, 100);
        }
    }

    public Player getPlayer() {
        return player;
    }

    public ArrayList<Actor> getActors() {
        return actors;
    }
}
