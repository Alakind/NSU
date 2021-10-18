package src

import java.io.OutputStream
import java.net.*
import java.util.*
import java.io.*

val BUFF = 4096;

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
    val buffer = ByteArray(BUFF);
    val charset = Charsets.UTF_8;

    val ip: InetAddress = InetAddress.getByName(adress);

    val server = ServerSocket(port.toInt(), backlog, ip);

    val client = server.accept();
    println("Client connected");

    // reading name and size
    val input = client.getInputStream();

    // reading size
    input.read(buffer, 0, BUFF);
    val size: Long = (buffer.toString(charset).split("\n"))[0].toLong();
    println(size);

    // readin name
    val curDir: String = (System.getProperty("user.dir"));

    input.read(buffer, 0, BUFF);
    val filenameCome: String = (buffer.toString(charset).split("\n"))[0];
    val filename: String = curDir + "/downloads/" + (filenameCome.split("/")).last();
    println(filename);

    // making file
    val fileStream: OutputStream = File(filename).outputStream();

    // reading file
    val inputStream = client.getInputStream();

    var left: Long = size;
    while(left > 0) {
        var readed: Int = inputStream.read(buffer, 0, BUFF);
        left -= readed;

        fileStream.write(buffer, 0, readed);
    }

    println("I'm done");
}
