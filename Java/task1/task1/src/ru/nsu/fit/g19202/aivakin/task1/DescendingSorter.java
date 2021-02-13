package ru.nsu.fit.g19202.aivakin.task1;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class DescendingSorter implements MyWordSorter {

    @Override
    public Collection<MyWord> sort(Collection<MyWord> myWords) {
        ArrayList<MyWord> wordsArray = new ArrayList<>(myWords);
        Collections.sort(wordsArray, new MyWordComp());

        return wordsArray;
    }
    
}
