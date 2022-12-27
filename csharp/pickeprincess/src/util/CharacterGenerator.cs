using database;
using exceptions;
using Microsoft.EntityFrameworkCore;

namespace util;

using model;

public class CharacterGenerator : ICharacterGenerator
{
    private ApplicationContext _db;
    
    public CharacterGenerator(ApplicationContext db)
    {
        this._db = db;
    }
    
    public Character[] GetCharactersList()
    {
        string[] lines = System.IO.File.ReadAllLines(Path.Combine(Environment.CurrentDirectory, "../../../res", "top100characters.txt"));

        var random = new Random();
        lines = lines.OrderBy(x => random.Next()).ToArray();

        Character[] characters = new Character[lines.Length];

        for (int i = 0; i < characters.Length; i++)
        {
            characters[i] = new Character(lines[i], i + 1);
        }

        characters = characters.OrderBy(x => random.Next()).ToArray();

        return characters;
    }

    public async Task<Character[]> GetCharactersListDb()
    {
        var attemptEntity = await _db.Attempts
            .Include(c => c.CharactersList)
            .FirstOrDefaultAsync(a => a.Number == AttemptData.AttemptNumber);

        if (attemptEntity == null)
        {
            throw new InvalidInputException("Attempt number is not valid!");
        }
        
        return attemptEntity.CharactersList.Select(characterEntity => new Character(
                characterEntity.Name,
                characterEntity.Coolness
            )
        ).ToArray();
    }
}
