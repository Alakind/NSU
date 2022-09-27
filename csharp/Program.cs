using view.ConsoleView;
using util.FileReader;
using model.Character;

var view = new ConsoleView();
var reader = new FileReader();

view.Greet();

Character[] characters = reader.GetCharacters();

foreach (Character character in characters) {
    view.ShowCharacter(character);
}
