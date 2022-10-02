namespace model;

class Hall
{

    public Hall(Character[] characters)
    {
        this.CharactersInHall = characters;
        this.CurrentCharacter = null;
        this.PassedNumber = 0;
    }

    public Character? CurrentCharacter{ get; private set; }
    public Character[] CharactersInHall{ get; private set; }
    private int PassedNumber;

    public Character? NextCharacter()
    {
        if (CharactersInHall.Length == PassedNumber) {
            return null;
        }

        return CharactersInHall[PassedNumber++];
    }
}
