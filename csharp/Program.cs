using view;
using util;
using model;

var view = new ConsoleView();
var reader = new CharacterGenerator();

view.Greet();

Character[] characters = reader.GetCharactersFromFile();

var hall = new Hall(characters);

var character = hall.NextCharacter();

while (character != null)
{
    view.ShowCharacter(character);
    character = hall.NextCharacter();
}
