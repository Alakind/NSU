namespace model;

class Character
{

    public Character(string name, int coolness)
    {
        this.Coolness = coolness;
        this.Name = name;
    }

    public int Coolness{ get; private set; }

    public string Name{ get; private set; }
}
