package src

import java.io.OutputStream
import java.net.*
import java.io.*
import java.util.*

val BUFF = 100;

// USE
// 127.0.0.1
// 8800
fun main(args: Array<String>) {
    if (args.size < 3) {
        println("Enter adress, port and path to file as arguments");
        return;
    }

    val adress: String = args[0];
    val port: String = args[1];
    val filename: String = args[2];

    val charset = Charsets.UTF_8;

    val ip: InetAddress = InetAddress.getByName(adress);
    val client = Socket(ip, port.toInt());
    val output: OutputStream = client.getOutputStream();

    // sending name of file
    output.write((filename + "\n").toByteArray(charset));

    // sending size pf file
    output.write((File(filename).length().toString() + "\n").toByteArray(charset));

    // reading and sending file
    val inputStream: InputStream = File(filename).inputStream();

    val buffer = ByteArray(BUFF);
    while(inputStream.read(buffer, 0, BUFF) != -1) {
        output.write(buffer);
    }
    output.write(buffer);
}
