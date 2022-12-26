using Microsoft.EntityFrameworkCore;

namespace database;

public class ApplicationContext : DbContext
{
    public DbSet<AttemptEntity> Attempts { get; set; }
    
    public DbSet<CharacterEntity> Characters { get; set; }
    
    public ApplicationContext()
    {
        Database.EnsureCreated();
    }
    
    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseNpgsql("Host=localhost;Port=5432;Database=princessdb;Username=admin;Password=1234");
    }
}