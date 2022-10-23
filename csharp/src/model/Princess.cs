namespace model;

using util;

class Princess
{
    private Friend Victoria;
    private int CharactersVisitedCounter;
    private ThroneRoom GoldenThroneRoom;

    public Princess(ThroneRoom throneRoom, Friend friend)
    {
        Victoria = friend;
        CharactersVisitedCounter = 0;
        GoldenThroneRoom = throneRoom;
    }

    /// <summary>
    /// Chooses groom by some algorithm.
    /// Returns their name.
    /// </summary>
    public string? ChooseGroom()
    {
        string coolestYet = GoldenThroneRoom.GetNextVisitorName();
        string currentCharacterName = GoldenThroneRoom.GetNextVisitorName();
        CharactersVisitedCounter++;
        while (CharactersVisitedCounter < Constants.NumberOfCharacters * Constants.PartToPass)
        {
            coolestYet = Victoria.PickCoolest(currentCharacterName, coolestYet);
            currentCharacterName = GoldenThroneRoom.GetNextVisitorName();
            CharactersVisitedCounter++;
        }

        currentCharacterName = GoldenThroneRoom.GetNextVisitorName();
        CharactersVisitedCounter++;
        while (
            Victoria.PickCoolest(coolestYet, currentCharacterName) == coolestYet &&
            CharactersVisitedCounter < Constants.NumberOfCharacters - 2
        )
        {
            currentCharacterName = GoldenThroneRoom.GetNextVisitorName();
            CharactersVisitedCounter++;
        }

        if (Victoria.PickCoolest(coolestYet, currentCharacterName) == coolestYet)
        {
            return null;
        }

        return currentCharacterName;
    }

    public int GetHappines(int? coolness)
    {
        if (!coolness.HasValue)
        {
            return Constants.NooneChosenPoints;
        }
        if (coolness < Constants.NumberOfCharacters / 2)
        {
            return 0;
        }
        return coolness.Value;
    }
}
