using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using util;
using model;
using mocks;

namespace PickyPrincessTest;

[TestClass]
public class CharacterGeneratorTest
{
    [TestMethod]
    public void NamesUnique()
    {
        var generator = new CharacterGeneratorMock();

        Character[] characters = generator.GetCharactersList();
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