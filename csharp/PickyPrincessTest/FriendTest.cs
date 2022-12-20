using Microsoft.VisualStudio.TestTools.UnitTesting;
using util;
using model;
using exceptions;
using System;

namespace PickyPrincessTest;

[TestClass]
public class FriendTest
{
    [TestMethod]
    public void CompareTest()
    {
        var generator = new CharacterGenerator();
        var hall = new Hall(generator);
        var friend = new Friend(hall);

        var characterName1 = hall.GetNextVisitorName();
        var characterName2 = hall.GetNextVisitorName();

        var character1 = hall.GetVisitedCharacterByName(characterName1);
        var character2 = hall.GetVisitedCharacterByName(characterName2);
        
        var coolestCharacter = character1.Coolness > character2.Coolness
            ? character1.Name : character2.Name;
        
        Assert.AreEqual(coolestCharacter, friend.PickCoolest(character1.Name, character2.Name));
    }

    [TestMethod]
    public void NotFamiliarTest()
    {
        var generator = new CharacterGenerator();
        var hall = new Hall(generator);
        var friend = new Friend(hall);

        var characterName = hall.GetNextVisitorName();
        
        Action action = () => friend.PickCoolest(characterName, "anonim");

        Assert.ThrowsException<InvalidInputException>(action);
    }
}