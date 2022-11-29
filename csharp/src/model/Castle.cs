namespace model;

using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using exceptions;
using view;
using util;
using model;

class Castle : IHostedService
{
    private IHostApplicationLifetime Lifetime;
    private Princess princess;
    private Hall hall;
    private ThroneRoom throneRoom;
    private Friend friend;
    private CharacterGenerator reader;

    public Castle(Princess princess, Hall hall, ThroneRoom throneRoom, Friend friend, CharacterGenerator reader, IHostApplicationLifetime lifetime)
    {
        this.princess = princess;
        this.hall = hall;
        this.throneRoom = throneRoom;
        this.friend = friend;
        this.reader = reader;
        Lifetime = lifetime;
    }

    private void StartGroomViewings()
    {
        var view = new ConsoleView();

        view.Greet();

        Character[] characters = reader.GetCharactersFromFile();

        try
        {
            string? groomName = princess.ChooseGroom();

            if (groomName != null)
            {
                Character? groom = hall.GetVisitedCharacterByName(groomName);
                view.ShowHappines(princess.GetHappines(groom?.Coolness));
            }

            view.ShowGroom(groomName);
        }
        catch(CastleException error)
        {
            Console.WriteLine($"Exception: {error}");
        }
        finally
        {
            Lifetime.StopApplication();
        }
    }

    public Task StartAsync(CancellationToken cancellationToken)
    {
        Lifetime.ApplicationStarted.Register(() =>
        {
            Task.Run(StartGroomViewings, cancellationToken);
        });
        return Task.CompletedTask;
    }

    public Task StopAsync(CancellationToken cancellationToken)
    {
        return Task.CompletedTask;
    }
}
