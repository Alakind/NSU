namespace model;

class Hall
{
    public Character? CurrentCharacter { get; private set; }
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
    public Character? GetBeenCharacterByName(string? name)
    {
        foreach (Character character in CharactersVisited)
        {
            if (character.Name == name)
            {
                return character;
            }
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
        if (this.GetBeenCharacterByName(characterName) == null)
        {
            return false;
        }
        return true;
    }
}
