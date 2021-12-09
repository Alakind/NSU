package ru.ivakin.snake.model

import ru.ivakin.snake.proto.SnakesProto;
import ru.ivakin.snake.proto.SnakesProto.GameState.Snake.SnakeState;

class MySnake() {
    var state: SnakeState = SnakeState.ALIVE;
}
