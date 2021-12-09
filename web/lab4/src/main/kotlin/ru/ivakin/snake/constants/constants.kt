package ru.ivakin.snake.constants


object SnakeConstants{
    val CELL_SIZE: Int = 50;

    val BIG_POINT: Int = CELL_SIZE;
    val MEDIUM_POINT: Int = (CELL_SIZE * 0.75).toInt();
    val SMALL_POINT: Int = (CELL_SIZE / 2).toInt();
}
