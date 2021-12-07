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

@Composable
@Preview
fun Playfield(size: Int) {
    Column {
        for (i in 1..size) {
            Row {
                for (j in 1..size) {
                    // Box(Modifier.size(100.dp).background(Color.Blue)) {
                    //     Box(Modifier.clip(CircleShape).size(50.dp).background(Color.Green).align(Alignment.Center))
                    // }
                    val color: Color = if (i % 2 == j % 2) Color(200, 200, 200) else Color(50, 50, 200);
                    Box(Modifier.size(100.dp).background(color))
                }
            }
        }
    }
}
