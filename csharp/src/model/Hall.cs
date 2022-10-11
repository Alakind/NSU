namespace model;

class Hall
{
    public Character? CurrentCharacter { get; private set; }
    public List<Character> CharactersInHall { get; private set; }
    public List<Character> CharactersBeen { get; private set; }
    public int PassedNumber;

    public Hall(Character[] characters)
    {
        this.CharactersInHall = new List<Character>(characters);
        this.CharactersBeen = new List<Character>();
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
    }

    public Character? GetBeenCharacterByName(string? name) {
        for (int i = 0; i < CharactersBeen.Count; i++)
        {
            if (CharactersBeen[i].Name == name){
                return CharactersBeen[i];
            }
            else if (CurrentCharacter?.Name == name)
            {
                return CurrentCharacter;
            }
        }
        return null;
    }

    public string? NextCharacter()
    {
        if (CharactersInHall.Count == 0)
        {
            return null;
        }
        if (CurrentCharacter != null)
        {
            CharactersBeen.Add(CurrentCharacter);
        }

        Character nextCharacter = CharactersInHall[0];
        CharactersInHall.RemoveAt(0);
        PassedNumber++;
        CurrentCharacter = nextCharacter;
        return nextCharacter.Name;
    }
}
