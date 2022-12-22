namespace util;

using model;

public class CharacterGenerator : ICharacterGenerator
{
    public Character[] GetCharactersList()
    {
        string[] lines = System.IO.File.ReadAllLines(Path.Combine(Environment.CurrentDirectory, "res", "top100characters.txt"));

        var random = new Random();
        lines = lines.OrderBy(x => random.Next()).ToArray();

        Character[] characters = new Character[lines.Length];

        for (int i = 0; i < characters.Length; i++)
        {
            characters[i] = new Character(lines[i], i + 1);
        }

        characters = characters.OrderBy(x => random.Next()).ToArray();

        return characters;
    }
}