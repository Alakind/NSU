namespace view.ConsoleView;

using model.Character;

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
        Console.WriteLine(character.Name + ", " + character.Coolness.ToString());
    }
}
