package nsu.ivakin.snakeWeb.controllers.view;

import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import nsu.ivakin.snakeWeb.gui.snakeWebApp;
import nsu.ivakin.snakeWeb.gui.SceneFactory;
import nsu.ivakin.snakeWeb.util.GameExecutorService;


public class MenuViewController {
    @FXML
    private Button newGameButton;

    @FXML
    private Button searchGamesButton;

    @FXML
    private Button exitButton;

    public void newGameClicked() {
        Scene newGameSettings = SceneFactory.getInstance().getScene(SceneFactory.SceneType.NEW_GAME_SETTINGS);
        snakeWebApp.getStage().setScene(newGameSettings);
    }

    // TODO
    public void searchGamesClicked(){
        Scene gameSearch = SceneFactory.getInstance().getScene(SceneFactory.SceneType.GAME_SEARCH);
        snakeWebApp.getStage().setScene(gameSearch);
    }

    public void exitClicked(){
        snakeWebApp.getNetworkControllerBridge().stopCurrentGame();
        GameExecutorService.getExecutorService().shutdownNow();
        snakeWebApp.getStage().close();
        System.exit(0);
    }
}
