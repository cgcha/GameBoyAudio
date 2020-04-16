//the gameboy sound has 4 channels, 2 square waves, 1 sawtooth, and 1 noise channel

//the squarewave channels have a frequency value from 0-2047, volume from 0-15, 
//volume sweeping from -8-7

//only the first squarewave channel can use frequency sweeping, having a frequency sweep period 0-7,
// and a sweep rate from -8-7

//the wave table

class SquareWave1
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

class SquareWave2
{
public:
    int freq;
    int volume;
    int volumeSweeping;
    
    void print()
    {
 
    }
};

class Sawtooth
{
public:
    void print()
    {

    }
};

class Noise
{
public:

    void print()
    {

    }
};


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
