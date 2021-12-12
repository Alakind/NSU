package ru.ivakin.snake.model;

import java.util.Vector;

class GameState() {
    var snakes = Vector<SnakeModel>();
    var food = Vector<Point>();

    fun addSnake(snake: SnakeModel) {
        snakes.add(snake);
    }

    fun addFood(snack: Point) {
        food.add(snack);
    }
}
