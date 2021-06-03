package ru.nsu.fit.g19202.aivakin.task2.commands;

import org.junit.jupiter.api.Test;
import ru.nsu.fit.g19202.aivakin.task2.CalcContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class PushTest {

    @Test
    public void testPush() {
        CalcContext context = new CalcContext();
        Push push = new Push();

        String[] args = new String[2];
        args[1] = "42";

        push.execute(args, context);

        assertEquals(42.0, context.getStack().pop(), 1e-9);
    }
}
