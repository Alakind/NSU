package nsu.ivakin.snakeWeb.controllers.view;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import nsu.ivakin.snakeWeb.contexts.AnnouncementContext;
import nsu.ivakin.snakeWeb.controllers.ClientController;
import nsu.ivakin.snakeWeb.gui.snakeWebApp;
import nsu.ivakin.snakeWeb.gui.SceneFactory;
import nsu.ivakin.snakeWeb.proto.SnakesProto.GameMessage.AnnouncementMsg;

import java.util.Map;

public class AnnouncementsViewController {

    private ClientController clientController = ClientController.getInstance();

    @FXML
    private GridPane announcementsGrid;

    @FXML
    private Button backButton;

    public void backClicked(){
        snakeWebApp.setScene(SceneFactory.SceneType.MENU);
    }

    public void initialize() {
        clientController.registerAnnouncementListener(this::onAnnouncementsUpdate);
    }

    private void onAnnouncementsUpdate(Map<AnnouncementMsg, AnnouncementContext> announcements){
        Platform.runLater(() -> {
            announcementsGrid.getChildren().clear();
            int i = 0;

            for (var entry : announcements.entrySet()) {
                updateGrid(entry.getKey(), entry.getValue(), i++);
            }
        });

    }

    private void updateGrid(AnnouncementMsg announcement, AnnouncementContext context, int rank){
        Button joinButton = new Button("Join");
        joinButton.setOnAction(ae -> {
            clientController.joinGame(context.getMasterAddress(), false, announcement);
            snakeWebApp.setScene(SceneFactory.SceneType.GAME);
        });

        Label sizeLabel = new Label(
                "[" + announcement.getConfig().getWidth() + " x " + announcement.getConfig().getHeight() + "]"
        );
        Label addressLabel = new Label(
                context.getMasterAddress().toString()
        );

        addLabel(sizeLabel, 0, rank);
        addLabel(addressLabel, 1, rank);
        announcementsGrid.add(joinButton, 2, rank);
    }

    private void addLabel(Label label, int x, int y){
        label.getStyleClass().add("score-label");
        announcementsGrid.add(label, x, y);
    }
}
