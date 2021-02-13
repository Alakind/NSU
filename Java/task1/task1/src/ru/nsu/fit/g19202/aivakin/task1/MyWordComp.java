package ru.nsu.fit.g19202.aivakin.task1;

import java.util.Comparator;

public class MyWordComp implements Comparator<MyWord>{

    @Override
    public int compare(MyWord o1, MyWord o2) {
        if (o1.getFrequency() > o2.getFrequency()) {
            return -1;
        }
        if (o1.getFrequency() < o2.getFrequency()) {
            return 1;
        }
        return o1.getWord().compareTo(o2.getWord());
    }
    
}
