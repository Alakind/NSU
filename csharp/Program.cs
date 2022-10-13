using view;
using util;
using model;

var view = new ConsoleView();
var reader = new CharacterGenerator();

view.Greet();

Character[] characters = reader.GetCharactersFromFile();

var hall = new Hall(characters);
var throneRoom = new ThroneRoom(hall);

var victoria = new Friend(hall);

var diana = new Princess(throneRoom, victoria);

string? groomName = diana.ChooseGroom();

Character? groom = hall.GetBeenCharacterByName(groomName);

view.ShowGroom(groomName);
view.ShowHappines(diana.GetHappines(groom?.Coolness));
