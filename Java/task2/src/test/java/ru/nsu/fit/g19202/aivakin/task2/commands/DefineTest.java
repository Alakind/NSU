package ru.nsu.fit.g19202.aivakin.task2.commands;

import org.junit.jupiter.api.Test;
import ru.nsu.fit.g19202.aivakin.task2.CalcContext;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class DefineTest {

    @Test
    public void testDefine() {
        CalcContext context = new CalcContext();
        Define define = new Define();

        String[] args = new String[3];
        args[1] = "a";
        args[2] = "1";

        define.execute(args, context);

        assertEquals(1.0, context.getDefined().get("a"), 1e-9);
    }
}
