using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Chester3.Common;

namespace Common.Test
{
    [TestClass]
    public class NameTest
    {

        static Random rand = new Random();
        public static UInt64 NextInt64()
        {
            var buffer = new byte[sizeof(UInt64)];
            rand.NextBytes(buffer);
            return BitConverter.ToUInt64(buffer, 0);
        }

        [TestMethod]
        public void Position_Row_Column()
        {
            Position pos = new Position(44);


            Assert.AreEqual(4, pos.Column);
            Assert.AreEqual(5, pos.Row);
        }

        [TestMethod]
        public void Bitboard_Position_Iterator()
        {
            int testsToDo = 1000;
            for (int i = 0; i < testsToDo; ++i)
            {

            }
        }
        


    }
}
