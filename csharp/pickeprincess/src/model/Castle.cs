namespace model;

using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using exceptions;
using view;
using util;
using model;

public class Castle : IHostedService
{
    private IHostApplicationLifetime Lifetime;
    private readonly Princess _princess;
    private readonly Hall _hall;
    private readonly ThroneRoom _throneRoom;
    private readonly Friend _friend;
    private readonly ICharacterGenerator _reader;

    public Castle(Princess princess, Hall hall, ThroneRoom throneRoom, Friend friend, ICharacterGenerator reader, IHostApplicationLifetime lifetime)
    {
        this._princess = princess;
        this._hall = hall;
        this._throneRoom = throneRoom;
        this._friend = friend;
        this._reader = reader;
        Lifetime = lifetime;
    }

    private void StartGroomViewings()
    {
        var view = new ConsoleView();

        view.Greet();

        Character[] characters = _reader.GetCharactersList();

        try
        {
            string? groomName = _princess.ChooseGroom();

            if (groomName != null)
            {
                Character? groom = _hall.GetVisitedCharacterByName(groomName);
                view.ShowHappines(_princess.GetHappines(groom?.Coolness));
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
