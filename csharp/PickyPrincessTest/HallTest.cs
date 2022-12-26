using Microsoft.VisualStudio.TestTools.UnitTesting;
using util;
using model;
using exceptions;
using System;
using database;
using Microsoft.EntityFrameworkCore;
using mocks;

namespace PickyPrincessTest;

[TestClass]
public class HallTest
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
    public void NextCharacterTest()
    {
        var generator = new CharacterGeneratorMock();
        var hall = new Hall(generator);

        for (int i = 0; i < 3; i++)
        {
            var characterName = hall.GetNextVisitorName();
            var character = hall.GetVisitedCharacterByName(characterName);

            Assert.AreEqual(character.Coolness, i + 1);
        }
    }

    [TestMethod]
    public void NoCharactersLeftTest()
    {
        var generator = new CharacterGenerator(_context);
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
