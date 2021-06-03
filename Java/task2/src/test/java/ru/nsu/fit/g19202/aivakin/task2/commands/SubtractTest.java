package ru.nsu.fit.g19202.aivakin.task2.commands;

import org.junit.jupiter.api.Test;
import ru.nsu.fit.g19202.aivakin.task2.CalcContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class SubtractTest {

    @Test
    public void testSub() {
        CalcContext context = new CalcContext();
        Subtract sub = new Subtract();

        context.getStack().add(1.0);
        context.getStack().add(2.0);

        try {
            sub.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(1.0, context.getStack().pop(), 1e-9);
    }

    @Test
    public void testSubEmpty() {
        CalcContext context = new CalcContext();
        Subtract sub = new Subtract();

        try {
            sub.execute(null, context);
        } catch (CalcException e) {
            assertNotNull(e);
        }
    }

    @Test
    public void testSubNeg() {
        CalcContext context = new CalcContext();
        Subtract sub = new Subtract();

        context.getStack().add(1.0);
        context.getStack().add(-2.0);

        try {
            sub.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(-3.0, context.getStack().pop(), 1e-9);
    }
}
