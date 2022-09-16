using view.ConsoleView;
using util.FileReader;
using model.Character;

var view = new ConsoleView();
var reader = new FileReader();

view.Greet();

Character[] characters = reader.GetCharacters();

for (int i = 0; i < characters.Length; i++) {
    view.ShowCharacter(characters[i]);
}
