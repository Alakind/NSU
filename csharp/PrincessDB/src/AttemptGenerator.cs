using database;

namespace PrincessDB;

using model;
using util;

public class AttemptGenerator
{
    private ApplicationContext _db;

    public AttemptGenerator(ApplicationContext db)
    {
        _db = db;
    }
    
    public async Task GenerateAttempt()
    {
        var generator = new CharacterGenerator(_db);
        
        for (var i = 0; i < Constants.NumberOfCharacters; i++)
        {
            var characters = generator.GetCharactersList();
            var indexInAttempt = 0;
            var attempt = new AttemptEntity
            {
                Number = i,
                CharactersList = characters.Select(character => new CharacterEntity
                {
                    Coolness = character.Coolness,
                    Name =  character.Name,
                    IndexInAttempt = indexInAttempt++,
                    Attempt = i
                }).ToArray().ToList()
            };
            
            await _db.Attempts.AddAsync(attempt);
        }
        await _db.SaveChangesAsync();
    }
}
