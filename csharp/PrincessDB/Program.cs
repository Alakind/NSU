using database;
using Microsoft.EntityFrameworkCore;
 
namespace PrincessDB;

public class Program
{
    public static async Task Main(string[] args)
    {
        var generator = new AttemptGenerator();
        
        await using ApplicationContext db = new ApplicationContext();

        await generator.Generate(db);
    }
}

