namespace database;

using model;

public class AttemptEntity
{
    public int Id { get; set; }
    public int Number { get; set; }
    public List<CharacterEntity> CharactersList { get; set; }
}