package ru.nsu.fit.g19202.aivakin.task2;

import ru.nsu.fit.g19202.aivakin.task2.commands.CalcException;

import java.util.Map;
import java.util.Stack;

public interface Command {
    void execute(String[] args, CalcContext context) throws CalcException;
}