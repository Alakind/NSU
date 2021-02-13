package ru.nsu.fit.g19202.aivakin.task1;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.Locale;

public class CSVMaker implements AutoCloseable, MyWriter {
    private Writer writer;
    private int wordsTotal = 0;

    CSVMaker(OutputStream outStream) {
        writer = new BufferedWriter(new OutputStreamWriter(outStream));
    }

    private void makeLine(MyWord word) throws IOException {
        double freq = 0;
        if (wordsTotal != 0) {
            freq = word.getFrequency() / (double) wordsTotal;
        }
        writer.write(String.format(Locale.UK, "%s, %d, %f%%%n", word.getWord(), word.getFrequency(), freq * 100));
        
    }

    public void writeMyWords(Collection<MyWord> words) throws IOException {
        for (MyWord myWord : words) {
            wordsTotal += myWord.getFrequency();
        }

        for (MyWord myWord : words) {
            makeLine(myWord);
        }
    }

    @Override
    public void close() throws Exception {
        writer.close();
    }
}
