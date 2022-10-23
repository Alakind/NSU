namespace model;

class ThroneRoom
{
    private Hall GreatWaitingRoom;

    public ThroneRoom(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    /// <summary>
    /// Returns name of next character
    /// </summary>
    public string GetNextVisitorName()
    {
        return GreatWaitingRoom.GetNextVisitorName();
    }
}
