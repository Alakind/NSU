package ivakin.socks;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class SocksServer {
    private static Logger logger = LogManager.getLogger(SocksServer.class);

    private final int port;
    public static String serverAdress = "127.0.0.1";

    private DatagramChannel dnsChannel;

    public SocksServer(int port) {
        this.port = port;
    }

    public void work() {
        
    }


}
