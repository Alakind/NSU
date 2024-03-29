package ivakin.socks;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;

public class App {

    private static Logger logger = LogManager.getLogger(App.class);

    public static int DEFAULT_PORT = 1112;

    public static void main(String[] args) throws IOException {
        logger.info("App start executing");
        int port = args.length > 0 ? Integer.parseInt(args[0]) : DEFAULT_PORT;
        final SocksServer socksServer = new SocksServer(port);
        socksServer.serveConnections();
    }
}
