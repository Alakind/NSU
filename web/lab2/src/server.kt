package src

import java.io.OutputStream
import java.net.*
import java.util.*
import java.io.*
import java.lang.Thread

val BUFF = 4096;

const val backlog = 10;
val charset = Charsets.UTF_8;

class SpeedInfo(download: Long, fSize: Long) {
    public var downloaded: Long = download;
    public var fullSize: Long = fSize;
    private var secondsSpent: Long = 0;

    public fun averageSpeed(): Long {
        return downloaded / secondsSpent;
    }
    public fun addSeconds(seconds: Long) {
        secondsSpent += seconds;
    }
}

fun printInfoThread(speedInfo: SpeedInfo) {
    Thread.sleep(3000);
    speedInfo.addSeconds(3);

    println(speedInfo.downloaded.toString() + " / " + speedInfo.fullSize.toString() + " bytes");
    println("Average speed: " + speedInfo.averageSpeed().toString());
}

fun clientRun(server: ServerSocket){

    val client = server.accept();
    println("Client connected");

    val buffer = ByteArray(BUFF);

    // reading name and size
    val input = client.getInputStream();

    // reading size
    input.read(buffer, 0, BUFF);
    val size: Long = (buffer.toString(charset).split("\n"))[0].toLong();

    // readin name
    val curDir: String = (System.getProperty("user.dir"));

    input.read(buffer, 0, BUFF);
    val filenameCome: String = (buffer.toString(charset).split("\n"))[0];
    val filename: String = curDir + "/downloads/" + (filenameCome.split("/")).last();

    // Showing speed info
    val speedInfo = SpeedInfo(0, size);
    val thread: Thread = Thread(Runnable {
        printInfoThread(speedInfo);
    });
    thread.start();

    // making file
    val fileStream: OutputStream = File(filename).outputStream();

    // reading file
    val inputStream = client.getInputStream();



    var left: Long = size;
    while(left > 0) {
        var readed: Int = inputStream.read(buffer, 0, BUFF);
        left -= readed;

        speedInfo.downloaded = size - left;

        fileStream.write(buffer, 0, readed);
    }

    thread.join();

    println("File sent successfully!");
}

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

    var threads: Vector<Thread> = Vector<Thread>();

    while (true) {
        for (i in 1..backlog) {
            threads.add(Thread(Runnable {
                clientRun(server);
            }));

            threads.lastElement().start();
        }
    }
}
