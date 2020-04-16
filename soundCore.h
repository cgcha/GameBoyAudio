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
        int freq;
        int freqSweeping;
        int volume;
        int volumeSweeping;
        

        void print()
        {

        }
    };

    class SquareWave2Values
    {
    public:
        int freq;
        int volume;
        int volumeSweeping;
        
        void print()
        {
    
        }
    };

    class SawtoothValues
    {
    public:
        void print()
        {
            
        }
    };

    class NoiseValues
    {
    public:

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

    short Noise(double volume) {
		short result = 0;
		short amplitude = 30000 * volume;
		result = rand() % amplitude;
		return result;
	}

    short Sawtooth(double time, double freq, double volume) {
		short result = 0;
		short amplitude = 30000 * volume;
		result = rand() % amplitude;
		return result;
	}

}

//set duty channel FC
void FC(int x, int y)
{
}

//play a pulse note
void PN()
{


}

//play a noise note
void NN(){


}

//loop
void loop(){

}

//end
void FF(){


}
