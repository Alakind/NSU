namespace exceptions;

public class HallException : CastleException
{
    public HallException()
    {
    }

    public HallException(string message)
        : base(message)
    {
    }
}