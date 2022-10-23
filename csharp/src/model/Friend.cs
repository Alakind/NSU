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
    /// Returns coolest character name out two.
    /// </summary>
    public string PickCoolest(string currentCharacterName, string visitedCharacterName)
    {
        if (
            !GreatWaitingRoom.IsCharacterVisitedByName(currentCharacterName) ||
            !GreatWaitingRoom.IsCharacterVisitedByName(visitedCharacterName)
        )
        {
            throw new InvalidInputException("Character given to camparison is not valid!");
        }
        return  GreatWaitingRoom.GetVisitedCharacterByName(currentCharacterName).Coolness
                >
                GreatWaitingRoom.GetVisitedCharacterByName(visitedCharacterName).Coolness
            ?
            currentCharacterName
            :
            visitedCharacterName;
    }
}
