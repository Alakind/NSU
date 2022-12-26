namespace util;

using model;

public interface ICharacterGenerator
{
    public Character[] GetCharactersList();

    public Task<Character[]> GetCharactersListDb();
}
