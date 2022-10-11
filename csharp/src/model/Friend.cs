namespace model;

static class Friend
{
    public static bool CharactersComparator(Character? firstCharacter, Character? secondCharacter)
    {
        if (firstCharacter == null || secondCharacter == null)
        {
            return true;
        }
        return firstCharacter.Coolness > secondCharacter.Coolness;
    }

    public static Character? PickCoolest(Character? currentCharacter, Character? beenCharacter, Hall hall)
    {
        if (currentCharacter == null || beenCharacter == null || hall.CharactersInHall.Contains(beenCharacter))
        {
            return null;
        }
        if (CharactersComparator(currentCharacter, beenCharacter))
        {
            return currentCharacter;
        }
        return beenCharacter;
    }
}
