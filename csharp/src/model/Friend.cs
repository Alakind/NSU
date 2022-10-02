namespace model;

static class Friend
{

    public static bool compareCharacters(Character firstChatacter, Character secondCharacter)
    {
        return firstChatacter.Coolness > secondCharacter.Coolness;
    }
}
