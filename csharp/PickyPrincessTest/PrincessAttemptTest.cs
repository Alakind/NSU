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
    [DataRow(0)]
    [DataRow(2)]
    [DataRow(34)]
    [DataRow(42)]
    public async void PrincessHandleAttemptTest(int attemptNumber)
    {
        var attemptGenerator = new AttemptGenerator(_context);

        await attemptGenerator.GenerateAttempt();

        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);
        var throneRoom = new ThroneRoom(hall);
        var princess = new Princess(throneRoom, friend);
        
        AttemptData.AttemptNumber = attemptNumber;
        await hall.CallNewCharacters();
        string? groomName1 = princess.ChooseGroom();
        
        await hall.CallNewCharacters();
        string? groomName2 = princess.ChooseGroom();

        Assert.Equals(groomName1, groomName2);
    }
}
