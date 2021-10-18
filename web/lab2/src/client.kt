package src

import java.io.OutputStream
import java.net.*
import java.io.*
import java.util.*

val BUFF = 4096;

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
    val buffer = ByteArray(BUFF);
    val charset = Charsets.UTF_8;

    val ip: InetAddress = InetAddress.getByName(adress);
    val client = Socket(ip, port.toInt());
    val output: OutputStream = client.getOutputStream();

    // sending size of file
    val fileSize = File(filename).length();
    ByteArrayInputStream((fileSize.toString() + "\n").toByteArray(charset)).read(buffer, 0, BUFF);
    output.write(buffer, 0, BUFF);

    // sending name of file
    ByteArrayInputStream((filename + "\n").toByteArray(charset)).read(buffer, 0, BUFF);
    output.write(buffer, 0, BUFF);


    // reading and sending file
    val fileStream: InputStream = File(filename).inputStream();

    var readed: Int = fileStream.read(buffer, 0, BUFF);
    while(readed != -1) {
        output.write(buffer, 0, readed);

        readed = fileStream.read(buffer, 0, BUFF);
    }
}
