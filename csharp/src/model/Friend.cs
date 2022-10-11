namespace model;

class Friend
{
    public Hall GreatWaitingRoom { get; private set; }

    public Friend(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    public string? PickCoolest(string? currentCharacter, string? beenCharacter)
    {
        if (currentCharacter == null || beenCharacter == null)
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

    public string? NextCharacter()
    {
        return GreatWaitingRoom.NextCharacter();
    }
}
