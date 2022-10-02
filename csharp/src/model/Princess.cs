namespace model;

class Princess
{

    public Princess(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    public Hall GreatWaitingRoom{ get; private set; }

    public Character? ClassicSolution() {
        Character? coolestYet = GreatWaitingRoom.NextCharacter();
        Character? currentCharacter = GreatWaitingRoom.NextCharacter();
        while (GreatWaitingRoom.PassedNumber < 40)
        {
            coolestYet = Friend.PickCoolest(coolestYet, currentCharacter);
            currentCharacter = GreatWaitingRoom.NextCharacter();
        }

        currentCharacter = GreatWaitingRoom.NextCharacter();
        while (Friend.CompareCharacters(coolestYet, currentCharacter) && GreatWaitingRoom.PassedNumber < 98)
        {
            currentCharacter = GreatWaitingRoom.NextCharacter();
        }

        if (Friend.CompareCharacters(coolestYet, currentCharacter)) {
            return null;
        }

        return currentCharacter;
    }
}
