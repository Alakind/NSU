namespace database;

using model;

/// <summary>
/// Enitity to store character
/// </summary>
public class CharacterEntity
{
    public int Id { get; set; }
    public int Coolness { get; set; }
    public string Name { get; set; }
    public int IndexInAttempt { get; set; }
    public int Attempt { get; set; }
}