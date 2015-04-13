#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#define MAGNIFY 20000

typedef struct Wave {
	char RIFF[4];
	int chunkSize; 
	char WAVE[4];
	char format[4];
	int formatSize;    // 16
	short audioFormat; // 1
	short numChannel;  // 2
	int sampleRate;    // 44100
	int byteRate;      // 4*44100
	short blockAlign;  // 4
	short bitsPerSample; // 24 byte
	char data[4];
	int dataSize; // 8 byte
} WAVE;

typedef struct Note {
	double frequency;
	double duration;
} NOTE;

double FindDelta(double frequency, double duration, int sampleNum)
{
	double PI = cos(-1);
	double delta = (2*PI) * frequency / 44100;
	return delta;
}

int main(void)
{
	//process note
	NOTE note[1000];
	int noteNum = 0, i, j;
	double dur = 0;
	while (scanf("%lf%lf", &note[noteNum].frequency, &note[noteNum].duration) != EOF) {
		dur += note[noteNum].duration;
		noteNum++;
	}
	//printf("%f secs\n%d notes\n", dur, noteNum);

	//process headers
	WAVE wave;
	strcpy(wave.RIFF, "RIFF");
	strcpy(wave.WAVE, "WAVE");
	strcpy(wave.format, "fmt");
	wave.format[3] = 32;
	strcpy(wave.data, "data");
	wave.formatSize = 16;
	wave.audioFormat = 1;
	wave.numChannel = 2;
	wave.sampleRate = 44100;
	wave.bitsPerSample = 16; //bits
	wave.byteRate = 44100 * 2 * 2; // wave.sampleRate * wave.numChannel * (wave.bitsPerSample/8) byte
	wave.blockAlign = 2 * 2; // wave.numChannel * (wave.bitsPerSample/8) byte
	wave.dataSize = wave.byteRate * dur;
	wave.chunkSize = 36 + wave.dataSize;
	
	//write file 
	FILE *fp;
	fp = fopen("wave.wav", "wb");
	assert(fp != NULL);

	fwrite(&wave, sizeof(WAVE), 1, fp);

	int sampleNum;
	for (i = 0 ; i < noteNum ; i++) {
		sampleNum = note[i].duration * 44100 * 2; // dur * sampleRate * channel
		short int sample[sampleNum];
		double delta = FindDelta(note[i].frequency, note[i].duration, sampleNum);
		for (j = 0 ; j < sampleNum ; j += 2) {
			sample[j] = sin(delta * j) * MAGNIFY;
			sample[j+1] = sin(delta * j) * MAGNIFY;
		}
		fwrite(sample, sizeof(short int), sampleNum, fp);
	}
	fclose(fp);
	return 0;
}