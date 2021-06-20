package ru.nsu.fit.g19202.aivakin.task2;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class CalcContext {
    private Stack<Double> stack = new Stack<>();
    private Map<String, Double> params = new HashMap<>();
    private Map<String, Double> defined = new HashMap<>();

    public Map<String, Double> getParams() {
        return params;
    }

    public Stack<Double> getStack() {
        return stack;
    }

    public Map<String, Double> getDefined() {
        return defined;
    }
}
