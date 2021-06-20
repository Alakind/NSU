package ru.nsu.fit.g19202.aivakin.task2;

import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

public class CommandFactory {

    private static class Helper {
        private static final CommandFactory factory = new CommandFactory();
    }

    public static CommandFactory getInstance() {
        return Helper.factory;
    }

    private final Map<String, Command> commands = new HashMap<>();

    private CommandFactory() {
        try(var in = Main.class.getResourceAsStream("commands.properties")) {
            Properties props = new Properties();
            props.load(in);

            for (var name : props.stringPropertyNames()) {
                String className = props.getProperty(name);
                var cmd = (Command)Class.forName(className).newInstance();

                commands.put(name, cmd);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public Command findCommandByName(String name) {
        return commands.get(name);
    }
}
