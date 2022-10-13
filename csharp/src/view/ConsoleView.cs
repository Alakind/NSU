namespace view;

using model;
using util;

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

    public void ShowGroom(string? character)
    {
        if (character == null)
        {
            Console.WriteLine($"Princess is strong and independant");
            return;
        }
        Console.WriteLine($"Princess have picked: {character}!!!");
    }

    public void ShowHappines(Character? groom)
    {
        if (groom == null)
        {
            Console.WriteLine($"Princess happiness is {Constants.NooneChosenPoints}");
            return;
        }
        else if (groom.Coolness < Constants.NumberOfCharacters / 2)
        {
            Console.WriteLine($"Princess happiness is {0}");
            return;
        }
        Console.WriteLine($"Princess happiness is {groom.Coolness}");
    }
}
