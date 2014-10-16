using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Chester3.Common
{
    /// <summary>
    /// Represents a set of the 64 squares.
    /// </summary>
    /// <remarks>
    /// The least significant to most significant bits of the 64 bit integer
    /// correspond to the squares iterated in English reading order.
    /// </remarks>
    
    internal struct BitBoard
    {
        private ulong value;

        public BitBoard(ulong value){
            this.value = value;
        }

        public override string ToString()
        {
            string result = String.Empty;
            //for (int row = 0; row < 8; row++)
            //{
                
            //}
            return result;
        }
        
        #region Basic Operations << >> ~ | & ^
        public static BitBoard operator <<(BitBoard bb, int x)
        {
            return new BitBoard(bb.value << x);
        }

        public static BitBoard operator >>(BitBoard bb, int x)
        {
            return new BitBoard(bb.value >> x);
        }

        public static BitBoard operator ~(BitBoard bb)
        {
            return new BitBoard(~bb.value);
        }

        public static BitBoard operator |(BitBoard bb1, BitBoard bb2)
        {
            return new BitBoard(bb1.value | bb2.value);
        }

        public static BitBoard operator &(BitBoard bb1, BitBoard bb2)
        {
            return new BitBoard(bb1.value & bb2.value);
        }

        public static BitBoard operator ^(BitBoard bb1, BitBoard bb2)
        {
            return new BitBoard(bb1.value ^ bb2.value);
        }
        
        #endregion


    }
}
