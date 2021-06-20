package ru.nsu.fit.g19202.aivakin.task2.commands;

import ru.nsu.fit.g19202.aivakin.task2.CalcContext;
import ru.nsu.fit.g19202.aivakin.task2.Command;

public class Sqrt implements Command {

    @Override
    public void execute(String[] args, CalcContext context) throws CalcException {
        if (context.getStack().size() < 1) {
            throw new CalcException("No objects in stack");
        }
        var value = context.getStack().pop();

        context.getStack().push(Math.sqrt(value));
    }
}
