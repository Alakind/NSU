using Microsoft.VisualStudio.TestTools.UnitTesting;
using util;

namespace PickyPrincessTest;

[TestClass]
public class UnitTest1
{
    [TestMethod]
    public void TestMethod1()
    {
        var generator = new CharacterGenerator();

        Assert.AreEqual(1, 1);
    }
}