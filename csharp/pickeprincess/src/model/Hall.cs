namespace model;

using util;
using exceptions;

public class Hall
{
    public Character? CurrentCharacter;
    private List<Character> CharactersInHall;
    private List<Character> CharactersVisited;
    private int PassedNumber;
    private ICharacterGenerator characterGenerator;

    public Hall(ICharacterGenerator characterGenerator)
    {
        this.characterGenerator = characterGenerator;
        this.CharactersVisited = new List<Character>();
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
    }

    public async Task CallNewCharacters()
    {
        this.CharactersVisited = new List<Character>();
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
        Character[] characters = await characterGenerator.GetCharactersListDb();
        this.CharactersInHall = new List<Character>(characters);
    }

    /// <summary>
    /// Returns Character object by their name only if character already seen princess.
    /// Otherwise returns null.
    /// </summary>
    public Character? GetVisitedCharacterByName(string name)
    {
        var foundCharacter = CharactersVisited.FirstOrDefault(character => character.Name == name);
        if (foundCharacter != null)
        {
            return foundCharacter;
        }
        if (CurrentCharacter?.Name == name)
        {
            return CurrentCharacter;
        }
        return null;
    }

    /// <summary>
    /// Returns next cahracters name
    /// </summary>
    public string GetNextVisitorName()
    {
        if (CurrentCharacter != null)
        {
            CharactersVisited.Add(CurrentCharacter);
        }

        if (CharactersVisited.Count == Constants.NumberOfCharacters)
        {
            throw new HallException("Characters in hall list is empty");
        }

        Character nextCharacter = CharactersInHall[0];
        CharactersInHall.RemoveAt(0);
        PassedNumber++;
        CurrentCharacter = nextCharacter;
        return nextCharacter.Name;
    }

    public bool IsCharacterVisitedByName(string characterName)
    {
        return this.GetVisitedCharacterByName(characterName) != null;
    }
}
