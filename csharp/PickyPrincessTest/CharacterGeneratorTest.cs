using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using util;
using model;
using mocks;
using FluentAssertions;

namespace PickyPrincessTest;

[TestClass]
public class CharacterGeneratorTest
{
    [TestMethod]
    public void NamesUnique()
    {
        var generator = new CharacterGeneratorMock();

        Character[] characters = generator.GetCharactersList();
        characters.Should().OnlyHaveUniqueItems();
    }
}
