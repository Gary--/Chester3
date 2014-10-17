using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chester3.Common
{
    internal static class Chess
    {
        public enum Piece : byte { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, UNKNOWN};
        public enum Color : byte { WHITE, BLACK };
    }
}
