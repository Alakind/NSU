package ru.nsu.fit.g19202.aivakin.task2;

import ru.nsu.fit.g19202.aivakin.task2.commands.Add;
import ru.nsu.fit.g19202.aivakin.task2.commands.CalcException;
import ru.nsu.fit.g19202.aivakin.task2.commands.Print;
import ru.nsu.fit.g19202.aivakin.task2.commands.Push;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

public class Main {

    public static void main(String[] args) {
        CalcContext context = new CalcContext();

        try {
            BufferedReader reader;
            if (args.length == 0) {
                reader = new BufferedReader(new InputStreamReader(System.in));
            } else {
                File file = new File(args[0]);
                FileReader fr = new FileReader(file);
                reader = new BufferedReader(fr);
            }


            CommandFactory factory = CommandFactory.getInstance();
            Journal journal = Journal.getInstance();

            while (true) {
                String arg = reader.readLine();
                if (arg == null || arg.isEmpty()) {
                    break;
                }

                var comArgs = arg.split(" ");
                if (comArgs[0].contains("#")) {
                    continue;
                }

                journal.makeNote(comArgs[0]);

                if (comArgs[0].equals("hist")) {
                    journal.showHistory();
                    continue;
                }

                var cmd = factory.findCommandByName(comArgs[0]);
                if (cmd == null) {
                    System.out.println("Command not found");
                    continue;
                }
                try {
                    cmd.execute(comArgs, context);
                } catch (CalcException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
