namespace model;

class Friend
{
    private Hall GreatWaitingRoom;

    public Friend(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    /// <summary>
    /// Returns coolest character out two. If one of them is null, or can't be compared -- returns null.
    /// </summary>
    public string? PickCoolest(string? currentCharacter, string? beenCharacter)
    {
        if (
            currentCharacter == null ||
            beenCharacter == null ||
            GreatWaitingRoom.GetBeenCharacterByName(currentCharacter) == null ||
            GreatWaitingRoom.GetBeenCharacterByName(beenCharacter) == null
        )
        {
            return null;
        }
        if (
            GreatWaitingRoom.GetBeenCharacterByName(currentCharacter)?.Coolness
            >
            GreatWaitingRoom.GetBeenCharacterByName(beenCharacter)?.Coolness
        )
        {
            return currentCharacter;
        }
        return beenCharacter;
    }

    /// <summary>
    /// Returns name of next character
    /// </summary>
    public string? GetNextCharacterName()
    {
        return GreatWaitingRoom.GetNextCharacterName();
    }
}
