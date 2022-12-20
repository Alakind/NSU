using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using util;
using model;

namespace PickyPrincessTest;

[TestClass]
public class UnitTest1
{
    [TestMethod]
    public void NamesUniq()
    {
        var generator = new CharacterGenerator();

        Character[] characters = generator.GetCharactersFromFile();
        var isCharacterBeen = new Dictionary<string, bool>();
        for (int i = 0; i < characters.Length; i++) {
            isCharacterBeen.Add(characters[i].Name, false);
        }

        for (int i = 0; i < characters.Length; i++) {
            Assert.AreEqual(isCharacterBeen[characters[i].Name], false);

            isCharacterBeen.Remove(characters[i].Name);
            isCharacterBeen.Add(characters[i].Name, true);
        }
    }
}