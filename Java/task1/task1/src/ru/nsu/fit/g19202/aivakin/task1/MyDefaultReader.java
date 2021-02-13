package ru.nsu.fit.g19202.aivakin.task1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.Map;
import java.util.Collection;
import java.util.HashMap;

public class MyDefaultReader implements MyReader {
    private Reader reader;
    
    MyDefaultReader(InputStream inStream) {
        reader = new BufferedReader(new InputStreamReader(inStream));
    }

    private String readWord() throws IOException {
        int character;
        StringBuilder newStringBuilder = new StringBuilder();

        character = reader.read();
        while (!Character.isLetterOrDigit(character)) {
            if (character == -1) {
                return null;
            }
            character = reader.read();
        }
        while (Character.isLetterOrDigit(character)) {
            newStringBuilder.appendCodePoint(character);
            character = reader.read();
        }

        return newStringBuilder.toString();
    }

    @Override
    public Collection<MyWord> readFile() throws IOException {
        Map<String, MyWord> freqMap = new HashMap<String, MyWord>();

        String newWord = readWord();
        while (newWord != null) {
            if (freqMap.containsKey(newWord)) {
                freqMap.get(newWord).increase();
            }
            else {
                freqMap.put(newWord, new MyWord(newWord, 1));
            }
            newWord = readWord();
        }

        return freqMap.values();
    }

    @Override
    public void close() throws IOException {
        reader.close();
    }
}
