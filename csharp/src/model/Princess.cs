namespace model;

using util;

class Princess
{
    private Friend Victoria;
    private int CharactersPassed;

    public Princess(Hall hall, Friend friend)
    {
        Victoria = friend;
        CharactersPassed = 1;
    }

    public string? ChooseGroom() {
        string? coolestYet = Victoria.NextCharacter();
        string? currentCharacter = Victoria.NextCharacter();
        while (CharactersPassed < Constants.NumberOfCharacters * Constants.PartToPass)
        {
            coolestYet = Victoria.PickCoolest(currentCharacter, coolestYet);
            currentCharacter = Victoria.NextCharacter();
            CharactersPassed++;
        }

        currentCharacter = Victoria.NextCharacter();
        CharactersPassed++;
        while (Victoria.CharactersComparator(coolestYet, currentCharacter) && CharactersPassed < Constants.NumberOfCharacters - 2)
        {
            currentCharacter = Victoria.NextCharacter();
            CharactersPassed++;
        }

        if (Victoria.CharactersComparator(coolestYet, currentCharacter))
        {
            return null;
        }

        return currentCharacter;
    }

    public int CountHappines(Character? groom)
    {
        if (groom == null)
        {
            return Constants.NooneChosenPoints;
        }
        else if (groom.Coolness < Constants.NumberOfCharacters / 2)
        {
            return 0;
        }
        return groom.Coolness;
    }
}
