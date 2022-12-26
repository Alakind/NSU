using database;

namespace PrincessDB;

using model;
using util;

public class AttemptGenerator
{
    public async Task Generate()
    {
        var generator = new CharacterGenerator(null);

        await using ApplicationContext db = new ApplicationContext();
        
        for (var i = 0; i < 100; i++)
        {
            var characters = generator.GetCharactersList();
            var numberInAttempt = 0;
            var attempt = new AttemptEntity
            {
                Number = i,
                CharactersList = characters.Select(character => new CharacterEntity
                {
                    Coolness = character.Coolness,
                    Name =  character.Name,
                    NumberInAttempt = numberInAttempt++,
                    Attempt = i
                }).ToArray().ToList()
            };
            
            await db.Attempts.AddAsync(attempt);
        }
        await db.SaveChangesAsync();
    }
}
