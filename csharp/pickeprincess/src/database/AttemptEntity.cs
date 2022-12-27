namespace database;

using model;

/// <summary>
/// Entity to store Attempt
/// </summary>
public class AttemptEntity
{
    public int Id { get; set; }
    public int Number { get; set; }
    public List<CharacterEntity> CharactersList { get; set; }
}