namespace util.FileReader;

using model.Character;

class FileReader
{
    public Character[] GetCharacters()
    {
        string[] lines = System.IO.File.ReadAllLines(@"./res/characters.txt");

        var random = new Random();
        lines = lines.OrderBy(x => random.Next()).ToArray();

        Character[] characters = new Character[lines.Length];

        for (int i = 0; i < characters.Length; i++)
        {
            characters[i] = new Character(lines[i], i + 1);
        }

        return characters;
    }
}
