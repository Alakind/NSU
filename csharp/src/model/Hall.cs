namespace model;

class Hall
{
    public Character? CurrentCharacter{ get; private set; }
    public List<Character> CharactersInHall{ get; private set; }
    public int PassedNumber;

    public Hall(Character[] characters)
    {
        this.CharactersInHall = new List<Character>(characters);
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
    }

    public Character? NextCharacter()
    {
        if (CharactersInHall.Count == 0)
        {
            return null;
        }

        Character nextCharacter = CharactersInHall[0];
        CharactersInHall.RemoveAt(0);
        PassedNumber++;
        return nextCharacter;
    }
}
