package ivakin.socks.messages;

import ivakin.socks.messages.types.AuthMethod;
import ivakin.socks.messages.types.ServerStatus;

public class ServerResponse implements SocksMessage {

    AuthMethod authMethod;
    ServerStatus serverStatus;

    public ServerResponse(AuthMethod authMethod, ServerStatus serverStatus) {
        this.authMethod = authMethod;
        this.serverStatus = serverStatus;
    }

    @Override
    public byte[] toByteArray() {
        byte []responseBytes = new byte[2];
        switch (serverStatus) {
            case SUCCESS -> {
                responseBytes[1] = 0x00;
            }
            case FAILURE -> {
                responseBytes[1] = 0x11;
            }
        }
        return responseBytes;
    }
}
