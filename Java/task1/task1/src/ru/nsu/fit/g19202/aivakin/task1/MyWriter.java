package ru.nsu.fit.g19202.aivakin.task1;

import java.io.IOException;
import java.util.Collection;

interface MyWriter {
    public void writeMyWords(Collection<MyWord> words) throws IOException;
}
