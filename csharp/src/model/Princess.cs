namespace model;

using util;

class Princess
{
    private Friend Victoria;
    private int CharactersPassed;

    public Princess(Hall hall, Friend friend)
    {
        Victoria = friend;
        CharactersPassed = 0;
    }

    /// <summary>
    /// Chooses groom by some algorithm.
    /// Returns their name.
    /// </summary>
    public string? ChooseGroom()
    {
        string? coolestYet = Victoria.GetNextCharacterName();
        string? currentCharacterName = Victoria.GetNextCharacterName();
        CharactersPassed++;
        while (CharactersPassed < Constants.NumberOfCharacters * Constants.PartToPass)
        {
            coolestYet = Victoria.PickCoolest(currentCharacterName, coolestYet);
            currentCharacterName = Victoria.GetNextCharacterName();
            CharactersPassed++;
        }

        currentCharacterName = Victoria.GetNextCharacterName();
        CharactersPassed++;
        while (Victoria.PickCoolest(coolestYet, currentCharacterName) == coolestYet && CharactersPassed < Constants.NumberOfCharacters - 2)
        {
            currentCharacterName = Victoria.GetNextCharacterName();
            CharactersPassed++;
        }

        if (Victoria.PickCoolest(coolestYet, currentCharacterName) == coolestYet)
        {
            return null;
        }

        return currentCharacterName;
    }
}
