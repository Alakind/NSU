package ru.ivakin.snake.model;

import androidx.compose.ui.graphics.Color

import java.util.Vector;

import ru.ivakin.snake.proto.SnakesProto;
// import ru.ivakin.snake.proto.SnakesProto;
// import ru.ivakin.snake.proto.SnakesProto.GameState.Snake;

class SnakeModel(val playerId: Int, val head: Point, val color: Color) {
    var points = Vector<Point>();

    init {
        points.add(head);
    }

    // var snakeState = Snake();

    // var state.snakeState = ALIVE;
    // var direction = SnakesProto.Direction.UP;

}
