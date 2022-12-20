namespace util;

using model;

public class CharacterGenerator
{
    public Character[] GetCharactersFromFile()
    {
        string[] lines = System.IO.File.ReadAllLines(Path.Combine(Environment.CurrentDirectory, $@"res", "top100characters.txt"));

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

    public Character[] GetCharactersMock()
    {
        string[] lines = {
            "Character1",
            "Character2",
            "Character3",
            "Character4",
            "Character5",
            "Character6",
            "Character7",
            "Character8",
            "Character9",
            "Character10"};

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
