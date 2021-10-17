package src

import java.io.OutputStream
import java.net.*
import java.util.*
import java.io.*

val BUFF = 100;
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

    // reading name and size
    val input = BufferedReader(InputStreamReader(client.getInputStream()));

    val filename = input.readLine();
    println(filename);
    println(input.readLine());

    // making file
    val fileStream: OutputStream = File(filename + "hehe").outputStream();

    // reading file
    val inputStream = client.getInputStream();

    val buffer = ByteArray(BUFF);
    while(inputStream.read(buffer, 0, BUFF) != -1) {
        fileStream.write(buffer);
    }
    fileStream.write(buffer);

    println("I'm done");
}
