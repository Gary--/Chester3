using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chester3.Common
{
    /// <summary>
    /// Represents one square on the board.
    /// </summary>
    /// <remarks>
    ///      C0 C1 C2 C3 C4 C5 C6 C7
    ///      -----------------------
    /// R0 |  0  1  2  3  4  5  6  7
    /// R1 |  8  9 10 11 12 13 14 15
    /// R2 | 16 17 18 19 20 21 22 23
    /// R3 | 24 25 26 27 28 29 30 31
    /// R4 | 32 33 34 35 26 27 38 39
    /// R5 | 40 41 42 43 44 45 46 47
    /// R6 | 48 49 50 51 52 53 54 55
    /// R7 | 56 57 58 59 60 61 62 63
    /// </remarks>
    internal struct Position
    {
        byte value;

        public Position(int value)
        {
#if DEBUG
            if (value < 0 || value > 63)
            {
                throw new ArgumentOutOfRangeException(
                    String.Format("Cannot initialize Position with value: {0}",value));
            }
#endif
            this.value = (byte)value;
        }

        public Position(int row, int column)
        {
#if DEBUG
            if (row < 0 || row > 7 || column < 0 || column > 7)
            {
                throw new ArgumentOutOfRangeException(
                    String.Format("Cannot initialize Position with (row,col): ({0}.{1})", row,column));
            }
#endif
            this.value = (byte)(row * 8 + column);
        }

        public int Row
        {
            get { return value / 8; }
        }

        public int Column
        {
            get { return value % 8; }
        }
    }
}
