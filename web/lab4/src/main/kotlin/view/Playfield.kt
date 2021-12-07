package ru.ivakin.snake.view

import androidx.compose.desktop.ui.tooling.preview.Preview
import androidx.compose.foundation.layout.*
// import androidx.compose.material.Button
// import androidx.compose.material.Slider
// import androidx.compose.material.Text
import androidx.compose.foundation.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
// import androidx.compose.ui.layout.onSizeChanged
// import androidx.compose.ui.platform.LocalDensity
import androidx.compose.ui.unit.*
// import kotlin.random.Random
// import androidx.compose.ui.draw.alpha
import androidx.compose.ui.draw.*
import androidx.compose.foundation.shape.*
import androidx.compose.ui.*

@Composable
@Preview
fun Playfield() {
    Row {
        Box(Modifier.size(100.dp).background(Color.Blue)) {
            Box(Modifier.clip(CircleShape).size(50.dp).background(Color.Green).align(Alignment.Center))
        }
        Box(Modifier.size(100.dp).background(Color.Red))
    }
}
