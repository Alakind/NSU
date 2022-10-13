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
    public string? PickCoolest(string? currentCharacterName, string? beenCharacterName)
    {
        if (
            currentCharacterName == null ||
            beenCharacterName == null ||
            !GreatWaitingRoom.IsCharacterVisitedByName(currentCharacterName) ||
            !GreatWaitingRoom.IsCharacterVisitedByName(beenCharacterName)
        )
        {
            return null;
        }
        if (
            GreatWaitingRoom.GetBeenCharacterByName(currentCharacterName)?.Coolness
            >
            GreatWaitingRoom.GetBeenCharacterByName(beenCharacterName)?.Coolness
        )
        {
            return currentCharacterName;
        }
        return beenCharacterName;
    }
}
