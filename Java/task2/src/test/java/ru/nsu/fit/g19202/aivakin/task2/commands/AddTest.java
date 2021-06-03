package ru.nsu.fit.g19202.aivakin.task2.commands;

import org.junit.jupiter.api.Test;
import ru.nsu.fit.g19202.aivakin.task2.CalcContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class AddTest {

    @Test
    public void testAdd() {
        CalcContext context = new CalcContext();
        Add add = new Add();

        context.getStack().add(1.0);
        context.getStack().add(2.0);

        try {
            add.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(3.0, context.getStack().pop(), 1e-9);
    }

    @Test
    public void testAddEmpty() {
        CalcContext context = new CalcContext();
        Add add = new Add();

        try {
            add.execute(null, context);
        } catch (CalcException e) {
            assertNotNull(e);
        }
    }

    @Test
    public void testAddNeg() {
        CalcContext context = new CalcContext();
        Add add = new Add();

        context.getStack().add(1.0);
        context.getStack().add(-2.0);

        try {
            add.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(-1.0, context.getStack().pop(), 1e-9);
    }
}
