package nsu.ivakin.snakeWeb.gui;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import nsu.ivakin.snakeWeb.NetworkControllerBridge;
import nsu.ivakin.snakeWeb.controllers.ClientController;
import nsu.ivakin.snakeWeb.proto.SnakesProto;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.List;

public class snakeWebApp extends Application {


    private static NetworkControllerBridge networkControllerBridge;

    private static Stage stage;

    private static FieldCanvas fieldCanvas;

    private static GridPane scoreGrid;

    public static Stage getStage() {
        return stage;
    }

    private void setStage(Stage stage) {
        snakeWebApp.stage = stage;
    }

    public static NetworkControllerBridge getNetworkControllerBridge() {
        return networkControllerBridge;
    }

    @Override
    public void start(Stage stage) throws IOException {
        setStage(stage);

        initGameClient();
        FXMLLoader loader = new FXMLLoader();
        URL xmlUrl = getClass().getResource("/login.fxml");
        loader.setLocation(xmlUrl);
        AnchorPane root = loader.load();

        Scene scene = new Scene(root);

        InputStream iconStream = getClass().getResourceAsStream("/snake.png");
        Image image = new Image(iconStream);
        stage.getIcons().add(image);

        stage.setTitle("ZMiYKA");
        stage.setWidth(1000);
        stage.setHeight(700);
        stage.setResizable(false);
        stage.setScene(scene);
        stage.show();
    }

    private void initGameClient() throws IOException {
        networkControllerBridge = new NetworkControllerBridge();
        networkControllerBridge.registerErrorListener(erMsg -> {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Error");

            alert.setHeaderText(null);
            alert.setContentText(erMsg);

            alert.showAndWait();
        });
    }

    public static FieldCanvas getFieldCanvas() {
        return fieldCanvas;
    }

    public static void setFieldCanvas(FieldCanvas fieldCanvas) {
        snakeWebApp.fieldCanvas = fieldCanvas;
    }

    public static void setScene(SceneFactory.SceneType sceneType){
        Scene scene = SceneFactory.getInstance().getScene(sceneType);
        stage.setScene(scene);
    }

    public void go(String[] args){
        launch(args);
    }

    @Override
    public void stop(){
        System.exit(0);
    }
}
