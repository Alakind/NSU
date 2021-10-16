package src

import java.io.OutputStream
import java.net.*
import java.util.*

const val backlog = 10;

// USE
// 127.0.0.1
// 8800
fun main(args: Array<String>) {
    if (args.size < 2) {
        println("Enter adress and port as arguments");
        return;
    }

    val adress = args[0];
    val port = args[1];

    val ip: InetAddress = InetAddress.getByName(adress);

    val server = ServerSocket(port.toInt(), backlog, ip);

    val client = server.accept();
    println("Client connected");


    println("I'm done");
}
