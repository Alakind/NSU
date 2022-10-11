namespace model;

using util;

class Princess
{
    public Hall GreatWaitingRoom{ get; private set; }

    public Princess(Hall hall)
    {
        GreatWaitingRoom = hall;
    }

    public Character? ChooseGroom() {
        Character? coolestYet = GreatWaitingRoom.NextCharacter();
        Character? currentCharacter = GreatWaitingRoom.NextCharacter();
        while (GreatWaitingRoom.PassedNumber < Constants.NumberOfCharacters * Constants.PartToPass)
        {
            coolestYet = Friend.PickCoolest(currentCharacter, coolestYet, GreatWaitingRoom);
            currentCharacter = GreatWaitingRoom.NextCharacter();
        }

        currentCharacter = GreatWaitingRoom.NextCharacter();
        while (Friend.CharactersComparator(coolestYet, currentCharacter) && GreatWaitingRoom.PassedNumber < Constants.NumberOfCharacters - 2)
        {
            currentCharacter = GreatWaitingRoom.NextCharacter();
        }

        if (Friend.CharactersComparator(coolestYet, currentCharacter))
        {
            return null;
        }

        return currentCharacter;
    }
}
