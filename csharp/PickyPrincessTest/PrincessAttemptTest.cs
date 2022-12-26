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
        var attemptGenerator = new AttemptGenerator();

        await attemptGenerator.Generate(_context);

        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);
        
        await hall.SetUpDB();
        
        string? groomName = princess.ChooseGroom();

        if (groomName != null)
        {
            Character? groom = hall.GetVisitedCharacterByName(groomName);
            Assert.IsInstanceOfType(princess.GetHappines(groom?.Coolness), typeof(int));
        }
    }
}
