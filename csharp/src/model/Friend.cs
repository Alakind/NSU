namespace model;

class Friend
{
    public Hall GreatWaitingRoom { get; private set; }

    public Friend(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    public bool CharactersComparator(string? firstCharacter, string? secondCharacter)
    {
        if (firstCharacter == null || secondCharacter == null)
        {
            return true;
        }
        return GreatWaitingRoom.GetBeenCharacterByName(firstCharacter)?.Coolness
            >
            GreatWaitingRoom.GetBeenCharacterByName(secondCharacter)?.Coolness;
    }

    public string? PickCoolest(string? currentCharacter, string? beenCharacter)
    {
        if (currentCharacter == null || beenCharacter == null)
        {
            return null;
        }
        if (CharactersComparator(currentCharacter, beenCharacter))
        {
            return currentCharacter;
        }
        return beenCharacter;
    }

    public string? NextCharacter()
    {
        return GreatWaitingRoom.NextCharacter();
    }
}
