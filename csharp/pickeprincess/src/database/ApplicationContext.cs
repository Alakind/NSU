using Microsoft.EntityFrameworkCore;
using util;

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
        optionsBuilder.UseNpgsql("Host="+ Constants.DBHost
                                        + ";Port=" + Constants.DBPort
                                        + ";Database=" + Constants.DBName
                                        + ";Username=" + Constants.DBUsername
                                        + ";Password=" + Constants.DBPassword);
    }
}