package ru.nsu.fit.g19202.aivakin.task1;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;

public class Main {
    public static void main(String[] args) throws Exception {
        InputStream inStream = new FileInputStream(args[0]);
        OutputStream outStream = new FileOutputStream(args[1]);

        try (MyReader reader = new MyDefaultReader(inStream); CSVMaker writer = new CSVMaker(outStream)){
            Collection<MyWord> words = reader.readFile();

            writer.writeMyWords(new DescendingSorter().sort(words));
        }
        catch (IOException e) {
            System.err.println(e.getLocalizedMessage());
        }

        inStream.close();
        outStream.close();
    }
}
