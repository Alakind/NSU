package ru.ivakin.snake.model

import androidx.compose.ui.graphics.Color

class Point(var coordinates: Pair<Int, Int>, var color: Color, size: Int) {
    fun setCoordinates(x: Int, y: Int) {
        coordinates = Pair(x, y);
    }
}
