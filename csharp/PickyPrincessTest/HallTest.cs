using Microsoft.VisualStudio.TestTools.UnitTesting;
using util;
using model;
using exceptions;
using System;

namespace PickyPrincessTest;

[TestClass]
public class HallTest
{
    [TestMethod]
    public void NextCharacterTest()
    {
        var generator = new CharacterGenerator();
        var hall = new Hall(generator);

        var characterName = hall.GetNextVisitorName();
        Assert.IsInstanceOfType(characterName, typeof(string));

        var character = hall.GetVisitedCharacterByName(characterName);
        Assert.IsInstanceOfType(character.Name, typeof(string));
        Assert.IsInstanceOfType(character.Coolness, typeof(int));
    }

    [TestMethod]
    public void NoCharactersLeftTest()
    {
        var generator = new CharacterGenerator();
        var hall = new Hall(generator);
        var friend = new Friend(hall);

        for (int i = 0; i < 100; i++)
        {
            hall.GetNextVisitorName();
        }
        
        Action action = () => hall.GetNextVisitorName();

        Assert.ThrowsException<HallException>(action, "Characters in hall list is empty");
    }
}