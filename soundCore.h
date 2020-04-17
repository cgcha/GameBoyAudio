#include <SFML/Audio.hpp>


//the gameboy sound has 4 channels, 2 square waves, 1 sawtooth, and 1 noise channel

//the squarewave channels have a frequency value from 0-2047, volume from 0-15, 
//volume sweeping from -8-7

//only the first squarewave channel can use frequency sweeping, having a frequency sweep period 0-7,
// and a sweep rate from -8-7

//the wave table
namespace soundChannels{

    class SquareWave1Values
    {
    public:
        int dutyType;
        int freq;
        int freqSweepPeriod;
        int freqSweepRate;
        int volume;
        int volumeSweeping;
        int length;
        bool lengthTrigger;

        void print()
        {

        }
    };

    class SquareWave2Values
    {
    public:
        int dutyType;
        int freq;
        int volume;
        int volumeSweepPeriod;
        int volumeSweepRate;
        int length;
        bool lengthTrigger;
        void print()
        {
    
        }
    };

    class SawtoothValues
    {
    public:
        int freq;
        int volume;
        int length;
        bool lengthTrigger;
        void print()
        {
            
        }
    };

    class NoiseValues
    {
    public:
        int freq;
        int volume;
        int volumeSweepPeriod;
        int volumeSweepRate;
        int length;
        bool lengthTrigger;
        void print()
        {

        }
    };

}

namespace soundGenerator
{
    short SquareWave(double time, double freq, double volume){
        short result = 0;
        int tpc = 44100 / freq; // ticks per cycle
		int cyclepart = int(time) % tpc;
		int halfcycle = tpc / 2;
		short amplitude = 30000 * volume;
		if (cyclepart < halfcycle) {
			result = amplitude;
		}
		return result; 
    }

    short Sawtooth(double time, double freq, double volume) {
		short result = 0;
        int tpc = 44100 / freq; // ticks per cycle
		short amplitude = 30000 * volume;
		int cyclepart = int(time) % tpc;
		int halfcycle = tpc / 2;
        result += amplitude;
		if (cyclepart < halfcycle) {
			result = 0;
		}
		return result;
	}

    short Noise(double volume) {
		short result = 0;
		short amplitude = 30000 * volume;
        // need to implement true game boy noise semi-randomness
		result = rand() % amplitude;
		return result;
	}

}
namespace soundCommands
{
    //set duty channel FC
    void FC(/*1 byte instruction*/)
    {
        /* This uses a full 8 bits and holds 4 
           whole duty cycles of 2 bits each
           in order to make more interesting sounds. 
           If only one duty channel is wanted, 
           all four can be set to the same 
           Example: FC 1B = duty 0123 base 4
              00 01 10 11 = 0 1 2 3*/ 

    }

    //play a pulse note
    void PN(/* 4 byte instruction */)
    {
        /* OP Codes 20-2F 
           The lower half of the op code represents the length of the
           note in frames minus one, ranging from 1 to 16. Once the 
           note has been playing for the number of frames specified,
           the next note is played. (return) If there are no more
           notes, then the last one will keep playing until the
           volume is swept to zero. If this happens, the duty 
           cycle is not updated, to make the note taper off 
           smoothly. */
           
        /* The second byte of the command controls the volume and
           the volume sweep, and goes directly to the register that
           controls the audio channel. The upper half is the initial
           volume from 0 to 15. The lower half is a signed 4 bit number
           that controls the direction and speed of the volume sweep. 
           Positive numbers make the note get quieter over time, zero
           makes it stay the same, and negative numbers make it get louder.
           A smaller magnitude will make the note change quicker, and a 
           higher magnitude will have the opposite effect.*/
        
        /* The last two bytes contain the frequency value that is supplied 
           by the sound engine. The actual frequency that is played is 
           determined by the formula
           
           f_{hz}=131072/(2048-f_{dmg})

           Which gives us the note key

           n_{key}=12log_{2}(f_{hz}/440)+49

           This means that a small change in a low value doesn't have much
           of an effect, but a small change in a high value can change
           the pitch a lot. */

    }

    //play a noise note
    void NN(/* 3 byte instruction, last byte is noise parameter*/){

        /* This command is identical to the pulse note command (PN), but it
           is used by the noise channel instead. The only difference is that
           instead of a 16-bit frequency value, an 8-bit noise parameter is
           used.*/
        
        /* In byte 3, the third bit is  used to control the length of the
           LFSR, 15 bits when clear and 7 bits when set. The other seven 
           bits are used to control the frequency at which it is sampled.
           The first 4 bits are represented with S, and the last 3 bits are
           represented with H.
           
           These can be used for the formula
           f_{hz}=524288/(H*2^{S+1}) */
        
        /* This step is more complicated, but each time the LFSR is sampled,
           the output is just the inverse of the single lowest bit in the 
           register (the rightmost bit). This is then adjusted by the current 
           volume of the noise channel. Then the entire register is right 
           shifted once. The new bit 0 and previous bit 0 are XORed together
           and the new result is put at the 15th bit, and also the 7th bit 
           depending on the length setting.
           The purpose of this is to produce a pseudo random output, resulting
           in a noise that sort of sounds like TV static.*/
    }

    //loop
    void loop(){

    }

    //end
    void FF(){


    }
}