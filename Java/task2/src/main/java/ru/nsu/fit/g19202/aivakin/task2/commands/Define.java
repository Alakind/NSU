package ru.nsu.fit.g19202.aivakin.task2.commands;

import ru.nsu.fit.g19202.aivakin.task2.CalcContext;
import ru.nsu.fit.g19202.aivakin.task2.Command;

public class Define implements Command {

    @Override
    public void execute(String[] args, CalcContext context) {
        context.getDefined().put(args[1], Double.valueOf(args[2]));
    }
}
