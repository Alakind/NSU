namespace database;

public static class AttemptData
{
    public static int AttemptNumber;

    public static void SetAttemptNumber(string[] args)
    {
        if (args.Length == 0)
        {
            AttemptNumber = -1;
            return;
        }
        
        AttemptNumber = int.Parse(args[0]);
    }
}