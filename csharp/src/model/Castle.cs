namespace model;

using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using exceptions;
using view;
using util;

public class Castle : IHostedService
{
    private IHostApplicationLifetime Lifetime;

    public Castle(IHostApplicationLifetime lifetime)
    {
        Lifetime = lifetime;
    }

    private void StartGroomViewings()
    {
        var view = new ConsoleView();
        var reader = new CharacterGenerator();

        view.Greet();

        Character[] characters = reader.GetCharactersFromFile();

        var hall = new Hall(characters);
        var throneRoom = new ThroneRoom(hall);

        var victoria = new Friend(hall);

        var diana = new Princess(throneRoom, victoria);

        try
        {
            string? groomName = diana.ChooseGroom();

            if (groomName != null)
            {
                Character? groom = hall.GetVisitedCharacterByName(groomName);
                view.ShowHappines(diana.GetHappines(groom?.Coolness));
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