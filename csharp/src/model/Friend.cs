namespace model;

static class Friend
{

    public static bool CompareCharacters(Character? firstCharacter, Character? secondCharacter)
    {
        if (firstCharacter == null || secondCharacter == null) {
            return true;
        }
        return firstCharacter.Coolness > secondCharacter.Coolness;
    }

    public static Character? PickCoolest(Character? firstCharacter, Character? secondCharacter)
    {
        if (firstCharacter == null || secondCharacter == null) {
            return null;
        }
        if (CompareCharacters(firstCharacter, secondCharacter))
        {
            return firstCharacter;
        }
        return secondCharacter;
    }
}
