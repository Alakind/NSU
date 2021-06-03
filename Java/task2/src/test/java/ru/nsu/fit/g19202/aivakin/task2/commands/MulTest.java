package ru.nsu.fit.g19202.aivakin.task2.commands;

import org.junit.jupiter.api.Test;
import ru.nsu.fit.g19202.aivakin.task2.CalcContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class MulTest {

    @Test
    public void testMul() {
        CalcContext context = new CalcContext();
        Mul mul = new Mul();

        context.getStack().add(100.0);
        context.getStack().add(10.0);

        try {
            mul.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(1000.0, context.getStack().pop(), 1e-9);
    }

    @Test
    public void testDivEmpty() {
        CalcContext context = new CalcContext();
        Mul mul = new Mul();

        try {
            mul.execute(null, context);
        } catch (CalcException e) {
            assertNotNull(e);
        }
    }

    @Test
    public void testDivNeg() {
        CalcContext context = new CalcContext();
        Mul mul = new Mul();

        context.getStack().add(1.0);
        context.getStack().add(-2.0);

        try {
            mul.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(-2.0, context.getStack().pop(), 1e-9);
    }

    @Test
    public void testDivNegOnNeg() {
        CalcContext context = new CalcContext();
        Mul mul = new Mul();

        context.getStack().add(-1.0);
        context.getStack().add(-2.0);

        try {
            mul.execute(null, context);
        } catch (CalcException e) {
            e.printStackTrace();
        }

        assertEquals(2.0, context.getStack().pop(), 1e-9);
    }
}
