package ru.nsu.fit.g19202.aivakin.task2.commands;

import ru.nsu.fit.g19202.aivakin.task2.CalcContext;
import ru.nsu.fit.g19202.aivakin.task2.Command;

public class Print implements Command {

    @Override
    public void execute(String[] args, CalcContext context) {
        System.out.println(context.getStack());
    }
}
