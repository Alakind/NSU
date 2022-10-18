namespace model;

class Hall
{
    public Character? CurrentCharacter;
    private List<Character> CharactersInHall;
    private List<Character> CharactersVisited;
    private int PassedNumber;

    public Hall(Character[] characters)
    {
        this.CharactersInHall = new List<Character>(characters);
        this.CharactersVisited = new List<Character>();
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
    }

    /// <summary>
    /// Returns Character object by their name only if character already seen princess.
    /// Otherwise returns null.
    /// </summary>
    public Character? GetVisitedCharacterByName(string? name)
    {
        var foundCharacter = CharactersVisited.FirstOrDefault(character => character.Name == name);
        if (foundCharacter != null) {
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
    public string? GetNextVisitorName()
    {
        if (CharactersInHall.Count == 0)
        {
            return null;
        }
        if (CurrentCharacter != null)
        {
            CharactersVisited.Add(CurrentCharacter);
        }

        Character nextCharacter = CharactersInHall[0];
        CharactersInHall.RemoveAt(0);
        PassedNumber++;
        CurrentCharacter = nextCharacter;
        return nextCharacter.Name;
    }

    public bool IsCharacterVisitedByName(string characterName)
    {
        // TODO: ternary
        if (this.GetVisitedCharacterByName(characterName) == null)
        {
            return false;
        }
        return true;
    }
}
