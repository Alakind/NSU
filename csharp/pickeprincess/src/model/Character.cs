namespace model;

public class Character
{
    public int Coolness{ get; private set; }

    public string Name{ get; private set; }

    public Character(string name, int coolness)
    {
        this.Coolness = coolness;
        this.Name = name;
    }
}
