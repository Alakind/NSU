package nsu.ivakin.snakeWeb;

import nsu.ivakin.snakeWeb.contexts.SentMessagesKey;
import nsu.ivakin.snakeWeb.controllers.ClientController;
import nsu.ivakin.snakeWeb.models.ClientGameModel;
import nsu.ivakin.snakeWeb.contexts.MessageContext;
import nsu.ivakin.snakeWeb.network.Listener;
import nsu.ivakin.snakeWeb.network.Sender;
import nsu.ivakin.snakeWeb.util.ErrorListener;

import java.io.IOException;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class NetworkControllerBridge {
    private MulticastSocket socket;

    private Map<SentMessagesKey, MessageContext> sentMessages = new ConcurrentHashMap<>();

    private ClientController clientController;

    private Listener listener;

    private Sender sender;

    public NetworkControllerBridge() throws IOException {

        this.socket = new MulticastSocket(9192);
        this.sender = new Sender( socket, sentMessages, InetAddress.getByName("239.192.0.4"));
        this.clientController = ClientController.getInstance();
        clientController.setSender(sender);
        this.listener = new Listener( sender, sentMessages, socket, InetAddress.getByName("239.192.0.4"));
        listener.listen();
    }

    public void registerErrorListener(ErrorListener errorListener){
        clientController.registerErrorListener(errorListener);
    }

    public void stopCurrentGame(){
        listener.reload();
        clientController.stopCurrentGame();
        sender.stop();
    }
}
