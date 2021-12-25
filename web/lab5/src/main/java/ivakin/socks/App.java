package ivakin.socks;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class App {
    private static int defaultPort = 1112;
    private static Logger logger = LogManager.getLogger(App.class);

    public static void main(String[] args) {
        logger.info("Proxy initialized");

        int port = args.length == 0 ? defaultPort : Integer.parseInt(args[0]);

        final SocksServer socksServer = new SocksServer(port);
        
        socksServer.work();
    }
}
