namespace database;

using model;

public class CharacterEntity
{
    public int Id { get; set; }
    public int Coolness { get; set; }
    public string Name { get; set; }
    public int NumberInAttempt { get; set; }
    public int Attempt { get; set; }
}