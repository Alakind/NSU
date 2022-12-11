namespace model;

using exceptions;

public class Friend
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
        int currentCharacterCoolness = GreatWaitingRoom.GetVisitedCharacterByName(currentCharacterName).Coolness;
        int visitedCharacterCoolness = GreatWaitingRoom.GetVisitedCharacterByName(visitedCharacterName).Coolness;

        return currentCharacterCoolness > visitedCharacterCoolness ?
            currentCharacterName : visitedCharacterName;
    }
}
