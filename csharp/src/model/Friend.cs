namespace model;

using exceptions;

class Friend
{
    private Hall GreatWaitingRoom;

    public Friend(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    /// <summary>
    /// Returns coolest character name out two. If one of them is null, or can't be compared -- returns null.
    /// </summary>
    public string? PickCoolest(string? currentCharacterName, string? visitedCharacterName)
    {
        if (
            currentCharacterName == null ||
            visitedCharacterName == null ||
            !GreatWaitingRoom.IsCharacterVisitedByName(currentCharacterName) ||
            !GreatWaitingRoom.IsCharacterVisitedByName(visitedCharacterName)
        )
        {
            throw new InvalidInputException("Character given to camparison is not valid!");
        }
        if (
            GreatWaitingRoom.GetVisitedCharacterByName(currentCharacterName)?.Coolness
            >
            GreatWaitingRoom.GetVisitedCharacterByName(visitedCharacterName)?.Coolness
        )
        {
            return currentCharacterName;
        }
        return visitedCharacterName;
    }
}
