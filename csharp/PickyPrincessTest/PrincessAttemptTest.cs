using System;
using database;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using model;
using PrincessDB;
using util;

namespace PickyPrincessTest;

[TestClass]
public class PrincessAttemptTest
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
    public async void GenerateAttemptTest()
    {
        var attemptGenerator = new AttemptGenerator(_context);

        await attemptGenerator.GenerateAttempt();

        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);
        
        await hall.CallNewCharacters();
        
        string? groomName = princess.ChooseGroom();

        Character? groom = hall.GetVisitedCharacterByName(groomName);
        Assert.IsInstanceOfType(princess.GetHappines(groom?.Coolness), typeof(int));
    }
}
