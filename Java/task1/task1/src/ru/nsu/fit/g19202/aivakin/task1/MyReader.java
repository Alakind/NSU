package ru.nsu.fit.g19202.aivakin.task1;

import java.io.IOException;
import java.util.Collection;

interface MyReader extends AutoCloseable {
    public Collection<MyWord> readFile() throws IOException;
}
