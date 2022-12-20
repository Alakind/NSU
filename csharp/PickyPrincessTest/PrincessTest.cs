using Microsoft.VisualStudio.TestTools.UnitTesting;
using util;
using model;
using exceptions;
using System;

namespace PickyPrincessTest;

[TestClass]
public class PrincessTest
{
    [TestMethod]
    public void HappinessMathTest()
    {
        var generator = new CharacterGenerator();
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);

        var character = new Character("Name", 10);
        Assert.AreEqual(0, princess.GetHappines(character.Coolness));

        character = new Character("Name", 100);
        Assert.AreEqual(100, princess.GetHappines(character.Coolness));

        character = new Character("Name", 90);
        Assert.AreEqual(90, princess.GetHappines(character.Coolness));

        character = new Character("Name", 50);
        Assert.AreEqual(50, princess.GetHappines(character.Coolness));

        character = new Character("Name", 49);
        Assert.AreEqual(0, princess.GetHappines(character.Coolness));

        Assert.AreEqual(10, princess.GetHappines(null));
    }

    [TestMethod]
    public void NoCharactersLeftTest()
    {
        var generator = new CharacterGenerator();
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);

        for (int i = 0; i < 99; i++)
        {
            hall.GetNextVisitorName();
        }
        
        Action action = () => princess.ChooseGroom();

        Assert.ThrowsException<HallException>(action);
    }
}