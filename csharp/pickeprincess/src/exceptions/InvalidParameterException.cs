namespace exceptions;

public class InvalidInputException : CastleException
{
    public InvalidInputException()
    {
    }

    public InvalidInputException(string message)
        : base(message)
    {
    }
}