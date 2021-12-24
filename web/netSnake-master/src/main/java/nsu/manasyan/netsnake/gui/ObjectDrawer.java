package nsu.ivakin.snakeWeb.gui;

import nsu.ivakin.snakeWeb.Wrappers.FullPoints;
import nsu.ivakin.snakeWeb.models.Field;
import nsu.ivakin.snakeWeb.proto.SnakesProto;


public class ObjectDrawer {
    public static void drawFood(SnakesProto.GameState.Coord food){
        FieldCanvas fieldCanvas =  snakeWebApp.getFieldCanvas();
        fieldCanvas.drawPoint(food.getX(), food.getY(), Field.Cell.FOOD);
    }


    public static void drawSnake(FullPoints fullPoints) {
        FieldCanvas fieldCanvas = snakeWebApp.getFieldCanvas();
        fullPoints.getFullPoints().forEach(f -> fieldCanvas.drawPoint(f.getX(), f.getY(), Field.Cell.SNAKE));
        SnakesProto.GameState.Coord head = fullPoints.getFullPoints().get(fullPoints.getFullPoints().size() - 1);
        fieldCanvas.drawPoint(head.getX(), head.getY(), Field.Cell.HEAD);
    }
}
