namespace view;

using model;

class ConsoleView : IView
{
    public void Greet()
    {
        Console.WriteLine(@"Welcome to Picky Princess's Castle!
        ┈┈┈┈▅┈┈▕▀┈┈┈┈┈┈
        ┈┈┈▕┈┈┈╱╲▕▀┈┈┈┈
        ┈┈┈╱╲┈┈▏▕╱╲┈┈┈┈
        ┈┈┈▏▕╱╲▏▎▏▕╱╲┈▃
        ┈╱╲▏▎▅▂▅▂▏▎▏▎▏▏
        ▂▏▎▏▕╭┳┳╮▏┊▏▕╱╲
        ▏▏┊▏▎┃┊┊┃▏▎▏▎▏▕
        ▇▆▅▃▂┻┻┻┻▂▃▅▆▇▉
");
    }

    public void ShowCharacter(Character character)
    {
        Console.WriteLine($"{character.Name}, {character.Coolness}");
    }

    public void ShowGroom(Character? character)
    {
        if (character == null)
        {
            Console.WriteLine($"Princess is strong and independant");
            return;
        }
        Console.WriteLine($"Princess have picked: {character.Name}!!! They are solid {character.Coolness}/100!!!");
    }
}
