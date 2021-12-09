package ru.ivakin.snake.model

import ru.ivakin.snake.proto.SnakesProto;
import ru.ivakin.snake.proto.SnakesProto.GameState.Snake.SnakeState;
import ru.ivakin.snake.proto.SnakesProto.Direction;

class SnakeModel(val playerId: Int) {
    var state: SnakeState = SnakeState.ALIVE;
    var direction: Direction = Direction.UP;
}
