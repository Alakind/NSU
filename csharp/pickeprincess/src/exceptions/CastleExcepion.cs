namespace exceptions;

using System;

public class CastleException : Exception
{
    public CastleException()
    {
    }

    public CastleException(string message)
        : base(message)
    {
    }
}