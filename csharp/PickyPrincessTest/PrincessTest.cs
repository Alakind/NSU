using Microsoft.VisualStudio.TestTools.UnitTesting;
using util;
using model;
using exceptions;
using System;
using database;
using Microsoft.EntityFrameworkCore;

namespace PickyPrincessTest;

[TestClass]
public class PrincessTest
{
    private ApplicationContext _context;

    [ClassInitialize]
    public void SetUp()
    {
        var options = new DbContextOptionsBuilder<ApplicationContext>()
            .UseInMemoryDatabase(Guid.NewGuid().ToString())
            .Options;
        _context = new ApplicationContext();
    }

    [TestMethod]
    public void HappinessMathTestNull()
    {
        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);

        Assert.AreEqual(10, princess.GetHappines(null));
    }

    [TestMethod]
    [DataRow(100, 100)]
    [DataRow(98, 98)]
    [DataRow(0, 10)]
    [DataRow(90, 90)]
    [DataRow(50, 50)]
    [DataRow(0, 49)]
    public void HappinessMathTest(int expectHappiness, int coolness)
    {
        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);

        var character = new Character("Name", coolness);
        Assert.AreEqual(expectHappiness, princess.GetHappines(character.Coolness));
    }

    [TestMethod]
    public void NoCharactersLeftTest()
    {
        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);

        for (int i = 0; i < 99; i++)
        {
            hall.GetNextVisitorName();
        }
        
        Action action = () => princess.ChooseGroom();

        Assert.ThrowsException<HallException>(action, "Characters in hall list is empty");
    }
}
