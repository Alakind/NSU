using System;
using database;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using model;
using PrincessDB;
using util;

namespace PickyPrincessTest;

[TestClass]
public class AttemptGeneratorTest
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
        var generator = new AttemptGenerator(_context);

        await generator.GenerateAttempt();
        
        var attemptEntity = await _context.Attempts
            .Include(c => c.CharactersList)
            .FirstOrDefaultAsync(a => a.Number == AttemptData.AttemptNumber);
        
        Assert.AreEqual(attemptEntity.CharactersList.Count, 100);
    }
}
