using database;
using Microsoft.EntityFrameworkCore;
 
namespace PrincessDB;

public class Program
{
    public static async Task Main(string[] args)
    {
        await using ApplicationContext db = new ApplicationContext();
        
        var generator = new AttemptGenerator(db);

        await generator.GenerateAttempt();
    }
}

