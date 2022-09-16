namespace util.FileReader;

using model.Character;

class FileReader
{
    public Character[] GetCharacters()
    {
        string[] lines = System.IO.File.ReadAllLines(@"./res/characters.txt");

        var random = new Random();
        for (int i = lines.Length - 1; i >= 1; i--)
        {
            int j = random.Next(i + 1);
            var temp = lines[j];
            lines[j] = lines[i];
            lines[i] = temp;
        }

        Character[] characters = new Character[lines.Length];

        for (int i = 0; i < characters.Length; i++)
        {
            characters[i] = new Character(lines[i], i + 1);
        }

        return characters;
    }
}
