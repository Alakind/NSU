namespace model.Character;

class Character
{
    private int _coolness;
    private string _name;

    public Character(string name, int coolness)
    {
        this._coolness = coolness;
        this._name = name;
    }

    public int Coolness
    {
        get { return _coolness; }
    }

    public string Name
    {
        get { return _name; }
    }
}
