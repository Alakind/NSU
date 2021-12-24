package nsu.ivakin.snakeWeb.controllers.view;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import nsu.ivakin.snakeWeb.controllers.ClientController;
import nsu.ivakin.snakeWeb.gui.snakeWebApp;
import nsu.ivakin.snakeWeb.gui.SceneFactory;


public class LoginViewController {
    @FXML
    private TextField nameTextField;

    @FXML
    private Button loginButton;

    public void loginClicked(){
        String name = nameTextField.getText();
        ClientController.getInstance().setPlayerName(name);
        snakeWebApp.setScene(SceneFactory.SceneType.MENU);
    }
}
