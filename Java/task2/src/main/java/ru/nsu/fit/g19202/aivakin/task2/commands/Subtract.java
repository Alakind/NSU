package ru.nsu.fit.g19202.aivakin.task2.commands;

import ru.nsu.fit.g19202.aivakin.task2.CalcContext;
import ru.nsu.fit.g19202.aivakin.task2.Command;

public class Subtract implements Command {

    @Override
    public void execute(String[] args, CalcContext context) throws CalcException {
        if (context.getStack().size() < 2) {
            throw new CalcException("Less then two objects in stack");
        }
        var value1 = context.getStack().pop();
        var value2 = context.getStack().pop();

        context.getStack().push(value1 - value2);
    }
}
