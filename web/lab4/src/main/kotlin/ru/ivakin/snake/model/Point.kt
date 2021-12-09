package ru.ivakin.snake.model

import androidx.compose.ui.graphics.Color

class Point(var coordinates: Pair<Int, Int>, val color: Color, val size: Int) {
    fun setCoordinates(x: Int, y: Int) {
        coordinates = Pair(x, y);
    }
}
