using view;
using util;
using model;

var view = new ConsoleView();
var reader = new CharacterGenerator();

view.Greet();

Character[] characters = reader.GetCharactersFromFile();

var hall = new Hall(characters);

var diana = new Princess(hall);

Character? groom = diana.ChooseGroom();

view.ShowGroom(groom, diana.countHappines(groom));
