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
        

        public static BitBoard FULL { get { return new BitBoard(~0UL);} }
        public static BitBoard EMPTY { get { return new BitBoard(0UL); } }

        private UInt64 value;

        public BitBoard(UInt64 value)
        {
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

        public BitBoard LeastBit()
        {
            return new BitBoard(value & (UInt64)(-(Int64)value));
        }

        public static bool operator==(BitBoard bb1, BitBoard bb2){
            return bb1.value == bb2.value;
        }

        public static bool operator!=(BitBoard bb1, BitBoard bb2){
            return bb1.value != bb2.value;
        }

        public override bool Equals(object obj)
        {
            if (obj.GetType() == typeof(BitBoard))
            {
                return this.value.Equals(((BitBoard)obj).value);
            }


            return false;
        }

        public override int GetHashCode()
        {
            return value.GetHashCode();
        }

        /// <summary>
        /// Call only on a singular BitBoard.
        /// </summary>
        /// <returns>Position corresponding to the only on bit.</returns>
        public Position Position()
        {

#if DEBUG
            {
                BitBoard bit = this.LeastBit();
                if (bit != this)
                {
                    throw new InvalidOperationException("Cannot take Position of non singular BitBoard.");
                }
            }
#endif
            //TODO: optimize this
            for (int i = 0; i < 64; ++i)
            {
                if (value == (1UL << i))
                {
                    return new Position(i);
                }
            }

            return new Position(0);
        }

        #endregion
        public IEnumerable<Position> Positions()
        {
            //TODO: optimize this
            for (int i = 0; i < 64; ++i)
            {
                if (value == (1UL << i))
                {
                    yield return new Position(i);
                }
            }
        }

    }
}
