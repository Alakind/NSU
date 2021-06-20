package ru.nsu.fit.g19202.aivakin.task2;

import java.util.ArrayList;
import java.util.List;

public class Journal {

    List history = new ArrayList();

    private static class Helper {
        private static Journal journal = new Journal();
    }

    public static Journal getInstance() {
        return Journal.Helper.journal;
    }

    public void makeNote(String command) {
        history.add(command);
    }

    public void showHistory() {
        for (Object note : history) {
            System.out.println(note);
        }
    }

}
