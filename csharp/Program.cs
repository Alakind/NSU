using view;
using util;
using model;
using exceptions;

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
