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
public class FriendTest
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
    public void CompareTest()
    {
        var generator = new CharacterGeneratorMock();
        var hall = new Hall(generator);
        var friend = new Friend(hall);

        var lessCoolerCharacterName = hall.GetNextVisitorName();
        var moreCoolerCharacterName = hall.GetNextVisitorName();

        var lessCoolerCharacter = hall.GetVisitedCharacterByName(lessCoolerCharacterName);
        var moreCoolerCharacter = hall.GetVisitedCharacterByName(moreCoolerCharacterName);
        
        Assert.AreEqual(moreCoolerCharacterName, friend.PickCoolest(lessCoolerCharacter.Name, moreCoolerCharacter.Name));
    }

    [TestMethod]
    public void NotFamiliarTest()
    {
        var generator = new CharacterGenerator(_context);
        var hall = new Hall(generator);
        var friend = new Friend(hall);

        var characterName = hall.GetNextVisitorName();
        
        Action action = () => friend.PickCoolest(characterName, "anonim");

        Assert.ThrowsException<InvalidInputException>(action, "Character given to camparison is not valid!");
    }
}
