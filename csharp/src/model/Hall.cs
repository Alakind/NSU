namespace model;

class Hall
{
    public Character? CurrentCharacter { get; private set; }
    public List<Character> CharactersInHall { get; private set; }
    public List<Character> CharactersPassed { get; private set; }
    public int PassedNumber;

    public Hall(Character[] characters)
    {
        this.CharactersInHall = new List<Character>(characters);
        this.CharactersPassed = new List<Character>();
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
    }

    /// <summary>
    /// Returns Character object by their name only if character already seen princess.
    /// Otherwise returns null.
    /// </summary>
    public Character? GetBeenCharacterByName(string? name)
    {
        foreach (Character character in CharactersPassed)
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
    public string? GetNextCharacterName()
    {
        if (CharactersInHall.Count == 0)
        {
            return null;
        }
        if (CurrentCharacter != null)
        {
            CharactersPassed.Add(CurrentCharacter);
        }

        Character nextCharacter = CharactersInHall[0];
        CharactersInHall.RemoveAt(0);
        PassedNumber++;
        CurrentCharacter = nextCharacter;
        return nextCharacter.Name;
    }
}
