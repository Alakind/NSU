package ivakin.socks.messages;

import ivakin.socks.exceptions.WrongSocksMessageException;

public interface SocksMessage {
    byte[] toByteArray() throws WrongSocksMessageException;
}
