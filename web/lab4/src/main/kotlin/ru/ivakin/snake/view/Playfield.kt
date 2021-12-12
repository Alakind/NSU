package ru.ivakin.snake.view

import androidx.compose.desktop.ui.tooling.preview.Preview
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.*
import androidx.compose.ui.draw.*
import androidx.compose.foundation.shape.*
import androidx.compose.ui.*
import androidx.compose.material.*

import java.util.Vector;

import ru.ivakin.snake.constants.SnakeConstants
import ru.ivakin.snake.model.SnakeModel
import ru.ivakin.snake.model.Point

@Composable
@Preview
fun Playfield(snakes: Vector<SnakeModel>, food: Vector<Point>, size: Int = 10) {
    Column {
        for (i in 1..size) {
            Row {
                for (j in 1..size) {
                    var rendered = false;
                    val color: Color = if (i % 2 == j % 2) Color(200, 200, 200) else Color(50, 50, 200);

                    for (snack in food) {
                        if (snack.coordinates.first == j && snack.coordinates.second == i) {
                            Box(Modifier.size(SnakeConstants.CELL_SIZE.dp).background(color)) {
                                Box(Modifier.clip(CircleShape).size(SnakeConstants.SMALL_POINT.dp).background(Color.Green).align(Alignment.Center))
                            }
                            rendered = true;
                        }
                    }

                    for (snake in snakes) {
                        for (point in snake.points) {
                            if (point.coordinates.first == j && point.coordinates.second == i) {
                                Box(Modifier.size(SnakeConstants.CELL_SIZE.dp).background(color)) {
                                    Box(Modifier.clip(CircleShape).size(SnakeConstants.MEDIUM_POINT.dp).background(snake.color).align(Alignment.Center))
                                }
                                rendered = true;
                            }
                        }
                    }

                    if (!rendered) {
                        Box(Modifier.size(SnakeConstants.CELL_SIZE.dp).background(color))
                    }
                }
            }
        }
    }
}
