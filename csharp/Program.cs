using view;
using util;
using model;

var view = new ConsoleView();
var reader = new CharacterGenerator();

view.Greet();

Character[] characters = reader.GetCharactersFromFile();

var hall = new Hall(characters);

var victoria = new Friend(hall);

var diana = new Princess(hall, victoria);

string? groom = diana.ChooseGroom();

view.ShowGroom(groom, diana.CountHappines(hall.CurrentCharacter));
