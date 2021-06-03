package ru.nsu.fit.g19202.aivakin.task2.commands;

import org.junit.jupiter.api.Test;
import ru.nsu.fit.g19202.aivakin.task2.CalcContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class SqrtTest {

    @Test
    public void testSqrt() {
        CalcContext context = new CalcContext();
        Sqrt sqrt = new Sqrt();

        context.getStack().add(144.0);

        try {
            sqrt.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(12.0, context.getStack().pop(), 1e-9);
    }

    @Test
    public void testSqrtEmpty() {
        CalcContext context = new CalcContext();
        Sqrt sqrt = new Sqrt();

        try {
            sqrt.execute(null, context);
        } catch (CalcException e) {
            assertNotNull(e);
        }
    }

    @Test
    public void testSqrtNeg() {
        CalcContext context = new CalcContext();
        Sqrt sqrt = new Sqrt();

        context.getStack().add(-144.0);

        try {
            sqrt.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(Math.sqrt(-1), context.getStack().pop(), 1e-9);
    }
}
