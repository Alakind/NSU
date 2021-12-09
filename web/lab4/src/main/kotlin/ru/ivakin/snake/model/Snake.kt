package ru.ivakin.snake.model;

import java.util.Vector;

import ru.ivakin.snake.proto.SnakesProto;
import ru.ivakin.snake.proto.SnakesProto.GameState.Snake.SnakeState;
import ru.ivakin.snake.proto.SnakesProto.Direction;

class SnakeModel(val playerId: Int, val head: Point) {
    var state: SnakeState = SnakeState.ALIVE;
    var direction: Direction = Direction.UP;

    var points: Vector<Point> = Vector<Point>();
}
