namespace mocks;

using model;
using util;

public class CharacterGeneratorMock : ICharacterGenerator
{
    public Character[] GetCharactersList()
    {
        string[] lines = new string[3];
        
        for (int i = 0; i < 3; i++)
        {
            lines[i] = "Character" + i; 
        }

        Character[] characters = new Character[lines.Length];

        for (int i = 0; i < characters.Length; i++)
        {
            characters[i] = new Character(lines[i], i + 1);
        }

        return characters;
    }
}
