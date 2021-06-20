package ru.nsu.fit.g19202.aivakin.task2.commands;

import ru.nsu.fit.g19202.aivakin.task2.CalcContext;
import ru.nsu.fit.g19202.aivakin.task2.Command;

public class Push implements Command {

    @Override
    public void execute(String[] args, CalcContext context) {
        var input = args[1];

        boolean numeric = true;
        Double num = 0.0;
        try {
            num = Double.parseDouble(input);
        } catch (NumberFormatException e) {
            numeric = false;
        }

        if (numeric) {
            context.getStack().add(num);
        }
        else {
            context.getStack().add(context.getDefined().get(input));
        }
    }
}
