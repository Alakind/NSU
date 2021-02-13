package ru.nsu.fit.g19202.aivakin.task1;

public class MyWord {
    private String word;
    private int frequency;

    public String getWord() {
        return word;
    }
    public int getFrequency() {
        return frequency;
    }

    public MyWord(String word, int frequency) {
        this.word = word;
        this.frequency = frequency;
    }

    public void increase() {
        frequency++;
    }
}
